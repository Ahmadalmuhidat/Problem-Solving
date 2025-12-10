// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1 .
// You must write an algorithm with o(log n) runtime complexity.

#include <iostream>

int solve(std::vector<int>& nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  while(left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
}

int main()
{
  int N;
  std::cin >> N;

  while (N --)
  {
    int M, target;
    std::cin >> M >> target;
    std::vector<int> nums(M);
    for (int i = 0; i < M; i ++)
    {
      std::cin >> nums[i];
    }

    std::cout << solve(nums, target) << std::endl;
  }

  return 0;
}

