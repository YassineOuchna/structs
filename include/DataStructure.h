#pragma once
#include <vector>

class DataStructure {
    public:
        virtual ~DataStructure() = default;
        virtual void build(const std::vector<int> &values) = 0;
        virtual void display() = 0;
        virtual void sort() = 0;
};
