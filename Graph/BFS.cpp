#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    vector<vector<int>> adj;
    int n;
    int s;

    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    used[s] = true;
    q.push(s);
    d[s] = 0;
    p[s] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    int u;
    if (!used[u])
    {
        cout << "No path!";
    }
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}