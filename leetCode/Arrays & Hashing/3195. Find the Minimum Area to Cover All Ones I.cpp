class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // Maybe we can use two pointers on both
        // vertical and horizontal to reduce the time
        int stV = -1 , enV = -1;
        int stH = 1e9 , enH = -1e9;

        for(int i = 0 ; i < grid.size() ; ++i)
        {
            for(int j = 0 ; j < grid[0].size() ; ++j)
            {
                // vertical
                if(grid[i][j] == 1) {
                    if(stV == -1)
                     stV = i;
                    
                    enV = i;
                }

                // horizontal
                if(grid[i][j] == 1) {
                    if(j < stH)
                     stH = j;

                    if(j > enH)
                     enH = j;
                }
            }
        }

        int width = enH - stH + 1;
        int height = enV - stV + 1;

        return width * height;
    }
};

// Another sol which is much better (at least in my opinion)

class Solution {
    int findLeft(vector<vector<int>>& grid) {
        for(int j = 0 ; j < grid[0].size() ; ++j)
        {
            for(int i = 0 ; i < grid.size() ; ++i)
            {
                if(grid[i][j] == 1)
                 return j;
            }
        }

        return -1;
    }

    int findRight(vector<vector<int>>& grid) {
        for(int j = grid[0].size() - 1 ; j >= 0 ; --j)
        {
            for(int i = 0 ; i < grid.size() ; ++i)
            {
                if(grid[i][j] == 1)
                    return j;
            }
        }

        return -1;
    }

    int findTop(vector<vector<int>>& grid) {
        for(int i = 0 ; i < grid.size() ; ++i)
        {
            for(int j = 0 ; j < grid[0].size() ; ++j)
            {
                if(grid[i][j] == 1)
                    return i;
            }
        }

        return -1;
    }

    int findBottom(vector<vector<int>>& grid) {
        for(int i = grid.size() - 1 ; i >= 0 ; --i)
        {
            for(int j = 0 ; j < grid[0].size() ; ++j)
            {
                if(grid[i][j] == 1)
                    return i;
            }
        }

        return -1;
    }

public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = findLeft(grid);
        int right = findRight(grid);
        int top = findTop(grid);
        int bottom = findBottom(grid);

        int width = right - left + 1;
        int height = bottom - top + 1;

        return width * height;
    }
};
