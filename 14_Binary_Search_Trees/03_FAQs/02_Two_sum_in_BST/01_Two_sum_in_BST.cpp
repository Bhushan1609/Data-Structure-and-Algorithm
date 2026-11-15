class BSTIterator {
    stack<TreeNode*>st;
    bool reverseORnot;
public:
    BSTIterator(TreeNode* root,bool reverseORnot){
        this->reverseORnot=reverseORnot;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(reverseORnot==false)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverseORnot==false)
                root=root->left;
            else 
                root=root->right;
        }
        return ;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator sort(root,false);
        BSTIterator reverse(root,!false);
        int left=sort.next();
        int right=reverse.next();
        while(left<right){
            if(left+right==k)
                return true;
            else if(left+right<k)
                left=sort.next();
            else
                right=reverse.next();
        }
        return false;
    }
};