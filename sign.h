#include <vector>
#include<cmath>
#include <iostream>
#include <ifstream>

//the color of the layer of the image
enum class Color { red, green, blue };

class Sign {

private:

	//vectors representing the red, green, blue pixels in the image
	//16x16 images
	std::vector <int> redPix;
	std::vector <int> greenPix;
	std::vector <int> bluePix;

public:

	//constructor that reserves the size
	Sign();

	//reads in the red pixel of an imgae
	void readInRedPixels(std::string &fileName);

	//reads in the red pixel of an imgae
	void readInBluePixels(std::string &fileName);

	//reads in the green pixel of an imgae
	void readInGreenPixels(std::string &fileName);

	//returns the discrepancy betwen the pixel matrices from projecting the vectors
	//of query onto the corresponding vectors in this sign
	double getError(Sign &query);

	//returns the magnitude of a vector
	double findMagnitude(std::vector <double> &v);

	//projection of v1 onto v2
	std::vector <double>& Sign::projection(std::vector <double> &v1, std::vector <double> &v2);

	//returns the discrepancy betwen the pixel matrices from projecting the vectors
	//of query onto the corresponding vectors in this sign
	double getError(Sign &query);
};