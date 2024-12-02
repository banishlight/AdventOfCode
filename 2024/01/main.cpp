#include <vector>  // for lists
#include <sstream>
#include <fstream>  // opening input file
#include <iostream> // console output
#include <algorithm> // stable sort
#include <string>

int readInput(std::vector<int>& list1, std::vector<int>& list2) {
    std::string filename = "input.txt";
    // cin >> filename;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open input.txt" << std::endl;
    }

    int num1, num2;
    while (file >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
    }
    file.close();
    return 0;
}

int getDiff(std::vector<int>& list1, std::vector<int>& list2) {
    int total = 0;
    // ensure both lists are the same size
    if (list1.size() != list2.size()) {
        return -1;
    }
    for (int i = 0; i < list1.size(); i++) {
        total += std::abs(list1[i] - list2[i]); 
    }
    return total;
}

int getSimilarity(std::vector<int>& list1, std::vector<int>& list2) {
    int total = 0;
    for (int a = 0; a < list1.size(); a++) {
        int score = 0;
        for (int b = 0; b < list2.size(); b++) {
            if (list1[a] == list2[b]) {
                score += 1;
            }
        }
        total += list1[a] * score;
    }
    return total;
}

int main() {
    std::vector<int> list1, list2;
    readInput(list1, list2);
    stable_sort(list1.begin(), list1.end());
    stable_sort(list2.begin(), list2.end());
    std::cout << getDiff(list1, list2) << std::endl;
    std::cout << getSimilarity(list1, list2) << std::endl;
    return 0;
}
