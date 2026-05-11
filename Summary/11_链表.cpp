/*
 * 考点：链表 (Linked List)
 * 常见操作：遍历、反转、合并、检测环
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 1. 反转链表
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. 反转链表前 n 个节点
ListNode* reverseN(ListNode* head, int n) {
    ListNode* successor = nullptr;
    function<ListNode*(ListNode*, int)> reverse = 
        [&](ListNode* node, int n) -> ListNode* {
        if (n == 1) {
            successor = node->next;
            return node;
        }
        ListNode* last = reverse(node->next, n - 1);
        node->next->next = node;
        node->next = successor;
        return last;
    };
    return reverse(head, n);
}

// 3. 两两交换节点
ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    
    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = first->next;
        
        first->next = second->next;
        second->next = first;
        prev->next = second;
        
        prev = first;
    }
    return dummy.next;
}

// 4. 合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// 5. 删除链表的倒数第 N 个节点
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;
    
    return dummy.next;
}

// 6. 链表是否有环
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 7. 环形链表入口
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 8. 相交链表
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

// 9. 复制带随机指针的链表
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    
    // 第一遍：复制节点并连接
    Node* cur = head;
    while (cur) {
        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    
    // 第二遍：复制 random 指针
    cur = head;
    while (cur) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    
    // 第三遍：分离两个链表
    Node* newHead = head->next;
    cur = head;
    while (cur) {
        Node* copy = cur->next;
        cur->next = copy->next;
        if (copy->next) copy->next = copy->next->next;
        cur = cur->next;
    }
    return newHead;
}

/*
 * 链表技巧：
 * 1. dummy 头节点：简化边界处理
 * 2. 快慢指针：检测环、找中点
 * 3. 前后指针：找倒数第 k 个节点
 * 4. 穿针引线：反转链表
 */
