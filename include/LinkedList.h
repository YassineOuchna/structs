#pragma once
#include "DataStructure.h"
#include <cstddef>
#include <unordered_set>
#include <vector>

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
    ~LinkedList() override;
    LinkedList();
    LinkedList(int val);

    void display_list(const std::unordered_set<Node*>& highlight = {});
    void display() override;
    void build(const std::vector<int> &values) override;
    void sort() override;
};
