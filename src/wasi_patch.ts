// Classes for stdout patch, see https://github.com/TristanCacqueray/browser_wasi_shim/commit/f34ed671b2ce2099983f365e6bb30d6f7fe7009c

const EVENTTYPE_CLOCK = 0;
const EVENTTYPE_FD_READ = 1;
const EVENTTYPE_FD_WRITE = 2;
const EVENTRWFLAGS_FD_READWRITE_HANGUP = 1;

type UserData = BigInt;

export class EventType {
  public variant: "clock" | "fd_read" | "fd_write";

  constructor(variant: "clock" | "fd_read" | "fd_write") {
    this.variant = variant;
  }

  static from_u8(data: number): EventType {
    switch (data) {
      case EVENTTYPE_CLOCK:
        return new EventType("clock");
      case EVENTTYPE_FD_READ:
        return new EventType("fd_read");
      case EVENTTYPE_FD_WRITE:
        return new EventType("fd_write");
      default:
        throw "Invalid event type " + String(data);
    }
  }

  to_u8(): number {
    switch (this.variant) {
      case "clock":
        return EVENTTYPE_CLOCK;
      case "fd_read":
        return EVENTTYPE_FD_READ;
      case "fd_write":
        return EVENTTYPE_FD_WRITE;
      default:
        throw "unreachable";
    }
  }
}

export class EventRwFlags {
  private hangup: boolean;

  static from_u16(data: number): EventRwFlags {
    const self = new EventRwFlags();
    if (
      (data & EVENTRWFLAGS_FD_READWRITE_HANGUP) ==
      EVENTRWFLAGS_FD_READWRITE_HANGUP
    ) {
      self.hangup = true;
    } else {
      self.hangup = false;
    }
    return self;
  }

  to_u16(): number {
    let res = 0;
    if (this.hangup) {
      res = res | EVENTRWFLAGS_FD_READWRITE_HANGUP;
    }
    return res;
  }
}

export class EventFdReadWrite {
  private nbytes: BigInt;
  private flags: EventRwFlags;

  constructor(nbytes: BigInt, flags: EventRwFlags) {
    this.nbytes = nbytes;
    this.flags = flags;
  }

  write_bytes(view: DataView, ptr: number) {
    view.setBigUint64(ptr, this.nbytes.valueOf(), true);
    view.setUint16(ptr + 8, this.flags.to_u16(), true);
  }
}

export class Event {
  public userdata: UserData;
  public error: number;
  public type: EventType;
  public fd_readwrite: EventFdReadWrite | null;

  write_bytes(view: DataView, ptr: number) {
    view.setBigUint64(ptr, this.userdata.valueOf(), true);
    view.setUint32(ptr + 8, this.error, true);
    view.setUint8(ptr + 12, this.type.to_u8());
    if (this.fd_readwrite) {
      this.fd_readwrite.write_bytes(view, ptr + 16);
    }
  }

  static write_bytes_array(view: DataView, ptr: number, events: Array<Event>) {
    for (let i = 0; i < events.length; i++) {
      events[i].write_bytes(view, ptr + 32 * i);
    }
  }
}

export class SubscriptionClock {
  // FIXME
}

export class SubscriptionFdReadWrite {
  private fd: number;

  static read_bytes(view: DataView, ptr: number): SubscriptionFdReadWrite {
    const self = new SubscriptionFdReadWrite();
    self.fd = view.getUint32(ptr, true);
    return self;
  }
}

export class SubscriptionU {
  public tag: EventType;
  private data: SubscriptionClock | SubscriptionFdReadWrite;

  static read_bytes(view: DataView, ptr: number): SubscriptionU {
    const self = new SubscriptionU();
    self.tag = EventType.from_u8(view.getUint8(ptr));
    switch (self.tag.variant) {
      case "clock":
        break; // FIXME implement
      case "fd_read":
      case "fd_write":
        self.data = SubscriptionFdReadWrite.read_bytes(view, ptr + 4);
        break;
      default:
        throw "unreachable";
    }
    return self;
  }
}

export class Subscription {
  public userdata: UserData;
  public u: SubscriptionU;

  static read_bytes(view: DataView, ptr: number): Subscription {
    const subscription = new Subscription();
    subscription.userdata = view.getBigUint64(ptr, true);
    subscription.u = SubscriptionU.read_bytes(view, ptr + 8);
    return subscription;
  }

  static read_bytes_array(
    view: DataView,
    ptr: number,
    len: number
  ): Array<Subscription> {
    const subscriptions: Subscription[] = [];
    for (let i = 0; i < len; i++) {
      subscriptions.push(Subscription.read_bytes(view, ptr + 12 * i));
    }
    return subscriptions;
  }
}
