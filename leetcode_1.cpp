// Given an array of integers nums and an integer target, return true if the two numbers such that they add up to target.

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> solve(int *nums, int numsSize, int target)
{
  std::unordered_map<int, int> map;

  for (int i = 0; i < numsSize; i++)
  {
    int complement = target - nums[i];
    if (map.find(complement) != map.end())
    {
      return {map[complement], i};
    }
    map[nums[i]] = i;
  }

  return {};
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int target, numsSize;
    std::cin >> target >> numsSize;

    int *nums = new int[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }

    auto result = solve(nums, 4, target);
    for (auto i : result)
    {
      std::cout << i << " ";
    }
    delete[] nums;
  }

  return 0;
}