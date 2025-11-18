#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000000;

int findMinIndex(queue<int>& q, int sortedIndex) {
    int min_index = -1;
    int min_val = INF;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (curr <= min_val && i <= sortedIndex) {
            min_val = curr;
            min_index = i;
        }

        q.push(curr);
    }
    return min_index;
}

void moveMinToRear(queue<int>& q, int min_index) {
    int min_val;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == min_index)
            min_val = curr;
        else
            q.push(curr);
    }
    q.push(min_val);
}

void sortQueue(queue<int>& q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int min_index = findMinIndex(q, n - 1 - i);
        moveMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
