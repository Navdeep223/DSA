class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxfreq=0;
        int left=0;
        int ans=0;
        vector<int> mp(26,0);
        for(int right=0;right<n;right++){
            mp[s[right]-'A']++;
            maxfreq=max(maxfreq,mp[s[right]-'A']);
            while((right-left+1)-maxfreq > k){
                mp[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);
            
        }
        return ans;
    }
};