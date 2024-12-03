#include <vector>
#include <fstream> // opening input file
#include <iostream> // console output
#include <string>
#include <sstream>

int getReports(std::vector<std::vector<int>>& reports) {
    std::string filename = "../02/input.txt";
    // cin >> filename;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open input.txt" << std::endl;
        return -1;
    }
    
    std::string line;
    while(std::getline(file, line)) {
        std::vector<int> level;
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            level.push_back(num);
        }
        reports.push_back(level);
    }
    file.close();
    return 0;
}

int checkLevel(std::vector<int>& level, bool byOne = false) {
    enum state {
        NONE,
        INCREASING,
        DECREASING
    };
    state myState = NONE;
    bool removed = false;
    for (int i = 0; i < level.size() - 1; i++) {
        if (i == 0) {
            if(level[0] > level[1]) {
                myState = DECREASING;
            }
            else {
                myState = INCREASING;
            }
        }
        int curNum = level[i];
        int nextNum = level[i+1];
        // This could be better but it gets the job done.
        if (myState == INCREASING) {
            if (!((nextNum - curNum) <= 3 && (nextNum - curNum) >= 1)) {
                if (byOne && !removed) {
                    removed = true;
                    level.erase(level.begin() + i);
                    i = 0;
                }
                else { 
                    return 1;
                }
            }
        }
        else if (myState == DECREASING) {
            if (!((curNum - nextNum) <= 3 && (curNum - nextNum) >= 1)) {
                if (byOne && !removed) {
                    removed = true;
                    level.erase(level.begin() + i);
                    i = 0;
                }
                else {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int checkSafe(std::vector<std::vector<int>>& reports, bool byOne = false) {
    int total = 0;
    for (int i = 0; i < reports.size(); i++) {
        if (checkLevel(reports[i], byOne) == 0) {
            total += 1;
        }
    }
    return total;
}

int main () {
    std::vector<std::vector<int>> reports;
    getReports(reports);
    std::cout << checkSafe(reports) << std::endl;
    std::cout << checkSafe(reports, true) << std::endl;
}