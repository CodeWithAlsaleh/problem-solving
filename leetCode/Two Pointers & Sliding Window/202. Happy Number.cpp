class Solution {
public:
    bool isHappy(int n) {
        // This is also can be solved using Floyd’s cycle-finding (tortoise & hare)
        // which is the same as fast & slow pointers
        bool flag = true;
        int it = 1e2;
        while(it--) {
            int temp = getModifiedNumber(n);

            if(temp == 1)
             return true;

            n = temp;
        }

        return false;
    }

    int getModifiedNumber(int val) {
        int ans = 0;

        while(val) {
            int digit = val % 10;
            val /= 10;

            ans += digit * digit;
        }

        return ans;
    }
};

// Code for fast & slow pointers:

class Solution {
public:
    bool isHappy(int n) {
       int slow = n , fast = n;

       do {
        slow = getModifiedNumber(slow); // move slow by 1
        fast = getModifiedNumber(getModifiedNumber(fast)); // move fast by 2
       } while(slow != fast);

       return slow == 1;
    }

    int getModifiedNumber(int val) {
        int ans = 0;

        while(val) {
            int digit = val % 10;
            val /= 10;

            ans += digit * digit;
        }

        return ans;
    }
};
