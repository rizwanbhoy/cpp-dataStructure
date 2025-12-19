#include <iostream>

using namespace std ;

class Queue{

    int size ;
    int* array ;
    int front , rear ;

public : 

        Queue(int s){
            size = s ;
            array = new int[size] ;
            front = rear = -1 ;
        }

        void enQueue(int val){
            if (rear == size -1){
                cout << "Queue is Fulled \n";
                return ;
            }

            if (front == -1){
                front = 0 ;
            }

            cout << "Inserted Val : " << val << endl ;

            rear++ ;
            array[rear] = val ;
            
            
        }

        void deQueue(){
            if (front == -1){
                cout << "Queue is Empty \n";
                return ;
            }

            cout << "Delete Val : " << array[front] << endl ;

            front++ ;

            if (front > rear){
                front = rear = -1 ;
            }           
        }

        int getFront(){
            if (front == -1){
                cout << "Queue is Empty \n";
                return -1 ;
            }

            return array[front];            
        }
};

int main(){

    int size = 5 ;

    Queue queue(size);
    queue.enQueue(12);
    queue.enQueue(22);
    queue.deQueue();
    int resutl = queue.getFront();
    cout << resutl << " Front val \n" ;

    return 0 ; 
}