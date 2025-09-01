// using deque Trick
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        int ind = 0;
        deque<pair<int,int>> dq;

        for(int i = 0 ; i < k ; ++i)
        {
            while(!dq.empty() and dq.back().first < nums[i])
             dq.pop_back();

            dq.push_back(make_pair(nums[i] , i));
        }

        ans[ind++] = dq.front().first;

        for(int i = k ; i < nums.size() ; ++i)
        {
            while(!dq.empty() and dq.back().first < nums[i])
             dq.pop_back();

            dq.push_back(make_pair(nums[i] , i));

            if(dq.front().second < i - k + 1)
             dq.pop_front();

            ans[ind++] = dq.front().first;
        }

        return ans;
    }
};
