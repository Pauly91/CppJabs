#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> subset;
        int count(0);
        int index = 0;
        int maxCount = 0;
        for(int c1 = 0; c1 < s.length(); c1++)        
        {
            char c = s[c1];
            if (subset.find(c) == subset.end())
            {
                subset.insert(c);
                count++;
            }
            
            else
            {
                
                if (count > maxCount) {
                    maxCount = count;
                }

                
                
                subset.clear();
                count = 0;
                c1 = index;
                ++index;

            }
        }    
        
        if (count > maxCount) {
            maxCount = count;
        }

        return maxCount;
    }
};


int main(int argc, char const *argv[])
{
    Solution s1;
    string s;
    cin >> s;
    cout<< s1.lengthOfLongestSubstring(s) <<endl;
    return 0;
}
