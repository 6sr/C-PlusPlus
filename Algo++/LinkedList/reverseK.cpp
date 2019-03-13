//Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size 
//of List.
//You need not have to create a new list. Just reverse the old one using head.#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

node* reverseK (node *head, int k) {
  node* current = head;
  node* next = NULL;
  node* prev = NULL;
  int count = 0;

  while (current != NULL && count < k) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
  if (next != NULL)
    head->next = reverseK(next, k);
  return prev;
}

int main() {
  int n,k,d;
  node* head;
  cin>>n>>k>>d;
  head = new node(d);
  node* temp = head;
  for(int i = 1;i < n;i++) {
    cin>>d;
    temp->next = new node(d);
    temp = temp->next;
  }
  head = reverseK(head,k);
  while(head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
	return 0;
}
