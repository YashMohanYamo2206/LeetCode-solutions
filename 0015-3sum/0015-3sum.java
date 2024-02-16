class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        List<List<Integer>> res = new ArrayList<>();

        Arrays.sort(num);

        for (int i = 0; i < num.length; i++) {

            int target = -num[i];
            int front = i + 1;
            int back = num.length - 1;

            if(target < 0)
            {
                break;
            }

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(num[i]);
                    triplet.add(num[front]);
                    triplet.add(num[back]);
                    res.add(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet.get(1)) front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet.get(2)) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < num.length && num[i + 1] == num[i]) 
                i++;

        }
        return res;

    }
}