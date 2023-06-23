#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>


int strategy_score(const std::string& file_name, bool verbose) {
    // open the input.txt or simple.txt
    std::ifstream inputFile(file_name);

    if (inputFile.is_open()) {
            std::vector<std::string> lines; // file lines
            std::vector<char> fcs; // opponent strategy
            std::vector<char> lcs; // your strategy
            std::string line; // single line readed

        // read lines from the input file
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

        std::vector<int> results;

        for (int i: range) {
            int match = 0; 
            int bonus = 0;
            int res = 0;
            if (verbose == true) {
                std::cout << fcs[i] << lcs[i] << std::endl; 
            }
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
                match = 3; // draw scissor == scissor
                bonus = 3;
                res = match + bonus;
                results.push_back(res); 
            }
            if (verbose == true) {
                std::cout << res << std::endl;
            }
        }

        int score = std::accumulate(results.begin(), results.end(), 0);
        return score;

    } else {
        return 0;
    }
}

// part 2
int real_strategy(const std::string& file_name, bool verbose) {
    
    std::ifstream inputFile(file_name);

    if (inputFile.is_open()) {
            std::vector<std::string> lines; // file lines
            std::vector<char> fcs; // opponent strategy
            std::vector<char> lcs; // your strategy
            std::string line; // single line readed

        // read lines from the input file
        while (std::getline(inputFile, line)) {
            lines.push_back(line);
            char fc = line[0];
            char lc = line[2];
            fcs.push_back(fc);
            lcs.push_back(lc);
        }

        std::vector<int> range(lines.size());
        std::iota(range.begin(), range.end(), 0);

        std::vector<int> results;

        for (int i: range) {
            int match = 0; 
            int bonus = 0;
            int res = 0;
            if (verbose == true) {
                std::cout << fcs[i] << lcs[i] << std::endl; 
            }
            if (fcs[i] == 'A' && lcs[i] == 'X') {
                match = 0; // lost rock > scissor
                bonus = 3; // bonus scissor
                res = match + bonus;
                results.push_back(res);
            } else if (fcs[i] == 'A' && lcs[i] == 'Y') {
                match = 3; // draw rock == rock 
                bonus = 1; // bonus rock
                res = match + bonus;
                results.push_back(res);
            } else if (fcs[i] == 'A' && lcs[i] == 'Z') {
                match = 6; // win rock < paper
                bonus = 2; // bonsu paper
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'B' && lcs[i] == 'X') {
                match = 0; // lost paper > rock
                bonus = 1; // bonus rock
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'B' && lcs[i] == 'Y') {
                match = 3; // draw paper == paper
                bonus = 2; // bonus paper
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'B' && lcs[i] == 'Z') {
                match = 6; // draw paper < scissor
                bonus = 3; // bonus scissor
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'C' && lcs[i] == 'X') {
                match = 0; // lost scissor > paper 
                bonus = 2; // bonus paper
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'C' && lcs[i] == 'Y') {
                match = 3; // lost scissor == scissor
                bonus = 3;
                res = match + bonus;
                results.push_back(res); 
            } else if (fcs[i] == 'C' && lcs[i] == 'Z') {
                match = 6; // lost scissor < rock 
                bonus = 1; // bonus rock
                res = match + bonus;
                results.push_back(res); 
            }
            if (verbose == true) {
                std::cout << res << std::endl;
            }
        }

        int score = std::accumulate(results.begin(), results.end(), 0);
        return score;

    } else {
        return 0;
    }
} 


int main() {

    int score;

    // part 1
    score = strategy_score("input.txt", false);
    std::cout << score << std::endl;

    // part 2
    int real_score;
    real_score = real_strategy("input.txt", false);
    std::cout << real_score << std::endl;

    return 0;

}