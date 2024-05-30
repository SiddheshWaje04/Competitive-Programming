#include <bits/stdc++.h>
using namespace std;
#define int long long

template <class T>
class fenwick_tree
{
private:
    vector<T> t;
    int N; // Size of the array

public:
    // Constructor to initialize the fenwick tree with size N
    fenwick_tree(int size)
    {
        N = size;
        t.resize(N + 1); // Resize vector to hold values from 1 to N
    }

    // Find the sum of values in range `[1, i]`
    T sum(int i)
    {
        T res = 0;
        while (i)
        {
            res += t[i];
            i -= (i & -i);
        }
        return res;
    }

    // Add `val` to element at `i` (1-based)
    void add(int i, const T &val)
    {
        while (i <= N)
        {
            t[i] += val;
            i += (i & -i);
        }
    }

    // Get sum of range [l, r]
    T range_sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

signed main()
{
    int N = 10; // Example size of array
    fenwick_tree<int> f(N);

    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array (0-indexed, first element unused)

    // Populate the Fenwick Tree with initial array values
    for (int i = 1; i <= N; ++i)
    {
        f.add(i, arr[i]);
    }

    // Example usage:
    // Sum of first 5 elements
    cout << "Sum of first 5 elements: " << f.sum(5) << endl;

    // Sum of elements from index 3 to 7
    cout << "Sum of elements from 3 to 7: " << f.range_sum(3, 7) << endl;

    // Update element at index 4 (1-based index) by adding 5
    f.add(4, 5);
    cout << "Sum of elements from 3 to 7 after updating index 4: " << f.range_sum(3, 7) << endl;

    return 0;
}
