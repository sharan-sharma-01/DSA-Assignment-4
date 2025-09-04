#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(6);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
