#include <iostream>

using namespace std ;

class Node {
public : 
    int data ;
    Node* next ;
    Node(int val): data(val) , next(NULL){}

};

class List {
    Node* head ;
    Node* tail ;
public : 
    List(){
        head = NULL ;
        tail= NULL ;
    }

    int sizeOfList(){
        if (head == nullptr)
        {
            cout << "list is empty \n";
            return 0 ;
        }

        Node* temp = head ;
        int count = 0 ;
        while (temp != NULL)
        {
            temp = temp->next ;
            count ++ ;
        }
        return count ;
        
    }

    void insertAtHead(int val ){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode ;
            return ;
        }
        newnode->next = head ;
        head = newnode ;
    }

    void insertAtMid( int index ,int val){
        if(head == NULL){
            cout << "list is empty \n";
            return ;
        }
        int size = sizeOfList();
        if(index > size || index < 0){
            cout << "Index is Invalid \n";
            return ;
        }

        Node* newnode = new Node(val);

        if(index == 0){
            newnode->next = head ;
            head = newnode ;
            return ;
        }

        Node* temp = head ;
        for (int i = 0; i < index -1; i++)
        {
            temp = temp->next ;
        }

        newnode->next = temp->next ;
        temp->next = newnode;

        if(temp == tail){
            tail->next = newnode ;
            return ;
        }
    }

    void insertAtTail(int val ){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode ;
            return ;
        }

        tail->next = newnode ;
        tail = newnode ;
        return ;
    }

    void printList(){
        if (head == NULL)
        {
            cout << "List is Empty \n";
            return ;
        }

        Node* temp = head ;
        while (temp != NULL)
        {
            cout << temp->data << " -> " ;
            temp = temp->next ;
        }
        cout << endl ;
        
        
    }
};

int main (){

    List list ;
    list.insertAtHead(12);
    list.insertAtTail(19);
    list.insertAtHead(14);
    list.insertAtHead(11);
    list.insertAtMid(3 , 15);
    list.printList();
    return 0 ;
}