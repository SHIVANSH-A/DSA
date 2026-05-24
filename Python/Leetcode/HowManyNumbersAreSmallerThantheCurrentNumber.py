# Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

# Return the answer in an array.

 

# Example 1:

# Input: nums = [8,1,2,2,3]
# Output: [4,0,1,1,3]
# Explanation: 
# For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
# For nums[1]=1 does not exist any smaller number than it.
# For nums[2]=2 there exist one smaller number than it (1). 
# For nums[3]=2 there exist one smaller number than it (1). 
# For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
# Example 2:

# Input: nums = [6,5,4,8]
# Output: [2,1,0,3]
# Example 3:

# Input: nums = [7,7,7,7]
# Output: [0,0,0,0]
 

# Constraints:

# 2 <= nums.length <= 500
# 0 <= nums[i] <= 100

# class Solution(object):
#     def smallerNumbersThanCurrent(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[int]
#         """
#         res = [0]*len(nums)
#         for i in range(0,len(nums)):
#             for j in nums:
#                 if(nums[i]>j):
#                     res[i]+=1
#         return res

class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [0] * (max(nums) + 1)

        # Count frequency of each number
        for i in nums:
            res[i] += 1

        # Prefix sum
        for i in range(1, max(nums) + 1):
            res[i] += res[i - 1]

        # Result
        return [0 if i == 0 else res[i - 1] for i in nums]


# Main function
if __name__ == "__main__":
    nums = list(map(int, input("Enter numbers separated by space: ").split()))

    obj = Solution()
    ans = obj.smallerNumbersThanCurrent(nums)

    print("Result:", ans)