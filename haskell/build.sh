echo $'Building project...\n'
cabal build
if [ $? -ne 0 ]; then
  echo "Error: Project build failed"
  exit 1
fi
echo $'\nBuilt successfully!\n'

echo "Moving project binary..."
mkdir -p ../public
rm -f ../public/haskell.wasm
cp ./dist-newstyle/build/wasm32-wasi/ghc-*/haskell-0.1.0.0/x/haskell/build/haskell/haskell.wasm ../public/haskell.wasm
echo "Binary moved successfully!"