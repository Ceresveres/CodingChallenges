
int deleteAndEarn(vector<int>& nums) {
    int skip = 0;
    int take = 0;
    int n = 10001;

    //max points from taking an value and delete values that are +/- 1
    vector<int> values(n, 0);
    for (int num : nums) {
        values[num] += num;
    }

    for (int i = 0; i < n; i++ ) {
        int takei = skip + values[i];
        int skipi = max(skip, take);
        take = takei;
        skip = skipi;
    }
    cout << max(take, skip) << endl;
    return max(take, skip);
};
