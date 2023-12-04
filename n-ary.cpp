//
// Created by devik on 12/3/2023.
//
#include <vector>
#include <string>
#include <queue>
#include <ctime>
#include <iostream>
#include "n-ary.h"

using namespace std;
Node::Node(string nam, double val, double val2) {
    name = nam;
    value = val;
    value2 = val2;
}

void Node::insert(string& nam, double val, double val2) {
    if (val < value) {
        if (less.size() == n) {
            if (val <= less[0]->value) {
                less[0]->insert(nam, val, val2);
                return;
            }
            if (val >= less[n - 1]->value) {
                less[n - 1]->insert(nam, val, val2);
                return;
            }
            for (int i = n - 2; i >= 0; --i) {
                if (val >= less[i]->value) {
                    srand(time(nullptr));
                    if (rand() % 2 == 0) {
                        less[i]->insert(nam, val, val2);
                        return;
                    }
                    else {
                        less[i + 1]->insert(nam, val, val2);
                        return;
                    }
                }
            }
        }
        else {
            less.push_back(new Node(nam, val, val2));
            less = sort(less);
        }
    }
    else {
        if (more.size() == n) {
            if (val <= more[0]->value) {
                more[0]->insert(nam, val, val2);
                return;
            }
            if (val >= more[n - 1]->value) {
                more[n - 1]->insert(nam, val, val2);
                return;
            }
            for (int i = n - 2; i >= 0; --i) {
                if (val >= more[i]->value) {
                    srand(time(nullptr));
                    if (rand() % 2 == 0) {
                        more[i]->insert(nam, val, val2);
                        return;
                    }
                    else {
                        more[i + 1]->insert(nam, val, val2);
                        return;
                    }
                }
            }
        }
        else {
            more.push_back(new Node(nam, val, val2));
            more = sort(more);
        }
    }
}

vector<Node*> Node::sort(vector<Node*> children) {
    for (int i = 0; i < children.size(); ++i) {
        for (int j = i + 1; j < children.size(); ++j) {
            if (children[j]->value < children[i]->value) {
                swap(children[i], children[j]);
            }
        }
    }
    return children;
}

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(string& nam, double val, double val2) {
    if (root == nullptr) {
        root = new Node(nam, val, val2);
        return;
    }

    root->insert(nam, val, val2);
}

void Tree::print() {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        cout << node->name << " " << node->value << " " << node->value2 << endl;

        for (int i = 0; i < node->less.size(); ++i) {
            q.push(node->less[i]);
        }

        for (int i = 0; i < node->more.size(); ++i) {
            q.push(node->more[i]);
        }

        q.pop();
    }
}
// true is 5 smallest (price), false is 5 largest (rating)
vector<Node*> Tree::find(string& nam, bool sort) {
    vector<Node*> v;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();

        if (node->name == nam) {
            v.push_back(node);
        }
        for (int i = 0; i < node->less.size(); ++i) {
            q.push(node->less[i]);
        }

        for (int i = 0; i < node->more.size(); ++i) {
            q.push(node->more[i]);
        }

        q.pop();
    }

    vector<Node*> ret;
    if (sort) {
        for (int i = 0; i < v.size() && i < 5; ++i) {
            double min = 1000000;
            int minIndex = -1;
            for (int j = i; j < v.size(); ++j) {
                if (v[j]->value < min) {
                    min = v[j]->value;
                    minIndex = j;
                }
            }

            ret.push_back(v[minIndex]);
            v[minIndex] = v[i];
        }
    }
    else {
        for (int i = 0; i < v.size() && i < 5; ++i) {
            double min = -1;
            int minIndex = -1;
            for (int j = i; j < v.size(); ++j) {
                if (v[j]->value > min) {
                    min = v[j]->value;
                    minIndex = j;
                }
            }

            ret.push_back(v[minIndex]);
            v[minIndex] = v[i];
        }
    }

    return ret;
}



vector<Node*> Tree::findKey(string& nam, bool sort) {
    vector<Node*> v;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();

        if ((node->name).find(nam) != string::npos) {
            v.push_back(node);
        }
        for (int i = 0; i < node->less.size(); ++i) {
            q.push(node->less[i]);
        }

        for (int i = 0; i < node->more.size(); ++i) {
            q.push(node->more[i]);
        }

        q.pop();
    }

    vector<Node*> ret;
    if (sort) {
        for (int i = 0; i < v.size() && i < 5; ++i) {
            double min = 1000000;
            int minIndex = -1;
            for (int j = i; j < v.size(); ++j) {
                if (v[j]->value < min) {
                    min = v[j]->value;
                    minIndex = j;
                }
            }

            ret.push_back(v[minIndex]);
            v[minIndex] = v[i];
        }
    }
    else {
        for (int i = 0; i < v.size() && i < 5; ++i) {
            double min = -1;
            int minIndex = -1;
            for (int j = i; j < v.size(); ++j) {
                if (v[j]->value > min) {
                    min = v[j]->value;
                    minIndex = j;
                }
            }

            ret.push_back(v[minIndex]);
            v[minIndex] = v[i];
        }
    }
    return ret;
}



