#include <iostream>
#include <stack>
#define N 5
using namespace std;

int maze[N][N] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0},
    {1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0}
};

int visited[N] = {0,};

void DFS(int start) {
    int start_index = start -1;
    visited[start_index] = 1;

    for (int i = 0; i < N; ++i) {
        if (!visited[i] && maze[start_index][i] == 1) {
            // visited[i] = 1;
            DFS(i + 1);
        }
    }
    cout << start << " ";
}

void DFS_STACK(int start) {
    int start_index = start -1;
    stack<int> s;
    s.push(start_index);
    visited[start_index] = 1;

    while (!s.empty()) {
        bool push_flag = false;
        int node = s.top();
        
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && maze[node][i] == 1) {
                s.push(i);
                visited[i] = 1;
                push_flag = true;
                break;
            }
        }

        if (!push_flag) {
            cout << node + 1 << " ";
            s.pop();

        }
    }
}

int main() {
    // DFS(1);
    DFS_STACK(1);
}

 