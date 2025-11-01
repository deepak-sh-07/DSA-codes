
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = head;
        ListNode* tempd = dummy;
        while(temp){
            if(mp.find(temp->val)==mp.end()){
                tempd->next = temp;
                tempd = tempd->next;
            }
            temp = temp->next;
        }
        tempd->next = NULL;
        return dummy->next;
    }
};
