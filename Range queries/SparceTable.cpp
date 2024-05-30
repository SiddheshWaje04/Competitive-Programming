#include <bits/stdc++.h>
using namespace std;
#define int long long
class SparseTable
{
public:
    int **table;
    int LOGN;
    int size;

    int func(int a, int b)
    {
        return max(a, b);
    }

    SparseTable(vector<int> a)
    {
        int n = a.size();
        size = n;
        LOGN = 31 - __builtin_clz(n);
        table = new int *[LOGN + 1];

        table[0] = new int[n];
        for (int j = 0; j < n; j++)
        {
            table[0][j] = a[j];
        }

        for (int i = 1; i <= LOGN; i++)
        {
            int p = (1 << i);
            table[i] = new int[n - p + 1];
            for (int j = 0; j < n - p + 1; j++)
            {
                table[i][j] = func(table[i - 1][j], table[i - 1][j + (p >> 1)]);
            }
        }
    }

    int query(int l, int r)
    {
        int k = 31 - __builtin_clz(r - l + 1);
        return func(table[k][l], table[k][r - (1 << k) + 1]);
    }
    void display()
    {
        for (int i = 0; i <= LOGN; i++)
        {
            cout << '{';
            for (int j = 0; j < size - (1 << i) + 1; j++)
            {
                cout << table[i][j] << ",}"[j == size - (1 << i)];
            }
            cout << '\n';
        }
    }
};
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> a((int)s.size() + 1, 0);
        map<int, vector<int>> mp;
        for (int i = 1; i <= (int)s.size(); i++)
        {
            int k = a[i - 1];
            if (s[i - 1] == '(')
            {
                a[i] = k + 1;
            }
            else
            {
                a[i] = k - 1;
            }
            mp[a[i]].push_back(i);
        }
        SparseTable st(a);

        // for (int i = 0; i < a.size(); i++)
        //     cout << a[i] << " ";
        // cout << endl;

        // cout << st.query(0, 1) << endl;
        // cout << st.query(0, 2) << endl;
        int ct = 0, ans = 0;
        for (auto k : mp)
        {
            // for (auto p : k.second)
            //     cout << p << " ";
            // cout << endl;
            ct = 0;
            if (k.first != 0)
            {
                for (int i = 1; i < k.second.size(); i++)
                {
                    if (st.query(k.second[i - 1], k.second[i]) <= 2 * a[k.second[i - 1]])
                    {
                        ct++;
                    }
                    else
                    {
                        ct = 0;
                    }
                    ans += ct;
                    // cout << k.first << " " << ct << " " << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }
}