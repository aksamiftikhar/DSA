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
class Tree
{
private:
    Node* root;
public:
    Tree()
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

        root = n1;

        n1->left = n2;
        n1->right = n3;

        n3->left = n4;
        n3->right = n5;

    }
    void traverse_inorder(Node* node1)
    {
        if(node1!=NULL)
        {
            traverse_inorder(node1->left);

            traverse_inorder(node1->right);

cout<<node1->data<<endl;
        }
    }
};
int main()
{
    Tree tree1;
    tree1.createTree();
    tree1.traverse_inorder(tree1.getRoot());

    return 0;
}
