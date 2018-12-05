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

};