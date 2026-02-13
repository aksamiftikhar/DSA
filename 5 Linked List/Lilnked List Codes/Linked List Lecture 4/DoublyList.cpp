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
        void insertStart(int v)
        {
            Node* n = new Node;
            n->data = v;

        }
}

