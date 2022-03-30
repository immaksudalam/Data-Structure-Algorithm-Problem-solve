class Solution {
public:
 
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int ptr1= 0, ptr2 =0;
        vector<vector<int>>ans;
        
        while(ptr1<firstList.size() && ptr2<secondList.size()){
            int a = max(firstList[ptr1][0], secondList[ptr2][0]);
            int b = min(firstList[ptr1][1], secondList[ptr2][1]);
            if(a <= b){
                ans.push_back({a, b});
            }
            
            if(firstList[ptr1][1] <= secondList[ptr2][1]) ptr1++;
            else ptr2++;
            
            
        }
        return ans;
    }
};
