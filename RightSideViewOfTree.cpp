/*

right side view of tree

        5
    3       15  <--- right side view
1     4   10

*/


void helper(vector<TreeNode*> level){
    // stopping cond.
    if(level.size()==0)
        return;

    if(level.size()!=0)
        cout<<level[level.size()-1];

    vector<TreeNode*> new_level;
    for(auto it: level){
        if(it->left!=NULL) new_level.push_back(it->left);
        if(it->right!=NULL) new_level.push_back(it->right);
    }

    helper(new_level);
}

void rightside(TreeNode*  root){
    vector<TreeNode*> v;
    v.push_back(root);
    helper(root);
}



