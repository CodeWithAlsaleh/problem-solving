class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0 , b = 0 , c = 0;
        int L = 0 , R = 0;
        int n = s.length();
        int ans = 0;
        while(R != n)
        {
            if(s[R]=='a')
             a++;
            else if(s[R] == 'b')
             b++;
            else
             c++;
            
            while(a and b and c)
            {
                ans += n - R;
                if(s[L]=='a')
                    a--;
                else if(s[L] == 'b')
                    b--;
                else
                    c--;

                L++;
            }
            R++;
        }
        return ans;
    }
};
