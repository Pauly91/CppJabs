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
                    index.push_back(i);
                    index.push_back(j);
                    return index;
                }
            }
        }
        
    }
};


int main(int argc, char const *argv[])
{
    Solution s1;
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(5);
    vect.push_back(2);
    vect.push_back(3);
    vector<int> result;
    result = s1.twoSum(vect,5);

    for(auto i:result)
    {
        cout<<i;
    }
    return 0;
}