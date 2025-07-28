class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // 1e5 => 17 digts
        vector<int> v(17 , 0);
        vector<int> temp(17 , 0);

        for(auto it : nums)
        {
            for(int i = 0 ; i < 17 ; ++i)
            {
                int bit = (it >> i) & 1;
                
                if(bit)
                 v[i] = 1;
            }
        }

        return backTrack(0 , nums , v , temp);
    }

    int backTrack(int i , vector<int> &nums , vector<int> &v , vector<int> &temp)
    {
        if(i == nums.size())
        {
            for(int j = 0 ; j < 17 ; ++j)
            {
                if(v[j] and !temp[j])
                 return 0;
            }

            return 1;
        }

        int val = nums[i];

        addBits(val , temp);

        int take = backTrack(i + 1 , nums , v , temp);

        removeBits(val , temp);

        int notTake = backTrack(i + 1 , nums , v , temp);

        return take + notTake;
    }

    void addBits(int val , vector<int> &temp)
    {
        for(int j = 0 ; j < 17 ; ++j)
        {
            int bit = (val >> j) & 1;

            if(bit)
             temp[j]++;
        }
    }

    void removeBits(int val , vector<int> &temp)
    {
        for(int j = 0 ; j < 17 ; ++j)
        {
            int bit = (val >> j) & 1;

            if(bit)
             temp[j]--;
        }
    }
};
