/Check if a linked list is a palindrome.( Boolean return type )
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

int kLast(node* head,int k) {
  node* fast = head;
  while(k--) {
    fast = fast->next;
  }
  while(fast != NULL) {
    fast = fast->next;
    head = head->next;
  }
  return head->data;
}

bool isPalindrome(node* head,int n) {
  node* temp = head;
  for(int i = 1;i <= n / 2;i++) {
    int first = head->data;
    int last = kLast(temp,i);
    head = head->next;
    if(first != last) {
      return false;
    }
  }
  return true;
}

int main() {
  int n,input;
  cin>>n;
  node* head = NULL;
  for(int i = 0;i < n;i++) {
    cin>>input;
    insert(head,input);
  }
  if(isPalindrome(head,n)) {
    cout<<"True";
  }
  else {
    cout<<"False";
  }
	return 0;
}
