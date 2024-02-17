/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    class ListNodeComparator implements Comparator<ListNode> {
        public int compare(ListNode s1, ListNode s2) {
            return s1.val - s2.val;
        }
    }
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(new ListNodeComparator());
        for(int i = 0; i < lists.length; ++i){
            if(lists[i] != null){
                pq.add(lists[i]);
            }
        }
        ListNode dummy = new ListNode(), mergedList = dummy;
        while(!pq.isEmpty()){
            ListNode top = pq.poll();
            dummy.next = top;
            dummy = dummy.next;
            if(top.next != null) {
                pq.add(top.next);
            }
        }
        return mergedList.next;
    }
}