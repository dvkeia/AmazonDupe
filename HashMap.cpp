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
    numNodes = 0;
}

int HashMap::hashFunction(std::string k) {
    return std::hash<string>{}(k) % TABLESIZE;
}

void HashMap::insert(std::string name, std::string price, std::string rating) {
    int hash = hashFunction(name);
    while(table[hash] != nullptr && table[hash]->key != name)
    {
        hash += 1; //linear probing in case of collision
        if(hash > TABLESIZE)
        {
            return;
        }
    }

    if(table[hash] != nullptr)
    {
        delete table[hash];
    }

    pair<float, float> p = make_pair(stof(price), stof(rating));
    table[hash] = new HashNode(name, p);
    numNodes++;
}

pair<float, float> HashMap::searchName(std::string name) {
    int hash = hashFunction(name);
    while(table[hash] != nullptr && table[hash]->key != name)
    {
        hash += 1; //to get to the hash key we used when adding it to table
        if(hash > TABLESIZE)
        {
            pair<float, float> p = make_pair(-1, -1);
            return p; //bc clearly object does not exist in map
        }
    }

    if(table[hash] == nullptr)
    {
        pair<float, float> p = make_pair(-1, -1);
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

int HashMap::size() {
    return numNodes;
}

float HashMap::loadFactor() {
    return numNodes/TABLESIZE;
}

vector<HashMap::HashNode> HashMap::searchKeyword(string keyword) {
    vector<HashMap::HashNode> ans;
    for(int i = 0; i < TABLESIZE; i++)
    {
        if(table[i] != nullptr)
        {
            string product = table[i]->key;
            if (product.find(keyword) != string::npos) {
                ans.push_back(*(table[i]));
            }
        }
    }
    return ans;
}

vector<HashMap::HashNode> HashMap::searchKeywordPriceRating(std::string keyword, float priceOrating, std::string por) {
    vector<HashMap::HashNode> ans;
    if(por == "price") //searching by keyword and price
    {
        for(int i = 0; i < TABLESIZE; i++)
        {
            if(table[i] != nullptr)
            {
                string prod = table[i] -> key;
                float pr = table[i]->value.first;
                if(prod.find(keyword)!= string::npos && pr <= priceOrating)
                {
                    ans.push_back(*(table[i]));
                }
            }
        }
    }
    else if(por == "rating") //searching by keyword and rating
    {
        for(int i = 0; i < TABLESIZE; i++)
        {
            if(table[i] != nullptr)
            {
                string prod = table[i] -> key;
                float rate = table[i]->value.second;
                if(prod.find(keyword)!= string::npos && rate >= priceOrating)
                {
                    ans.push_back(*(table[i]));
                }
            }
        }
    }
    return ans;
}
