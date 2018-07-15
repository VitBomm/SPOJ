#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n = 0;
    while (true) {
        cin>>n;
        stack<int>  s;
        queue<int> q1;
        if( n == 0)
        {
            break;
        }
        for(int i = 0; i< n; i++)
        {
            int a;
            cin>>a;
            q1.push(a);
        }
        bool kt = true;
        int index = 1;
        for(int i = 0; i<n;i++)
        {
            while (s.size() >0 && s.top() == index) {
                index++;
                s.pop();
            }
            if(q1.front() == index)
            {
                index++;
                q1.pop();
            }
            else if(s.size() > 0 && s.top() < q1.front())
            {
                kt = false;
                break;
            }
                else
                {
                    s.push(q1.front());
                    q1.pop();
                }
        }
        if(kt) cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
