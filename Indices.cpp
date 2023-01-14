#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            if (nums_map.count(target - nums[i]) > 0) {
                return {nums_map[target - nums[i]], i};
            }
            nums_map[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    nums = {3, 2, 4};
    target = 6;
    result = solution.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    nums = {3, 3};
    target = 6;
    result = solution.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
``
