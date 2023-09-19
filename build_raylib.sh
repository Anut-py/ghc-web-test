EMCC=emcc
EMAR=emar

set -e
echo "Checking if raylib is built..."
if [ ! -f "raylib/src/libraylib.a" ]; then
  echo "raylib archive does not exist"
  echo $'Building raylib...\n'

  cd raylib/src

  $EMCC -c rcore.c -pthread -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2
  $EMCC -c rshapes.c -pthread -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2
  $EMCC -c rtextures.c -pthread -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2
  $EMCC -c rtext.c -pthread -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2
  $EMCC -c rmodels.c -pthread -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2
  $EMCC -c utils.c -pthread -Os -Wall -DPLATFORM_WEB
  $EMCC -c raudio.c -pthread -Os -Wall -DPLATFORM_WEB

  $EMAR rcs libraylib.a rcore.o rshapes.o rtextures.o rtext.o rmodels.o utils.o raudio.o

  cd ../..

  echo $'\nraylib archive built successfully, continuing\n'
else
  echo $'raylib archive already exists, continuing\n'
fi

echo $'Compiling bindings...'

emcc cbits/rl_bindings.c raylib/src/libraylib.a \
  -Iraylib/src \
  -DPLATFORM_WEB \
  -DGRAPHICS_API_OPENGL_ES2 \
  \
  -sUSE_GLFW=3 \
  -sIMPORTED_MEMORY \
  -sSHARED_MEMORY \
  -sUSE_PTHREADS \
  -sALLOW_MEMORY_GROWTH \
  -sASYNCIFY \
  -sSTACK_SIZE=5MB \
  \
  -sMODULARIZE \
  -sEXPORT_NAME=Raylib \
  -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,setMainLoop \
  \
  -Wno-pthreads-mem-growth \
  \
  -o raylib.js

echo $'Bindings compiled successfully!\n'

echo "Moving output files..."

rm -f ./public/raylib.wasm
mv raylib.wasm ./public

rm -f ./src/raylib.js
mv raylib.js ./src

rm -f raylib.worker.js

echo "Output files moved successfully!"
