//Append the last K elements of a linked list to the front.K can be greater than N.

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

void disp(node* head) {
  if(head == NULL) {
    return;
  }
  while(head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
}

int main() {
  int n,k,input;
  cin>>n;
  node* head = NULL;
  for(int i = 0;i < n;i++) {
    cin>>input;
    insert(head,input);
  }
  cin>>k;
  if(k >= n) {
    k = k % n;
  }
  node* fast = head;
  node* slow = head;
  for(int i = 0;i < k;i++) {
    fast = fast->next;
  }
  node* temp = NULL;
  while(fast->next != NULL) {
    fast = fast->next;
    temp = slow;
    slow = slow->next;
  }
  fast->next = head;
  head = slow->next;
  temp->next->next = NULL;
  disp(head);
	return 0;
}
