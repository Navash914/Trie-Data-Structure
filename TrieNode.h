//
// Created by Siddharth Vijay on 2019-01-21.
//

#include <string>
#include <vector>

using namespace std;
#ifndef TRIETEST_TRIENODE_H
#define TRIETEST_TRIENODE_H


class TrieNode {

public:
    //constructors
    TrieNode();
    TrieNode(string s);

    //destructor
    ~TrieNode();

    //getData
    string getData();

    TrieNode getChild(int i );

    TrieNode* getChildPointer(int i);

    vector<TrieNode*> getChildren();

    void insertChild(string s);

    void setWord();

    bool getWord();


private:
    string data;

    int depth_level;

    bool isWord = false;

    //note its a vector to conserve space because of unknown number of chidlren
    std::vector<TrieNode*>children = std::vector<TrieNode*>(38);

    /////[0-9] = 0-9
    /////[10]  = -
    /////[11]  = /
    /////[12]  = " "
    /////[13-38] = a-z


    //used to convert character to index in node's vector
    int calculateIndex(char c);

};


#endif //TRIETEST_TRIENODE_H
