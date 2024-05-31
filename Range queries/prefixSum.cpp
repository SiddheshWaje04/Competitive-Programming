// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#include <vector>

struct PrefixSum
{
    std::vector<int> pre_sum;

    PrefixSum(const std::vector<int> &arr) : pre_sum(arr.size() + 1, 0)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            pre_sum[i + 1] = pre_sum[i] + arr[i];
        }
    }

    // Query function to get the sum in the range [l, r] (inclusive)
    int query(int l, int r) const
    {
        if (0 <= l && l <= r && r < pre_sum.size())
        {
            return pre_sum[r + 1] - pre_sum[l];
        }
        else
        {
            throw std::out_of_range("Invalid query range");
        }
    }
};

// Example usage
signed main()
{
    std::vector<int> arr = {1, 3, 5, 7, 2};
    PrefixSum ps(arr);

    // Get sum in range [2, 4]
    int sum = ps.query(2, 4);
    std::cout << "Sum in range [2, 4]: " << sum << std::endl; // Output: 15

    // Get sum in range [0, 3]
    sum = ps.query(0, 3);
    std::cout << "Sum in range [0, 3]: " << sum << std::endl; // Output: 16

    return 0;
}
