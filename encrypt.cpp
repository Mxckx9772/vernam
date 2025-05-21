#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
#include "include/ImagePGM.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage : " << argv[0] << "<input-string> <output-cipher-image-path> <output-image-key-path>" << endl;
        return 1;
    }

    string inputString = argv[1];
    string outputPath = argv[2];
    string keyPath = argv[3];

    size_t width = ceil(sqrt(inputString.length()));
    size_t height = width;

    vector<octet> imgData(width * height);

    for (size_t i = 0; i < imgData.size(); i++) {
        imgData[i] = inputString[i];
    }

    ImagePGM img(width, height, imgData.data());
    img.vernamEncrypt(keyPath.data());
    img.write(outputPath.data(), "Encrypted Image By Mosaic Team");
}