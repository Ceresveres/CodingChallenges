int trap(vector<int>& height) {
    int volume = 0;
    int rightmax = 0;
    int leftmax = 0;
    int righti = height.size()-1;
    int lefti = 0;        
    while (lefti <= righti) {
        if(height[lefti] <= height[righti]) {
            if(height[lefti] >= leftmax) {
                leftmax = height[lefti];
            } else {
                volume += leftmax - height[lefti];
            }
            lefti++;
        } else {
            if(height[righti] >= rightmax) {
                rightmax = height[righti]; 
            } else {
                volume += rightmax - height[righti];
            }
            righti--;
        }
    } 
    return volume;
};
