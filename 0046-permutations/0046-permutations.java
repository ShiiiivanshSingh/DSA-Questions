import java.util.*;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        perm(nums, 0, result);
        return result;
    }

    static void perm(int[] nums, int idx, List<List<Integer>> result) {
        if (idx == nums.length) {
            List<Integer> temp = new ArrayList<>();
            for (int num : nums) temp.add(num);
            result.add(temp);
            return;
        }
        for (int i = idx; i < nums.length; i++) {
            swap(nums, i, idx);
            perm(nums, idx + 1, result);
            swap(nums, i, idx);
        }
    }

    static void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
