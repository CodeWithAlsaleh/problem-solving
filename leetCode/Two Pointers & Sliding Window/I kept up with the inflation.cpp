// Using window of size 4 which will work fine if u analyze it
// why not window of size 3 ? cuz it will fail in this case [1, 2, 3, 1]
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 3; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1] or nums[i] == nums[i - 2] or nums[i] == nums[i - 3])
             return nums[i];
            else if(nums[i - 1] == nums[i - 2] or nums[i - 1] == nums[i - 3])
             return nums[i - 1];
            else if(nums[i - 2] == nums[i - 3])
             return nums[i - 2];
        }

        return INT_MIN;
    }
};

// Another sol which is to handle the sol in boyer-moore algo but we need first
// to chek the first 3 element cuz the target is repeated N-times and not N+1-times
// then if we chek the first 3 elements and we didn't find any matching elements
// we will end up with (M+1 repeated element in the array) where M = N - 3
// and finally we can implement the boyer-moore algo
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if(nums[0] == nums[1] or nums[0] == nums[2])
         return nums[0];
        else if(nums[1] == nums[2])
         return nums[1];

        int ans = 0, cnt = 0;

        for(int i = 3; i < nums.size(); ++i) {
            if(!cnt) {
                cnt++;
                ans = nums[i];
            }
            else if(nums[i] == ans)
             cnt++;
            else 
             cnt--;
        }

        return ans;
    }
};
