#include <vector>  // for lists
#include <sstream>
#include <fstream>  // opening input file
#include <iostream> // console output

int readInput(std::vector<int>& list1, std::vector<int>& list2) {
    std::ifstream file("input.txt");
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

int main() {
    std::vector<int> list1, list2;
    readInput(list1, list2);
    return 0;
}
