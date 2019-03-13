#include<iostream>
using namespace std;

class node {
public :
    int data;
    node * next;
    node(int d) {   //constructor
        data = d;   //initializes int member "data" as d
        next = NULL;    //initializes next as NULL
    }
};

node* merge(node* a,node* b) {      //see inputing manner of this program
    if(a == NULL) {
        return b;
    }
    if(b == NULL) {
        return a;
    }
    node *c;

    if(a->data < b->data) {
        c = a;
        c->next = merge(a->next,b);
    }
    else {
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}

void disp(node *head) {
    while(head != NULL) {
        cout<<head->data<<"  ";
        head = head->next;
    }
}

void insertAtHead(node *&head,int data) {       // (node*) is like data type of head
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}


int main() {
  int t,n,d;
  cin>>t;
  node *ans[t + 1];
  for(int i = 0;i < t;i++) {
    cin>>n;
    int d1[n];
    for(int j = 0;j < n;j++) {
      cin>>d1[j];
    }
    node *head1;
    head1 = NULL;
    for(int j = 0;j < n;j++) {
      insertAtHead(head1,d1[n - j - 1]);
    }
    cin>>n;
    int d2[n];
    for(int j = 0;j < n;j++) {
      cin>>d2[j];
    }
    node *head2;
    head2 = NULL;
    for(int j = 0;j < n;j++) {
      insertAtHead(head2,d2[n - j - 1]);
    }
    ans[i] = merge(head1,head2);
    disp(ans[i]);
    delete head1;
    delete head2;
  }
  for(int i =0;i < t;i++) {
    //disp(ans[i]);
  }
	return 0;
}
