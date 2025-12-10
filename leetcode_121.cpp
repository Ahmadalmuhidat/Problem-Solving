// You are given an array prices where prices(il is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <iostream>

int solve(int *nums, int numsSize)
{
  int buying_price = nums[0];
  int max_profit = 0;

  for (int i = 1; i < numsSize; i++)
  {
    int profit = nums[i] - buying_price;
    if (profit > max_profit)
    {
      max_profit = profit;
    }

    if (nums[i] < buying_price)
    {
      buying_price = nums[i];
    }
  }

  return max_profit;
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

    std::cout << solve(nums, numsSize) << std::endl;
    delete[] nums;
  }

  return 0;
}