/**
 * List implementation by Rodolfo M
 */

#include <iostream>

using namespace std;

struct node {
    int value;
    node *next;
};

class List {
    private:
        node *head, *tail;
    public:
        List(){
            head = NULL;
            tail = NULL;
        }

        void push_back(int value) {
            node *new_node = new node;
            new_node->value = value;
            new_node->next = NULL;

            if(head == NULL) {
                head = new_node;
                tail = new_node;
                new_node = NULL;
            }
            else {
                tail->next = new_node;
                tail = new_node;
            }
        }

        int get(int pos) {
            int i=0;
            node *curr = head;
            while(i++<pos) {
                curr = curr->next;
            }
            return curr->value;
        }

        void display() {
            node *temp = head;
            while(temp!=NULL){
                cout << temp->value << ' ';
                temp = temp->next;
            }
        }

        void insert(int value, int pos) {
            node *pre = head;
            node *post = head;
            node *new_node = new node;
            new_node->value = value;

            for(int i=0; i<pos; i++){
                pre = post;
                post = post->next;
            }

            new_node->next = post;
            pre->next = new_node;
        }

        void erase(int pos) {
            node *pre = head;
            node *post = head;

            for(int i=0; i<pos; i++){
                pre = post;
                post = post->next;
            }

            pre->next = post->next;
            delete post;
        }
};

int main () {
    List list = new List();

    list.push_back(5);
    list.push_back(7);
    list.push_back(10);

    list.display();

    list.insert(8, 2);

    return 0;
}
