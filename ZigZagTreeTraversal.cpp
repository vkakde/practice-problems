#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

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

void zigZag(int level, vector<Node*> v){
    vector<Node*> new_v;
    if(level%2==0){
        for(auto it: v){
            cout<<" "<<it->val<<" ";
            if(it->left!=NULL) new_v.push_back(it->left);
            if(it->right!=NULL) new_v.push_back(it->right);
        }
    }
    else{
        for(int i=v.size()-1; i>=0; i--){
            cout<<" "<<v[i]->val;
            if(v[i]->right!=NULL) new_v.push_back(v[i]->right);
            if(v[i]->left!=NULL) new_v.push_back(v[i]->left);
            std::reverse(new_v.begin(), new_v.end());
        }
    }
    if(new_v.size()!=0){
        zigZag(level+1, new_v);
    }
}

void levelOrder(vector<Node*> v){
    if(v.size()==0)
        return;
    vector<Node*> new_v;
    for(auto it: v){
        cout<<" "<<it->val<<" ";
        if(it->left!=NULL) new_v.push_back(it->left);
        if(it->right!=NULL) new_v.push_back(it->right);
    }
    if(new_v.size()!=0){
        levelOrder(new_v);
    }
}

int main (){
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(12);

   vector<Node*> v;
   v.push_back(root);

   cout<<"\nZigzag order: \n";
   zigZag(0, v);

   cout<<"\nLevel order: \n";
   levelOrder(v);

    return 0;
}