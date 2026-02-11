class Solution {
    void buildFreqArray(string &s , vector<vector<int>> &freq) {
        freq[0][0] = s[0] == 'a';
        freq[1][0] = s[0] == 'b';
        freq[2][0] = s[0] == 'c';
       
        for(int i = 1; i < s.length(); ++i) {
            freq[0][i] += freq[0][i - 1] + (s[i] == 'a');
            freq[1][i] += freq[1][i - 1] + (s[i] == 'b');
            freq[2][i] += freq[2][i - 1] + (s[i] == 'c');
        }
    }

    bool can(int mid, string &s, vector<vector<int>> &freq, int len, int k) {
        int L = -1;
        for(int i = len - mid; i <= len; ++i) {
            int a = freq[0][len - 1], b = freq[1][len - 1], c = freq[2][len - 1];

            if(i > 0) {
                a -= freq[0][i - 1];
                b -= freq[1][i - 1];
                c -= freq[2][i - 1];
            }

            if(L >= 0) {
                a += freq[0][L];
                b += freq[1][L];
                c += freq[2][L];
            }

            if(a >= k and b >= k and c >= k)
             return true;
            
            L++;
        }

        return false;
    }
public:
    int takeCharacters(string s, int k) {
        if(k == 0)
         return 0;
        
        const int len = s.length();
        vector<vector<int>> freq(3, vector<int>(len, 0));

        buildFreqArray(s, freq);

        if(freq[0][len - 1] < k or freq[1][len - 1] < k or freq[2][len - 1] < k)
         return -1;

        int st = 0, en = len, ans = -1;

        while(st <= en) {
            int mid = st + (en - st) / 2;

            if(can(mid, s, freq, len, k)) {
                ans = mid;
                en = mid - 1;
            }
            else
                st = mid + 1;
        }

        return ans;
    }
};
