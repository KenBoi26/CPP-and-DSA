// Question 1
// You are using GCC
#include <iostream>
#include <iomanip> 

using namespace std;

const int MAX_SIZE = 100;

class Queue {
public:
    int arr[MAX_SIZE];
    int frontIdx;
    int rearIdx;

    Queue() {
        frontIdx = -1;
        rearIdx = -1;
    }

    bool isEmpty() {
        return (frontIdx == -1 && rearIdx == -1);
    }

    bool isFull() {
        return (rearIdx == MAX_SIZE - 1);
    }

    void enqueue(int element) {
        //Type your code here
        if(isFull()){
            cout << "Queue is full.";
            return;
        }
        if(isEmpty()){
            frontIdx = 0;
            rearIdx = 0;
        }else{
            rearIdx++;
        }
        
        arr[rearIdx] = element;
        
    
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        if (frontIdx == rearIdx) {
            frontIdx = -1;
            rearIdx = -1;
        } else {
            frontIdx++;
        }
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[frontIdx];
    }
};

double findQueueAverage(Queue& q) {
    //Type your code here
    
    if(q.isEmpty()){
        return 0.0;
    }
    
    double sum;
    int count = q.rearIdx - q.frontIdx + 1;
    
    for(int i = q.frontIdx; i <= q.rearIdx; i++){
        sum += q.arr[i];
    }
    
    return sum / count;
    
}

int main() {
    Queue q;
    int n;

    cin >> n;

    if (n == 0) {
        cout << "Queue is empty." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        q.enqueue(element);
    }

    double average = findQueueAverage(q);

    cout << fixed << setprecision(2) << average << endl;

    return 0;
}



// Question 2
#include <iostream>
#define max 5

int insertq(int queue[max], int& front, int& rear, int data) {
    if (rear == max - 1) {
        return 0;
    }
    if (front == -1) {
        front = 0;
    }
    if (rear == -1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
    return 1;
}

int delq(int queue[max], int& front, int& rear, int& data) {
    if (front == -1) {
        return 0;
    }
    data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return 1;
}

void display(int queue[max], int front, int rear) {
    if (front == -1) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    std::cout << "Elements in the queue are: ";
    for (int i = front; i <= rear; i++) {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int queue[max], data;
    int front, rear, reply, option;
    front = rear = -1;

    while (true) {
        if (!(std::cin >> option))
            break;

        if (option == 4) {
            std::cout << "Exiting the program" << std::endl;
            return 0;
        }

        switch (option) {
            case 1:
                if (!(std::cin >> data))
                    break;

                reply = insertq(queue, front, rear, data);
                if (reply == 0)
                    std::cout << "Queue is full" << std::endl;
                else
                    std::cout << data << " is inserted in the queue" << std::endl;
                break;

            case 2:
                reply = delq(queue, front, rear, data);
                if (reply == 0) {
                    std::cout << "Queue is empty" << std::endl;
                } else {
                    std::cout << "Deleted number is: " << data << std::endl;
                }
                break;

            case 3:
                display(queue, front, rear);
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
using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int arr[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == MAX_SIZE);
    }

    void enqueue(int element, int priority) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }

        arr[size] = element;
        priorities[size] = priority;
        size++;

        
        for (int i = size - 1; i > 0; i--) {
            if (priorities[i] < priorities[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swap(priorities[i], priorities[i - 1]);
            } else {
                break;
            }
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
            priorities[i] = priorities[i + 1];
        }
        size--;
    }

    void printPriorityQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int element, priority;
        cin >> element;
        cin >> priority;
        pq.enqueue(element, priority);
    }

    pq.printPriorityQueue();

    pq.dequeue();

    pq.printPriorityQueue();

    return 0;
}


// Question 4
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_PATIENTS = 100;

struct Patient {
    int priority;
    char name[100];
};

struct PriorityQueue {
    int size;
    Patient patients[MAX_PATIENTS];
};

bool queue_is_empty(PriorityQueue* queue) {
    return queue->size == 0;
}

void push(PriorityQueue* queue, int priority, char name[]) {
    if (queue->size == MAX_PATIENTS) {
        cout << "Queue is full." << endl;
        return;
    }

    int i = queue->size;
    queue->patients[i].priority = priority;
    strcpy(queue->patients[i].name, name);
    queue->size++;

    while (i > 0 && queue->patients[i].priority < queue->patients[i - 1].priority) {
        swap(queue->patients[i], queue->patients[i - 1]);
        i--;
    }
}

void pop(PriorityQueue* queue) {
    if (queue_is_empty(queue)) {
        cout << "Error: Queue is empty." << endl;
        return;
    }

    cout << "Patient with priority " << queue->patients[0].priority << " and name " << queue->patients[0].name << " has been treated." << endl;

    for (int i = 0; i < queue->size - 1; i++) {
        queue->patients[i] = queue->patients[i + 1];
    }
    queue->size--;
}

int main() {
    PriorityQueue queue;
    queue.size = 0;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            int priority;
            char name[100];
            cin >> priority;
            cin >> name;
            push(&queue, priority, name);
        } else if (choice == 2) {
            pop(&queue);
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
