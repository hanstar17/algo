// https://leetcode.com/problems/add-to-array-form-of-integer/

// provided by leetcode
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
// provided by leetcode end

#include <vector>
#include <unordered_map>
Node *DeepCopy(Node *head) {
    if (!head)
        return nullptr;
    
    std::unordered_map<Node *, Node *> map;
    Node *copyHead = new Node(head->val, head->next, head->random);
    map[head] = copyHead;
    head = head->next;
    while (head) {
        Node *copy = new Node(head->val, head->next, head->random);
        map[head] = copy;
        head = head->next;
    }

    head = copyHead;
    while (head) {
        head->next = map[head->next];
        head->random = map[head->random];
        head = head->next;
    }
    
    return copyHead;
}

#include <iostream>
int main() {
    std::vector<Node> a(2);
    a[0].val = 1;
    a[0].next = &a[1];
    a[0].random = &a[1];

    a[1].val = 2;
    a[1].next = nullptr;
    a[1].random = &a[1];

    for (int i = 1; i < a.size(); ++i)
        a[i - 1].next = &a[i];
    
    auto copied = DeepCopy(a.data());
    while (copied) {
        int val = copied->val;
        int nextVal = copied->next ? copied->next->val : -1;
        int randomVal = copied->random ? copied->random->val : -1;
        std::cout << val << ", " << nextVal << ", " << randomVal << std::endl;
        
        copied = copied->next;
    }
    return 0;
}