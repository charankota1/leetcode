class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()&&mp[s[i]]>=l){
                l=mp[s[i]]+1;
            }
            mp[s[i]]=i;
            res=max(res,i-l+1);
        }
        return res;
    }
};