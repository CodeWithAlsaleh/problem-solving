class Solution {
    // Using prime sieve
    vector<int> getPrimes(int n) {
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;

        for(int p = 2; p * p <= n; ++p) {
            if(primes[p]) {
                for(int i = p * p; i <= n; i += p)
                 primes[i] = 0;
            }
        }

        return primes;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<int> primes = getPrimes(33);

        for(int i = left; i <= right; ++i) {
            // This fun will give us the number of set bits in any value we pass to it
            if(primes[__builtin_popcount(i)])
             ans++;
        }

        return ans;
    }
};
