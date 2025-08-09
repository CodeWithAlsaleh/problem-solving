class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
         return false;

        int mx = pow(2 , 30);

        return mx % n == 0;
    }
};
