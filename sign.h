#include <vector>
#include<cmath>
#include <iostream>
#include <fstream>

//the color of the layer of the image
enum class Color { red, green, blue };

class Sign {
    
private:
    
    //vectors representing the red, green, blue pixels in the image
    //16x16 images
    std::vector <double> redPix;
    std::vector <double> greenPix;
    std::vector <double> bluePix;
    
public:
    
    //constructor that reserves the size
    Sign();
    
    //reads in the red pixel of an imgae
    void readInRedPixels(std::ifstream &read);
    
    //reads in the red pixel of an imgae
    void readInBluePixels(std::ifstream &read);
    
    //reads in the green pixel of an imgae
    void readInGreenPixels(std::ifstream &read);
    
    void readInImagePixels(std::string &redFile, std::string &blueFile, std::string &greenFile);
    
    //returns the discrepancy betwen the pixel matrices from projecting the vectors
    //of query onto the corresponding vectors in this sign
    double getError(Sign &query);
    
    //returns the magnitude of a vector
    double findMagnitude(std::vector <double> &v);
    
    //projection of v1 onto v2
    std::vector <double> projection(std::vector <double> &v1, std::vector <double> v2);
    
    // Returns the magnitude of the difference between two vectors
    double mag_of_diff(std::vector <double> &v1, std::vector <double> &v2);
};
