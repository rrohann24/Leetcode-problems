class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n =s.size();
        int time=0;
        while(true){
            bool flag=0;
            int i=0;
            while(i<n-1){
                if(s[i]=='0' && s[i+1]=='1'){
                    flag=true;
                    s[i]='1';
                    s[i+1]='0';
                    i+=2;
                    flag=true;
                }
                else i++;
            }
            if(flag) time++;
            
            else break;
        }
        return time;
    }
};