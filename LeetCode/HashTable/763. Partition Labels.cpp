class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>hash(200, 0);
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
        }
        vector<int>ans;
        int cnt=0;
        int first;
        first = hash[s[0]];
        s+='#';
        map<char, int>mp;
        mp[s[0]]=1;
        for(int i=0; i<s.size()-1; i++){
          if(!mp[s[i]]){
               first += hash[s[i]];
               mp[s[i]]=1;
           }
           first--;
           cnt++;
           if(first==0){
               ans.push_back(cnt);
               first = hash[s[i+1]];
               mp.clear();
               mp[s[i+1]]=1;
               cnt=0;
               
           }
        }
        return ans;
    }
};
