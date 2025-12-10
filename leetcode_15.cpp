// Given an integer array nums, return all the triplets (nums(i], nums(jl, nums(k]l suchthat i != j, i != k, and j != k, and nums[i] + numsjl + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

#include <iostream>
#include <vector>

std::vector<std::vector<int>> solve(int *nums, int numsSize)
{
  std::vector<std::vector<int>> result;
  std::sort(nums, nums + numsSize);

  for (int i = 0; i < numsSize - 2; i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
    {
      continue;
    }

    int left = i + 1;
    int right = numsSize - 1;

    while (left < right)
    {
      int total = nums[i] + nums[left] + nums[right];

      if (total == 0)
      {
        result.push_back({nums[i], nums[left], nums[right]});
        left++;
        right--;

        while (left < right && nums[left] == nums[left - 1])
        {
          left++;
        }
        while (left < right && nums[right] == nums[right + 1])
        {
          right--;
        }
      }
      else if (total < 0)
      {
        left++;
      }
      else
      {
        right--;
      }
      delete[] nums;
    }
  }

  return result;
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int numsSize;
    std::cin >> numsSize;

    int *nums = new int[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }

    auto result = solve(nums, numsSize);

    for (auto triplet : result)
    {
      std::cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]\n";
    }

    delete[] nums;
  }

  return 0;
}
