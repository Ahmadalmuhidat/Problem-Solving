// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
// Let these two numbers be numbers ( indexil and numbers(indexz] where 1 <= index, < indexz <= numbers. length .
// Return the indices of the two numbers, index, and index, added by one as an integer array (index,, indexz] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.

#include <iostream>
#include <vector>

std::vector<int> solve(int *nums, int numsSize, int target)
{
  int left = 0, right = numsSize - 1;

  while (left < right)
  {
    int sum = nums[left] + nums[right];

    if (sum == target)
    {
      return {left + 1, right + 1};
    }
    else if (sum < target)
    {
      left++;
    }
    else
    {
      right--;
    }
  }

  return {};
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int numsSize, target;
    std::cin >> numsSize >> target;

    int *nums = new int[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }

    std::vector<int> result = solve(nums, numsSize, target);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    delete[] nums;
  }
  return 0;
}