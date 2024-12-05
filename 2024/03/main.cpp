#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "evaluate.hpp"

using namespace std;

int getInput(string& input) {
    string filename("../03/input.txt");
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open input.txt" << endl; 
        return -1;
    }
    stringstream buf;
    buf << file.rdbuf();
    input = buf.str();

    file.close();
    return 0;
}

vector<string> checkRegex(string input) {
    regex pattern(R"(mul\(\d+,\d+\))");
    smatch match;
    vector<string> found;
    while (regex_search(input, match, pattern)) {
        found.push_back(match.str());
        input = match.suffix(); // iterate
    }
    return found;
}

void printFound(vector<string> found) {
    for(int i = 0; i < found.size(); i++) {
        cout << found[i] << endl;
    }
}

vector<string> sliceFound(vector<string> found) {
    for(int i = 0; i < found.size(); i++) {
        found[i] = found[i].substr(4, found[i].size()-5);
    }
    return found;
}

string foundFormatted(vector<string> found) {
    string result = "";
    for(int i = 0; i < found.size(); i++) {
        size_t pos = found[i].find(",");
        if (pos != string::npos) {
            found[i].replace(pos, 1, " * ");
        }
        if( i != found.size()-1) {
            result += found[i] + " + ";
        }
        else {
            result += found[i];
        }
    }
    return result;
}

int main() {
    string input;
    getInput(input);
    vector<string> found = checkRegex(input);
    // cout << foundFormatted(sliceFound(found)) << endl;
    cout << evaluate(foundFormatted(sliceFound(found))) << endl;
    return 0;
}