 int jump(vector<int>& nums) { 
        int step = 0;
        for(int l = 0, r = 0; r < nums.size() - 1; step++){
        	int r_new = 0;
        	for(int i = l; i <= r; i++) r_new =  max(r_new, i + nums[i]);
        	l = r + 1;
        	r = r_new;
        }
        return step;
    }
