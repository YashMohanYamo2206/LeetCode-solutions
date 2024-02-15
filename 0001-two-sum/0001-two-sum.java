class Solution { 
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> vals = new HashMap<>();
        for(int i = 0; i < nums.length; ++i){
            int comp = target - nums[i];
            if(vals.containsKey(comp)){
                return new int[] {i, vals.get(comp)};
            }
            vals.put(nums[i], i);
        }
        return new int[2];
    }
}