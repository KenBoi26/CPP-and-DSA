// Question 1
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(const Queue& q) {
    return q.front == -1;
}

bool isFull(const Queue& q) {
    return q.rear == MAX_SIZE - 1;
}

void enqueue(Queue& q, int data) {
    if (isFull(q)) {
        return;
    }

    if (isEmpty(q)) {
        q.front = 0;
    }

    q.rear++;
    q.queue[q.rear] = data;
}

int dequeue(Queue& q) {
    if (isEmpty(q)) {
        return -1; // Assuming -1 as an invalid value for the dequeue operation
    }

    int data = q.queue[q.front];

    if (q.front == q.rear) {
        initializeQueue(q);
    } else {
        q.front++;
    }

    return data;
}

struct Solution {
    int firstUniqChar(const std::string& s) {
        int charCount[256] = {0}; // Assuming ASCII characters

        for (char c : s) {
            charCount[c]++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        return -1; // No unique character found
    }
};

int main() {
    Solution solution;
    std::string input;
    std::cin >> input;

    int result = solution.firstUniqChar(input);
    std::cout << result << std::endl;

    return 0;
}


// Question 2
#include <iostream>

struct Queue {
    int* arr;        // array to store queue elements
    int front;       // front points to the front element in the queue
    int rear;        // rear points to the last element in the queue
    int capacity;    // maximum capacity of the queue
    int size;        // current size of the queue
};

void initializeQueue(Queue& q, int capacity) {
    q.arr = new int[capacity];
    q.capacity = capacity;
    q.front = 0;
    q.rear = -1;
    q.size = 0;
}

bool isEmpty(const Queue& q) {
    return q.size == 0;
}

bool isFull(const Queue& q) {
    return q.size == q.capacity;
}

void enqueue(Queue& q, int item) {
    if (isFull(q)) {
        std::cout << "Queue is full\n";
        return;
    }
    q.rear = (q.rear + 1) % q.capacity;
    q.arr[q.rear] = item;
    q.size++;
}

int getFront(const Queue& q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty\n";
        return -1; // Assuming -1 as an invalid value for the front element
    }
    return q.arr[q.front];
}

int getRear(const Queue& q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty\n";
        return -1; // Assuming -1 as an invalid value for the rear element
    }
    return q.arr[q.rear];
}

int main() {
    int N;
    std::cin >> N;

    Queue queue;
    initializeQueue(queue, N); // Creating a queue of capacity N

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        enqueue(queue, num);
    }

    std::cout << "Front element: " << getFront(queue) << std::endl;
    std::cout << "Rear element: " << getRear(queue) << std::endl;

    delete[] queue.arr;

    return 0;
}


// Question 3

#include <iostream>

struct Node {
    int pages;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initializeQueue(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void enqueue(Queue* q, int pages) {
    Node* newNode = new Node();
    newNode->pages = pages;
    newNode->next = nullptr;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

bool dequeue(Queue* q, int& pages) {
    if (isEmpty(q)) {
        return false;
    }
    Node* temp = q->front;
    pages = temp->pages;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node* temp = q->front;
    while (temp != nullptr) {
        std::cout << temp->pages << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Queue q;
    int option;
    int pages;

    initializeQueue(&q);

    while (true) {
        if (!(std::cin >> option)) {
            break;
        }

        if (option == 0) {
            std::cout << "Exiting the program" << std::endl;
            return 0;
        }

        switch (option) {
            case 1:
                if (!(std::cin >> pages)) {
                    break;
                }
                enqueue(&q, pages);
                std::cout << "Print job with " << pages << " pages is enqueued" << std::endl;
                break;

            case 2:
                if (dequeue(&q, pages)) {
                    std::cout << "Processing print job: " << pages << " pages" << std::endl;
                } else {
                    std::cout << "Queue is empty" << std::endl;
                }
                break;

            case 3:
                display(&q);
                break;

            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }

    return 0;
}


// Question 3
#include <iostream>

struct Node {
    int pages;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initializeQueue(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void enqueue(Queue* q, int pages) {
    Node* newNode = new Node();
    newNode->pages = pages;
    newNode->next = nullptr;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

bool dequeue(Queue* q, int& pages) {
    if (isEmpty(q)) {
        return false;
    }
    Node* temp = q->front;
    pages = temp->pages;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node* temp = q->front;
    std::cout << "Print jobs in the queue: ";
    while (temp != nullptr) {
        std::cout << temp->pages << " pages ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Queue q;
    int option;
    int pages;

    initializeQueue(&q);

    while (true) {
        if (!(std::cin >> option)) {
            break;
        }

        if (option == 0) {
            std::cout << "Exiting the program" << std::endl;
            return 0;
        }

        switch (option) {
            case 1:
                if (!(std::cin >> pages)) {
                    break;
                }
                enqueue(&q, pages);
                std::cout << "Print job with " << pages << " pages is enqueued" << std::endl;
                break;

            case 2:
                if (dequeue(&q, pages)) {
                    std::cout << "Processing print job: " << pages << " pages" << std::endl;
                } else {
                    std::cout << "Queue is empty" << std::endl;
                }
                break;

            case 3:
                display(&q);
                break;

            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }

    return 0;
}


// Question 4
#include <iostream>

struct Node {
    int customerID; 
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initializeQueue(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void enqueue(Queue* q, int customerID) { 
    Node* newNode = new Node();
    newNode->customerID = customerID;
    newNode->next = nullptr;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

bool dequeue(Queue* q, int& customerID) { 
    if (isEmpty(q)) {
        return false;
    }
    Node* temp = q->front;
    customerID = temp->customerID;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node* temp = q->front;
    std::cout << "Customer IDs in the queue are: "; 
    while (temp != nullptr) {
        std::cout << temp->customerID << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Queue q;
    int customerID;
    int option;

    initializeQueue(&q);

    while (true) {
        if (!(std::cin >> option)) {
            break;
        }

        switch (option) {
            case 1:
                if (!(std::cin >> customerID)) {
                    break;
                }

                enqueue(&q, customerID);
                std::cout << "Customer ID " << customerID << " is enqueued" << std::endl;
                break;

            case 2:
                if (dequeue(&q, customerID)) {
                    std::cout << "Dequeued customer ID: " << customerID << std::endl;
                } else {
                    std::cout << "Queue is empty" << std::endl;
                }
                break;

            case 3:
                display(&q);
                break;

            case 0:
                std::cout << "Exiting program" << std::endl;
                return 0;

            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }

    return 0;
}
