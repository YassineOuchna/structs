#include "utils.h"
#include <sstream>
#include <random>
#include <ctime>

namespace utils {

    std::vector<int> parseInputValues(std::string& line) {
        std::vector<int> values = {};
        std::istringstream iss(line);

        int val;
        while (iss >> val) {
            values.push_back(val);
        }

        // no integers specified, generate random numbers
        if (values.size() == 0) {
            std::srand(std::time(nullptr));
            size_t s = 9;
            for (size_t index = 0; index < s; index++) {
                int val = std::rand() % 21;
                values.push_back(val);
            }
        }

        return values;
    }
}


