class Solution {
    const int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long ans = 0, bits = 0;
    
        for(int i = 1; i <= n; ++i) {
            if((i & (i - 1)) == 0)
             bits++;

            ans <<= bits;
            ans |= i;
            ans %= MOD;
        }

        return ans;
    }
};
