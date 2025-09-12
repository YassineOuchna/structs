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
            }
        };

        void display() override {
            for (size_t index = 0; index < size; index++) {
                std::cout << buffer[index] << " | ";
            }
            std::cout << std::endl;
        };
};