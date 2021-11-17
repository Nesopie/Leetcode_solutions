// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countVowelSubstrings(string word) {
        int i = 0, j = 0, k = 0, vowels = 0;

        unordered_map<char,int> mp;
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 0;

        int counter = 0;

        for(int i = 0; i < word.length(); i++) {
            if(mp.count(word[i])) {
                vowels += ++mp[word[i]] == 1; //only increment when you see the word for the first time
                for(; vowels == 5; k++)
                    vowels -= --mp[word[k]] == 0; //if vowel counter reaches zero then vowels will decrease by 1
                counter += k - j; //all substrings for j to i are k - j
            }else {
                mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = vowels = 0;
                j = k = i + 1;
            }
        }
        
        return counter;
    }
};
