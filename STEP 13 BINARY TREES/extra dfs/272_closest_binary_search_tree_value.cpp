// Given the root node of a binary search tree (BST) and a target value. The task is to find the k values in the BST that are closest to the target value. The answer can be returned in any order. It is guaranteed that there is only one unique set of k values in the BST that are closest to the target.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

// Max heap to store the k closest values and their
// distances from the target.
priority_queue<pair<double, int> > maxH;

// Recursive helper function to traverse the tree and find
// the closest values.
void solve(TreeNode* root, double target, int k)
{
    if (root == nullptr) {
        return;
    }

    // Calculate the distance from the current node's value
    // to the target.
    double distanceFromTarget
        = abs((double)root->val - target);

    // Push the node's value and distance onto the max heap.
    maxH.push({ distanceFromTarget, root->val });

    // If the heap size exceeds k, remove the element with
    // the largest distance.
    if (maxH.size() > k) {
        maxH.pop();
    }

    // Recursively explore the left and right subtrees.
    solve(root->left, target, k);
    solve(root->right, target, k);
}

// Function to find the k closest values in a binary search
// tree to a given target.
vector<int> closestKValues(TreeNode* root, double target,
                           int k)
{
    // Clear the max heap before each call.
    maxH = priority_queue<pair<double, int> >();

    // Traverse the tree and find the closest values.
    solve(root, target, k);

    // Extract the k closest values from the max heap and
    // store them in a vector.
    vector<int> result;
    while (!maxH.empty()) {
        result.push_back(maxH.top().second);
        maxH.pop();
    }

    // Return the vector of k closest values.
    return result;
}

int main()
{
    /*
        Let's create the following BST:

              5
           /     \
          3      6
         /  \
       2   4

    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    double target = 3.714286;
    int k = 2;

    vector<int> result = closestKValues(root, target, k);

    cout << "The closest " << k << " values to " << target
         << " are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}