#include <iostream>
#include <queue>
#define N 5
using namespace std;

int maze[N][N] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0}
};
int visited[N + 1] = {0,};

void BFS(int start) {
    queue<int>  Q;
    Q.push(start);
    visited[start -1] = 1;
    cout << "BFS: ";
    while (!Q.empty()) {
        int front = Q.front();
        cout << front << " ";
        Q.pop();
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && maze[front -1][i] == 1) {
                Q.push(i + 1);
                visited[i] = 1;
            }
        }

    }
    cout << endl;
}

int main() {
    // for (int i = 1; i <= N; ++i) {

    // }
    BFS(1);
}