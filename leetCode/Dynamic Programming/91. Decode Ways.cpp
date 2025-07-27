// Iterative
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();

        if(s[0] == '0') return 0;

        vector<int> dp(len , 0);
        dp[0] = 1;

        for(int i = 1 ; i < len ; ++i)
        {
            int L = 0 , R = 0;

            if(s[i] != '0')
                L = dp[i-1];

            if(checkTwoDigits(s[i-1] , s[i]))
                R = i>= 2 ? dp[i-2] : 1;

            dp[i] = L + R;
        }

        return dp[len-1];
    }

    bool checkTwoDigits(char ch1 , char ch2)
    {
        bool check1 = ch1 == '1' and ch2 - '0' <= 9;
        bool check2 = ch1 == '2' and ch2 - '0' <= 6;

        return check1 or check2;
    }

};

// Recursive
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() , -1);
        return dpFun(0 , s , dp);
    }

    int dpFun(int i , string & s , vector<int> &dp) {
        if(i == s.length())
         return 1;

        if(checkZero(s[i]))
         return 0;
        
        if(~dp[i])
         return dp[i];
        
        int L = dpFun(i + 1 , s , dp);

        int R = 0;
        if(i + 1 < s.length() and checkTwoDigits(s[i] , s[i+1]))
            R = dpFun(i + 2 , s , dp);

        return dp[i] = L + R;
    }

    bool checkZero(char ch)
    {
        return ch == '0';
    }

    bool checkTwoDigits(char ch1 , char ch2)
    {
        bool check1 = ch1 == '1' and ch2 - '0' <= 9;
        bool check2 = ch1 == '2' and ch2 - '0' <= 6;

        return check1 or check2;
    }

};
