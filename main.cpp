//
// Created by devik on 11/27/2023.
//
#include <iostream>
#include <bits/stdc++.h>
#include "HashMap.h"
#include "n-ary.h"
using namespace std;


int main()
{
    //In main, read in the dataset, store values in the structures

    //first read into hashmap
    //HashMap hm;
    /*while(hm.size() < 100000)
    {
        //read in name, price, rating from file
        //insert
    }

    //next read into tree*/

    Tree tree;
    for (int i = 0; i < 100000; ++i) {

        string s = "ABC" + to_string('a' + i - 97);
        //cout << s.find("AB") << endl;
        tree.insert(&s, i % 3);

    }
    //cout << endl;
    tree.print();
    //tree.root -> between(10, 90);
    string s = "ABC9";
}