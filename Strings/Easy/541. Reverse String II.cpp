// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string reverseStr(string s, int k) {
        bool shouldReverse = true;

        int start = 0;
        int end = s.size() < k ? s.size() - 1 : k - 1;
        int n = s.size();

        while(start < n && end < n) {
            if(shouldReverse) 
                reverse(s,start,end);
            start = end + 1;
            end = end + k > n ? n - 1 : end + k; //handle the case when there are less than k chars left
            shouldReverse = !shouldReverse;
        }

        return s;
    }

    void reverse(string &s, int start, int end) {
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
};
