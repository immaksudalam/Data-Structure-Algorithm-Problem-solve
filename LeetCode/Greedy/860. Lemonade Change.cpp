class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntfive=0;
        int cntten=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5)cntfive++;
            else if(bills[i]==10){
                if(cntfive){
                    cntfive--;
                    cntten++;
                }
                else return false;
            }
            else{
                if(cntten && cntfive){
                    cntten--;
                    cntfive--;
                }
                else if(cntfive>=3){
                    cntfive-=3;
                }
                else return false;
            }
        }
        return true;
    }
};
