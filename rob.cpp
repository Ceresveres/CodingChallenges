// runtime O(n)
// space O(1)
int rob(vector<int>& nums) {
    if (nums.size() <= 0 ) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 0; i < nums.size(); i++ ) {
      int temp = prev1;
      prev1 = max(prev2 + nums[i], prev1);
      prev2 = temp;
    }
    return prev1;
}

// same as above excepts treats arrayvector as a circle
int rob(vector<int>& nums) {
    int n = nums.size(); 
    if (n < 2) return n ? nums[0] : 0;
    return max(robIterate(nums, 0, n - 2), robIterate(nums, 1, n - 1));
}

int robIterate(vector<int>& nums, int l, int r) {
    int prev1 = 0, prev2 = 0;
    for (int i = l; i <= r; i++) {
        int temp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = temp;
    }
    return prev1;
}
