
#include "sign.h"

//reserves the sign of each vector
Sign::Sign() {
    redPix.reserve(256);
    greenPix.reserve(256);
    bluePix.reserve(256);
}

//reads in the red pixel of an imgae
void Sign::readInRedPixels(std::ifstream &read) {
    
    int value;
    
    //while there is input to read in
    while (read >> value) {
        redPix.push_back(value);
    }
}

//reads in the red pixel of an imgae
void Sign::readInBluePixels(std::ifstream &read) {
    
    int value;
    
    //while there is input to read in
    while (read >> value) {
        bluePix.push_back(value);
    }
}

//reads in the green pixel of an imgae
void Sign::readInGreenPixels(std::ifstream &read) {
    
    int value;
    
    //while there is input to read in
    while (read >> value) {
        greenPix.push_back(value);
    }
}

void Sign::readInImagePixels(std::string &redFile, std::string &greenFile, std::string &blueFile) {
    
    //ifstream to read in image
    std::ifstream read;
    
    //load up each of the pixel vectors
    read.open(redFile);
    readInRedPixels(read);
    read.close();
    
    read.open(greenFile);
    readInGreenPixels(read);
    read.close();
    
    read.open(blueFile);
    readInBluePixels(read);
    read.close();
}

//returns the magnitude of a vector
double Sign::findMagnitude(std::vector <double> &v) {
    
    double mag = 0;
    
    //square each value
    for (auto val : v) {
        mag += std::pow(val, 2);
    }
    
    //return the square root
    return std::sqrt(mag);
}

//projection of v1 onto v2
//v2 not by reference to avoid changing v2
std::vector <double> Sign::projection(std::vector <double> &v1, std::vector <double> v2) {
    
    double dotProd = 0;
    
    //dot product the two vectors
    for (unsigned i = 0; i < v1.size(); ++i) {
        dotProd += (v1[i] * v2[i]);
    }
    
    dotProd /= std::pow(findMagnitude(v2),2);
    
    //multiply this by v2 to get projection
    
    for (auto &val : v2) {
        val *= dotProd;
    }
    return v2;
}

//returns the discrepancy betwen the pixel matrices from projecting the vectors
//of query onto the corresponding vectors in this sign
double Sign::getError(Sign &span_sign) {
    
    // Get the projections
    std::vector<double> redProj = projection(redPix, span_sign.redPix);
    std::vector<double> greenProj = projection(greenPix, span_sign.greenPix);
    std::vector<double> blueProj = projection(bluePix, span_sign.bluePix);
    
    double mag = mag_of_diff(redProj, span_sign.redPix);
    mag += mag_of_diff(greenProj, span_sign.greenPix);
    mag += mag_of_diff(blueProj, span_sign.bluePix);
    
    // Return the sum of all the channels' projection magnitudes
    return mag;
}


// Returns the magnitude of the difference between two vectors
double Sign::mag_of_diff(std::vector <double> &v1, std::vector <double> &v2){
    
    double mag_diff = 0;
    
    for (unsigned i = 0; i < (unsigned)v1.size(); ++i){
        mag_diff += std::abs(v2[i] - v1[i]);
    }
    
    return std::sqrt(mag_diff);
}
