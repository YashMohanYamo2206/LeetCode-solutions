class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        Set<Character> currentSubStr = new HashSet<Character>();
        int l = 0, maxUnqLen = 0;
        for (int r = 0; r < s.length(); r++) {
            while (currentSubStr.contains(s.charAt(r))){
                currentSubStr.remove(s.charAt(l));
                l++;
            }
            maxUnqLen = Math.max(maxUnqLen, r - l + 1);
            currentSubStr.add(s.charAt(r));
        }
        return maxUnqLen;
    }
}