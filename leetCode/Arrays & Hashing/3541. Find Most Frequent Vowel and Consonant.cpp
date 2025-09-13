class Solution {
public:
    int maxFreqSum(string s) {
        set<char> st = {'a' , 'i' , 'u' , 'o' , 'e'};
        unordered_map<char,int> vowels;
        unordered_map<char,int> consonant;

        int cnt1 = 0 , cnt2 = 0;
        
        for(auto &it : s)
        {
            if(st.find(it) != st.end())
            {
                vowels[it]++;
                cnt1 = max(cnt1 , vowels[it]);
            }
            else
            {
                consonant[it]++;
                cnt2 = max(cnt2 , consonant[it]);
            }
        }

        return cnt1 + cnt2;
    }
};
