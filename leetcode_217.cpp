// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <iostream>
#include <set>

bool solve(int* nums, int numsSize)
{
  std::set<int> seen; // we can use hashmap instead of the set

  for (int i = 0; i < numsSize; i++)
  {
    if (seen.find(nums[i]) != seen.end())
    {
      return true;
    }
    seen.insert(nums[i]);
  }
  return false;
}

int main()
{
  int N;
  std::cin >> N;

  while (N --)
  {
    int numsSize;
    std::cin >> numsSize;

    int* nums = new int[numsSize];

    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }

    std::cout << (solve(nums, numsSize) ? "true" : "false") << std::endl;
    delete[] nums;
  }

  return 0;
}