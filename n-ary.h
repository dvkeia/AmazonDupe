#include<bits/stdc++.h>
#pragma once
using namespace std;
int n = 5;


struct Node {
    // unique value of the node
    int value;

    // set of chlidren that are smaller/greater than it
    vector<Node *> less;
    vector<Node *> more;

    // name of the object
    string name;

    //creates a node
    Node(string nam, int val) {
        name = nam;
        value = val;
    }

    //inserts a node with name nam and value val
    void insert(string *nam, int val) {
        if (val < value) {
            if (less.size() == n) {
                if (val <= less[0]->value) {
                    less[0]->insert(nam, val);

                    return;
                }
                if (val >= less[n - 1]->value) {
                    less[n - 1]->insert(nam, val);
                    return;
                }
                for (int i = n - 2; i >= 0; --i) {
                    if (val >= less[i]->value) {
                        srand(time(nullptr));
                        if (rand() % 2 == 0) {
                            less[i]->insert(nam, val);
                            return;
                        } else {
                            less[i + 1]->insert(nam, val);
                            return;
                        }

                    }
                }
            } else {

                less.push_back(new Node(*nam, val));
                less = sort(less);

            }
        } else {
            if (more.size() == n) {
                if (val <= more[0]->value) {
                    more[0]->insert(nam, val);
                    return;
                }
                if (val >= more[n - 1]->value) {
                    more[n - 1]->insert(nam, val);
                    return;
                }
                for (int i = n - 2; i >= 0; --i) {
                    if (val >= more[i]->value) {
                        srand(time(nullptr));
                        if (rand() % 2 == 0) {
                            more[i]->insert(nam, val);
                            return;
                        } else {
                            more[i + 1]->insert(nam, val);
                            return;
                        }

                    }
                }
            } else {

                more.push_back(new Node(*nam, val));
                more = sort(more);

            }
        }
    }

    //sorts a vector of children nodes in order of value (uses bubble sort)
    vector<Node *> sort(vector<Node *> children) {
        for (int i = 0; i < children.size(); ++i) {
            for (int j = i + 1; j < children.size(); ++j) {
                if (children[j]->value < children[i]->value) {

                    swap(children[i], children[j]);

                }
            }
        }
        return children;
    }

    // prints all the values below the node that is between min and max
    void between(int min, int max) {
        if (min <= value && value <= max) {
            cout << name << " " << value << endl;
            for (int i = 0; i < less.size(); ++i) {
                less[i]->between(min, max);
            }
            for (int i = 0; i < more.size(); ++i) {
                more[i]->between(min, max);
            }
        } else if (value < min) {
            for (int i = 0; i < more.size(); ++i) {
                more[i]->between(min, max);
            }

        } else {
            for (int i = 0; i < less.size(); ++i) {
                less[i]->between(min, max);
            }

        }

    }

    // // prints all the values below the node that has the name exactly nam
    void find(string nam) {
        if (name == nam) {
            cout << name << " " << value << endl;
        }
        for (int i = 0; i < less.size(); ++i) {
            less[i]->find(nam);
        }
        for (int i = 0; i < more.size(); ++i) {
            more[i]->find(nam);
        }
    }

    // prints all the values below the node that includes the word nam
    void findKey(string nam) {
        if (name.find(nam) != string::npos) {
            cout << name << " " << value << endl;
        }
        for (int i = 0; i < less.size(); ++i) {
            less[i]->findKey(nam);
        }
        for (int i = 0; i < more.size(); ++i) {
            more[i]->findKey(nam);
        }
    }

    // prints all the values below the node that is between min and max and have the name exactly nam
    void findBetween(string nam, int min, int max)
    {
        if (min <= value && value <= max && nam == name) {
            if (name == nam)  {
                cout << name << " " << value << endl;
            }
            for (int i = 0; i < less.size(); ++i) {
                less[i]->findBetween(nam, min, max);
            }
            for (int i = 0; i < more.size(); ++i) {
                more[i]->findBetween(nam, min, max);
            }
        } else if (value < min) {
            for (int i = 0; i < more.size(); ++i) {
                more[i]->findBetween(nam, min, max);
            }

        } else {
            for (int i = 0; i < less.size(); ++i) {
                less[i]->findBetween(nam, min, max);
            }

        }
    }

    // prints all the values below the node that is between min and max and have the word nam in name
    void findKeyBetween(string nam, int min, int max)
    {
        if (min <= value && value <= max ) {
            if (name.find(nam) != string::npos) {
                cout << name << " " << value << endl;
            }
            for (int i = 0; i < less.size(); ++i) {
                less[i]->findKeyBetween(nam, min, max);
            }
            for (int i = 0; i < more.size(); ++i) {
                more[i]->findKeyBetween(nam, min, max);
            }
        } else if (value < min) {
            for (int i = 0; i < more.size(); ++i) {
                more[i]->findKeyBetween(nam, min, max);
            }

        } else {
            for (int i = 0; i < less.size(); ++i) {
                less[i]->findKeyBetween(nam, min, max);
            }

        }
    }
};

struct Tree {

    Tree() {
        root = nullptr;
    }

    // root of the tree
    Node *root;

    // inserts a node with name nam and value val
    void insert(string *nam, int val) {
        if (root == nullptr) {
            root = new Node(*nam, val);
            return;
        }


        root->insert(nam, val);
    }

    // prints all the values of the tree
    void print() {
        queue<Node *> q;

        q.push(root);

        while (!q.empty()) {
            Node *node = q.front();

            cout << node->name << " " << node->value << " less: ";

            for (int i = 0; i < node->less.size(); ++i) {
                cout << node->less[i]->value << " ";
                q.push(node->less[i]);
            }
            cout << "\t more: ";
            for (int i = 0; i < node->more.size(); ++i) {
                cout << node->more[i]->value << " ";
                q.push(node->more[i]);
            }
            cout << endl;
            q.pop();
        }
    }

};