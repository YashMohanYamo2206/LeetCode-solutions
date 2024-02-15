public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0, end = 0, result = 0;
        int[] cache = new int[128];

        for (char c: s.toCharArray()) {
            start = Math.max(start, cache[c]);
            cache[c] = end + 1;
            result = Math.max(result, end - start + 1);
            end++;
        }

        return result;
    }
}