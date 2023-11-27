//
// Created by devik on 11/27/2023.
//
#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int TABLESIZE = 100000;

class HashMap{

private:
    struct HashNode{
        string key;
        pair<string, string> value;
        HashNode(string k, pair<string, string> v){
            key = k;
            value = v;
        }
    };
    HashNode** table; //pointer to pointer; pointer to array of hashnode pointers

    int hashFunction(string k);

public:
    HashMap();
    void insert(string name, string price, string rating);
    pair<string, string> searchName(string name);
    ~HashMap();
};

