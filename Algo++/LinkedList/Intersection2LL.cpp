//There are two linked lists. Due to some programming error, the end node of one of the linked list got linked into the second list, 
//forming an inverted Y shaped list. Now it's your job to find the point(Node) at which the two linked lists are intersecting.

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
  int n,m,input;
  cin>>n;
  node* head1 = NULL;
  for(int i = 0;i < n;i++) {
    cin>>input;
    insert(head1,input);
  }
  cin>>m;
  node* head2 = NULL;
  for(int i = 0;i < n;i++) {
    cin>>input;
    insert(head2,input);
  }
  int diff = 0;
  if(n > m) {
    diff = n - m;
  }
  else if(n != m) {
    diff = m - n;
    node* temp = head1;
    head1 = head2;
    head2 = temp;
  }
  for(int i = 0;i < diff;i++) {
    head1 = head1->next;
  }
  int flag = 1;
  while(head1 != NULL) {
    if(head1->data == head2->data) {
      cout<<head1->data;
      flag = 0;
      break;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  if(flag) {
    cout<<"-1";
  }
	return 0;
}
