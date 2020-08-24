# Neural-Network-in-C-plus-plus
Its a simple neural network in c++ implemented in c++
the data used here is planar data used in deeplearning.ai's first course in deep learning series hosted on coursera
The data is hardcoded in dataset module
The c++ libraries required are vector, string, iostream, iomanip, bits/stdc++.h, time.h, cstdlib, math.h


# Running the project
Make sure you have all the libraries mentioned above.
Everything starts with index.cpp.
Compile all .cpp file by "g++ *.cpp -o train".
By default no of iterations is set to 20000 and learning rate is 1.2.To provide custom learning rate and no of iterations you can pass them as command line argument.
First argument is no of iteration and second one is learning rate. Follow sequence of command line arguments otherwise it may give error.
Run the code using "./train" or "./train 2000 1.2".If you run above command output will be printed in terminal. To direct output you can apend "> filename.txt" to the 
"./train" or "./train 2000 1.2".
Example: "./train 2000 1.2 > result.txt"
