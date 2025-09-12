#include "utils.h"

namespace utils {

    std::vector<int> parseInputValues(std::string& line) {
        std::vector<int> values = {};
        std::string num;

        for (char c : line) {
            if (c == ' ') {
                if (!num.empty()) {
                    values.push_back(std::stoi(num));
                    num = "";
                    continue;
                }
            }
            num += c;
        }
        if (!num.empty()) {
            values.push_back(std::stoi(num));
        }
        return values;
    }
}


