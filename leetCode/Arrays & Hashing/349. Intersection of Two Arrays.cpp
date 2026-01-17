// Using Hashing T -> O(N + M) & S -> O(N + M)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nums1Freq, nums2Freq;

        for(auto &it : nums1)
         nums1Freq[it] = 1;

        for(auto &it : nums2)
         nums2Freq[it] = 1;

        vector<int> ans;

        for(auto &[a, b] : nums1Freq)
         if(nums2Freq[a])
          ans.push_back(a);

        return ans;
    }
};

// Sorting and Two Pointers T -> O(N log(N) + M log(M)) & S -> O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int p1 = 0, p2 = 0;
        vector<int> ans;

        while(p1 < nums1.size() and p2 < nums2.size()) {
                if(nums1[p1] == nums2[p2]) {
                    int ele = nums1[p1];

                    ans.push_back(ele);

                    while(p1 < nums1.size() and nums1[p1] == ele)
                    p1++;
                    
                    while(p2 < nums2.size() and nums2[p2] == ele)
                    p2++;
                }
                else {
                    if(nums1[p1] < nums2[p2])
                    p1++;
                    else
                    p2++;
                }
        }

       return ans;
    }
};
