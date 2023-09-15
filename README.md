# ghc-web-test

This is an example project that uses GHC's WebAssembly build capabilities in a
simple application to demonstrate how to call Haskell from JavaScript and vice
versa.

## Prerequisites

To run this project you will need to have installed Nix, Cabal, and NodeJS

## Running the code

### Compile the Haskell code

Run the following command:

```sh
nix shell https://gitlab.haskell.org/ghc/ghc-wasm-meta/-/archive/master/ghc-wasm-meta-master.tar.gz --extra-experimental-features nix-command --extra-experimental-features flakes
```

This will enter a nix flake with the GHC to WASM compiler available.

Then run the following commands to compile the Haskell code:

```sh
cd haskell
./build.sh
```

You can then run `exit` to terminate the Nix flake.

### Start the frontend server

Run the following commands in this directory:

```sh
npm install
npm run serve
```

This will start up a server and open a window to localhost:8080.

If you want to make changes to the TS code, you can edit it and the server will automatically refresh. To make changes to the Haskell code, run the build.sh script after you edit the code.
