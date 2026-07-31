def find_max_min(nums):

    maximum = nums[0]
    minimum = nums[0]

    for num in nums:
        if num > maximum:
            maximum = num

        if num < minimum:
            minimum = num

    return maximum, minimum

nums = [int(x) for x in input("\nEnter numbers separated by spaces: ").split()]

maximum, minimum = find_max_min(nums)

print("\nMaximum value:", maximum)
print("Minimum value:", minimum, "\n")