class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        int r = 0;
        int maxi = 0;

        unordered_set<char> st;

        while (r < s.length()) {

            if (st.find(s[r]) == st.end()) {
                // character is not present
                st.insert(s[r]);

                maxi = max(maxi, r - l + 1);

                r++;
            }
            else {
                // duplicate found
                st.erase(s[l]);
                l++;
            }
        }

        return maxi;
    }
};