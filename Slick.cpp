
#include <iostream>
#include <queue>
#define MAX 251
using namespace std;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int w,h;
int dem=1;
bool visited[MAX][MAX];
int maze[MAX][MAX];
vector<int> v;
struct Cell {
    int r, c;
    bool operator == (const Cell &other) {
        return r == other.r && c == other.c;
    }
};

bool isValid(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

int BFS(Cell s) {
    dem = 1;
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if (isValid(r, c) && maze[r][c] == 1 && !visited[r][c]) {
                visited[r][c] = true;
                q.push((Cell) {r, c});
                dem++;
            }
        }
    }
    
    return dem;
}

int main() {
    while (true) {
         v = vector<int>(MAX*MAX,0);
        cin>>h>>w;
        if(h==0 && w==0)
        {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j =0; j<w; j++) {
                cin>>maze[i][j];
            }
        }
        Cell start;
        for (int i = 0; i<h; i++) {
            for (int j = 0; j<w; j++) {
                visited[i][j] = false;
            }
        }
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(maze[i][j]== 1 && visited[i][j] == false)
                {
                    start.r = i;
                    start.c = j;
                    int temp = BFS(start);
                    v[temp]++;
//                    cout<<temp<<"\t";
                    count++;
                }
            }
        }
        cout<<count<<endl;
        for(int i = 1; i<MAX*MAX;i++)
            {
                if(v[i]!=0)
                    {
                        cout<<i<<" "<<v[i]<<endl;
                    }
            }
    }
    return 0;
}
