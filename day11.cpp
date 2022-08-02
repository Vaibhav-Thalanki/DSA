/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        root->next = NULL;
        Node* current = root;
        Node* currentNext = root->left;
        while(currentNext!=NULL){
            while(current){
            if(current->left)
            current->left->next = current->right;
                cout<<current->val<<"\n";
            if(current->next){
                current->right->next = current->next->left;
                
            }
                current=current->next;
            }
            current = currentNext;
            currentNext=currentNext->left;
        }
        return root;
    }
};