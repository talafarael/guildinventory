#include "getFileContent.h"
#include <fstream>
#include <string>

std::string getFileContent(std::string fileName) {
    std::string line;
    std::string fileContents;
    std::ifstream in(fileName);

    if (in.is_open()) {
        while (std::getline(in, line)) {
            fileContents += line;
        }
    }
    return fileContents.empty() ? "" : fileContents;
}