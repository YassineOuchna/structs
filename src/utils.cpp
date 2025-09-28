#include "utils.h"
#include <sstream>
#include <random>
#include <ctime>

namespace utils {

    std::vector<int> generateRandomInstance(size_t s) {
        std::vector<int> values = {};

        if (values.size() == 0) {
            std::srand(std::time(nullptr));
            for (size_t index = 0; index < s; index++) {
                int val = std::rand() % 121;
                values.push_back(val);
            }
        }

        return values;
    }
}


