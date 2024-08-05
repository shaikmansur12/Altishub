#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x){
        val = x;
        next = nullptr;
    }
};

node* reverse_Linkedlist(node* head){
    node* curr = head;
    node* prev = nullptr;
    while(curr){
        node* next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(node*head){
    node* curr = head;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    cout<<"Before Reversing the list"<<endl;
    printList(head);
    node* reversed_head = reverse_Linkedlist(head);
    cout<<endl<<"After reversing the list"<<endl;
    printList(reversed_head);
    
    return 0;
}