//Arrange elements in a Linked List such that all even numbers are placed after odd numbers.
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
void segregateEvenOdd(node **head_ref)  
{  
    node *end = *head_ref;  
    node *prev = NULL;  
    node *curr = *head_ref;  
  
    /* Get pointer to the last node */
    while (end->next != NULL)  
        end = end->next;  
  
    node *new_end = end;  
  
    /* Consider all odd nodes before the first  
     even node and move then after end */
    while (curr->data % 2 != 1 && curr != end)  
    {  
        new_end->next = curr;  
        curr = curr->next;  
        new_end->next->next = NULL;  
        new_end = new_end->next;  
    }  
  
    // 10->8->17->17->15  
    /* Do following steps only if  
    there is any even node */
    if (curr->data%2 == 1)  
    {  
        /* Change the head pointer to  
        point to first even node */
        *head_ref = curr;  
  
        /* now current points to 
        the first even node */
        while (curr != end)  
        {  
            if ( (curr->data) % 2 == 1 )  
            {  
                prev = curr;  
                curr = curr->next;  
            }  
            else
            {  
                /* break the link between 
                prev and current */
                prev->next = curr->next;  
  
                /* Make next of curr as NULL */
                curr->next = NULL;  
  
                /* Move curr to end */
                new_end->next = curr;  
  
                /* make curr as new end of list */
                new_end = curr;  
  
                /* Update current pointer to 
                next of the moved node */
                curr = prev->next;  
            }  
        }  
    }  
  
    /* We must have prev set before executing  
    lines following this statement */
    else prev = curr;  
  
    /* If there are more than 1 odd nodes  
    and end of original list is odd then  
    move this node to end to maintain  
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 1)  
    {  
        prev->next = end->next;  
        end->next = NULL;  
        new_end->next = end;  
    }  
    return;  
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
  segregateEvenOdd(&head);
  while(head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
	return 0;
}
