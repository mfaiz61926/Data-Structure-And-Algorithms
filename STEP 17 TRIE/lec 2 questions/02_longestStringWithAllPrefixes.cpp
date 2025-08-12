#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch){
        return (links[ch-'a']!= NULL);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }

    public: void insert(string word){
        Node* node= root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    public: bool checkIfPrefixExists(string word){
        bool f1=true;
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false)return false;
            }
            else{

                return false;
            }
        }
        return true;
    }
};

string completeString(int n,vector<string>&a){
    Trie trie;
    for(auto &it:a){
        trie.insert(it);
    }
    string longest="";
    for(auto &it:a){
        if(trie.checkIfPrefixExists(it)){
            if(it.length()>longest.length()){
                longest=it;
            }
            else if(it.length()==longest.length() && it<longest){
                longest=it;
            }
        }
    }
    if(longest=="")return "None";
    return longest;
}