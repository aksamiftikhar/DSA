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
		Node* tail;
    public:
        LList()
        {
            head=NULL;
			tail=NULL;
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
			n1->prev = n3;
			n2->prev = n1;
            n2->next = n3;
			n3->prev = n2;
			n3->next = n1;

            head = n1;
			tail = n3;
        }

        void insertStart(int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;
            newNode->prev = NULL;

			if(head == NULL)
            {
                head = newNode;
                tail = newNode;
                tail->next = head;
                head->prev = tail;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                tail->next = newNode;
                newNode->prev = tail;

                head = newNode;
            }
		}

		/*
		int deleteStart()
        {
            if(head!=NULL)
            {
                Node* Temp = head;
                int x = Temp->data;
                head = head->next;
                delete Temp;
                return x;
            }
        }
        void deleteLast()
        {
            if(head==NULL)
                cout<<"empty list";
            else
            {
                if(head->next==NULL)
                {
                    deleteStart();
                }
                else
                {
                    Node *curr=head->next, *prev=head;
                    while(curr->next!=NULL)
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                    delete curr;
                    prev->next = NULL;
                }
            }
        }
		*/
		/*

        void insertMiddle1(int loc, int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;


            if(head == NULL)
            {
                head = newNode;
            }
            // The following is a special case, because in this case head
            // should also be updated.
            else if(loc==1)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                struct Node *curr = head;
                struct Node *prev = NULL;
                int nodeCount=0;
                while(curr!=NULL)
                {
                    nodeCount = nodeCount+1;
                    if(nodeCount==loc)
                    {
                        newNode->next = curr;
                        prev->next = newNode;
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }

            }
        }

		void deleteMiddle(int loc, int V)
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
            Node* todel = temp->next;
            temp->next = todel->next;
            delete temp->next;

        }
		*/
        void display()
        {
            cout<<"display method"<<endl;
            Node* temp = head;
            do
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }while(temp!=head);
        }
};

int main()
{
	LList l2;
	l2.createList();
	l2.display();

	l2.insertStart(102);
	l2.insertStart(420);
	l2.display();

/*LList l1;
    l1.insertStart(30);


    struct Node *newNode = new Node;
    newNode->data = 65;
    newNode->next = NULL;


    l1.insertStartNode(newNode);
    l1.insertStart(50);
    l1.insertStart(90);
    l1.insertStart(60);
    l1.insertMiddle1(4, 100);

    l1.display();

    l1.deleteLast();
    l1.deleteLast();
    l1.deleteLast();
    l1.deleteLast();
l1.deleteLast();
l1.deleteLast();

    l1.display();

*/
    return 0;
}

