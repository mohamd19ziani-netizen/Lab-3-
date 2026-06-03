#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int x, y, dist;
};

int main() {

    cout << "Author: зиани мохаммед" << endl;
    cout << "Group: 090304-РПИа-о25" << endl;

    string start, finish;

    cin >> start >> finish;

    int sx = start[0] - 'A';
    int sy = start[1] - '1';

    int fx = finish[0] - 'A';
    int fy = finish[1] - '1';

    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    bool visited[8][8] = {};

    queue<Node> q;

    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == fx && cur.y == fy) {
            cout << "Minimum moves: "
                 << cur.dist
                 << endl;
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < 8 &&
                ny >= 0 && ny < 8 &&
                !visited[nx][ny]) {

                visited[nx][ny] = true;
                q.push({nx, ny, cur.dist + 1});
            }
        }
    }

    return 0;
}
