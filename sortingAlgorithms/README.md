# Purpose
This repository's aim is understanding and originally implementing well-known sorting algorithms.

Compilation is done with using cmake.

in order to compile sorting algorithms, you must specify the type of sorting. 

currently there are two sorting algorithms are implemented:

-insertion

-merge

Usage example is like:
```sh
mkdir build
cd build
cmake -DSORT_TYPE=merge ..
make -j${nproc}
./sort
```
