#include<bits/stdc++.h>
#include<unordered_map>
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

void find_target_node(TreeNode<int>*root,int target,TreeNode<int>*& target_node){
    if(!root)
        return;
    if(root->data==target)
        target_node=root;
    find_target_node(root->left,target,target_node);
    find_target_node(root->right,target,target_node);
}

void do_parent_mapping(TreeNode<int>* root,unordered_map<TreeNode<int>*,TreeNode<int>*>&parent_mapping){
    if(!root)
        return ;
    if(root->left)
        parent_mapping[root->left]=root;
    if(root->right)
        parent_mapping[root->right]=root;
    do_parent_mapping(root->left,parent_mapping);
    do_parent_mapping(root->right,parent_mapping);
}

int minTime(TreeNode<int>* root, int target) {
    int ans;
    TreeNode<int>*target_node=NULL;
    unordered_map<TreeNode<int>*,TreeNode<int>*>parent_mapping;
    unordered_map<TreeNode<int>*,int>visited;
    find_target_node(root,target,target_node);
    parent_mapping[root]=NULL;
    do_parent_mapping(root,parent_mapping);

    queue<pair<TreeNode<int>*,int>>q;
    q.push({target_node,0});
    visited[target_node]++;

    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        ans=temp.second;
        if(temp.first->left && !visited[temp.first->left]){
            q.push({temp.first->left,temp.second+1});
            visited[temp.first->left]++;
        }

        if(temp.first->right && !visited[temp.first->right]){
            q.push({temp.first->right,temp.second+1});
            visited[temp.first->right]++;
        }

        TreeNode<int>* parent=NULL;
        if(parent_mapping.find(temp.first)!=parent_mapping.end())
            parent=parent_mapping[temp.first];

        if(parent && !visited[parent_mapping[temp.first]]){
            q.push({parent_mapping[temp.first],temp.second+1});
            visited[parent]++;
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    TreeNode<int>* root=NULL;
    root=TreeNode<int>::recursive_tree(root);
    
    cout<<"minTime : "<<minTime(root,4)<<endl;
    return 0;
}