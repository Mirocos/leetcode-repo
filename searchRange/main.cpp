//
// Created by zeming on 22-6-13.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftSearch){
        int n = nums.size();
        int l = 0, r = n-1;
        int mid = (l + r) / 2;
        int ans = -1;
        while(l <= r ){

            if(nums[mid] == target)
                ans = mid;
            if(leftSearch){
                if(nums[mid] >= target){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                mid = (l+r) / 2;
            } else {
                if(nums[mid] <= target){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                mid = (l+r) / 2;
            }

        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1,-1};
        if(nums.size() == 0)
            return ans;


        int l = 0, r = nums.size() - 1;
        if(target < nums[l] || target > nums[r])
            return ans;

        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }
};


int main(){

    Solution s;
    std::vector<int> nums{5,7,7,8,8,10};
    auto ret = s.searchRange(nums, 6);
    std::cout << ret[0] << " " << ret[1] << std::endl;


}