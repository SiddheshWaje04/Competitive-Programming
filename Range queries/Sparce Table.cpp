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
int main()
{
}