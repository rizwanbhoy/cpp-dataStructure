#include <iostream>

using namespace std ;

class DeQueue{

    int size ;
    int* array ;
    int front ;
    int rear ;

public :

    DeQueue(int s){
        size = s ;
        array = new int[size] ;
        front = -1 ;
        rear = -1 ;
    }

    void enQueueFront(int val){
        if (front == (rear +1 ) % size){
            cout << "DeQueue is Fulled \n";
            return ;
        }

        if (front == -1){
            front = rear = 0 ;
        }
        else {
            front = (front -1 + size) % size ;
        }

        cout << "Inserted Val : " << val << " At Index : " << front << endl ;

        array[front] = val ;        
    }

    void enQueueRear(int val){
        if (front == (rear + 1) % size ){
            cout << "DeQueue is Fulled \n";
            return ;
        }

        if (front == -1){
            front = rear = 0 ;
        }
        else {
            rear = (rear + 1 ) % size ;
        }

        cout << "Inserted Val : " << val << " At Index : " << rear << endl ;

        array[rear] = val ;    
    }

    void printQueue() {
    if (front == -1) {
        cout << "Queue is Empty \n";
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << array[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}

    void deQueueFront(){
        if (front == -1){
            cout << "Queue is Empty \n"; 
            return ;
        }

        cout << "Deleted Val : " << array[front] << endl ;
        
        if (front == rear){
            front = rear = -1 ; 
        }
        else {
            front =  ( front + 1 ) % size ;
        }
        
    }

    void deQueueRear(){
        if (front == -1 ){
            cout << "DeQueue is Empty \n";
            return ;
        }

        cout << "Deleted Val : " << array[rear] << endl ;

        if (front == rear){
            front = rear = -1 ;
        }
        else {
            rear = (rear -1 + size ) % size ;
        }
        
        
    }
};

int main() {

    int size = 5 ;

    DeQueue dq(size);
    dq.enQueueFront(15);
    dq.enQueueFront(20);
    dq.enQueueFront(19);
    dq.enQueueRear(17);
    dq.enQueueRear(16);
    dq.enQueueRear(18);

    dq.printQueue();

    cout << "After Delete From Front \n";
    dq.deQueueFront();
    dq.printQueue();

    cout << "After Delete From Rear \n";
    dq.deQueueRear();
    dq.printQueue();

    return 0 ;
}