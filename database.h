#include "sign.h"
#include <string>

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

	//trains the traffic sign recognizer with the images in the database
	void train();

	// Uses the various span errors to predict the road sign of the inputted image
	std::string predictSign(Sign &query);
};
