#pragma once
#include "DataStructure.h"

struct Node {
    int value;
    Node* next {nullptr};

    Node(int val = 0) : value(val) {};
};

class LinkedList : public DataStructure {
    private:
        Node* head;
        size_t size;

    public:
        ~LinkedList() override {
            std::cout << "Destroying Linked List" << std::endl;
            display_list();
            while (head != nullptr) {
                Node* tmp = head->next;
                delete head;
                head = tmp;
                display_list();
            }

        }

        LinkedList() : head(new Node()) {};
        LinkedList(int val) : head(new Node(val)) {};

        void display_list(const std::unordered_set<Node*>& highlight = {}) {
            const char* blue = "\033[1;34m"; // bright blue
            const char* reset = "\033[0m";

            Node* cur = head;
            while (cur != nullptr) {
                if (highlight.find(cur) != highlight.end()) {
                    std::cout << blue << cur->value << reset << " --> ";
                } else {std::cout << cur->value << " --> ";}
                cur = cur->next;
            }
            std::cout << "NULL" << std::endl;
        }

        void display() override {
            display_list();
        }

        void build(const std::vector<int> &values) override {
            Node* cur = head;
            head->value = values[0];
            size++;
            std::unordered_set<Node*> highlight = {cur};
            display_list(highlight);
            for (size_t i = 1; i<values.size(); i++) {
                Node* new_node = new Node(values[i]);
                cur->next = new_node;
                cur = new_node;
                size++;
                highlight = {cur};
                display_list(highlight);
            }
        };

        void sort() override {

            std::cout << "-------- Bubble Sorting ---------" << std::endl;
            for (size_t _ = 0; _< size; _++) {
                Node* cur = head;
                bool ordered = true;
                while (cur) {
                    std::unordered_set<Node*> highlight {};
                    Node* next = cur->next;
                    highlight.insert(cur);
                    if (next && cur->value > next->value) {
                        highlight.insert(next);
                        display_list(highlight);

                        int tmp = next->value;
                        next->value = cur->value;
                        cur->value = tmp;
                        ordered = false;
                    }
                    cur = next;
                }
                // no more rounds needed
                if (ordered) {break;}
            }

            std::cout << "Sorted!" << std::endl;
            display();

        };

};