#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};
class BST
{
private:
    Node* root;
public:
    BST()
    {
        root = NULL;
    }
    Node* getRoot()
    {
        return root;
    }
    void createTree()
    {
        Node* n1 = new Node(1);
        Node* n2 = new Node(2);
        Node* n3 = new Node(3);
        Node* n4 = new Node(4);
        Node* n5 = new Node(5);

        root = n4;

		n4->left = n3;
        n4->right = n5;

		n3->left = n1;
        n1->right = n2;

    }
    void traverse_inorder(Node* node1)
    {
        if(node1!=NULL)
        {
            traverse_inorder(node1->left);
			cout<<node1->data<<endl;
            traverse_inorder(node1->right);
        }
    }
    Node* BST_Insert(Node* curr_root, Node* new_node)
    {
        if(curr_root==NULL)
            curr_root = new_node;
        else if(new_node->data<curr_root->data)
            curr_root->left = BST_Insert(curr_root->left, new_node);
        else
            curr_root->right = BST_Insert(curr_root->right, new_node);
        return curr_root;
    }
};
int main()
{
    BST tree1;
    tree1.createTree();
    Node* newNode = new Node(0);
    tree1.BST_Insert(tree1.getRoot(), newNode);
    tree1.traverse_inorder(tree1.getRoot());

    return 0;
}
