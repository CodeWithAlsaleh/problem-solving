// This is a simple DP sol, but the encoding idea was something really good and new to me
class Solution {
    const int MOD = 1e9 + 7;

    int encodeRow(const string& r) {
        int mask = 0;

        for (char c : r) {
            mask *= 4;
            if (c == 'R') mask += 1;
            else if (c == 'Y') mask += 2;
            else if (c == 'G') mask += 3;
        }

        return mask;
    }

    int encodePrevChar(char c) {
        if (c == 'X') return 0;
        if (c == 'R') return 1;
        if (c == 'Y') return 2;

        return 3; // G
    }

    int getNumberOfWays(int i, int j, int n, char prevChar, string &prevRow, vector<vector<vector<vector<int>>>> &dp) {
        if(i == n)
         return 1;

        int rowMask = encodeRow(prevRow), prevCharCode = encodePrevChar(prevChar);

        if(~dp[j][prevCharCode][rowMask][i])
         return dp[j][prevCharCode][rowMask][i];

        int sum = 0, newRow = j == 2 ? i + 1 : i;

        // Try RED
        if(prevChar != 'R' and prevRow[j] != 'R') {
            char prevRowChar = prevRow[j], newChar = j == 2 ? 'X' : 'R';
            prevRow[j] = 'R';

            sum = (sum + getNumberOfWays(newRow, (j + 1) % 3, n, newChar, prevRow, dp)) % MOD;

            prevRow[j] = prevRowChar;
        }

        // Try YELLOW
        if(prevChar != 'Y' and prevRow[j] != 'Y') {
            char prevRowChar = prevRow[j], newChar = j == 2 ? 'X' : 'Y';
            prevRow[j] = 'Y';

            sum = (sum + getNumberOfWays(newRow, (j + 1) % 3, n, newChar, prevRow, dp)) % MOD;

            prevRow[j] = prevRowChar;
        }

        // Try GREEN
        if(prevChar != 'G' and prevRow[j] != 'G') {
            char prevRowChar = prevRow[j], newChar = j == 2 ? 'X' : 'G';
            prevRow[j] = 'G';

            sum = (sum + getNumberOfWays(newRow, (j + 1) % 3, n, newChar, prevRow, dp)) % MOD;

            prevRow[j] = prevRowChar;
        }

        return dp[j][prevCharCode][rowMask][i] = sum;
    }
public:
    int numOfWays(int n) {
        int ans = 0;
        string prevRow(3, 'X');

        // When u are using multiple vectors inside each other "vector<vector<vector ..etc" 
        // always put the largest vector size at the end this makes the code much faster

        vector<vector<vector<vector<int>>>> dp(3, 
        vector<vector<vector<int>>>(4, 
        vector<vector<int>>(63, 
        vector<int> (n, -1))));

        ans = getNumberOfWays(0, 0, n, 'X', prevRow, dp);

        return ans;
    }
};

// I Don't understand this code but it's the most efficient one T => O(n), S => O(1)
using ll = long long;

class Solution {
    const ll MOD = 1e9 + 7;
public:
    int numOfWays(int n) {
        ll A = 6, B = 6;

        for (int r = 2; r <= n; ++r) {
            ll A2 = (3 * A + 2 * B) % MOD, B2 = (2 * A + 2 * B) % MOD;
            A = A2; B = B2;
        }

        return (A + B) % MOD;
    }
};
