class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , 1);
        vector<int> bits(32 , 0);
        int ind = n - 1;
        ans[ind] = 1;

        addBits(nums[ind] , bits);

        for(int i = n - 2 ; i >= 0 ; --i)
        {   
            addBits(nums[i] , bits);
            bool flag = check(ind , bits , nums[ind]);

            while(flag and ind > i)
            {
                removeBits(nums[ind] , bits);
                ind--;
                flag = check(ind , bits , nums[ind]);
            }

            ans[i] = ind - i + 1;
        }

       return ans;
    }

    // To check if we can delete nums[ind] without affecting the max bitwise OR
    bool check(int &ind , vector<int> &bits , int &val)
    {
        bool flag = true;

        for(int i = 0 ; i < 32 ; ++i)
        {
            int bit = (val >> i) & 1;

            if(bit and bits[i] - bit == 0)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }

    void addBits(int &val , vector<int> &bits)
    {
        for(int i = 0 ; i < 32 ; ++i)
        {
            int bit = (val >> i) & 1;
            bits[i] += bit;
        }
    }

    void removeBits(int &val , vector<int> &bits)
    {
        for(int i = 0 ; i < 32 ; ++i)
        {
            int bit = (val >> i) & 1;
            bits[i] -= bit;
        }
    }
};
