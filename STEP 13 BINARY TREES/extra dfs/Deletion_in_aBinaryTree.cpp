#include <bits/stdc++.h>
using namespace std;
//Structre of the node of the tree is as
struct Node
{
    int data;
    Node* left, *right;
};

class Solution {
public:
    Node* deleteNode(Node* root, int key) {
        if (!root) return nullptr;

        if (!root->left && !root->right) {
            if (root->data == key) {
                delete root;
                return nullptr;
            }
            return root;
        }

        queue<Node*> q;
        q.push(root);

        Node* target = nullptr;
        Node* deepest = nullptr;
        Node* parent = nullptr;

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            if (cur->data == key)
                target = cur;

            if (cur->left) {
                parent = cur;
                q.push(cur->left);
            }

            if (cur->right) {
                parent = cur;
                q.push(cur->right);
            }

            deepest = cur;
        }

        if (!target) return root;

        target->data = deepest->data;

        if (parent->right == deepest)
            parent->right = nullptr;
        else
            parent->left = nullptr;

        delete deepest;

        return root;
    }
};