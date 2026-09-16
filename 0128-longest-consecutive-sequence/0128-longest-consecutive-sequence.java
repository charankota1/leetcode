class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return 1;

        Arrays.sort(nums);

        int currentStreak = 1;
        int longestStreak = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - 1 == nums[i - 1]) {
                currentStreak++;
                longestStreak = Math.max(longestStreak, currentStreak);
            } else if (nums[i] != nums[i - 1]) {
                currentStreak = 1;
            }
        }

        return longestStreak;
    }
}
