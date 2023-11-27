//
// Created by devik on 11/27/2023.
//

#include "HashMap.h"

HashMap::HashMap() {
    table = new HashNode * [TABLESIZE];
    for(int i = 0; i < TABLESIZE; i++)
    {
        table[i] = nullptr;
    }
}

int HashMap::hashFunction(std::string k) {
    return std::hash<string>{}(k) % TABLESIZE;
}

void HashMap::insert(std::string name, std::string price, std::string rating) {
    int hash = hashFunction(name);
    while(table[hash] != nullptr && table[hash]->key != name)
    {
        hash += 1;
        if(hash > TABLESIZE)
        {
            return; //just don't add it at that point??
        }
    }

    if(table[hash] != nullptr)
    {
        delete table[hash];
    }

    pair<string, string> p = make_pair(price, rating);
    table[hash] = new HashNode(name, p);
}

pair<string, string> HashMap::searchName(std::string name) {
    int hash = hashFunction(name);
    while(table[hash] != nullptr && table[hash]->key != name)
    {
        hash += 1; //to get to the hash key we used when adding it to table
        if(hash > TABLESIZE)
        {
            pair<string, string> p = make_pair("null", "null");
            return p; //bc clearly object does not exist in map
        }
    }

    if(table[hash] == nullptr)
    {
        pair<string, string> p = make_pair("null", "null");
        return p; //bc clearly object does not exist in map
    }
    else
    {
        return table[hash]->value;
    }
}

HashMap::~HashMap() {
    for(int i = 0; i < TABLESIZE; i++)
    {
        if(table[i] != nullptr)
        {
            delete table[i];
        }
    }
    delete[] table;
}