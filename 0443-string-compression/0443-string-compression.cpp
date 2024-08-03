class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('\0');
        string ans;
        int tmp=0;
        char tmp2;
        for(int i=0;i<chars.size()-1;i++){
            tmp2=chars[i];
            tmp=1;
            while(chars[i+1]==tmp2){
                i++;
                tmp++;
            }
            ans=ans+tmp2;
            if(tmp>1){
                ans=ans+to_string(tmp);
            }
        }
        chars.clear();
        for(auto i:ans){
            chars.push_back(i);
        }
        return chars.size();
    }
};