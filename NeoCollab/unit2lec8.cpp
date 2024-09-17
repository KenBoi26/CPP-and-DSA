// You are using GCC
#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        
        Node(int val){
            this->data = val;
            this->next = nullptr;
        }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    
    n->next = head;
    head = n;
}

void displayLL(Node* head){
    Node* temp = head;
    
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}



int main(){
    Node* head = nullptr;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        insertAtHead(head, num);
    }
    
    cout << "Created Linked list: ";
    displayLL(head);
    cout << endl;
    
    int num1;
    cin >> num1;
    
    insertAtHead(head, num1);
    
    cout << "Final List: ";
    displayLL(head);
    
    
    
    
    return 0;
}

// You are using GCC
#include <iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        
        Node(char val){
            this->data = val;
            this->next = nullptr;
        }
};

void insertAtTail(Node* &head, char val){
    Node* temp = head;
    
    if(temp == nullptr){
        head = new Node(val);
        return;
    }else{
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        temp->next = new Node(val);
    }
}


void insert(Node* &head, char val, int pos){
    
    if(pos == 1){
        Node* n = new Node(val);
        n->next = head;
        head = n;
        return;
    }
    
    int count = 1;
    
    
    Node* temp = head;
    
    while(temp->next != nullptr && count != pos-1){
        temp = temp->next;
        count++;
    }
    
    Node* n = new Node(val);
    n->next = temp->next;
    temp->next = n;
}


void display(Node* &head){
    Node* temp = head;
    
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int main(){
    
    Node* head = nullptr;
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        char num;
        cin >> num;
        
        insertAtTail(head, num);
    }
    
    cout << "Current Linked List: ";
    display(head);
    cout << endl;
    
    char num;
    int pos;
    
    cin >> num >> pos;
    
    insert(head, num, pos);
    
    cout << "Updated Linked List: ";
    display(head);
    
    
    
    
    return 0;
}

// You are using GCC
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int val){
            this->data = val;
            this->next = nullptr;
        }
};

void push(Node* &head_ref, int new_data)
{
    //Type your code here
    Node* n = new Node(new_data);
    
    n->next = head_ref;
    head_ref = n;
    
}


void append(Node* &head_ref, int new_data)
{
    //Type your code here
    Node* n = new Node(new_data);
    if(head_ref == nullptr){
        head_ref = n;
        return;
    }
    
    Node* temp = head_ref;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    
    temp->next = n;
    
    
}

void printList(Node* node)
{
    //Type your code here
    Node* temp = node;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

int main()
{
    Node* head = NULL;

    int num_of_nodes, new_val;
    cin >> num_of_nodes;

    for (int i = 0; i < num_of_nodes; i++) {
        int val;
        cin >> val;
        push(head, val);
    }

    cout << "Created Linked list:";
    printList(head);

    cin >> new_val;

    append(head, new_val);

    cout << "\nFinal list:";
    printList(head);

    return 0;
}