class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid;
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[low] <= nums[mid]) {
                if (mid + 1 > high)
                    return nums[low];
                if (nums[mid + 1] <= nums[high]) {
                    if (nums[low] < nums[mid + 1]) {
                        return nums[low];
                    }
                    return nums[mid + 1];
                }
                else {
                    low = mid;
                }
            } else {
                high = mid;
            }
        }
        
        return nums[mid];
    }
};
