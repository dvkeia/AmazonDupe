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
    HashMap hm;
    hm.insert("book1", "15", "3.2");
    hm.insert("book2", "16", "3.3");
    hm.insert("book3", "17", "3.4");
    hm.insert("book4", "18", "3.5");
    hm.insert("book5", "19", "3.6");
    hm.insert("book6", "20", "3.7");
    hm.insert("book7", "14", "3.1");
    hm.insert("book8", "13", "2.6");
    hm.insert("book9", "12", "3");
    hm.insert("book10", "11", "2.8");

    vector<HashMap::HashNode> v1 = hm.searchKeywordPriceRating("book", 45, "price");
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i].key << " " << v1[i].value.first << endl;
    }
    cout << "\n";
    vector<HashMap::HashNode> v2 = hm.searchKeywordPriceRating("book", 1.0, "rating");
    for(int i = 0; i < v2.size(); i++)
    {
        cout << v2[i].key << " " << v2[i].value.second << endl;
    }
     //read into tree
}