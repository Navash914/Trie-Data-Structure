#include <iostream>
#include "TrieDS.h"
#include <sstream>
#include "TrieNode.h"
using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;

    TrieDS* tree = new TrieDS();

    TrieNode* sup = new TrieNode();
    string input;
    string command;
    string item;

    //std::cout<<"Hello world 2"<<std::endl;
    while(!cin.eof()){
        cout<<">>";

        getline(cin, input);

        stringstream lineStream(input);

        lineStream>>command;
        lineStream>>item;

        if(command == "add")
        tree->add(item);

        if(command == "search")
            tree->search(item);


    }

    tree->add("B a l d w i n");
   // tree->search(" B a l d w i n");
    tree->search("Baldwin");
    return 0;
}