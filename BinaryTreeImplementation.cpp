#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node * left;
        Node * right;
        Node(int d):data(d),left(NULL),right(NULL){}
};
class BinaryTree{
    // Node * root;
    public:
        // BinaryTree(): root(NULL){}

    Node * buildNode(int data)
    {   
        Node *newNode = new Node(data);
        return newNode;
    }
Node * insert(Node * root,int data)
{
    //level order insertion
    if(root == NULL)
    {
     root=buildNode(data);
     return root;
    }
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node * temp= q.front();
        q.pop();
        if(temp->left != NULL)
            q.push(temp->left);
        else{
            temp->left=buildNode(data);
            return root;
        }
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = buildNode(data);
            return root;
        }
    }
}
void preOrderTraversal(Node * root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node * root)
{
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node * root)
{
    if(root==NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}    
};

					
int main()
{
    BinaryTree bt;
    int data;
    int choice;
    cout<<"Enter the root value: "<<endl;
    cin>>data;
    Node * root= new Node(data);
    do
    {
        cout<<"1.Insert 2.PreOrder Traversal 3.InOrder Traversal 4.PostOrder Traversal 5.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Input: "<<endl;
                cin>>data;
                bt.insert(root,data);
                break;
            case 2:
                cout<<"Pre Order: "<<endl;
                bt.preOrderTraversal(root);
                cout<<endl;
                break;
            case 3:
                cout<<"In Order: "<<endl;
                bt.inOrderTraversal(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Post Order: "<<endl;
                bt.postOrderTraversal(root);
                cout<<endl;
                break;
        }
    }while(choice !=5);
    return 0;
}