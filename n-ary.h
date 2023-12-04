#pragma once

#include <vector>
#include <string>
#include <queue>
#include <ctime>
#include <iostream>

static int n = 1;

struct Node {
    double value;
    double value2;
    std::vector<Node*> less;
    std::vector<Node*> more;
    std::string name;

    Node(std::string nam, double val, double val2);

    void insert(std::string& nam, double val, double val2);
    std::vector<Node*> sort(std::vector<Node*> children);
};

struct Tree {
    Node* root;

    Tree();

    void insert(std::string& nam, double val, double val2);
    void print();
    std::vector<Node*> find(std::string& nam, bool sort);
    std::vector<Node*> findKey(std::string& nam, bool sort);
};

