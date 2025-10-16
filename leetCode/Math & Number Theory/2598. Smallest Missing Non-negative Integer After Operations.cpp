class Solution {
    int mod(double a , double b) {
        return a - b * floor(a / b);
    }
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // u can reach x from num[i] if (x = num[i] % k)
        int ans = 0;
        unordered_map<int,int> mp;

        for(auto &it : nums)
         mp[mod(it , value)]++;

        for(int i = 0 ; i <  nums.size() ; ++i) {
            if(mp[ans]) {
                mp[ans + value] += mp[ans] - 1;
                ans++;
            }
            else
             break;
        }

        return ans;
    }
};
