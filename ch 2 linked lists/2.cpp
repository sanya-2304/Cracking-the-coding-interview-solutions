// Remove Dups: Write code to remove duplicates from an unsorted linked list. 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
// [Naive Approach] Finding the length of list - Two Pass 
//  O(N) Time and O(1) Space
int getKthFromLast(Node *head, int k) {
        // Your code here
        int n=0;
        Node* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        temp=head;
        if(k>n) return -1;
        int reachpt=n-k;
        while(reachpt!=0){
            temp=temp->next;
            reachpt--;
        }
        return temp->data;
    }


void printList(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(1);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(4);
    printList(head);
   cout<<getKthFromLast(head, 4)<<endl;
    return 0;
}

