// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height [i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

#include <iostream>

int solve(int *nums, int numsSize)
{
  int left = 0, right = numsSize - 1, maxArea = 0;

  while (left < right)
  {
    int height = std::min(nums[left], nums[right]);
    int width = right - left;
    int area = height * width;

    maxArea = std::max(maxArea, area);

    if (nums[left] < nums[right])
    {
      left++;
    }
    else
    {
      right--;
    }
  }

  return maxArea;
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

    std::cout << result << std::endl;
    delete[] nums;
  }

  return 0;
}
