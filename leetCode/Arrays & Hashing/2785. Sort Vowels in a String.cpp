class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> mp = { {'A',1} , {'a',1} , {'I',1} , {'i',1} , {'O',1} , {'o',1} , {'U',1} ,{'u',1} , {'E',1} , {'e',1} };
        vector<char> vowels;

        for(auto &it : s)
        {
            if(mp[it])
             vowels.push_back(it);
        }

        sort(vowels.begin() , vowels.end());
        int ind = 0;

        string ans = s;

        for(int i = 0 ; i < s.length() ; ++i)
        {
            if(mp[s[i]])
                ans[i] = vowels[ind++];
        }

        return ans;
    }
};
