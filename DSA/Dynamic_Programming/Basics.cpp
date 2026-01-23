#include <bits/stdc++.h>
using namespace std;

/*
Dynamic Programming (DP)

DP ke mainly do approaches hote hain:

1) Top-Down Approach
   - Recursion + memoisation use hota hai
   - Jo values pehle calculate ho chuki hoti hain,
     unhe dp array me store kar lete hain

2) Bottom-Up Approach
   - Tabulation use hoti hai
   - Loop ke through base cases se answer build karte hain

--------------------------------------------------

DP ko hum Fibonacci series se samajhte hain:
f(0) = 0
f(1) = 1
f(n) = f(n-1) + f(n-2)

--------------------------------------------------

DP ki zarurat kyun hoti hai?
Normal recursion me same values baar-baar calculate hoti hain,
jis se time complexity badh jaati hai. DP me hum results ko
store kar lete hain aur dobara calculate nahi karte.

--------------------------------------------------
*/

// Bottom-Up (Tabulation)
int fibo2(int n, vector<int>& dp) {
    if (n <= 1) return n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Top-Down (Memoisation)
int fibo(int n, vector<int>& dp) {
    if (n <= 1) return dp[n] = n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter the Nth term of the Fibonacci series" << endl;
    cin >> n;

    vector<int> dp(n + 1, -1);

    // Bottom-up approach use kiya hai
    int ans = fibo2(n, dp);
    cout << ans << endl;

    return 0;
}
