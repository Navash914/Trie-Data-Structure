//
// Created by Siddharth Vijay on 2019-01-21.
//

#include "TrieDS.h"
#include <algorithm>
#include <iostream>

//constructor
TrieDS::TrieDS() {

    root = new TrieNode(" ");

}


//destructor
TrieDS::~TrieDS() {

    ///////////
    ///leave this for later/////
    /////its gonna be messy/////
    ///////////////////////////

}


//list of functions
void TrieDS::add(string s) {

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);

    //cout<<"this is the string we adding " + s<<endl;

   /* if(this->search(s) == true){
        cout<<"already in it "<<endl;
        return;

    }*/

    TrieNode* temp = this->root;

    //iterate through string/tree  --> i represents depth level
    for(int i = 0; i<s.length(); i++){

        //which character to look for and whch index of children array
        char checkChar = s.at(i);
        int indexChar = calculateIndex(checkChar);

        //check if current node already has filled in child with checkChar
        if(temp->getChildPointer(indexChar) != nullptr){
            //move temp down one level and iterate
            temp = temp->getChildPointer(indexChar);

        }

        else{//if it doesn't exist already --> insert new node, and move temp and iterate down

            temp->insertChild(s.substr(0, i+1));
            temp = temp->getChildPointer(indexChar);

        }

    }//end iteration

    //final node is a word
    temp->setWord();

    std::cout<<"success add" <<std::endl;

}


bool TrieDS::search(string s) {

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);


    TrieNode* temp = this->root;
    std::vector<std::string> list;

    //iterate through string/tree  --> i represents depth level
    for(int i = 0; i<s.length(); i++){

        //which character to look for and whch index of children array
        char checkChar = s.at(i);
        int indexChar = calculateIndex(checkChar);

        //check if current node has child containing letter we are looking for

        if(temp->getChildPointer(indexChar) == nullptr){
            //if does not contain, return out of function
            std::cout<<"not found"<<std::endl;
            return false;
        }

        //if it does contain move down one level
        if(temp->getChildPointer(indexChar) != nullptr){
            temp = temp->getChildPointer(indexChar);
        }
    }//end of iteration


    //once its reached here, do the following:
    //traverse through subTree of every child of current node that is non-null
    traverse(temp, list);

    for(auto it = list.begin(); it!=list.end(); it++){
        std::cout<<*it<<std::endl;
    }

    return true;

}

// add all full words to a list and output
std::vector<std::string> TrieDS::traverse(TrieNode* temp_root, std::vector<std::string> &list){

    //check current node
    if(temp_root->getWord()){
        //std::cout<<temp_root->getData()<<std::endl;
        //add it to the list
        list.push_back(temp_root->getData());
    }

    //iterate through children
    for(int i =0; i<temp_root->getChildren().size(); i++){

        if(temp_root->getChildPointer(i) != nullptr){
            traverse(temp_root->getChildPointer(i), list);
        }

    }

    return list;
}

int TrieDS::calculateIndex(char c){

    //exceptions

    if(c == ' '){
        return 12 ;
    }

    if(c == '/'){
        return 11;
    }

    if(c == '-'){
        return 10;
    }

    if(isdigit(c)){//if c is an integer
        return c-48;
    }

    //else, c is a character
    return (c-84);



}