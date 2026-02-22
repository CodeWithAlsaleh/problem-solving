class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> mp;
        int ans = 0;

        /*
           Why hashing using bitmask works fine here ?
           cuz int => 32 bit and the number of english
           lowercase is 26, so if we set all bits for
           each char in the cur word we won't get int
           overflow
        */

        for(auto &it : words) {
            int mask = 0;

            for(auto &ch : it)
             mask |= (1 << (ch - 'a'));

            ans += mp[mask];
            mp[mask]++;
        }

        return ans;
    }
};
