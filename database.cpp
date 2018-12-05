#include "sign.h"

class Database {

private:

	struct Span {

		//name of the sign
		std::string name;

		//vector of the different varainces of road signs
		std::vector <Sign> signs;
        
        //returns the discrepancy betwen the pixel matrices from projecting the vectors
        //of query onto the corresponding vectors in this sign in the span
        double getSpanError(Sign &query) {

            double totError = 0;
            // Iterate through the vector of signs
            for (unsigned i = 0; i < signs.size(); ++i) {
                // At each sign, add the error
                totError += query.getError(signs[i]);
            }
            return totError / signs.size();
        }
	};

	//vector of all the spans of signs
	std::vector <Span> data;

public:

	void train() {
		std::ifstream fin;
		fin.open("fileName.txt");

		std::string file;
		std::string signName;
		int numImages;

		//iterate through the files in the text files and create the appropriate signs and spans
		while (fin >> file) {

			//read in the sign name and number of images
			signName = file;
			fin >> numImages;

			//loop through the image text files
			for (unsigned i = 0; i < numImages * 3; ++i) {
				fin >> file;

			}

		}

	}

	// Uses the various span errors to predict the road sign of the inputted image
    std::string predictSign(Sign &query) {

        // Keep track of the minimum span and the element at which it occurred
        std::string nameMinError = data[0].name;

        double minError = data[0].getSpanError;

        // Edge case: accounting for when size is 0 to avoid segfault
        if (data.size() > 0) {

            // Iterate through the vector of spans
            for (unsigned i = 1; i < data.size(); ++i) {

                // Reset the minimum when necessary
                if (data[i].getSpanError < minError) {

                    minError = data[i].getSpanError;
                    nameMinError = data[i].name;
                }
            }
        }
        // Return the final minimum
        return nameMinError;
    }
};
