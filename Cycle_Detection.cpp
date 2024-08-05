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

bool iscycle(node* head){
    if(head || head->next){
        return false;
    }
    node *slow = head;
    node* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
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
    head->next->next->next->next = new node(5);
    // if(iscycle(head)){
    //     cout<<"\nYes, Cycle is Detected\n";
    // }else{
    //     cout<<"\nNo Cycle Detected\n";
    // }
    // creating the cycle to check for a cycle
    cout<<"\nCreated the cycle link manually at 3rd node\n";
    node*cyclenode = head->next->next;
    node* cur = head;
    printList(head);
    while(cur->next!=nullptr){
        cur = cur->next; 
    }
    cur->next = cyclenode;
    if(iscycle(head)){
        cout<<"\nYes, Cycle is Detected\n";
    }else{
        cout<<"\nNo Cycle Detected\n";
    }
    
    
    return 0;

}