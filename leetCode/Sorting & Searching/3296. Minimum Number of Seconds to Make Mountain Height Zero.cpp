using ll = long long;

class Solution {
    ll findSum(ll seconds, ll t) {
        /*
          Instead of doing a nested binary search, we can solve the quadratic formula:

          val * mid * (mid + 1) / 2 <= seconds => mid * (mid + 1) <= 2 * seconds / val
          => let k = 2 * seconds / val

          => mid * (mid + 1) <= k => mid² + mid - k <= 0
          => let x = mid
          => x² + x - k <= 0
          => solving the quadratic formula => (sqrt(1 + 4 * k) - 1) / 2 is the answer
        */ 
        ll k = (2 * seconds) / t;
        ll x = (sqrt(1 + 4.0 * k) - 1) / 2;
        
        return x;
    }

    bool can(ll mid, ll mountainHeight, vector<int>& workerTimes) {
        for(auto &it : workerTimes)
            mountainHeight -= findSum(mid, it);

        return mountainHeight <= 0;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll st = 1, en = 1e18, ans = 0;

        while(st <= en) {
            ll mid = st + (en - st) / 2LL;

            if(can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                en = mid - 1;
            }
            else
                st = mid + 1;
        }

        return ans;
    }
};
