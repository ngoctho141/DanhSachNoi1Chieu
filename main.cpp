#include <iostream>
struct node{
    int data;
    node *next;
};
void push_back(node& head, node &x) {
    //node tmp2 = head; //địa chỉ tmp2 khác head
    node* tmp = &head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = &x;
}
//Cách 1
/*void push_forward(node** head, node& x){
    x.next = *head;
    *head = &x;
}*/
void push_forward(node*& head, node& x){
    x.next = *&head;
    head = &x;
}
void printList(node head){
    node * tmp = &head;
    do{
    std::cout << tmp->data << std::endl;
    tmp = tmp->next;
    }while(tmp!=NULL);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    node head,a,b,c,d,e,f;
    head.data = 1;
    head.next = NULL;
    a.data = 2;
    a.next = NULL;
    b.data = 3;
    b.next = NULL;
    c.data = 4;
    c.next = NULL;
    d.data = 5;
    d.next = NULL;
    push_back(head, a);
    push_back(head, b);
    push_back(head, c);
    push_back(head, d);

    e.data = -1;
    e.next = NULL;
    f.data = -2;
    f.next = NULL;

    //Cách 1, tiếp ở main
    /*node * tmp = &head;
    push_forward(&tmp,e);

    printList(*tmp);*/

    node * tmp = &head;
    push_forward(tmp,e);
    push_forward(tmp,f);
    printList(*tmp);


    return 0;
}
