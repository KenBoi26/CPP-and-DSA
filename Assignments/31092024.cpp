#include <iostream>
using namespace std;

void sort(node* &head){
    if (head == NULL)
        return;
    node* odd = head;
    node* even = head->next;
    node* temp = even->next;
    node* evenStart = even;
    bool flag = 0;
    while(temp != nullptr){
        if (flag){
            even->next = temp;
            even = even->next;
        }else{
            odd->next = temp;
            odd = odd->next;
        }
        temp = temp->next;
        flag = !flag;
    }
    odd->next = evenStart;
    even->next = NULL;
}