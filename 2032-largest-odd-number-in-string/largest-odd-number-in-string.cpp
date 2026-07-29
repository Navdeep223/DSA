class Solution {
public:
    string largestOddNumber(string num) {
        int idx=-1;
        for(int i=num.length()-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                idx=i;
                break;
            }
        }
        if(idx==-1)
        return "";
        int start=0;
        while(start<idx && num[start]==0){
            start++;
        }
        return num.substr(start,idx-start+1);
    }
};