class NumMatrix {
    int n , m;
    vector<vector<int>> pref;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        pref = matrix;
        
        for(int i = 0 ; i < n ; ++i)
        {
           for(int j = 0 ; j < m ; ++j)
           {
                int val1 = 0 , val2 = 0 , val3 = 0;

                // pref[i-1][j]
                if(i > 0)
                 val1 = pref[i-1][j];

                // pref[i][j-1]
                if(j > 0)
                 val2 = pref[i][j-1];

                // pref[i-1][j-1]
                if(i > 0 and j > 0)
                 val3 = pref[i-1][j-1];

                pref[i][j] = matrix[i][j] + val1 + val2 - val3;   
           }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = pref[row2][col2];

        if(row1 > 0)
         total -= pref[row1-1][col2];

        if(col1 > 0)
         total -= pref[row2][col1-1];

        if(row1 > 0 and col1 > 0)
         total += pref[row1-1][col1-1];

        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
