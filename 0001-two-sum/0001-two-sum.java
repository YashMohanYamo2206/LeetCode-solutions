class Solution {
    class SortPair implements Comparator<Pair<Integer , Integer>> { 
        // Used for sorting in ascending order of 
        // roll number 
        public int compare(Pair<Integer , Integer> a, Pair<Integer , Integer> b) 
        { 
            return a.getKey() - b.getKey(); 
        } 
    } 
 
    public int[] twoSum(int[] nums, int target) {
        List<Pair<Integer , Integer>> vals = new ArrayList<>();
        for(int i = 0; i < nums.length; ++i){
            vals.add(new Pair<Integer, Integer>(nums[i], i));
        }
        Collections.sort(vals, new SortPair());
        int l = 0, r = nums.length - 1, sum;
        while(l < r){
            sum = vals.get(l).getKey() + vals.get(r).getKey();
            if(sum == target){
                int[] indices = {vals.get(l).getValue(), vals.get(r).getValue()};
                return indices;
            }
            if(sum < target){
                l++;
            } else {
                r--;
            }
        }
        return nums;
    }
}