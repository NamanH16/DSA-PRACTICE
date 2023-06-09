class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> freq(26, 0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        char ans = letters[0];
        int check = target-'a';
        for(int i=0;i<freq.size();i++){
            if(i>check && freq[i]>0){
                ans = (char)(i+'a');
                break;
            }
        }
        return ans;
    }
};