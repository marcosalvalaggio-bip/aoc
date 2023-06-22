#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main() {

    // open the input.txt or simple.txt
    std::ifstream inputFile("simple.txt");

    if (inputFile.is_open()) {
        std::vector<std::string> lines;
        std::vector<char> fcs;
        std::vector<char> lcs;
        std::string line;
        
        while (std::getline(inputFile, line)) {
            lines.push_back(line);
            char fc = line[0];
            char lc = line[2];
            fcs.push_back(fc);
            lcs.push_back(lc);
        }

        inputFile.close();

        // print the lines readed 
        for (const std::string& ln: lines) {
            std::cout << ln << std::endl;
            // char fc = ln[0];
            // std::cout << fc << std::endl;
        }
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }


    return 0;

}