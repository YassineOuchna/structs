#pragma once
#include "DataStructure.h"
#include <iostream>
#include <cstdlib>

class Array : public DataStructure {
    private:
        size_t capacity;
        size_t size;
        int* buffer;
        size_t elementSize = sizeof(int);

        void display_buffer(int* &disp_buffer, size_t disp_size, size_t capacity) {
            std::cout << "| ";
            for (size_t index = 0; index < capacity; index++) {
                if (index < disp_size) {
                    std::cout << disp_buffer[index] << " | ";
                } else {
                    std::cout << ' ' << " | ";
                }
            }
            std::cout << std::endl;
        };
    public:
        ~Array() override {
            free(buffer);
            buffer = nullptr;
        };

        Array(size_t initCapacity = 5) : capacity(initCapacity), size(0) {
            buffer = static_cast<int*>(malloc(capacity * elementSize));
            if (!buffer) {
                std::cout << "Memory allocation failed for array" << std::endl;
                return;
            }
        };

        void resize() {
            capacity *= 2;
            int* new_buffer = static_cast<int*>(malloc(capacity * elementSize));

            for (size_t index = 0; index < size; index++) {
                new_buffer[index] = buffer[index];
            }

            free(buffer);
            buffer = new_buffer;
        }

        void append(int x) {
            if (capacity == size) {
                Array::resize();
            }

            buffer[size] = x;
            size++;
        };

        void build(const std::vector<int> &values) override {
            for (int val : values) {
                Array::append(val);
                Array::display();
            }
        };

        void sort() override {
            int* sorted_buff = static_cast<int*>(malloc(capacity));
            sorted_buff[0] = buffer[0];
            std::cout << "Initializing sorted array" << std::endl;
            Array::display_buffer(sorted_buff, 1, capacity);
            for (size_t index = 1; index < size; index++) {
                std::cout << "placing " << buffer[index] << std::endl;
                sorted_buff[index] = buffer[index];
                Array::display_buffer(sorted_buff, index+1, capacity);
                size_t spot = index;
                while (sorted_buff[spot] < sorted_buff[spot-1]) {
                    int m = sorted_buff[spot];
                    sorted_buff[spot] = sorted_buff[spot-1];
                    sorted_buff[spot-1] = m;
                    Array::display_buffer(sorted_buff, index+1, capacity);
                    if (spot == 0) {
                        break;
                    }
                    spot--;
                }
                std::cout << "--------------------------------" << std::endl;
            }
            free(buffer);
            buffer = sorted_buff;
        };

        void display() override {
            Array::display_buffer(buffer, size, capacity);
        };

};