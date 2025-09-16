class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for(int i = 0 ; i < nums.size() ; ++i)
        {
            int val = nums[i];
            while(!st.empty() and gcd(val , st.top()) > 1)
            {
                val = lcm(val , st.top());
                st.pop();
            }

            st.push(val);
        }

        vector<int> ans(st.size());
        int ind = st.size() - 1;

        while(ind >= 0)
        {
            ans[ind--] = st.top();
            st.pop();
        }

        return ans;
    }
};
