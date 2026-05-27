class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        vector<bool> invalid(26, false);

        for(int i=0; i<word.size(); i++ ){
            if(word[i] >= 'a' and word[i] <= 'z') {
                int idx = word[i] - 'a';
                lower[idx] = true;

                if(upper[idx]) {
                    invalid[idx] = true;
                }
            }
            else if(word[i] >= 'A' and word[i] <= 'Z') {
                int idx = word[i] - 'A';
                upper[idx] = true;
            }
        }

        int cnt = 0;
        for(int i=0; i<26; i++) {
            if(lower[i] and upper[i] and !invalid[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};
