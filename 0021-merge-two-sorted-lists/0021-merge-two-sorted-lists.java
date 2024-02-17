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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null){
            return null;
        }
        ListNode mergedList, dummyList = new ListNode();
        mergedList = dummyList;
        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                dummyList.next = list1;
                list1 = list1.next;
            } else {
                dummyList.next = list2;
                list2 = list2.next;
            }
            dummyList = dummyList.next;
        }
        while(list1 != null){
            dummyList.next = list1;
            list1 = list1.next;
            dummyList = dummyList.next;
        }
        while(list2 != null){
            dummyList.next = list2;
            list2 = list2.next;
            dummyList = dummyList.next;
        }
        return mergedList.next;
    }
}