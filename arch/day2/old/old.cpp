#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>


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

        std::vector<int> range(lines.size());
        std::iota(range.begin(), range.end(), 0);

        // print the lines readed 
        for (const std::string& ln: lines) {
            std::cout << ln << std::endl;
            // char fc = ln[0];
            // std::cout << fc << std::endl;
        }

        // for (char c: fcs) {
        //     std::cout << c << std::endl;
        // } 

        // for (char c: lcs) {
        //     std::cout << c << std::endl;
        // } 

        std::vector<int> results;
        for (int i: range) {
            int match = 0; 
            int bonus = 0;
            int res = 0;
            std::cout << fcs[i] << lcs[i] << std::endl; 
            if (fcs[i] == 'A' && lcs[i] == 'Z') {
                match = 0; // lost rock > scissor
                bonus = 3;
                res = match + bonus;
                results.push_back(res);
            } else if (fcs[i] == 'A' && lcs[i] == 'Y') {
                match = 6; // win rock < paper
                bonus = 2;
                res = match + bonus;
                results.push_back(res);
            } else if (fcs[i] == 'A' && lcs[i] == 'X') {
                match = 3; // draw rock == rock
                bonus = 1;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'B' && lcs[i] == 'X') {
                match = 0; // lost paper > rock
                bonus = 1;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'B' && lcs[i] == 'Z') {
                match = 6; // win paper < scissor
                bonus = 3;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'B' && lcs[i] == 'Y') {
                match = 3; // draw paper == paper
                bonus = 2;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'C' && lcs[i] == 'Y') {
                match = 0; // lost scissor > paper 
                bonus = 2;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'C' && lcs[i] == 'X') {
                match = 6; // lost scissor < rock 
                bonus = 1;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'C' && lcs[i] == 'Z') {
                match = 3; // lost scissor < rock 
                bonus = 3;
                res = match + bonus;
                results.push_back(res); 
            }
            std::cout << res << std::endl;
            // bool status = fcs[i] == 'A';
            // std::cout << status << std::endl;
        }

        int score = std::accumulate(results.begin(), results.end(), 0);
        std::cout << "Final score: " << score << std::endl;



    } else {
        std::cout << "Failed to open the file." << std::endl;
    }


    return 0;

}