#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define MAX 10005
const int INF = 1e9;
using namespace std;
vector<vector<pair<long long int, long long int>>> graphs, grapht;
vector<long long int> dists(MAX,INF);
vector<long long int> distt(MAX,INF);
long long int path[MAX];
struct option
{
    bool operator()(const pair<long long int, long long int> &a, const pair<long long int,long long int> &b)
    {
        return a.second > b.second;
    }
};
void Dijtrans(long long int s,vector<long long int> &disttemp,vector<vector<pair<long long int, long long int>>> &graphtemp)
{
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,option> pq;
    pq.push(make_pair(s, 0));
    disttemp[s] = 0;
    while(!pq.empty())
    {
        pair<long long int,long long int> top = pq.top();
        pq.pop();
        long long int u = top.first;
        long long int w = top.second;
        for(int i = 0 ; i < graphtemp[u].size();i++)
        {
            pair<long long int,long long int> neighbor = graphtemp[u][i];
            if(w+ neighbor.second < disttemp[neighbor.first])
            {
                disttemp[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, disttemp[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}

int main()
{

    long long int q,n,m,s,t,k;
    long long int a,b,c;
    cin>>q;
    while (q--) {
        cin>>n>>m>>k>>s>>t;
        graphs = vector<vector<pair<long long int,long long int>>>(MAX+5, vector<pair<long long int,long long int>>());
        grapht = vector<vector<pair<long long int,long long int>>>(MAX+5, vector<pair<long long int,long long int>>());
        dists = vector<long long int>(n+1,INF);
        distt = vector<long long int>(n+1,INF);
        for(int i = 0 ; i <m;i++)
        {
            cin>>a>>b>>c;
            graphs[a].push_back(pair<long long int,long long  int>(b,c));
            grapht[b].push_back(pair<long long int,long long int>(a,c));
        }
        Dijtrans(s, dists,graphs);
        Dijtrans(t, distt, grapht);
        long long int temp = INF;
        for(int i = 0; i<k;i++)
            {
                cin>>a>>b>>c;
                temp = min(dists[t], min(temp, c+min(dists[a]+distt[b],dists[b]+distt[a])));
            }
        if(temp == INF)
            {
                cout<<-1<<endl;
            }
        else
            {
                cout<<temp<<endl;
            }
    }
    return 0;
}
