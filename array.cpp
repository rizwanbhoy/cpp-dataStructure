#include <iostream>

using namespace std ;

class Array{

    int size ;
    int capacity ;
    int* numbers ;

public : 
        Array() : size(0) , capacity(0) , numbers(nullptr) {}

        void createArray(int val , int arr[] ){
            capacity = val ;
            numbers = new int[capacity] ;
            for (int i = 0; i < capacity ; i++)
            {
                 numbers[i] = arr[i];
            }

            size = capacity ;
        }

        void insertAtFirst(int val){
            if(capacity == 0){
                cout << "no size to store \n";
                return ;
            }

            for (int i = size; i > 0; i--){
                numbers[i] = numbers[i-1];
            }
            numbers[0] = val ;
            size++;

            capacity = size ;            
        }

        void insertAtMid(int index , int val ){
            if( capacity == 0){
                cout << "Array is Empty \n";
                return ;
            }

            if (index > capacity || index < 0)
            {
                cout << "invalid index \n";
                return ;
            }

            if (index == 0)
            {
                insertAtFirst(val);
                return ;
            }
            
            
            for (int i = size ; i > index; i--)
            {
                numbers[i] = numbers[i-1];                
            }
            numbers[index] = val ;

            size ++ ;
        }

        void insertAtLast(int val){
            if (capacity == 0){
                cout << "Array is Empty \n";
                return ;
            }
            size ++ ;
            numbers[size-1] = val ; 
            capacity = size ;
            
        }

        void printArray(){

            if (capacity == 0)
            {
                cout << "Array is empty \n";
                return ;
            }
            

            cout << "[ " ;
            for (int i = 0; i < size ; i++)
            {
                cout << numbers[i] << ' ';
            }
            cout << " ]" << endl ;
            
        }

        void deleteFromFirst(){
            if(capacity == 0){
                cout << "Array is Empty \n" ;
                return ;
            }
         
            for (int i = 1; i < size; i++)
            {
                numbers[i-1] = numbers[i] ;
            }

            size -- ;
        }

        void deleteFromMid(int index){
            if(capacity == 0){
                cout << "Array is Empty \n" ;
                return ;
            }

            if (index == 0)
            {
                deleteFromFirst();
                return ;
            }
            

            for (int i = index; i < size -1; i++)
            {
                numbers[i] = numbers[i+1]; 
            }

            size -- ;
            
        }
        
        void deleteFromLast(){
            if(capacity == 0){
                cout << "Array is empty \n";
                return ;
            }
            size -- ;
            
        }

};

int main(){

    int size = 5 ;
    int numbers [size] = { 11, 12,13,14,16 };
    Array arr ;
    arr.createArray(size , numbers);
    arr.printArray();
    cout << "insert at First \n";
    arr.insertAtFirst(10);
    arr.printArray();
    cout << "insert At Last \n";
    arr.insertAtLast(17);
    arr.printArray();

    cout << "insertAt mid called \n";
    arr.insertAtMid(5 , 15);
    arr.printArray();
    cout << "delete from last \n";
    arr.deleteFromFirst();
    arr.printArray();

    cout << "delete From Last \n";
    arr.deleteFromLast();
    arr.printArray();

    cout << "Delete From Mid \n";
    arr.deleteFromMid(3);
    arr.printArray();
    return 0 ;
}