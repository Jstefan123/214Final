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

			//loop through the rgb text files for this image
			for (unsigned i = 0; i < 3; ++i) {

				//set the three pixel vectors for this sign in the span
				std::string red, green, blue;
				fileRead >> red >> green >> blue;

				//add the folder name in front of the file names
				red = "Normalized_Database_RGB/" + red;
				green = "Normalized_Database_RGB/" + green;
				blue = "Normalized_Database_RGB/" + blue;

				sign.readInImagePixels(red, green, blue);
			}

			//add the sign to the span
			span.signs.push_back(sign);
		}
	}

}

// Uses the various span errors to predict the road sign of the inputted image
std::string Database::predictSign(Sign &query) {

	// Keep track of the minimum span and the element at which it occurred
	std::string nameMinError = data[0].name;

	double minError = data[0].getSpanError(query);

	// Iterate through the vector of spans
	for (unsigned i = 1; i < data.size(); ++i) {

		// Reset the minimum when necessary

		double error = data[i].getSpanError(query);

		if (error < minError) {

			minError = error;
			nameMinError = data[i].name;
		}
	}
	// Return the final minimum
	return nameMinError;
}
