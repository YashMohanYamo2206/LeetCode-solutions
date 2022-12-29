class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){ // no answer exists
            return {};
        }
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums.back() < 0){ // all positive or negative then no answer
            return {};
        }
        for(int firstElement = 0; firstElement < nums.size() - 2 && nums[firstElement] <= 0; ++firstElement){
            if(firstElement > 0 && nums[firstElement]==nums[firstElement-1]){ // exclude duplicates for 1st element
                continue;
            }
            int secondElement = firstElement + 1, thirdElement = nums.size() - 1;
            while(secondElement < thirdElement){ // 2nd element comes before 3rd element
                int sum = nums[firstElement] + nums[secondElement] + nums[thirdElement];
                if(sum < 0){
                    secondElement++;
                }
                else if(sum > 0){
                    thirdElement--;
                }
                else{
                    triplets.push_back({nums[firstElement],nums[secondElement],nums[thirdElement]});
                    secondElement++;
                    while(secondElement < thirdElement && nums[secondElement] == nums[secondElement -  1]){ // exclude duplicates for 2nd element
                        secondElement++;
                    }
                    thirdElement--;
                    while(secondElement < thirdElement && nums[thirdElement] == nums[thirdElement + 1]){ // exclude dupplicates for 3rd element
                        thirdElement--;
                    }
                }
            }
        }
        return triplets;
    }
};