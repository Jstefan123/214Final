#include "sign.h"

class Database {

private:

	struct Span {

		//name of the sign
		std::string name;

		//vector of the different varainces of road signs
		std::vector <Sign> signs;
	};

	//vector of all the spans of signs
	std::vector <Span> data;

public:
	//returns the discrepancy betwen the pixel matrices from projecting the vectors
	//of query onto the corresponding vectors in this sign in the span
	double getSpanError(Span &data, Sign &query) {

	}
};