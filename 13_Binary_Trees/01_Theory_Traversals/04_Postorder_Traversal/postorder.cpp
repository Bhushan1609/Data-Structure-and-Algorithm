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

    static void preorder(TreeNode* root){
        if(!root)
            return ;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    static void iterative_preorder(TreeNode* root){
        stack<TreeNode*>st;
        if(!root)
            return ;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ;
    }

    static void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    static void iterative_inorder(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode* curr=root;

        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }else{
                curr=st.top();
                st.pop();
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
        return;
    }

    static void postorder(TreeNode* root){
        if(!root)
            return ;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    static void iterative_postorder(TreeNode* root){
        stack<TreeNode*>st1,st2;
        if(!root)
            return;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* temp=st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
        }
        while(!st2.empty()){
            cout<<st2.top()->data<<" ";
            st2.pop();
        }
        return ;
    }

    static void iterative_postorder1(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode* curr=root;
        
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        cout<<temp->data<<" ";
                    }
                }else{
                    curr=temp;
                }
            }
        }

        return;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    TreeNode<int>* root=NULL;
    root=TreeNode<int>::recursive_tree(root);
    TreeNode<int>::levelorder(root);

    cout<< "Preorder Traversal : ";
    TreeNode<int>::preorder(root);
    cout<<endl;
    cout<< "Iterative Preorder Traversal : ";
    TreeNode<int>::iterative_preorder(root);
    cout<<endl;

    cout<< "Inorder Traversal : ";
    TreeNode<int>::inorder(root);
    cout<<endl;
    cout<< "Iterative Inorder Traversal : ";
    TreeNode<int>::iterative_inorder(root);
    cout<<endl;

    cout<< "Postorder Traversal : ";
    TreeNode<int>::postorder(root);
    cout<<endl;
    cout<< "Iterative Postorder Traversal : ";
    TreeNode<int>::iterative_postorder(root);
    cout<<endl;
    cout<< "Iterative Postorder Traversal : ";
    TreeNode<int>::iterative_postorder1(root);
    cout<<endl;


    
    return 0;
}