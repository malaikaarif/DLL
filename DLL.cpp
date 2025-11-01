#include <iostream>
using namespace std;

// ================================================
//              NODE DEFINITION
// ================================================

class Node{
    public:
     int d;
     Node* next;
     Node* prev;

     Node(int d){
        this -> d =d;
        this -> next = NULL;
        this -> prev = NULL;
     }


     ~Node(){
        int value = this -> d;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data "<< value << endl;
     }
};


// ================================================
//              TRAVERSAL / DISPLAY
// ================================================


void print (Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> d << " ";
        temp = temp -> next;
    }

    cout << endl;
}


// ================================================
//              SEARCHING
// ================================================


bool searchNode(Node* &head, int key){
    Node* temp =head;
    while(temp != NULL){
     if(temp -> d == key){
        return true;
     }
     temp=temp -> next;
    }
    return false;
}



// ================================================
//              INSERTION FUNCTIONS
// ================================================




// ================================================
//              INSERTION AT HEAD
// ================================================



void insertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head=temp;
        tail=temp;
        return;
    }

    temp -> next = head;
    head -> prev = temp;
    head = temp;

}



// ================================================
//              INSERTION AT TAIL
// ================================================



void insertAtTail(Node* &head, Node* &tail , int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head=temp;
        tail=temp;
        return;
    }

    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

}



// ================================================
//              INSERTION AT POSITION
// ================================================




void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    // if position is 1
  if(position == 1){
    insertAtHead(head,tail,d);
    return;
  }

  // traversing
  Node* temp = head;
   int cnt=1;
   while(cnt<position - 1){
     temp=temp -> next;
     cnt++;
   }

   // If position is last one
   if(temp -> next == NULL){
    insertAtTail(head,tail,d);
    return;
   }

   // If position is middle one;

   Node* nodeToInsert = new Node(d);
   nodeToInsert -> next = temp -> next;
   temp -> next -> prev = nodeToInsert;
   temp -> next = nodeToInsert;
   nodeToInsert -> prev = temp;
}




// ================================================
//              DELETION
// ================================================




// ================================================
//              DELETION AT HEAD
// ================================================


void deleteAtHead(Node* &head, Node* & tail){
    // empty list

    if(head == NULL){
        cout<<"List is Empty "<< endl;
        return;
    }

    // in case of one node
    if(head -> next == NULL){
        delete head;
        head=NULL;
        tail=NULL;
        cout<<"node deleted "<< endl;
        return;
    }

    // in case of more than one node
    Node*temp=head;
    head=head -> next;
    head -> prev = NULL;
    temp ->next = NULL;
    delete temp;

}



// ================================================
//              DELETION AT TAIL
// ================================================


void deleteAtTail(Node*& head,Node*&tail){
    // empty list
    if(head == NULL){
        cout<<"List is empty "<<endl;
        return;
    }
    // if it has one node
    
    if(head -> next == NULL){
        delete head;
        head=NULL;
        tail=NULL;
        cout<< "One node is deleted "<< endl;
        return;

    }

    // if more than one node
    // directly go to tail --- becoz we have prev

    Node*temp=tail;
    tail = tail -> prev;
    tail -> next = NULL;
    temp -> prev = NULL;
    delete temp;

}



// ================================================
//              DELETION AT POSITION
// ================================================

void deleteAtPosition(Node* &head, Node*&tail, int position){
     // empty list

     if(head == NULL){
        cout<<"List is Empty "<< endl;
        return;
     }

     // If position 1
     if(position==1){
        deleteAtHead(head,tail);
        return;
     }

     // Traversing
     Node*temp=head;
     int cnt = 1;
     while(cnt < position && temp != NULL){
        temp = temp -> next;
        cnt++;
     }

     // If invalid
     if(temp == NULL){
        cout<<"Invalid Position "<< endl;
        return;
     }

     // If last position
     if(temp->next == NULL){
        deleteAtTail(head,tail);
        return;
     }

     // If middle position

     temp -> prev -> next = temp -> next;
     temp -> next -> prev = temp -> prev;
     temp -> next = NULL;
     temp -> prev = NULL;
     delete temp;
}







// ================================================
//                    MAIN
// ================================================


int main(){
    Node*head=NULL;
    Node*tail=NULL;

    // insertAtHead(head,tail,10);
    // insertAtHead(head,tail,15);
    // insertAtHead(head,tail,20);
    // print(head);

    insertAtTail(head,tail,25);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,10);
    print(head);

    
    insertAtPosition(head, tail , 1, 100);
    insertAtPosition(head, tail , 2, 50);
    print(head);

    deleteAtHead(head,tail);
    print(head);

    deleteAtTail(head,tail);
    print(head);

    


    deleteAtPosition(head,tail,3);
    print(head);


    deleteAtPosition(head,tail,2);
    print(head);

    int key=50;
    if(searchNode(head,key)){
        cout<<key<< " Found in list "<< endl;
    }
    else{
        cout<<"Not Found! "<< endl;
    }


}



