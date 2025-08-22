class Solution {
    const int mxVal = 1000;
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // since we can't use neg values as indices we will convert each
        // value into pos by adding maximum value possible to each one
        vector<int> arr1(2 * mxVal + 1 , 0);
        vector<int> arr2(2 * mxVal + 1 , 0);

        vector<vector<int>> ans(2);

        for(int i = 0 ; i < nums1.size() ; ++i)
        {
            int val1 = nums1[i] + mxVal;
            arr1[val1] = 1;
        }

        for(int i = 0 ; i < nums2.size() ; ++i)
        {
            int val2 = nums2[i] + mxVal;
            arr2[val2] = 1;
        }

        for(int i = 0 ; i <=  2LL * mxVal ; ++i)
        {
            if(arr1[i] and !arr2[i])
             ans[0].push_back(i - mxVal);
        
            if(arr2[i] and !arr1[i])
             ans[1].push_back(i - mxVal);
        }

        return ans;
    }
};

// Another sol

class Solution {
    const int OFFSET = 1000;
    const int mxVal = 2 * 1000 + 1;
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // since we can't use neg values as indices we will convert each
        // value into pos by adding maximum value possible to each one
        bitset<2001> b1;
        bitset<2001> b2;

        for(int i = 0 ; i < nums1.size() ; ++i)
        {
            int val1 = nums1[i] + OFFSET;
            b1.set(val1);
        }

        for(int i = 0 ; i < nums2.size() ; ++i)
        {
            int val2 = nums2[i] + OFFSET;
            b2.set(val2);
        }

        vector<vector<int>> ans(2);

        for(int i = 0 ; i < mxVal ; ++i)
        {
            if(b1[i] and !b2[i])
             ans[0].push_back(i - OFFSET);
        
            if(b2[i] and !b1[i])
             ans[1].push_back(i - OFFSET);
        }

        return ans;
    }
};
