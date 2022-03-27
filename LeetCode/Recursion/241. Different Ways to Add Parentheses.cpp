class Solution {
public:
    int calculate(int a, int b, char op){
        if(op == '+') return a+b;
        else if(op == '-') return a-b;
        else return a*b;
    }
    
    vector<int> calculateWays(string exp){
        vector<int>ans;
        
        for(int i=0; i<exp.size(); i++){
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                string s1 = exp.substr(0, i);
                string s2 = exp.substr(i+1, exp.size());
                
                vector<int> leftRes = calculateWays(s1);
                vector<int> rightRes = calculateWays(s2);
                
                for(auto t1: leftRes)
                    for(auto t2: rightRes){
                        ans.push_back(calculate(t1, t2, exp[i]));
                    }
            }
        }
        if(ans.size()==0){
            ans.push_back(stoi(exp));
        }
        
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return calculateWays(expression);
    }
};
