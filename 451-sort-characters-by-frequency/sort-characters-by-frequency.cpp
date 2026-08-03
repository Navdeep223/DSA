class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
            vector<char> chars;
            for(char ch:s){
                freq[ch]++;
            }
            for(auto it: freq)
            chars.push_back(it.first);
            sort(chars.begin(),chars.end(),[&](char a,char b){
                return freq[a]>freq[b];
            });
            string ans="";
            for(char ch:chars){
                for(int i=0;i<freq[ch];i++){
                    ans.push_back(ch);
                }
            }
            return ans;
    }
};