#define all(x) x.begin() , x.end()
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Idea: we want to calc the longest consecutive subarray of the maxValue in nums
        int mx = *max_element(all(nums));

        int mxCnt = 0;
        int cnt = 0;

        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(nums[i] == mx)
                cnt++;
            else
            {
                mxCnt = max(mxCnt , cnt);
                cnt = 0;
            }
        }
        mxCnt = max(mxCnt , cnt);

        return mxCnt;
    }
};
