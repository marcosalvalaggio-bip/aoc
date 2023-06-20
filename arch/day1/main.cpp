#include <iostream>
#include <numeric>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt"); // Replace "input.txt" with the path to your file

    if (inputFile.is_open()) {
        
        std::vector<int> results;
        std::vector<std::string> lines;
        std::string line;
        int sum = 0;

        while (std::getline(inputFile, line)) {
            lines.push_back(line);
        }

        inputFile.close();

        // Print the lines
        for (const std::string& ln : lines) {
            if (!ln.empty()) {
                try {
                    int number = std::stoi(ln);
                    sum += number;
                } catch (const std::exception& e){
                    std::cout << "lezzo" << std::endl; 
                }
            } else {
                results.push_back(sum);
                sum = 0;
            }
        }
        results.push_back(sum);

        auto max = std::max_element(results.begin(), results.end());

        // for (int number: results) {
        //     std::cout << number << std::endl;
        // }

        std::cout << "\n" << std::endl;
        std::cout << "max: " << *max << std::endl;

        // Sort the vector in descending order
        std::sort(results.begin(), results.end(), std::greater<int>());
        
        // for (int number: results) {
        //     std::cout << number << std::endl;
        // }

        std::vector<int> res(results.begin(), results.begin()+3);

        for (int number: res) {
            std::cout << number << std::endl;
        }

        int res_acc = std::accumulate(res.begin(), res.end(), 0);
        std::cout << "acc: " << res_acc << std::endl;

    } else {
        std::cout << "Failed to open the file." << std::endl;
    }

    return 0;
}
