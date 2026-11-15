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

int ceil(TreeNode<int>* root,int val){
    int ceil=-1;
    while(root){
        if(root->data == val){
            ceil=root->data;
            return ceil;
        }

        if(val > root->data){
            root=root->right;
        }else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}

pair<int,int> mini_maxi(TreeNode<int>* root){
    int mini=INT_MAX,maxi=INT_MIN;
    TreeNode<int>* root1=root,*root2=root;
    while(root1){
        mini=min(mini,root1->data);
        root1=root1->left;
    }

    while(root2){
        maxi=max(maxi,root2->data);
        root2=root2->right;
    }
    return {mini,maxi};
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    TreeNode<int>* root=TreeNode<int>::recursive_bst();
    TreeNode<int>::levelorder(root);
    cout<<mini_maxi(root).first<<" : "<<mini_maxi(root).second<<endl;
    return 0;
}