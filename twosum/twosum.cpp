#include <iostream>
#include <vector>           
#include <unordered_map>
using namespace std;

class Solution{
    public:
        // creating a hash map to store number -> index pairs
        // key: actual number from array | value: index position
        vector<int> twoSum(vector<int>& nums, int target){   
            unordered_map<int, int> numMap;

            // loop throgh each elem in input array
            for (int i=0; i< nums.size(); i++){

                // calc what number is needed to reach target
                // if target= 9 and current number=2, we need 7 to make sum
                int complement= target- nums[i];

                // check if complement exists in hash map
                // count() returns 1 if key exists, 0 if it doesnt
                if (numMap.count(complement)){
                    // pair found, returns:
                    // 1. numMap[complement]= index where complement was found
                    // 2. i = current index
                    return {numMap[complement], i};
                }
                // store current num and index in map
                numMap[nums[i]]= i;
            }
            return {};
        }
};

int twosum(){
    Solution solution;

    // Test case 1: [2,7,11,15], target = 9
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test 1 - Input: [2,7,11,15], Target: " << target1 << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    cout << "Values: " << nums1[result1[0]] << " + " << nums1[result1[1]] << " = " << target1 << endl << endl;

    return 0;
}