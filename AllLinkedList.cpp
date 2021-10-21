

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data; 
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head; 
    head = n;

}

void insertAtTail(node* &head,int val){
    //case where head is null

    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;

}


void display(node* head){
    node* temp = head; 
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletAtHead(node* &head){
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node* &head,int val){

    if(head == NULL){
        return;
    }

    if(head->next == NULL){ //it means our first element is last element
        deletAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

//iterative way to reverse link list
node* reverse(node* &head){
    node* prevptr =NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

//recursive way to reverse a linked list
node* reverseRecursive(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
 
    return newhead;
}

//detect a cycle in a linked list
//flaids or hair and tortise algo

//we can use slow or fast pointer here
// where slow pointer 1 step and fast pointer traverse 
//2 step if they meet at same point then the cycle is present in linked list

void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){  //upto last
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectcycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            return true;
        }
    } 
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int main( ) {
    node* head = NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtHead(head,25);
    insertAtHead(head,50);
    display(head);
    // node* newhead = reverseRecursive(head);
    // display(newhead);
    makeCycle(head,3);
    // display(head);
    cout<<detectcycle(head)<<endl;
    removeCycle(head);
    cout<<detectcycle(head)<<endl;
    display(head);


    
    return 0;
}
