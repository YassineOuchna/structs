#pragma once
#include "DataStructure.h"
#include <iostream>
#include <unordered_set>
#include <iomanip>
#include <cstdlib>


class Array : public DataStructure {
    private:
        size_t capacity;
        size_t size;
        int* array;
        size_t elementSize = sizeof(int);

        void display_array(int* &disp_array, size_t disp_size, const std::unordered_set<size_t>& highlight) {
            display_array(disp_array, disp_size, 0, highlight);
        }

        void display_array(int* &disp_array, size_t disp_size, size_t cap = 0, const std::unordered_set<size_t>& highlight = {}) {
            if (cap == 0) cap = capacity;
            const char* blue = "\033[1;34m"; // bright blue
            const char* reset = "\033[0m";
            size_t width = 4;

            std::cout << "|";
            for (size_t index = 0; index < disp_size; index++) {
                if (highlight.find(index) != highlight.end()) {
                    std::cout << blue << std::setw(width) << disp_array[index] << reset << " |";
                } else {
                    std::cout << std::setw(width) << disp_array[index] << " |";
                }
            }
            // Display remaining capacity
            for (size_t index = disp_size; index < cap; index++) {
                std::cout << std::setw(width) << ' ' << " |";
            }
            std::cout << std::endl;
        };
    public:
        ~Array() override {
            delete[] array;
            array = nullptr;
        };

        Array(size_t initCapacity = 5) : capacity(initCapacity), size(0) {
            array = new int[capacity];
            if (!array) {
                std::cout << "Memory allocation failed for array" << std::endl;
                return;
            }
        };

        void resize() {
            capacity *= 2;
            int* new_array  = new int[capacity];
            std::copy(array, array + capacity, new_array);
            delete[] array;
            array = new_array;
        }

        void append(int x) {
            if (capacity == size) {
                Array::resize();
            }

            array[size] = x;
            size++;
        };

        void build(const std::vector<int> &values) override {
            for (int val : values) {
                Array::append(val);
                Array::display();
            }
        };

        void copy(int* &dest) {
            // Copies the array elements onto dest
            for (size_t index = 0; index < size; index++) {
                dest[index] = array[index];
            }
        }

        void display() override {
            Array::display_array(array, size);
        };

        void sort() override {
            int* dummy_copy = new int[capacity];
            copy(dummy_copy);
            insertion_sort(dummy_copy);
            bubble_sort(dummy_copy);
            std::cout << "----------------------- Merge sort -----------------------" << std::endl;
            copy(dummy_copy);
            dummy_copy = merge_sort(dummy_copy, 0, size-1);
            delete[] dummy_copy;
        }

        void bubble_sort(int* buf) {

            std::cout << "----------------------- Bubble Sort -----------------------" << std::endl;
            std::cout << "n rounds each of them a misplaced int is swaped with its neighbor" << std::endl;
            Array::display_array(buf, size);
            for (size_t r = 0; r < size; r++) {
                for (size_t index = 0; index < size-1; index++) {
                    if (buf[index] > buf[index+1]) {
                        std::unordered_set<size_t> highlighted = {index, index+1};
                        Array::display_array(buf, size, highlighted);
                        std::swap(buf[index], buf[index+1]);
                    }
                }
            }
            std::cout << "Final result" << std::endl;
            Array::display_array(buf, size);
        }

        int* merge_sort(int* buf, size_t l, size_t r) {
            int* sorted = new int[r-l+1];
            if (l==r) {
                sorted[0] = buf[l];
                return sorted;
            }
            size_t middle = (l+r) / 2;
            int* left = merge_sort(buf, l, middle);
            int* right = merge_sort(buf, middle+1, r);

            size_t cout_width = 7;
            std::cout  << std::setw(cout_width) << "Left:";
            display_array(left, middle-l+1, middle-l+1);
            std::cout  << std::setw(cout_width) <<"Right:";
            display_array(right, r-middle, r-middle);

            size_t li = 0;
            size_t ri = 0;
            size_t i = 0;
            while (i <= (r-l)) {
                // right array exhausted
                if (ri >= r-middle) {
                    sorted[i] = left[li];
                    li++;
                } else if (li >= middle-l+1) {
                    sorted[i] = right[ri];
                    ri++;
                } else {
                    if (left[li] < right[ri]) {
                        sorted[i] = left[li];
                        li++;
                    } else {
                        sorted[i] = right[ri];
                        ri++;
                    }
                }
                i++;
            }
            delete[] right;
            delete[] left;
            std::cout  << std::setw(cout_width) << "Merged:";
            if (r-l+1 == size) {
                display_array(sorted, size);
            } else display_array(sorted, r-l+1, r-l+1);
            return sorted;
        }

        void insertion_sort(const int* buf) {

            std::cout << "----------------------- Insertion Sort -----------------------" << std::endl;
            std::cout << "Constructs an always sorted array and correctly places each element" << std::endl;
            int* sorted_buff = new int[capacity];
            sorted_buff[0] = buf[0];
            Array::display_array(sorted_buff, 1);

            // O(n**2) algorithm
            for (size_t index = 1; index < size; index++) {
                std::cout << "placing " << buf[index] << std::endl;
                sorted_buff[index] = buf[index];
                std::unordered_set<size_t> highlighted = {index};
                Array::display_array(sorted_buff, index+1, highlighted);
                size_t spot = index;
                while (sorted_buff[spot] < sorted_buff[spot-1]) {
                    int m = sorted_buff[spot];
                    sorted_buff[spot] = sorted_buff[spot-1];
                    sorted_buff[spot-1] = m;
                    std::unordered_set<size_t> highlighted = {spot-1};
                    Array::display_array(sorted_buff, index+1, highlighted);
                    if (spot == 1) {
                        break;
                    }
                    spot--;
                }
                std::cout << "--------------------------------" << std::endl;
            }
        };

};