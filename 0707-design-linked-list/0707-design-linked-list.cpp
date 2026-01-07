class Node {
  public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}

};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList(): head(nullptr), size(0) {}
    int get(int index) {
        // Return -1 for invalid index
        if(index>=size || index < 0) {
            return -1;
        }
        Node* current=head;
        for(int i=0;i<index;++i) {
            current= current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    

    void addAtTail(int val) {
        addAtIndex(size, val);       
    }

    void addAtIndex(int index, int val) {
        // Return if invalid index
        if (index>size || index < 0) {
            return;
        }
        Node* current= head;
        Node* new_node = new Node(val);

        if (index == 0) {
            new_node->next = current;
            // Update head
            head = new_node;
        }
        else {
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }          
            new_node->next = current->next;
            current->next = new_node;
        }
        size++;
    }
    

    void deleteAtIndex(int index) {
        if(index>=size || index < 0) {
            return;
        }

        if (index == 0) {
            Node* nextNode = head->next;
            // Always remember to free memory to prevent memory leak
            delete head;
            head = nextNode;            
        }
        else {
            Node* current= head;
            // Run loop till index-1 as we need to insert node at index
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }

            Node* nextNode = current->next->next;
            // Always remember to free memory to prevent memory leak
            delete current->next;
            current->next = nextNode;
        }
        // Decrease size whenever we delete node
            size--;
    }

    // Destructor
    ~MyLinkedList()
    {
        Node *p = head;
        // Delete node at head while head is not null
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */