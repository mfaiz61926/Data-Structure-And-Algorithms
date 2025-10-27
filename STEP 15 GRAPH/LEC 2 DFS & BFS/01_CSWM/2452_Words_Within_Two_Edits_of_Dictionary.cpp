#include <vector>
#include <string>
#include <iostream>
using namespace std;  // second easy method is below

// Node definition for Trie
struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

// Trie class
class Trie {
private:
    Node* root;

    // DFS to check if a word exists in the Trie within 2 edits
    bool dfs(Node* node, const string& word, int index, int edits) {
        if (edits > 2) return false;
        if (index == word.length()) return node->isEnd() && edits <= 2;

        int currCharIndex = word[index] - 'a';
        for (int i = 0; i < 26; i++) {
            if (node->links[i] != nullptr) {
                if (i == currCharIndex) {
                    if (dfs(node->links[i], word, index + 1, edits)) return true;
                } else {
                    if (dfs(node->links[i], word, index + 1, edits + 1)) return true;
                }
            }
        }

        return false;
    }

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool isWithinTwoEdits(const string& word) {
        return dfs(root, word, 0, 0);
    }
};

// Solution class
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        vector<string> result;
        for (const string& query : queries) {
            if (trie.isWithinTwoEdits(query)) {
                result.push_back(query);
            }
        }
        return result;
    }
};


// good method 
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (const string& query : queries) {
            for (const string& dictWord : dictionary) {
                int diff = 0;
                for (int i = 0; i < query.size(); ++i) {
                    if (query[i] != dictWord[i]) {
                        ++diff;
                        if (diff > 2) break;
                    }
                }
                if (diff <= 2) {
                    result.push_back(query);
                    break; // No need to check other dict words
                }
            }
        }

        return result;
    }
};