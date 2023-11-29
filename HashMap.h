//
// Created by devik on 11/27/2023.
//
#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int TABLESIZE = 150000;

class HashMap{

private:
    int hashFunction(string k);
    int numNodes;

public:
    struct HashNode{
        string key;
        pair<float, float> value;
        HashNode(string k, pair<float, float> v){
            key = k;
            value = v;
        }
    };
    HashNode** table; //pointer to pointer; pointer to array of hashnode pointers

    HashMap();
    void insert(string name, string price, string rating);
    pair<float, float> searchName(string name);
    vector<HashNode> searchKeyword(string keyword);
    vector<HashNode> searchKeywordPriceRating(string keyword, float priceOrating, string por);
    ~HashMap();
    int size();
    float loadFactor();
};

