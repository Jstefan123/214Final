//
//  driver.cpp
//  
//
//  Created by John Landy on 12/5/18.
//

//reads in the text file that has all the test file names from cin

#include "database.h"

int main() {
    // Create an instance of the Database class
    Database d;
    // Train using files from within the directory
    d.train();

	std::string testFile;

	//while there are test files to read
	while (std::cin >> testFile) {

		std::string redIn = testFile + "_red.txt";
		std::string greenIn = testFile + "_green.txt";
		std::string blueIn = testFile + "_blue.txt";

		// Create a Sign object from these files
		Sign sign;
		sign.readInImagePixels(redIn, greenIn, blueIn);

		// Predict the sign from the vector of signs
		std::string prediction = d.predictSign(sign);
		std::cout << "Prediction: " << prediction << '\n';

		std::cout << "Image: stop_sign" << '\n';
	}

	return 0;
}
