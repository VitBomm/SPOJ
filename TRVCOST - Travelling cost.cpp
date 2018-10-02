#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define MAX 501
const int INF = 1e9;
using namespace std;
vector<vector<pair<int,int>>> graph;
//vector<vector<pair<int, int> > > graph;
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
    int n;
    cin>>n;
    graph = vector<vector<pair<int, int>>> (MAX + 5, vector<pair<int, int>>());
    dist = vector<int>(MAX,INF);
    int a,b,w;
    for(int i = 0; i <n; i++)
    {
        cin>>a;
        cin>>b;
        cin>>w;

            graph[a].push_back(pair<int, int>(b,w));
            graph[b].push_back(pair<int, int>(a,w));
    }
    int u;
    cin>>u;
    int q;
    cin>>q;
    Dijkstra(u);
    int e1;
    for(int i = 0 ; i <q;i++)
    {
        cin>>e1;
        if(dist[e1] == INF)
        {
            cout<<"NO PATH"<<endl;
        }
        else
        {
        cout<<dist[e1]<<endl;
        }
    }
    
    return 0;
}
