#include <cstdlib>
#include <vector>
#include <iostream>
#include "include/ImagePGM.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage : " << argv[0] << "<input-cipher-image-path> <input-image-key-path>" << endl;
        return 1;
    }

    string inputPath = argv[1];
    string keyPath = argv[2];

    ImagePGM img;
    img.read(inputPath.data());
    img.vernamDecrypt(keyPath.data());

    for (size_t y = 0; y < img.height(); y++) {
        for (size_t x = 0; x < img.width(); x++) {
            std::cout << static_cast<char>(img[y][x]);
        }
    }

    std::cout << std::endl;
}