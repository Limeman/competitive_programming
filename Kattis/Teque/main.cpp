#include<cstdio>

class teque {
    public:
    teque(): head(nullptr), tail(nullptr), stomach(nullptr) {}

    void push_back(int x) {
        node* tmp = new node(x);
        if (head == nullptr) {
            head = tmp;
            stomach = tmp;
            tail = tmp;
        }
        else {
            tmp->prev = this->tail;
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }
    void push_front(int x) {
        node* tmp = new node(x);
        if (head == nullptr) {
            head = tmp;
            stomach = tmp;
            tail = tmp;
        }
        else {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }
    void push_mid(int x) {
        node* tmp = new node(x);
        if (head == nullptr) {
            head = tmp;
            stomach = tmp;
            tail = tmp;
        }
        else if (head == tail) {
            push_back(x);
        }
        else if (stomach == tail) {
            tmp->prev = head;
            tmp->next = tail;
            head->next = tmp;
            tail->prev = tmp;
            stomach = tmp;
        }
        else {
            tmp->prev = stomach;
            tmp->next = stomach->next;
            stomach->next = tmp;
            stomach->next->prev = tmp;
            stomach = tmp;
        }
    }
    int get(int i) {
        node* curr = head;
        while (i--) {
            //printf("%d\n", i);
            curr = curr->next;
        }
        return curr->val;
    }

    void print() {
        node* curr = head;
        while (curr != nullptr) {
            printf("%d\n", curr->val);
            curr = curr->next;
        }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }

    private:
    struct node {
        node(int x): val(x), next(nullptr), prev(nullptr) {}

        node* next;
        node* prev;
        int val;
    };
    node* head;
    node* tail;
    node* stomach;
};

int main() {
    teque vals;
    int val, n;
    char command[12];

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", command, &val);
        if (command[0] == 'g') {
            printf("%d\n", vals.get(val));
        }
        else if (command[5] == 'b') {
            vals.push_back(val);
        }
        else if (command[5] == 'f') {
            vals.push_front(val);
        }
        else {
            vals.push_mid(val);
        }
        //vals.print();
    }
    return 0;
}