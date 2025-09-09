class Solution {
    int MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n , 0);
        dp[0] = 1;

        for(int i = 1 ; i < n ; ++i)
        {
            int ind = i - delay;
            int ind2 = i - forget;
            dp[i] = dp[i-1];

            int val = 0;

            if(ind2 >= 0)
             val = dp[ind2];

            if(i == forget) 
             dp[i] = getMod(dp[i] - val);

            if(ind >= 0)
                dp[i] = getMod(getMod(dp[i] + dp[ind]) - val);
        }

        return getMod(dp[n-1]);
    }

    int getMod(int n) {
        return n - MOD * floor(double(n) / MOD);
    }
};
