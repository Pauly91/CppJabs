#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = i+1;j < nums.size();j++)
            {
                cout<<target<<" == "<<nums[i]<<" + " << nums[j] << endl;
                if(target == (nums[i] + nums[j]))
                {
                    index = {i,j};
                    return index;
                }
            }
        }
        
    }
};


int main(int argc, char const *argv[])
{
    Solution s1;
    vector<int>v = {1, 3, 5, 7};
    vector<int> result;
    result = s1.twoSum(v,5);
    return 0;
}
