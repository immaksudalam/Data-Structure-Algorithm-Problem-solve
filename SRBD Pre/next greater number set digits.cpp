int solve(string &s, int n){
    int i;
    for(i=n-1; i>=0; i--){
        if(i==0){
            i--;
            break;
        }
        if(s[i-1]<s[i]){
            i--;
            break;
        }
    }
    if(i==-1)return -1;
    int j;
    for(j=n-1; j>i; j--){
        if(s[i]<s[j]){
            swap(s[i], s[j]);
            break;
        }
    }
    sort(s.begin()+i+1, s.end());
    return stoi(s);
    
}
class Solution
{
    public:
    int findNext (int N) 
    {
        string s = to_string(N);
        int len = s.size();
        return solve(s, len);
       
    }  
