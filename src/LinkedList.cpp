#include "LinkedList.h"
#include <iostream>

LinkedList::~LinkedList() {
    std::cout << "Destroying Linked List" << std::endl;
    display_list();
    while (head != nullptr) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
        display_list();
    }
}

LinkedList::LinkedList() : head(new Node()), size(0) {}

LinkedList::LinkedList(int val) : head(new Node(val)), size(0) {}

void LinkedList::display_list(const std::unordered_set<Node*>& highlight) {
    const char* blue = "\033[1;34m"; 
    const char* reset = "\033[0m";

    Node* cur = head;
    while (cur != nullptr) {
        if (highlight.find(cur) != highlight.end()) {
            std::cout << blue << cur->value << reset << " --> ";
        } else {
            std::cout << cur->value << " --> ";
        }
        cur = cur->next;
    }
    std::cout << "NULL" << std::endl;
}

void LinkedList::display() {
    display_list();
}

void LinkedList::build(const std::vector<int>& values) {
    Node* cur = head;
    head->value = values[0];
    size++;
    std::unordered_set<Node*> highlight = {cur};
    display_list(highlight);
    for (size_t i = 1; i < values.size(); i++) {
        Node* new_node = new Node(values[i]);
        cur->next = new_node;
        cur = new_node;
        size++;
        highlight = {cur};
        display_list(highlight);
    }
}

void LinkedList::sort() {
    std::cout << "-------- Bubble Sorting ---------" << std::endl;
    for (size_t _ = 0; _ < size; _++) {
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
        if (ordered) { break; }
    }
    std::cout << "Sorted!" << std::endl;
    display();
}
