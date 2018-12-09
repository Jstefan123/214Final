#include "database.h"

void Database::train() {

	std::fstream fileRead;
	fileRead.open("fileNames.txt");

	std::string file;
	unsigned numImages;

	//iterate through the files in the text files and create the appropriate signs and spans
	while (fileRead >> file) {

		//create the Span for this sign
		Span span;

		//read in the sign name and number of images
		span.name = file;

		fileRead >> numImages;

		//loop through the images
		for (unsigned i = 0; i < numImages; ++i) {
			
			//create this individual sign
			Sign sign;

			//set the three pixel vectors for this sign in the span
			std::string red, green, blue;
			fileRead >> red >> green >> blue;

			//add the folder name in front of the file names
			red = "Normalized_Database_RGB/" + red;
			green = "Normalized_Database_RGB/" + green;
			blue = "Normalized_Database_RGB/" + blue;

			sign.readInImagePixels(red, green, blue);

			//add the sign to the span
			span.signs.push_back(sign);
		}
		//push back the span onto the database
		data.push_back(span);
	}

}

// Uses the various span errors to predict the road sign of the inputted image
//return a pair of pairs
//{ {prediction name, prediction error} , {nextClosest name, nextClosest error}}
std::pair < std::pair <std::string, double >, std::pair <std::string, double > > Database::predictSign(Sign &query) {

	// Keep track of the minimum span and the element at which it occurred
	std::string nameMinError = data[0].name;
	std::string nameNextMinError = data[1].name;

	double minError = data[0].getSpanError(query);
	double nextMinError = data[1].getSpanError(query);

	if (nextMinError < minError) {
		std::swap(minError, nextMinError);
		std::swap(nameMinError, nameNextMinError);
	}

	// Iterate through the vector of spans
	for (unsigned i = 2; i < data.size(); ++i) {

		// Reset the minimum when necessary

		double error = data[i].getSpanError(query);

		if (error < nextMinError) {

			if (error < minError) {

				//set old minError to the next minError
				nextMinError = minError;
				nameNextMinError = nameMinError;

				minError = error;
				nameMinError = data[i].name;
			}
			else {
				nextMinError = error;
				nameNextMinError = data[i].name;
			}
		}
	}
	// Return the stuff as specified at the comment above the function header
	return { {nameMinError, minError}, {nameNextMinError, nextMinError} };
}
