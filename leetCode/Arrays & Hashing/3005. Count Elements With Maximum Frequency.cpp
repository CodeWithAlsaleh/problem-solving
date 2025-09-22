class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx = 0;

        for(auto &it : nums) {
            mp[it]++;
            mx = max(mx , mp[it]);
        }

        int sum = 0;

        for(auto &[a,b] : mp) {
            if(b == mx)
             sum += mx;
        }

        return sum;
    }
};
