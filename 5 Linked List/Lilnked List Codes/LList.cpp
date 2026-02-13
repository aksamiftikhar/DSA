/******************************************************************************

LINKED LIST implementation in C++

*******************************************************************************/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
	Node* prev;
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

            head = n1;
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
    l1.display();
    return 0;
}
