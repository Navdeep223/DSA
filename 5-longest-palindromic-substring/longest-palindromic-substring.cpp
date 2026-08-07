class Solution {
public:
    void expand(string &s, int left, int right,
                int &start, int &maxLen)
    {
        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right])
        {
            left--;
            right++;
        }

        // palindrome is from left+1 to right-1
        int len = right - left - 1;

        if (len > maxLen)
        {
            maxLen = len;
            start = left + 1;
        }
    }

    string longestPalindrome(string s)
    {
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.size(); i++)
        {
            // odd palindrome
            expand(s, i, i, start, maxLen);

            // even palindrome
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};
