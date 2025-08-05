class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Just a simple 2D dp recursive approach (can be optimized to 1D but i don't know how)
        unordered_map<int,unordered_map<int,int>> dp(nums.size());
        return recursion(0 , nums , dp ,0 , target);
    }

    int recursion(int i , vector<int>& nums , unordered_map<int,unordered_map<int,int>> &dp , int sum , int &target) {
        if(i == nums.size())
         return sum == target ? 1 : 0;

        if(dp[i].find(sum) != dp[i].end())
         return dp[i][sum];

        
        int neg = recursion(i + 1 , nums , dp ,sum - nums[i] , target);
        int pos = recursion(i + 1 , nums , dp , sum + nums[i] , target);

        return dp[i][sum] = neg + pos;
    }
};
