#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <map>
#include <iterator>
#define MAX 10005
const int INF = 1e9;
using namespace std;
vector<vector<pair<int,int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct option
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
    
};
void Dijkstra(int s)
{
    priority_queue<pair<int, int>,vector<pair<int,int>>,option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        for(int i = 0; i < graph[u].size();i++)
        {
            pair<int, int> neighbor = graph[u][i];
            if(w+neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}
int main()
{
    int Q,n;
    cin>>Q;
    while (Q--) {
        // NOTE
        cin>>n;
        map<string,int> mapp;
        map<string,int>::iterator it;
        graph = vector<vector<pair<int, int>>> (MAX + 5, vector<pair<int, int>>());
        string a;
        int m,b,c;
        for(int i = 1;i<=n; i++)
        {
            cin>>a;
            mapp[a] = i;
            cin>>m;
            for(int j = 0; j <m;j++)
            {
                cin>>b;
                cin>>c;
                graph[i].push_back(pair<int, int>(b,c));
            }
        }
        int rs;
        cin>>rs;
        string name1,name2;
        while(rs--)
        {
            cin>>name1>>name2;
            it = mapp.find(name1);
            dist = vector<int>(MAX,INF);
            Dijkstra(it->second);
            it = mapp.find(name2);
            cout<<dist[it->second]<<endl;
        }
    }
    return 0;
}
