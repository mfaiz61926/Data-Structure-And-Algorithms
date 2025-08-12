#include <bits/stdc++.h>
using namespace std;

//Node structure for trie
struct Node {
    // Array to store links to child nodes, each index represent a letter
    Node* links[26];
    //Flag indicating if the node marks the end of a word
    bool flag=false;

    //check if the node contains a specific key (letter)
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    // Insert a new node with a specific key(letter) into the trie
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    //Get the node with a specific key(letter) form the trie
    Node* get(char ch){
        return links[ch-'a'];
    }

    //set the current node as the end of a word
    void setEnd(){
        flag=true;
    }

    //Check if the current node marks the end of a word
    bool isEnd(){
        return flag;
    }
};


// Trie class
class Trie{
    private:
        Node* root;
    
    public:
        //constructor to initialize the trie with an empty root node 
        Trie(){
            root=new Node();
        }

        //Inserts a word into the trie
        //Time complexity O(len), where len is the length of the word
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    //Create a new node for the letter if not prensent
                    node->put(word[i],new Node());
                }
                //Move to the next node
                node=node->get(word[i]);
            }
            //Mark the end of the word
            node->setEnd();
        }

        //Return if the word is in the trie
        bool search(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    //if a letter is not found, the word is not in the trie
                    return false;
                }
                //Mode to the next node
                node=node->get(word[i]);
            }
            //check if the last node marks the end of a word
            return node->isEnd();
        }


        //Return if there is any word in the trie that starts with the given prefix
        bool startsWith(string prefix){
            Node* node = root;
            for(int i=0;i < prefix.length();i++){
                if(!node->containsKey(prefix[i])){
                    //if a letter is not found, there is no word with the given prefix
                    return false;
                }
                //Move to the next node
                node=node->get(prefix[i]);
            }
            //The prefix is found in the trie
            return true;
        }
};

int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    return 0;
}