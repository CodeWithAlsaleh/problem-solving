class Solution {
    const int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        /*
            Concatenating a number with another is the same as shfiting the number left by the number of bits for
            the new number and using OR bitwise operator => 1, 2 => (1, 10) => (1 << 2) => 100 => (100 | 10) => 110

            The number of bits gorws as a pow of 2 => whenever we find a value which is a power of two we increase
            the number of bits => to check of this number is a power of two => we can use this formula (i & (i - 1))
        */
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
