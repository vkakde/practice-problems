#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v){
        val = v;
        left = right = NULL;
    }
};

void inorder(struct Node *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root == NULL)
        return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main (){
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(12);

    cout<<"\nPrinting inorder ...\n";
    inorder(root);

    cout<<"\nPrinting preorder ...\n";
    preorder(root);

    cout<<"\nPrinting potsorder ...\n";
    postorder(root);

    return 0;
}