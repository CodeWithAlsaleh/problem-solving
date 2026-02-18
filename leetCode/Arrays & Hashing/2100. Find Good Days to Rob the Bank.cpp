class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> prefBefore(n, 0), suffAfter(n, 0);

        prefBefore[0] = 1, suffAfter[n - 1] = 1;

        for(int i = 1; i < n; ++i)
            prefBefore[i] = prefBefore[i - 1] + (security[i] <= security[i - 1]);

        for(int i = n - 2; i >= 0; --i)
            suffAfter[i] = suffAfter[i + 1] + (security[i] <= security[i + 1]);

        vector<int> ans;

        for(int i = time; i < n - time; ++i) {
            int before = prefBefore[i];
            before = i - time >= 0 ? before - prefBefore[i - time] : before;

            int after = suffAfter[i];
            after = i + time < n ? after - suffAfter[i + time] : after;

            if(before == time and after == time)
             ans.push_back(i);
        }

        return ans;
    }
};
