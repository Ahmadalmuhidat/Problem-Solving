// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

#include <iostream>
#include <algorithm>

void solve(int* nums, int numsSize, int k)
{
  int left = 0;
  int right = left + k - 1;

  while (right < numsSize)
  {
    int maxVal = nums[left];

    for (int i = left; i <= right; i++)
    {
      if (nums[i] > maxVal)
      {
        maxVal = nums[i];
      }
    }

    std::cout << maxVal << " ";

    left++;
    right++;
  }

  std::cout << std::endl;
}


int main()
{
  int N;
  std::cin >> N;

  while (N --)
  {
    int numsSize, k;
    std::cin >> numsSize, k;

    int* nums = new int[numsSize];

    for (int i = 0; i < numsSize; i++)
    {
      std::cin >> nums[i];
    }

    solve(nums, numsSize, k);
    delete[] nums;
  }

  return 0;
}