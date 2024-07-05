class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int firstCriticalPoint = 0;
        int prevCriticalPoint = 0;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;

        while (curr->next != NULL) {
            // found local minima
            if (prev->val > curr->val and curr->val < curr->next->val) {
                if (firstCriticalPoint == 0) {
                    firstCriticalPoint = i;
                    prevCriticalPoint = i;
                } else {
                    minDist = min(minDist, i - prevCriticalPoint);
                    prevCriticalPoint = i;
                }
            }
            // found local maxima
            if (prev->val < curr->val and curr->val > curr->next->val) {
                if (firstCriticalPoint == 0) {
                    firstCriticalPoint = i;
                    prevCriticalPoint = i;
                } else {
                    minDist = min(minDist, i - prevCriticalPoint);
                    prevCriticalPoint = i;
                }
            }
            i++;
            prev = curr;
            curr = curr->next;
        }

        if(minDist == INT_MAX){
            return {-1, -1};
        }
        return {minDist, prevCriticalPoint - firstCriticalPoint};
    }
};