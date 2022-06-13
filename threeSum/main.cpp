//
// Created by zeming on 22-5-25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ret;


        int n = nums.size();
        if(n < 3)
            return ret;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int k = n-1;
            // two sum
            for(int j = i + 1; j < n; ++j){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                while(j < k && nums[j] + nums[k] > target){
                    --k;
                }
                if(j == k){
                    break;
                }

                if(nums[j] + nums[k] == target){
                    ret.push_back({nums[i], nums[j], nums[k]});
                }

            }
            // two sum, input from,to,target

        }
        return ret;
    }
};


int main(){
    vector<int> nums{-2,0,1,1,2};

    Solution solution;
    auto ret = solution.threeSum(nums);

    return 0;
}