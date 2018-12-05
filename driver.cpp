//
//  driver.cpp
//  
//
//  Created by John Landy on 12/5/18.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "database.h"
#include "sign.h"

int main(int argc, char *argv[]) {
    // Create an instance of the Database class
    Database d;
    // Train using files from within the directory
    d.train();
    // Read in the filename from the command line
    std::string filename = argv[1];
    std::string redIn = filename + "_red.txt";
    std::string greenIn = filename + "_green.txt";
    std::string blueIn = filename + "_blue.txt";
    // Create a Sign object from these files
    Sign sign;
    sign.readInImagePixels(redIn, greenIn, blueIn);
    // Predict the sign from the vector of signs
    std::string prediction = d.predictSign(sign);
    std::cout << prediction << std::endl;
}
