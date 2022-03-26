class Solution {
public:
    vector<string> result;
    map<char, string>mp;
    string digit;
    
    void backtrack(int i, string curstr){
        if(i == digit.size()){
            result.push_back(curstr);
            return;
        }
        
        for(int j=0; j<mp[digit[i]].size(); j++)
            backtrack(i+1, curstr + mp[digit[i]][j]);
    }
    vector<string> letterCombinations(string digits) {
        digit = digits;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string st="";
        if(digits.size())backtrack(0, st);
        
        return result;
    }
};
