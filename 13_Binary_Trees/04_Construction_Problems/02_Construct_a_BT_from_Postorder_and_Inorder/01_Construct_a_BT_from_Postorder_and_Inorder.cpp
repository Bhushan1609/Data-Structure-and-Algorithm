#include<bits/stdc++.h>
#include<map>
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

    static TreeNode* non_recursive_tree(TreeNode* root){
        T data;
        cout<<"Enter data for root : ";cin>>data;

        if(data==-1)
            return NULL;

        root=new TreeNode(data);

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                T leftdata,rightdata;
                TreeNode* temp=q.front();
                q.pop();
                cout<<"Enter data for the left of "<<temp->data<<" ";
                cin>>leftdata;
                cout<<endl;
                if(leftdata!=-1){
                    temp->left=new TreeNode(leftdata);
                    q.push(temp->left);
                }

                cout<<"Enter data for the right of "<<temp->data<<" ";
                cin>>rightdata;
                cout<<endl;
                if(rightdata!=-1){
                    temp->right=new TreeNode(rightdata);
                    q.push(temp->right);
                }
            }
        }

        return root;
    }

    static TreeNode* recursive_tree(TreeNode* root){
        T data;
        cout<<"Enter the data : ";
        cin>>data;
        cout<<endl;

        if(data==-1)
            return NULL;

        root=new TreeNode(data);

        cout<<"Enter the left node of "<<root->data<<" : ";
        cout<<endl;
        root->left=recursive_tree(root->left);

        cout<<"Enter the right node of "<<root->data<<" : ";
        cout<<endl;
        root->right=recursive_tree(root->right);

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

TreeNode<int>* build(int postStart,int postEnd,int inStart,int inEnd,vector<int>&postorder,vector<int>&inorder,map<int,int>&inMap){
    if(postStart>postEnd or inStart>inEnd)
        return NULL;
    TreeNode<int>* root=new TreeNode(postorder[postEnd]);
    int index=inMap[postorder[postEnd]];
    int remains=index-inStart;
    root->left=build(postStart,postStart+remains-1,inStart,index-1,postorder,inorder,inMap);
    root->right=build(postStart+remains,postEnd-1,index+1,inEnd,postorder,inorder,inMap);
    return root;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>inorder,postorder;
    inorder={9,3,15,20,7};
    postorder={9,15,7,20,3};

    int n=inorder.size();
    map<int,int>inMap;

    for(int i=0;i<n;i++)
        inMap[inorder[i]]=i;

    TreeNode<int>* root=build(0,n-1,0,n-1,postorder,inorder,inMap);
    TreeNode<int>::levelorder(root);
    return 0;
}