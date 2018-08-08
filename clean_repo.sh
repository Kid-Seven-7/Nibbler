#!/usr/bin/env/bash

make fclean
find . -name ".DS_Store" -exec rm {} \;
rm -rf bin;
rm -rf build;
