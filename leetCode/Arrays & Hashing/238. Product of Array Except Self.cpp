class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 0);
        int mul = 1;

        // Count the number of zeros in nums
        int zeroCnt = 0;
        for (auto &it : nums) 
        {
            if (it == 0)
                zeroCnt++;
        }

        // If there are more than 1 zero
        // return an array of zeros
        if (zeroCnt > 1)
            return ans;

        // Calc the product of all non-zero elements
        for (auto &it : nums) 
        {
            if (it != 0)
                mul *= it;
        }

        // If there is exactly 1 zero only the index
        // with zero gets the product of non-zero elements
        if (zeroCnt == 1) 
        {
            for (int i = 0; i < len; ++i)
            {
                if (nums[i] == 0)
                {
                    ans[i] = mul;
                    break;
                }
            }

            return ans;
        }

        // If there are no zeros each index gets (mul / nums[i])
        for (int i = 0; i < len; ++i)
            ans[i] = mul / nums[i];

        return ans;
    }
};
