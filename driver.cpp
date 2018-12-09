//
//  driver.cpp
//  
//
//  Created by John Landy on 12/5/18.
//

//reads in the text file that has all the test file names from cin

#include "database.h"

#include <iomanip>

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
		std::pair < std::pair < std::string, double >, std::pair < std::string, double > > prediction;
		prediction = d.predictSign(sign);

		std::cout << "Image: ";

		//read in correct prediction
		std::cin >> testFile;
		std::cout << testFile << '\n';

		
		std::cout << std::setprecision(2) << std::fixed;

		std::cout << "Prediction: " << prediction.first.first << '\n';
		std::cout << "Next Closest: " << prediction.second.first << '\n';
		std::cout << "Error Difference: " << prediction.second.second - prediction.first.second <<
			" (" << ((prediction.second.second - prediction.first.second) / prediction.first.second) * 100 << "%)" << '\n';

		std::cout << '\n';
	}

	return 0;
}
