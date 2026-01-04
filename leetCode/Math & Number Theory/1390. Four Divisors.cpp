class Solution {
    pair<int,int> getNumberOfDivisors(int num) {
        int cnt = 0, sum = 0;

        for(int i = 1; i * i <= num; ++i) {
            if(num % i == 0) {
                cnt++;
                sum += i;

                if(num / i != i)
                 cnt++, sum += num / i;
            }
        }

        return make_pair(cnt, sum);
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(auto &it : nums) {
            auto p = getNumberOfDivisors(it);

            if(p.first == 4)
             ans += p.second;
        }

        return ans;
    }
};
