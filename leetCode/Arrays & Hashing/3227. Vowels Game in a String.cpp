class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;

        for(auto &it : s)
        {
            if(it == 'a' or it == 'i' or it == 'u' or it == 'o' or it == 'e')
             cnt++;
        }

        return cnt > 0;
    }
};
