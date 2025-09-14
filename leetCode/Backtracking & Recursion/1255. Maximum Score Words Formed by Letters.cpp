class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> mp;

        for(auto &it : letters)
         mp[it]++;

        return backTrack(0 ,  words , score , mp , 0);
    }

    int backTrack(int i , vector<string> &words , vector<int> &score , unordered_map<char,int> &mp , int sum)
    {
        if(i == words.size())
         return sum;

        int take = 0 , noTake = 0;

        bool flag = true;
        int cnt = 0;

        unordered_map<char,int> mp2;

        for(auto &it : words[i])
        {
            if(mp[it]) {
             mp[it]--;
             mp2[it]++;
             cnt += score[it - 97];
            }
            else
             flag = false;
        }

        if(flag) 
            take = backTrack(i+1 , words , score , mp , sum + cnt);

        for(auto &[a , b] : mp2)
         mp[a] += b;

        noTake = backTrack(i+1 , words , score , mp, sum);

        return max(take , noTake);
    }
};
