#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void KMPPreprocess(string p, vector<int>& kmp)
{
    kmp[0] = 0;
    int m = p.length();
    int j = 0;
    
    int i = 1;
    while (i < m)
    {
        if (p[i] == p[j])
        {
            j++;
            kmp[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = kmp[j - 1];
            }
            else
            {
                // if (j == 0)
                kmp[i] = 0;
                i++;
            }
        }
    }
}
//void KMPSearch(string t, string p, vector<int> kmp)
//{
//    int n = t.length();
//    int m = p.length();
//    int result = 0;
//    int i = 0, j = 0;
//    while (i < n)
//    {
//        if (p[j] == t[i])
//        {
//            j++;
//            i++;
//        }
//        //to be continued
//        if (j == m)
//        {
//            cout << (i - j)+1 <<endl;
//            j = kmp[j - 1];
//        }
//        else if (i < n && p[j] != t[i])
//        {
//            if (j != 0)
//            {
//                j = kmp[j - 1];
//            }
//            else
//            {
//                i = i + 1;
//            }
//        }
//    }
//}
int main()
{
    ios_base::sync_with_stdio(false);
    string t, p;
    int result =0;
    while (cin>>p) {
        if(p == "*")
            return 0;
        result = 1;
        vector<int> kmp(p.length());
        KMPPreprocess(p,kmp);
        int len = p.length();
        int sub = len-kmp[len-1];
        if(sub<len && len%sub == 0)
        {
            result = len/sub;
        }
        cout<<result<<endl;
        
    }
    return 0;
}
