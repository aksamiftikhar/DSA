/******************************************************************************

LINKED LIST implementation in C++

*******************************************************************************/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class LList
{
    private:
        Node* head;
    public:
        LList()
        {
            head=NULL;
        }
        void createList()
        {
            Node *n1 = new Node;
            n1->data = 15;
            Node *n2  = new Node;
            n2->data = 78;
            Node *n3 = new Node;
            n3->data = 8;

            n1->next = n2;
            n2->next = n3;
            n3->next = NULL;

            head = n1;
        }
        void insertStart(int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;

            insertStart(newNode);
        }
        void insertStart(Node *newNode)
        {
            if(head==NULL)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }

        void insertMiddle(int loc, int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;

            Node*temp = head;
            int i=1;
            while(i<loc-1)
            {
                temp = temp->next;
                i++;
            }
            // temp will be pointing to predecessor
            Node* succ = temp->next;

            temp->next = newNode;// temp->next will be successor
            newNode->next = succ;
        }



        void display()
        {
            Node* temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
};
int main()
{
    LList l1;
    l1.createList();
    l1.insertStart(29);

    Node* n1 = new Node;
    n1->data = 50;
    n1->next = NULL;

    l1.insertStart(n1);
    l1.insertMiddle(4, 150);
    l1.display();
    return 0;
}
