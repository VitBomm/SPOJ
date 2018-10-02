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
    int n,exit,time,query;
    cin>>n>>exit>>time>>query;
    graph = vector<vector<pair<int, int>>> (MAX + 5, vector<pair<int, int>>());
    dist = vector<int>(MAX,INF);
    int a,b,w;
    for(int i = 0; i <query; i++)
    {
        cin>>a;
        cin>>b;
        cin>>w;

            graph[b].push_back(pair<int, int>(a,w));
    }
    Dijkstra(exit);
    int count = 0;
    for(int i = 1 ; i<=n;i++)
    {
        if(dist[i] <= time)
        {
            count++;
        }
    }
    cout<<count;
    
    return 0;
}
