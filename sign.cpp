
#include "sign.h"

//reserves the sign of each vector
Sign::Sign() {
	redPix.reserve(256);
	greenPix.reserve(256);
	bluePixPix.reserve(256);
}

//reads in the red pixel of an imgae
void Sign::readInRedPixels(std::ifstream &read, std::string &fileName) {

	int value;

	//while there is input to read in
	while (read >> value) {
		redPix.push_back(value);
	}
}

//reads in the red pixel of an imgae
void Sign::readInBluePixels(std::ifstream &read, std::string &fileName) {

	int value;

	//while there is input to read in
	while (read >> value) {
		bluePix.push_back(value);
	}
}

//reads in the green pixel of an imgae
void Sign::readInGreenPixels(std::ifstream &read, std::string &fileName) {

	int value;

	//while there is input to read in
	while (read >> value) {
		greenPix.push_back(value);
	}
}

void Sign::readInImagePixels(std::string &redFile, std::string &blueFile, std::string &greenFile) {

	//ifstream to read in image
	std::ifstream read;

	//load up each of the pixel vectors
	read.open(redFile);
	readInRedPixels(read, redFile);
	read.close();

	read.open(greenFile);
	readInGreenPixels(read, greenFile);
	read.close();

	read.open(blueFile);
	readInBluePixels(read, blueFile);
	read.close();
}

std::vector <int>& projection(std::vector <int> &p1, std::vector <int &p2) {

}
