#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isPrime(int num)
{
    // Handle special cases: 0 and 1 are not prime
    if (num <= 1)
    {
        return false;
    }

    // Efficiently check divisibility up to the square root of num
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    // If no divisors found, num is prime
    return true;
}

signed main()
{
}