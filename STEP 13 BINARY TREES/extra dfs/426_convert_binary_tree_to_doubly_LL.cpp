/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
  Node* head = NULL;
  Node* prev = NULL;
  
  void inord(Node* root){
      if(!root) return;
      
      inord(root->left);
      
      if(prev == NULL){
          head = root;
      }
      else{
          prev->right = root;
          root->left = prev;
      }
      prev = root;
      
      inord(root->right);
  }
    Node* bToDLL(Node* root) {
        // code here
        inord(root);
        return head;
    }
};