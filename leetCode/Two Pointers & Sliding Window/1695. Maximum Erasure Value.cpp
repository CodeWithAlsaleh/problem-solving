class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int L = 0, sum = 0, ans = 0;

        for (int R = 0; R < nums.size(); ++R) 
        {
            sum += nums[R];
            mp[nums[R]]++;

            // Remove from left until uniqueness is restored
            while (mp[nums[R]] > 1)
            {
                sum -= nums[L];
                mp[nums[L]]--;
                L++;
            }

            ans = max(ans, sum);
        }
        
        return ans;
    }
};
