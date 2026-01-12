// Brote force implementation
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        pair<int,int> p = make_pair(points[0][0], points[0][1]);

        for(auto &it : points) {
            if(p.first == it[0])
             ans += abs(p.second - it[1]);
            else if(p.second == it[1])
             ans += abs(p.first - it[0]);
            else {
                while(true) {
                    if(p.first == it[0]) {
                     ans += abs(p.second - it[1]);
                     break;
                    }
                    else if(p.second == it[1]) {
                     ans += abs(p.first - it[0]);
                     break;
                    }
                    else {
                        if(it[0] < p.first)
                         p.first--;
                        else
                         p.first++;
                        
                        if(it[1] < p.second)
                         p.second--;
                        else
                         p.second++;
                    }

                    ans++;
                }
            }

            p = make_pair(it[0], it[1]);
        }

        return ans;
    }
};

// Math implementation, the minimum value for traveling between Point A, B is => max(abs(a - c), abs(b - d)) where A{a, b} & B{c, d}
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        pair<int,int> p = make_pair(points[0][0], points[0][1]);

        for(auto &it : points) {
            ans += max(abs(p.first - it[0]), abs(p.second - it[1]));
            p = make_pair(it[0], it[1]);
        }

        return ans;
    }
};
