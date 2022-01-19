#include<iostream>
#include<vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        vector<ListNode*> v;
        while (true) {
			if (slow == nullptr)
				return nullptr;
			else if (find(v.begin(), v.end(), slow) != v.end()) {
				return slow;
			}
			else {
				v.push_back(slow);
			}
			slow = slow->next;
		}
	    return nullptr;
    }
};
