//Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

#include<iostream>
using namespace std;

class node {
public:
  int data;
  node* next;
  node(int d) {
    data = d;
    next = NULL;
  }
};

void insert(node* &head,int d) {
  if(head == NULL) {
    head = new node(d);
    return;
  }
  node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new node(d);
}

int main() {
  int k,input;
  node* head = NULL;
  cin>>input;
  while(input != -1) {
    insert(head,input);
    cin>>input;
  }
  cin>>k;
  node* fast = head;
  while(k--) {
    fast = fast->next;
  }
  while(fast != NULL) {
    fast = fast->next;
    head = head->next;
  }
  cout<<head->data;
	return 0;
}
