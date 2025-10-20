#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
  public:
    Node* merge(Node*a, Node*b){
        if(!a) return b;
        if(!b) return a;
        
        Node* res;
        if(a->data < b->data){
            res = a;
            res->bottom = merge(a->bottom, b);
        }
        else {
            res = b;
            res->bottom = merge(a, b->bottom);
        }
        return res;
    }
    Node *flatten(Node *root) {
        // code here
        if(!root) return nullptr;
        
        Node* head = flatten(root->next);
        return merge(root, head);        
    }
};