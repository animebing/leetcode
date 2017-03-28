/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// almost the same as grapy clone, but here only two neighbors
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        if (visited[head]) return visited[head];
        visited[head] = new RandomListNode(head->label);
        visited[head]->next = copyRandomList(head->next);
        visited[head]->random = copyRandomList(head->random);
        return visited[head];
    }
private:
    unordered_map<RandomListNode *, RandomListNode *> visited;
};



// based on the solution of liaison, https://discuss.leetcode.com/topic/7594/a-solution-with-constant-space-complexity-o-1-and-linear-time-complexity-o-n
// this method doesn't need extra space
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *iter = head;
        // copy the list and form a long linked list
        while (iter) {
            RandomListNode *next = iter->next;
            RandomListNode *copy = new RandomListNode(iter->label);
            iter->next = copy;
            copy->next = next;
            iter = next;
        }
        
        // random pointer in copied element
        iter = head;
        while (iter) {
            RandomListNode *next = iter->next->next;
            if (iter->random) iter->next->random = iter->random->next;
            iter = next;
        }
        
        // restore the original list, and extract the copy list
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *tmp = dummy;
        iter = head;
        while (iter) {
            RandomListNode *next = iter->next->next;
            tmp->next = iter->next;
            tmp = tmp->next;
            iter->next = next;
            iter = next;
        }
        return dummy->next;
    }
};