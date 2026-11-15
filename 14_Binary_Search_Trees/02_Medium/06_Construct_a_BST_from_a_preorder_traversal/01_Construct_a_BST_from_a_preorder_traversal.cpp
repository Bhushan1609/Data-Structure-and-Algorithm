#include<bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

template<class T>
class TreeNode{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data,TreeNode* left=NULL,TreeNode* right=NULL){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    static void create_bst(TreeNode* &root,int data){
        if(!root){
            root=new TreeNode(data);
            return;
        }
        if(data<root->data)
            create_bst(root->left,data);
        else
            create_bst(root->right,data);
    }

    static TreeNode* recursive_bst(){
        T data;
        cout<<"Enter data for root : ";cin>>data;
        TreeNode<int> *root=new TreeNode(data);
        while(true){
            cout<<"Enter data to add in the BST : ";cin>>data;
            if(data==-1)    
                break;
            create_bst(root,data);
        }

        return root;
    }

    static void levelorder(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();q.pop();
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
            cout<<endl;
        }

        return ;
    }
};

TreeNode<int>* build(int &i,vector<int>&preorder,int bound){
    if(i==preorder.size() || preorder[i]>bound)
        return NULL;
    TreeNode<int>* root=new TreeNode(preorder[i++]);
    root->left=build(i,preorder,root->data);
    root->right=build(i,preorder,bound);
    return root;
}

TreeNode<int>* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return build(i,preorder,INT_MAX);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>preorder={8,5,1,7,10,12};
    TreeNode<int>* root=bstFromPreorder(preorder);
    TreeNode<int>::levelorder(root);
    return 0;
}