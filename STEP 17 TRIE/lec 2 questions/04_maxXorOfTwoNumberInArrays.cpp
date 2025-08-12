                            
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* links[2]; 
    
    bool containsKey(int bit) {
        return (links[bit] != NULL); 
    }
    Node* get(int bit) {
        return links[bit]; 
    }
    
    void put(int bit, Node* node) {
        links[bit] = node; 
    }
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root; 
        for (int i = 31; i >= 0; i--) { 
            int bit = (num >> i) & 1; 
            if (!node->containsKey(bit)) { 
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }
    
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0; 
        for (int i = 31; i >= 0; i--) { 
            int bit = (num >> i) & 1; 
            if (node->containsKey(1 - bit)) { 
                
                maxNum |= (1 << i); 
                
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum; 
    }
};
int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    Trie trie; 
    for (auto& it : arr1) { 
        trie.insert(it);
    }
    int maxi = 0; 
    for (auto& it : arr2) { 
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}

void printArr(vector<int> arr){
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {3, 10, 5, 25, 2};
    vector<int> arr2 = {8, 1, 2, 12, 7};
    int n = arr1.size();
    int m = arr2.size();
    
    cout << "Arr1: ";
    printArr(arr1);
    cout << "Arr2: ";
    printArr(arr2);
    

    int result = maxXOR(n, m, arr1, arr2);
    cout << "Maximum XOR value: " << result << endl;

    return 0;
}
                            
                        