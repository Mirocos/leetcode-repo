//
// Created by zeming on 22-5-25.
//

#include <iostream>
#include <vector>


using namespace std;


class Solution{
public:
    int maxArea(vector<int>& height){
        int w = height.size();
        int left = 0, right = w-1;
        int maxArea = 0;
        while(left < right){
            int width = right - left;
            if(height[left] < height[right]){
                if(height[left] * width > maxArea){
                    maxArea = height[left] * width;
                }
                ++left;
            } else {
                if(height[right] * width > maxArea){
                    maxArea = height[right] * width;
                }
                --right;
            }
        }

        return maxArea;
    }
};


int main(){
    Solution solution;

    vector<int> h{1,1};
    cout << solution.maxArea(h);


    return 0;
}