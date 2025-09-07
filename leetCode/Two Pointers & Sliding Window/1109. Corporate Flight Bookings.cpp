class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int size = bookings.size();
        vector<int> diff(n+1 , 0);

        for(int i = 0 ; i < size ; ++i)
        {
            auto arr = bookings[i];
            arr[0]-- , arr[1]--;

            diff[arr[0]] += arr[2];
            diff[arr[1] + 1] -= arr[2];
        }

        for(int i = 1 ; i < n ; ++i)
         diff[i] += diff[i-1];

        vector<int> ans(n, 0);

        for(int i = 0; i < n ; ++i)
         ans[i] = diff[i];

        return ans;
    }
};
