#include "HashMap.h"
#include "n-ary.h"
using namespace std;

int main() {
    // testing the actual method
    std::cout
            << "Welcome to Amazon Dupe! Choose the data structure you want to store the items in. (1 for tree, 2 for hashmap)"
            << std::endl;
    int data_type;
    cin >> data_type;

    Tree price_tree, stars_tree;
    HashMap hashmap;
    //const std::string filename = "amazon_products.csv";
    const std::string filename = "C:/Users/devik/CLionProjects/AmazonDupe/amazon_products.csv";

    // Parsing logic integrated into main
    std::ifstream userFile;
    userFile.open(filename);
    if (!userFile.is_open()) {
        std::cerr << "Couldn't read file: " << filename << std::endl;
        return 1;
    }

    int rowsToParse = 120000;
    while (rowsToParse > 0) {
        std::string line;
        if (!std::getline(userFile, line)) {
            break;
        }

        std::istringstream ss(line);
        std::string asin,title,imgUrl,productURL,stars,reviews,price,listPrice,category_id,isBestSeller,boughtInLastMonth;

        // Parsing and inserting into data structures
        if (getline(ss, asin, ',') && getline(ss, title, ',') && getline(ss, imgUrl, ',') &&
            getline(ss, productURL, ',') && getline(ss, stars, ',') && getline(ss, reviews, ',') &&
            getline(ss, price, ',') && getline(ss, listPrice, ','), getline(ss, category_id, ','),
            getline(ss, isBestSeller, ','),getline(ss, boughtInLastMonth, ',') && rowsToParse != 120) {
            // Insert into Tree
            price_tree.insert(title, std::stod(price), std::stod(stars));
            stars_tree.insert(title, std::stod(stars), std::stod(price));

            // Insert into HashMap
            hashmap.insert(title, price, stars);


        }
        rowsToParse--;
    }

    userFile.close();
    //price_tree.print();
    //stars_tree.print();

    std::cout
            << "Choose whether you want to search for the exact title, or for a keyword. (1 for exact title, 2 for keyword)"
            << std::endl;
    int string_type;
    cin >> string_type;
    std::cout << "Enter the string: " << std::endl;
    string s;
    getline(cin, s);
    getline(cin, s);

    cout << "Choose whether you want the best items by price or rating. (1 for price, 2 for rating)" << std::endl;
    int sort_by;
    cin >> sort_by;


    vector<Node*> vtree;
    vector<HashMap::HashNode> vmap;
    if (data_type == 1) {
        vector < Node * > v;
        if (string_type == 1) {
            if (sort_by == 1) {
                vtree = price_tree.find(s, true);
            } else {
                vtree = stars_tree.find(s, false);
            }
        } else {
            if (sort_by == 1) {
                vtree = price_tree.findKey(s, true);
            } else {
                vtree = stars_tree.findKey(s, false);
            }
        }

        //if sort_by = 1 -> node -> name, node -> value = price, node -> value2 = rating
        //if sort_by - 2 -> node -> name, node -> value2 = price, node -> value = rating
    } else {
        vector <HashMap::HashNode> v;
        if (string_type == 1) {
            if (sort_by == 1) {
                pair<float, float> result = hashmap.searchName(s);
                vmap.emplace_back(s, result);
            } else {
                vmap = hashmap.searchKeyword(s);
            }
        } else {
            if (sort_by == 1) {
                vmap = hashmap.searchKeywordPriceRating(s, 100000, "price");
            } else {
                vmap = hashmap.searchKeywordPriceRating(s, 0, "rating");
            }
        }
    }


    /*cout << "Printing Price Tree:" << endl;
    price_tree.print();

    cout << "\nPrinting Stars Tree:" << endl;
    stars_tree.print();
    for(int i = 0; i < vtree.size(); i++)
    {
        cout << vtree[i]->name << " " << vtree[i]->value << " " << vtree[i]->value2 << endl;
    }*/

    cout << "\nPrinting Hash Map:" << endl;
    for (int i = 0; i < vmap.size(); ++i) {
        HashMap::HashNode hn = vmap[i];
        cout << hn.key << " " << hn.value.first << " " << hn.value.second << endl;
    }

    return 0;
}