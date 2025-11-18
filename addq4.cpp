#include <iostream>
#include <queue>
using namespace std;

int main() {
    int studentsArr[] = {1, 1, 0, 0};
    int sandwichesArr[] = {0, 1, 0, 1};

    int n = 4;
    queue<int> q;

    for (int i = 0; i < n; i++)
        q.push(studentsArr[i]);

    int top = 0;
    int count = 0;

    while (!q.empty() && count < q.size()) {
        int s = q.front();
        q.pop();

        if (s == sandwichesArr[top]) {
            top++;
            count = 0;
        } else {
            q.push(s);
            count++;
        }
    }

    cout << q.size();
    return 0;
}
