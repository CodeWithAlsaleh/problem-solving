/*
  Unlock all projects that have captial[i] <= w, then take the project that has the best profit using max heap
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), ind = 0;
        priority_queue<int> pq;
        vector<pair<int, int>> v(n);

        for(int i = 0; i < n; ++i)
         v[i] = make_pair(capital[i], profits[i]);

        sort(v.begin(), v.end());

        while(k--) {
            while(ind < n and v[ind].first <= w) {
                pq.push(v[ind].second);
                ind++;
            }

            if(pq.empty())
             break;

            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};
