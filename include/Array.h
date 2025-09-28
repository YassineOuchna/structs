#pragma once
#include "DataStructure.h"
#include <unordered_set>
#include <cstdlib>
#include <vector>

class Array : public DataStructure {
private:
    size_t capacity;
    size_t size;
    int* array;
    size_t elementSize = sizeof(int);

    void display_array(int*& disp_array, size_t disp_size, const std::unordered_set<size_t>& highlight);
    void display_array(int*& disp_array, size_t disp_size, size_t cap = 0, const std::unordered_set<size_t>& highlight = {});

public:
    ~Array() override;
    Array(size_t initCapacity = 5);

    void resize();
    void append(int x);
    void build(const std::vector<int>& values) override;
    void copy(int*& dest);
    void display() override;
    void sort() override;

    void bubble_sort(int* buf);
    int* merge_sort(int* buf, size_t l, size_t r);
    void insertion_sort(const int* buf);
};
