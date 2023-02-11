# ESGI - Programmation parallèle

# Getting started

1. Check if omp.h is recognized on your system, if not download it with `brew install libomp`
2. Compile the project with the `omp.h` with the following command :
    - For Linux : `g++ -Xpreprocessor -fopenmp -I /usr/local/opt/libomp/include/ -L /usr/local/opt/libomp/lib/ -lomp  *.cpp -o OmpTrace`
    - For MacOS M1 (with homebrew): ` g++ -Xpreprocessor -fopenmp -I /opt/homebrew/opt/libomp/include/ -L /opt/homebrew/opt/libomp/lib/ -lomp  *.cpp -o OmpTrace`
3. Execute the file outputted with `./OmpTrace image.png 20 20`