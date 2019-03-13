//Given a linked list with n nodes. Sort the linked list using insertion sort.
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

  
/* function to insert a new_node in a list. Note that this 
  function expects a pointer to head_ref as this can modify the 
  head of the input linked list (similar to push())*/
void sortedInsert(node** head_ref, node* new_node) 
{ 
    node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 
void insertionSort(node **head_ref) 
{ 
    // Initialize sorted linked list 
    node *sorted = NULL; 
  
    // Traverse the given linked list and insert every 
    // node to sorted 
    node *current = *head_ref; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
        node *next = current->next; 
  
        // insert current in sorted linked list 
        sortedInsert(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
    *head_ref = sorted; 
} 
  
int main() {
  int n,d;
  node* head;
  cin>>n>>d;
  head = new node(d);
  node* temp = head;
  for(int i = 1;i < n;i++) {
    cin>>d;
    temp->next = new node(d);
    temp = temp->next;
  }
  insertionSort(&head);
  while(head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
	return 0;
}
