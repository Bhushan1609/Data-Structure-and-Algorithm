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

string serialize(TreeNode<int>* root) {
    string ans="";
    if(!root)
        return ans;
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        if(!temp)
            ans.append("#,");
        else
            ans.append(to_string(temp->data)+',');
        if(temp)
            q.push(temp->left),q.push(temp->right);
    }
    return ans;
}

TreeNode<int>* deserialize(string data) {
    if(data.size() == 0)
        return NULL;    
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode<int>* root=new TreeNode(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int> *node=q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#"){
            node->left=NULL;
        }else{
            TreeNode<int>* leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }

        getline(s,str,',');
        if(str=="#"){
            node->right=NULL;
        }else{
            TreeNode<int>* rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    TreeNode<int>* root=NULL;
    root=TreeNode<int>::recursive_tree(root);
    TreeNode<int>::levelorder(root);
    return 0;
}