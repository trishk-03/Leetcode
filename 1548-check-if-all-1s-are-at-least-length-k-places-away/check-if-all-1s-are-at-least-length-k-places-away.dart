class Solution {
  bool kLengthApart(List<int> nums, int k) {
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] == 1) {
        for (int j = i + 1; j <= i + k && j < nums.length; j++) {
          if (nums[j] == 1) return false;
        }
      }
    }
    return true;
  }
}
