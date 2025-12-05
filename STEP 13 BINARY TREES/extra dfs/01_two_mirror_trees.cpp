//Node structure
struct Node
{
    int data;
    Node* left, *right;
}; 

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        if(!a || !b) return a==b;
        
        if(a->data == b->data  && areMirror(a->left , b->right) && areMirror(b->left, a->right)){
            
             return true;
        }
        return false;
        
    }
};