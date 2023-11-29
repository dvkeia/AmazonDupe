//
// Created by devik on 11/27/2023.
//
#include <iostream>
#include <bits/stdc++.h>
#include "HashMap.h"
using namespace std;


int main()
{
    HashMap hm;
    hm.insert("book", "15", "4.2");
    hm.insert("shirt", "20", "1.34");
    hm.insert("tshirt", "25", "2.4");
    cout << hm.searchName("book").first << " " << hm.searchName("tshirt").second << endl;
    vector<HashMap::HashNode> v;
    v = hm.searchKeyword("shirt");
    for(int i = 0; i < v.size(); i++)
    {
        HashMap::HashNode h = v[i];
        cout << "Product: " << h.key << " and " << "Price: " << h.value.first << " Rating: " << h.value.second << endl;
    }

    vector<HashMap::HashNode> vp;
    vp = hm.searchKeywordPriceRating("shirt", 21, "price");
    for(int i = 0; i < vp.size(); i++)
    {
        HashMap::HashNode h = vp[i];
        cout << "Product: " << h.key << " and " << "Price: " << h.value.first << " Rating: " << h.value.second << endl;
    }

    vector<HashMap::HashNode> vr;
    vr = hm.searchKeywordPriceRating("shirt", 2, "rating");
    for(int i = 0; i < vr.size(); i++)
    {
        HashMap::HashNode h = vr[i];
        cout << "Product: " << h.key << " and " << "Price: " << h.value.first << " Rating: " << h.value.second << endl;
    }
}