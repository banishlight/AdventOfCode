#include <regex>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int getInput(string& input) {
    string filename("../03/input.txt");
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open input.txt" << endl; 
        return -1;
    }
    file >> input;
    file.close();
    return 0;
}

string checkRegex(string input) {
    regex pattern(R"(mul\(\d+,\d+\))");


}

int main() {
    string input;
    getInput(input);


    return 0;
}