int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int best = INT_MIN;
    for (int i = 0; i <= nums.size()-1; i++) {
        sum += nums[i];
        best = max(sum, best);            
        if (sum<0) sum = 0;
    }
    return best;   
}
