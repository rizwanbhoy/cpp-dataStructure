#include <iostream> 

using namespace std ;

class Stack {

    int size ;
    int* arr ;
    int top ;
public : 
        Stack(int s){
            size = s ;
            arr = new int[size] ;
            top = -1 ;
            return ;
        }
        void push(int val){
            if(top == size -1){
                cout << "Stack is Overflow \n";
                return ;
            }
            arr[++top] = val ;
            return ;
        }

};

int main (){

    return 0 ;
}