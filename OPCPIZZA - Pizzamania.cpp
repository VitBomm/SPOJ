#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;
int t,n,m,e;
int countout;
vector<int> v;
int i,j;
int Check(vector<int> v,int _n,int sizez)
{
    i = 0;
    countout =0;
    j = sizez-1;
    while(i<j)
    {
        if(v[i]+v[j] == _n)
        {
            countout++;
            i++;
            j--;
        }
        else if (v[i]+v[j] < _n)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return countout;
}
int main()
{
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        v = vector<int>();
        cin>>n>>m;
        for(int j = 0;j<n;j++)
        {
            cin>>e;
            v.push_back(e);
        }
        sort(v.begin(),v.end());
        cout<<Check(v,m,v.size())<<endl;
    }
    return 0;
}
