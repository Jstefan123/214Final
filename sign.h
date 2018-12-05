#include <vector>
#include <iostream>
#include <ifstream>

//the color of the layer of the image
enum class Color { red, green, blue };

class Sign {

private:

	//name of the traffic sign
	std::string name;

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

};