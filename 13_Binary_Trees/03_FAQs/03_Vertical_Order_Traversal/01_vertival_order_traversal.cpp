#include<bits/stdc++.h>
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

vector<vector<int>> verticalTraversal(TreeNode<int>* root) {
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    q.push({root,{0,0}});

    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        TreeNode<int>* node=temp.first;
        int vertical_dist=temp.second.first;
        int level=temp.second.second;
        nodes[vertical_dist][level].insert(node->data);
        if(node->left)
            q.push({node->left,{vertical_dist-1,level+1}});

        if(node->right)
            q.push({node->right,{vertical_dist+1,level+1}});
    }

    vector<vector<int>>ans;

    for(auto x:nodes){
        vector<int>col;
        for(auto num:x.second)
            col.insert(col.end(),num.second.begin(),num.second.end());
        ans.push_back(col);
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
    
    for(auto &vec:verticalTraversal(root)){
        for(auto &num:vec)
            cout<<num<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}