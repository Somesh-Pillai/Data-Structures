#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next; //like int *ptr pointer
};
void printList(Node* n)  //printing from the given node
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
void push(Node** head_ref, int new_data)  //front push
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node; //head becomes new node
}
bool detectLoop(Node* h){
  unordered_set <Node*> s;   //hashtable with keys to indices
  while(h!=NULL){
    if(s.find(h) != s.end()) //find() returns the iterator of the key if found or else it returns end() of set
       return true;
    s.insert(h);  //inserting all nodes when encountered and checks if the same node is found again in the set
    h=h->next;
  }
    return false;
}
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Created Linked list is: ";
    printList(head);

    //creating a loop for testing
    head->next->next->next=head;
    if(detectLoop(head)==true)
      cout<<"\nLOOP EXISTS"<<" ";
  return 0;

  }
