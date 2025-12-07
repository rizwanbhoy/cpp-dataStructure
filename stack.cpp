#include <iostream> 

using namespace std ;

class Stack {

    int size ;
    int *arr ;
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

        void pop(){
            if (top == -1)
            {
                cout << "Stack is Empty \n";
                return ;
            }

            top-- ;
            
        }

        void peek(){
            if (top == -1 )
            {
                cout << "Stack is empty \n";
                return ;
            }

            cout <<  arr[top]  << endl ;
            
        }

        bool isempty(){
            if (top == 0)
            {

                cout << "Stack is empty \n";
                return true ;
            } 
            else{

                return false ;
            }
            
        }

        bool isFull(){
            if(top == size -1){
                return true ;
            }
            else {
                return false ;
            }
        }

};

int main (){

    int size = 4 ;
    Stack stack(size);
    stack.push(12);
    stack.push(13);
    stack.push(15);
    stack.pop();
    stack.peek();
    bool result = stack.isempty();
    cout << "Stack result : " << result << endl ;

    return 0 ;
}