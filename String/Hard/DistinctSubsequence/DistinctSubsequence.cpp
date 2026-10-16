#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();

        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;  // One way to form an empty string.

        for (char ch : s)
        {
            // Go backward so one character from s is used only once.
            for (int j = n - 1; j >= 0; j--)
            {
                if (ch == t[j]) 
                {
                    dp[j + 1] += dp[j];
                }
            }
        }

        return dp[n];
    }
};
    