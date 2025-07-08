class Solution {
public:
    Node* flatten(Node* head) {
        return check(head).first;
    }

    pair<Node*, Node*> check(Node* head){
        if (!head) {
            return {nullptr, nullptr};
        }
        if (!head->next && !head->child) {
            return {head, head};
        }

        Node* temp = head->next;
        Node* childTail = nullptr;

        if (head->child) {
            pair<Node*, Node*> pr = check(head->child);

            head->next = pr.first;
            pr.first->prev = head;
            head->child = nullptr;

            if (temp) {
                pr.second->next = temp;
                temp->prev = pr.second;
            }

            childTail = pr.second;
        }

        if (childTail) {
            // Now flatten what's after the child
            auto nextResult = check(childTail->next);
            return {head, nextResult.second ? nextResult.second : childTail};
        } else if (temp) {
            auto nextResult = check(temp);
            return {head, nextResult.second};
        }

        return {head, childTail ? childTail : head};
    }
};
