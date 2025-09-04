#include <iostream>
using namespace std;

#define MAX 100

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == MAX-1) || (rear == (front-1)%(MAX-1)); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX-1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX-1) {
            front = 0;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        } else {
            for (int i = front; i < MAX; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << arr[front] << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, val;
    do {
        cout << "1 Enqueue 2 Dequeue 3 Display 4 Peek 5 Exit\n";
        cin >> choice;
        if (choice == 1) {
            cin >> val;
            cq.enqueue(val);
        } else if (choice == 2) {
            cq.dequeue();
        } else if (choice == 3) {
            cq.display();
        } else if (choice == 4) {
            cq.peek();
        }
    } while (choice != 5);
    return 0;
}
