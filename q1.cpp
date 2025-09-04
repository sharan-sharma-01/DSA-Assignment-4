#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "1 Enqueue 2 Dequeue 3 Display 4 Peek 5 Exit\n";
        cin >> choice;
        if (choice == 1) {
            cin >> val;
            q.enqueue(val);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            q.display();
        } else if (choice == 4) {
            q.peek();
        }
    } while (choice != 5);
    return 0;
}
