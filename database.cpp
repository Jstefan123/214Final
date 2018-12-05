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

	// Uses the various span errors to predict the road sign of the inputted image
    std::string predictSign(Sign &query) {

        // Keep track of the minimum span and the element at which it occurred
        std::string nameMinError = data[0].name;

        double minError = data[0].getSpanError;

        // Iterate through the vector of spans
        for (unsigned i = 1; i < data.size(); ++i) {

            // Reset the minimum when necessary
            if (data[i].getSpanError < minError) {

                minError = data[i].getSpanError;
                nameMinError = data[i].name;
            }
        }
        // Return the final minimum
        return nameMinError;
    }
};
