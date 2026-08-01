class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
    	int mp1[256]={0};
        int mp2[256]={0};
        for(int i=0;i<s.length();i++){
            int c1=s[i];
            int c2=t[i];
            if(mp1[c1]==0 && mp2[c2]==0){
                mp1[c1]=c2;
                mp2[c2]=c1;
            }
            else{
                if(mp1[c1]!=c2 || mp2[c2]!=c1)
                return false;
            }
        }
        return true;
    }
};