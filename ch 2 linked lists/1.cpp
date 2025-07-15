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
// with temp buffer: tc: O(n) sc: O(n)
Node* removeDuplicates(Node *head) {
        Node* curr=head;
        Node* prev=nullptr;
        unordered_set<int>hashSet;
        while(curr!=NULL){
            if(hashSet.find(curr->data)!=hashSet.end()){
                    Node* del=curr;
                    prev->next=curr->next;
                    curr=curr->next;
                    delete del;
            }else {
                hashSet.insert(curr->data);
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }

// without temp buffer : tc: O(n^2) sc: O(1) - TLE
Node* removeDupsUnsorted(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* one=temp;
        while(one->next){
            if(one->next->data==temp->data){
                Node* del=one->next;
                one->next=one->next->next;
                delete del;
            }else{
                one=one->next;
            }
        }
        temp=temp->next;
    }
    return head;
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
    // head=removeDupsUnsorted(head);
    head=removeDuplicates(head);
    printList(head);
    return 0;
}

