cp -r $RECIPE_DIR/../src $SRC_DIR
cp -r $RECIPE_DIR/../includes $SRC_DIR
cp -r $RECIPE_DIR/../CMakeLists.txt $SRC_DIR
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=$PREFIX .
make -j${CPU_COUNT}
make install
