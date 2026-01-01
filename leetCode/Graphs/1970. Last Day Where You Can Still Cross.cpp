class Solution {
public:
    bool can(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for(int i = 0; i < day; ++i)
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int c = 0; c < col; ++c) {
            if(!grid[0][c]) {
                q.push({0, c});
                vis[0][c] = 1;
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == row - 1) return true;

            for(auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < row and nr >= 0 and nc >= 0 and nc < col and !grid[nr][nc] and !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int st = 0, en = row * col, ans = 0;

        while(st <= en) {
            int mid = st + (en - st) / 2;

            if(can(mid, row, col, cells)) {
                ans = mid;
                st = mid + 1;
            } else
                en = mid - 1;
        }

        return ans;
    }
};
