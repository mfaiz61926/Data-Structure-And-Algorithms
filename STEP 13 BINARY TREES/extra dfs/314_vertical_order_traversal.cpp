#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int, vector<int>>mp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                mp[level].push_back(node->data);
                
                if(node->left){
                    q.push({node->left, level - 1});
                }
                if(node->right){
                    q.push({node->right, level + 1});
                }
                
            }
        }
        vector<vector<int>>res;
        for(auto &it : mp){
            vector<int>ans;
            for(auto &i : it.second){
                ans.push_back(i);
            }
            res.push_back(ans);
        }
        
        return res;
    }
};