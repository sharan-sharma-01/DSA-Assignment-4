#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    int n = q.size();
    int* st = new int[n];
    int top = -1;
    int expected = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == expected)
            expected++;
        else {
            if (top != -1 && st[top] < x) {
                cout << "No";
                return 0;
            }
            st[++top] = x;
        }
    }

    while (top != -1) {
        if (st[top] != expected) {
            cout << "No";
            return 0;
        }
        top--;
        expected++;
    }

    cout << "Yes";
    return 0;
}
