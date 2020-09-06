#include <numeric>
#include <iostream>
#include <vector>
//#include <algorithom>
using namespace std;
#include <numeric>
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> returnVector;
        vector <int>::iterator Iter1;
        int j = 0, partotal;

        for (Iter1 = nums.begin() + 1; Iter1 != nums.end() + 1; Iter1++)
        {
            partotal = accumulate(nums.begin(), Iter1, 0);
            returnVector[j] = partotal;
            j++;
        }
        return returnVector;
    }
};

int main()
{
    return 0;
}