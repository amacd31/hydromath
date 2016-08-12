cp -r $RECIPE_DIR/.. $SRC_DIR
cmake -DCMAKE_INSTALL_PREFIX:PATH=$PREFIX .
make -j${CPU_COUNT}
make install
