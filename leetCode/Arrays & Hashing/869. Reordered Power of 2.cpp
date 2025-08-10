class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> mp(10 , 0);
        addDigits(mp , n);

        for(int i = 0 ; i < 31 ; ++i)
        {
            int val = pow(2 , i);
            if(checkNum(mp , val))
             return true;
        }

        return false;
    }

    void addDigits(vector<int> &mp , int val) {
        while(val) {
            mp[val % 10]++;
            val /= 10;
        }
    }

    bool checkNum(vector<int> &mp , int val) {
        vector<int> checkMp(10 , 0);
        addDigits(checkMp , val);
        return mp == checkMp;
    }
};
