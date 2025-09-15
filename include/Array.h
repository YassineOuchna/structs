#pragma once
#include "DataStructure.h"
#include <iostream>
#include <cstdlib>

class Array : public DataStructure {
    private:
        size_t capacity;
        size_t size;
        int* array;
        size_t elementSize = sizeof(int);

        void display_array(int* &disp_array, size_t disp_size, const std::vector<size_t>& highlight = {}) {
            const char* blue = "\033[1;34m"; // bright blue
            const char* reset = "\033[0m";

            std::cout << "| ";
            for (size_t index = 0; index < disp_size; index++) {
                bool is_highlighted = false;
                for (size_t i : highlight) {
                    if (i == index) {
                        is_highlighted = true;
                        break;
                    }
                }
                if (is_highlighted) {
                    std::cout << blue << disp_array[index] << reset << " | ";
                } else {
                    std::cout << disp_array[index] << " | ";
                }
            }
            // Display remaining capacity
            for (size_t index = disp_size; index < capacity; index++) {
                std::cout << ' ' << " | ";
            }
            std::cout << std::endl;
        };
    public:
        ~Array() override {
            free(array);
            array = nullptr;
        };

        Array(size_t initCapacity = 5) : capacity(initCapacity), size(0) {
            array = static_cast<int*>(malloc(capacity * elementSize));
            if (!array) {
                std::cout << "Memory allocation failed for array" << std::endl;
                return;
            }
        };

        void resize() {
            capacity *= 2;
            int* new_array = static_cast<int*>(malloc(capacity * elementSize));

            for (size_t index = 0; index < size; index++) {
                new_array[index] = array[index];
            }

            free(array);
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
            dest = (int*) malloc(capacity * sizeof(int));

            for (size_t index = 0; index < size; index++) {
                dest[index] = array[index];
            }

        }

        void display() override {
            Array::display_array(array, size);
        };

        void sort() override {
            int* dummy_copy = nullptr;
            copy(dummy_copy);
            sort_stupid(dummy_copy);
            bubble_sort(dummy_copy);
        }

        void bubble_sort(int* buf) {

            std::cout << "----------------------- Bubble Sort -----------------------" << std::endl;
            std::cout << "n rounds each of them a misplaced int is swaped with its neighbor" << std::endl;
            for (size_t r = 0; r < size; r++) {
                for (size_t index = 0; index < size-1; index++) {
                    if (buf[index] > buf[index+1]) {
                        std::vector<size_t> highlighted = {index, index+1};
                        Array::display_array(buf, size, highlighted);
                        std::swap(buf[index], buf[index+1]);
                    }
                }
            }
            std::cout << "Final result" << std::endl;
            Array::display_array(buf, size);
        }

        void sort_stupid(int* buf) {

            std::cout << "----------------------- Stupid Sort -----------------------" << std::endl;
            std::cout << "Constructs an always sorted array and correctly places each element" << std::endl;
            int* sorted_buff = static_cast<int*>(malloc(capacity * sizeof(int)));
            sorted_buff[0] = buf[0];
            Array::display_array(sorted_buff, 1);

            // O(n**2) algorithm
            for (size_t index = 1; index < size; index++) {
                std::cout << "placing " << buf[index] << std::endl;
                sorted_buff[index] = buf[index];
                std::vector<size_t> highlighted = {index};
                Array::display_array(sorted_buff, index+1, highlighted);
                size_t spot = index;
                while (sorted_buff[spot] < sorted_buff[spot-1]) {
                    int m = sorted_buff[spot];
                    sorted_buff[spot] = sorted_buff[spot-1];
                    sorted_buff[spot-1] = m;
                    std::vector<size_t> highlighted = {spot-1};
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