#include<iostream>

class teque {
    public:
        teque():head(nullptr), stomach(nullptr), tail(nullptr) {}
        teque(const teque& arg) {
            this->head = arg.head;
            this->stomach = arg.stomach;
            this->tail = arg.tail;
        }
        teque& operator= (const teque& arg) {
            node* tmp;
            while (this->head != nullptr) {
                tmp = this->head;
                this->head = this->head->next;
                tmp->next = nullptr;
                delete tmp;
            }
            tmp = arg.head;
            while (tmp->next != nullptr) {
                if (tmp == arg.head) {
                    this->head = new node(tmp->val);
                    this->tail = this->head;
                }
                else {
                    
                }
                tmp = tmp->next;
            }
        }
    private:
        struct node {
            node(int val):val(val), next(nullptr), prev(nullptr) {}
            node(int val, node* next): val(val), next(next), prev(nullptr) {}
            node(const node&arg) {
                this->val = arg.val;
                this->next = arg.next;
                this->prev = arg.prev;
            }
            node& operator = (const node &arg) {
                this->val = arg.val;
                this->next = arg.next;
                this->prev = arg.prev;
                return *this;
            }
            ~node() {}
            int val;
            node* prev;
            node* next;
        };
        node* head;
        node* stomach;
        node* tail;
};

int main() {
    teque t;
    return 0;
}