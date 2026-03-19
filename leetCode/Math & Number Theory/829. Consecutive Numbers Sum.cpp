// The ans is the number of odd divisors of N
class Solution {
    int getAns(int n) {
        int ans = 0;

        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                if(i & 1)
                 ans++;

                if(n / i != i and (n / i) & 1)
                 ans++;
            }
        }

        return ans;
    }
public:
    int consecutiveNumbersSum(int n) {
        return getAns(n);
    }
};

// Also another sol based on a mathematical formula => x = (n - sum(k - 1)) % k and x must be an integer
// where x => starting point and k => number of consecutive elements
// => n = x + x + 1 + x + 2 + x + 3 + x + 4 (k here equals to 5)
// => n = k * x + sum(k - 1)
// x = x = (n - sum(k - 1)) / k => since we want x to be a pos integer we can just use (n - sum(k - 1)) % k and check is the rem is 0
class Solution {
    int getSum(int n) {
        return n * (n + 1) / 2;
    }
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;

        for(int i = 1; getSum(i - 1) < n; ++i) {
            int check = (n - getSum(i - 1)) % i;

            if(!check)
             ans++;
        }

        return ans;
    }
};
