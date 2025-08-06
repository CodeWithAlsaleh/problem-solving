class Solution {
public:
    bool isPowerOfThree(int n) {
        // U can use math trick which is check if 3^19 % n == 0
        // if it's equal to 0 then the number is a power of 3
        // cuz 3^19 is the largest number within the given constraint

        if(n <= 0)
         return false;

        int st = 0, en = 19;

        while(st <= en)
        {
            int md = st + (en - st) / 2;
            int val = pow(3 , md);

            if(val == n)
             return true;

            if(val < n)
             st = md + 1;
            else
             en = md - 1;
        }

        return false;
    }
};
