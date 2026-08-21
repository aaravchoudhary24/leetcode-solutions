class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256] = {};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); ++right) {
            unsigned char c = s[right];

            left = max(left, last[c]);
            ans = max(ans, right - left + 1);

            last[c] = right + 1;
        }

        return ans;
    }
};