#include <iostream>
using namespace std;
template <class T>
class Node
{
    private:
        T data;
        Node<T>* next;
    public:
        Node(T V)
        {
            data = V;
            next = NULL;
        }
        T getData()       { return data; }
        void setData(T V) { data = V; }
        Node* getNext()    { return next; }
        void setNext(Node *nextNode) { next = nextNode; }

};

template <class T>
class SLList
{
private:
public:

};
int main()
{
    Node<string> nd("my node");
    cout<<nd.getData()<<endl<<nd.getNext();

	return 0;
}
