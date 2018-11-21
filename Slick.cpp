#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAX 253
using namespace std;
int maze[MAX][MAX];
bool visited[MAX][MAX];
const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};
int w,h;
struct Cell
{
    int r;
    int c;
    bool operator ==(const Cell &other)
    {
        return r == other.r && c == other.c;
    }
};
bool IsValid(int r, int c)
{
    return r >= 0 && r< h && c>=0 && c<w;
}
int BFS(Cell s)
{
    int dem = 1;
    queue<Cell> q;
    q.push(s);
    visited[s.r][s.c] = true;
    while(!q.empty())
    {
        Cell u = q.front();
        q.pop();
        for(int i = 0 ; i< 4;i++)
        {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if(!visited[r][c] && maze[r][c] == 1 && IsValid(r,c))
            {
                visited[r][c] = true;
                q.push((Cell){r,c});
                dem++;
            }
        }
    }
    return dem;
}
int main()
{
    while(true)
    {
        map<int,int> mapp;
        cin>>h>>w;
        if(w==0 && h ==0)
        {
            break;
        }
        for(int i = 0 ;i<h;i++)
        {
            for(int j = 0;j<w;j++)
            {
                cin>>maze[i][j];
            }
        }
        for(int i = 0 ;i<h;i++)
        {
            for(int j = 0;j<w;j++)
            {
                visited[i][j] = false;
            }
        }
        int countt = 0;
        for(int i = 0 ;i<h;i++)
        {
            for(int j = 0;j<w;j++)
            {
                if(maze[i][j] == 1 && visited[i][j] == false)
                {
                    int temp = BFS((Cell){i,j});
                    mapp[temp]++;
                    countt++;
                }
            }
        }
        map<int,int>::iterator it;
        cout<<countt<<endl;
        for(it = mapp.begin(); it!= mapp.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
    return 0;
}
