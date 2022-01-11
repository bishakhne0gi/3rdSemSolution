#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int key;
        Node * left;
        Node * right;
        Node(int d):key(d),left(NULL),right(NULL){}
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
    Node * buildTree(Node * root, int key)
{
    //base case
    if(root==NULL)
        return new Node(key);
    if(key<root->key)
        root->left=buildTree(root->left, key);
    else
        root->right=buildTree(root->right, key);
    return root;
}
void inOrderTravesal(Node * root)
{
    if(root==NULL)
        return;
    
    inOrderTravesal(root->left);
    cout<<root->key<<" ";
    inOrderTravesal(root->right);

}
void preOrderTravesal(Node * root)
{
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    preOrderTravesal(root->left);
    
    preOrderTravesal(root->right);

}
void postOrderTravesal(Node * root)
{
    if(root==NULL)
        return;
    
    postOrderTravesal(root->left);
    
    postOrderTravesal(root->right);
    cout<<root->key<<" ";

}
bool search(Node * root, int key)
{
    if(root==NULL)
        return false;
    if(root->key==key)
    {
        return true;
    }
    if(key<root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
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
        cout<<"1.Insert 2.PreOrder Traversal 3.InOrder Traversal 4.PostOrder Traversal 5.Search 6.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Input: "<<endl;
                cin>>data;
                bt.buildTree(root,data);
                break;
            case 2:
                cout<<"Pre Order: "<<endl;
                bt.preOrderTravesal(root);
                cout<<endl;
                break;
            case 3:
                cout<<"In Order: "<<endl;
                bt.inOrderTravesal(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Post Order: "<<endl;
                bt.postOrderTravesal(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Enter item to be searched: "<<endl;
                cin>>data;
                cout<<bt.search(root,data);
                cout<<endl;
            default:
                cout<<"Thank You! "<<endl;
        }
    }while(choice !=6);
    return 0;
}