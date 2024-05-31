// If lo has the answer keep hi = possble answers + 1
// In case of Predicate function 000001111111111111.. keeping hi as high as possible will work
// because hi as the answer but lo should be possible answer - 1 for the case 11111...
// If hi has the answer keep lo = possible answers - 1
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool func()
{
}
signed main()
{
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (func())
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
}