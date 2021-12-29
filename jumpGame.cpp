    bool canJump(vector<int>& nums) {
        int index = 0;
        int length = nums.size();
        for (int reach = 0; index <= reach && index < length; index++) {
            reach = max(index + nums[index], reach);
        }
        return index == nums.size();
    };
