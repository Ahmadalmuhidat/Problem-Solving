// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in o(n) time

#include <iostream>
#include <unordered_set>

int solve(std::vector<int> nums)
{
  std::unordered_set<int> numSet(nums.begin(), nums.end());
  int longestStreak = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    if (numSet.find(nums[i] - 1) == numSet.end())
    {
      int currentNum = nums[i];
      int currentStreak = 1;

      while (numSet.find(currentNum + 1) != numSet.end())
      {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = std::max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {

    int numsSize;
    std::cin >> numsSize;

    std::vector<int> nums(numsSize);
    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }
    
    std::cout << solve(nums) << std::endl;
    nums.clear();
  }

  return 0;
}