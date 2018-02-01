#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j)
{
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void print(vector<int>& nums)
{
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

void permutate(vector<int>& nums, int pos, vector<vector<int> >& result)
{
    int len = nums.size();

    if (pos == len) {
        result.push_back(nums);
        print(nums);
        return;
    }

    for (int i = pos; i < len; i++) {
        swap(nums, i, pos);
        permutate(nums, pos + 1, result);
        swap(nums, i, pos);
    }
}

int main()
{
    vector<int> nums;
    vector<vector<int> > result;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
 
    permutate(nums, 0, result);

    return 0;
}
