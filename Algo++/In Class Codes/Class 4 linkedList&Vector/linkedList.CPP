#include<iostream>
using namespace std;


//XOR list ,not use as can only traverse from end to end
//Try with head and tail ,doubly linked list

//In singly link list
//find 3rd last element
//convert into a1->an->a2->a(n-1)->..........
//reverse in parts

//Complexity of merge sort = nlogn
class node {
public :
    int data;
    node * next;
    node(int d) {   //constructor
        data = d;   //initializes int member "data" as d
        next = NULL;    //initializes next as NULL
    }
};

/*
class linkedList {
    node * head;
    node * tail;
public :
    void add()
};
*/

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

void insertInMiddle(node*&head,int data,int pos) {
    if(pos == 0) {
        insertAtHead(head,data);
        return;
    }
    node * temp = head;
    int i = 0;
    while(temp != NULL) {
        if(i == pos) {
            node * n = new node(data);
            n->next = temp->next;
            temp->next = n;
            break;
        }
        i++;
        temp = temp->next;
    }
}

void deleteAtHead(node*&head) {
    if(head != NULL) {
        node*temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteInMiddle(node *&head,int pos) {
    if(pos == 0) {
        deleteAtHead(head);
        return;
    }
    node * temp = head;
    node* prev = head;
    int i = 0;
    while(temp != NULL) {
        if(i == pos) {
            node * n = temp;
            prev->next = temp->next;
            temp->next = NULL;
            delete n;
            break;
        }
        i++;
        prev = temp;
        temp = temp->next;
    }
}

istream& operator>>(istream &a,node*&head) {
    int d;
    cin>>d;
    while(d != -1) {
        insertAtHead(head,d);
        cin>>d;
    }
    return a;
}

ostream& operator<<(ostream &a,node*head) {
    disp(head);
    return a;
}

bool search(node *head,int key) {
    //Base Case
    if(head == NULL) {
        return false;
    }
    //Rec Case
    if(head->data == key) {
        return true;
    }
    return search(head->next,key);
}

void reverse(node *&head) {
    node * temp = head;
    node * prev = NULL;
    /*
    if(temp != NULL) {
        temp = temp->next;
    }
    head->next = NULL;
    node*prev = head;
    */
    while(temp != NULL) {
        node * nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    head = prev;
}
/*
// My Algo for recReverse

node* prev = head;
recReverse(head->next);
head->next = prev;
*/
node* myRecReverse(node* prev, node* curr) {    // Initial call as myRecReverse(NULL, head)
    if(curr->next == NULL) {
        curr->next = prev;
        return curr;
    }
    node* currNext = curr->next;
    curr->next = prev;
    prev = curr;
    return myRecReverse(prev, currNext);
}

node * recReverse(node*head) {
    //Base
    if(head->next == NULL) {
        return head;
    }
    //Rec
    node*chotaHead = recReverse(head->next);
    node *temp = chotaHead;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return chotaHead;
}

node* midPoint(node*head) {
    node * slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* a,node* b) {      //see inputing manner of this program
    if(a == NULL) {
        return b;
    }
    if(b == NULL) {
        return a;
    }
    node *c;

    if(a->data < b->data) {
        c = new node(a->data);
        c->next = merge(a->next,b);
    }
    else {
        c = new node(b->data);
        c->next = merge(a,b->next);
    }
    return c;
}

node* mergeSort(node *l) {
    if(l == NULL || l->next == NULL) {
        return l;
    }
    node * mid = midPoint(l);
    node *a = l;
    node *b = mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a,b);
}

int main() {
    node *a = NULL;
    node *b = NULL;
    cin>>a;
    cout<<"\nB: ";
    cin>>b;
    node *c = NULL;
    c = merge(a,b);
    //7 5 3 1 -1
    //8 6 4 2 -1
    disp(c);
    /*
    node*head = NULL;
    cin>>head;
    
    //insertAtHead(head,5);
    //insertAtHead(head,6);
    //insertAtHead(head,7);
    
    insertInMiddle(head,4,1);
    
    disp(head);
    reverse(head);
    cout<<endl;
    disp(head);
    head = recReverse(head);
    cout<<endl;
    disp(head);
    */
    cout<<"\nLOL";
    return 0;
}

//Sample Input 
//1 2 3 5 6 -1