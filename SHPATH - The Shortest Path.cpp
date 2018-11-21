#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 10005
const int INF = 10e9;
using namespace std;
vector<vector<pair<int,int> > > graph;
vector<int> dist(MAX,INF);
struct option
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second > b.second;
    }
};
void Dijstras(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int> > , option> pq;
    pq.push(make_pair(s,0));
    dist[s] = 0;
    while(!pq.empty())
    {
        pair<int,int> top = pq.top();
        int u = top.first;
        int w = top.second;
        pq.pop();
        for(int i = 0 ; i < graph[u].size();i++)
        {
            pair<int,int> neighbor = graph[u][i];
            if(w + neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first,dist[neighbor.first]));

            }
        }
    }
}
int main()
{
    int T,e,a,b;
    cin>>T;
    while(T--)
    {
        int n;
        map<string,int> mapp;
        graph = vector<vector<pair<int,int> > >(MAX,vector<pair<int,int> >());
        dist = vector<int>(MAX,INF);
        cin>>n;
        string city;
        for(int i = 1 ; i<=n;i++)
        {
            cin>>city;
            mapp[city] = i;
            cin>>e;
            for(int j = 0; j<e;j++)
            {
                cin>>a>>b;
                graph[i].push_back(make_pair(a,b));
            }
        }
        cin>>e;
        string city1,city2;
        while(e--)
        {
            cin>>city1>>city2;
            dist = vector<int>(MAX,INF);
            Dijstras(mapp[city1]);
            cout<<dist[mapp[city2]]<<endl;
        }
    }
    return 0;
}
