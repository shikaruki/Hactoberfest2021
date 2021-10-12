#include <iostream>
using namespace std;
#define size 100

class queue{
    int queue[size];
    int rear = -1;
    int front = -1;
    
public:
    bool isFull(){
        if ((rear+1) % size == front){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isEmpty(){
        if (rear==-1 && front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int n){
        if(isFull()){
            cout << "\nQueue is full." << endl;
            return;
        }  
        else if (isEmpty()){
            front = rear = 0;
            queue[rear] = n;
        }
        else{
            rear = (rear+1)%size;
            queue[rear]= n;
        }
    }
    
    void dequeue(){
        if(isEmpty()){
            cout << "\nCannot delete.Queue is empty" << endl;
        }
        else if(rear==front){
            front = rear = -1;
        }
        else{
            cout << "\nElement deleted is : " << queue[front] <<endl;
            front = (front+1)%size;
            display();

        }
    }
    
    void display(){
        if (isEmpty()){
            cout << "\nQueue is empty." << endl;
        }
        else{ 
            cout << "\nValues in the queue are : " << endl;

            int i = front;
            while(i != rear){
                cout << queue[i] << " " ;
                i = (i+1)%size;
            }
            cout << queue[rear] << endl;
        }
    }
    void peek(){
        if(isEmpty()){
            cout << "\nQueue is Empty." << endl;
        }
        else{
            cout << "\nFirst element is : " << queue[front] << endl;
        }
    }
};


int main() {
    queue q1;
    int choice;
    
    do{
        
        cout << "\n===============MENU===============" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice : " << flush;
        cin >> choice;
        
        switch(choice){
            case 1:
                int num, value;
                cout << "\nEnter number of values to Enqueue : " << flush;
                cin >> num;
                
                for(int i=0; i < num; i++){
                    cout << "Enter value " << i+1 << " : ";
                    cin >> value;
                    q1.enqueue(value);
                }
                break;
            
            case 2:
                q1.dequeue();
                break;
                
            case 3:
                q1.display();
                break;
                
            case 4:
                q1.peek();
                break;
                
            case 5:
                exit(0);
                break;
                
            default:
                cout << "Invalid Input!!!" << endl;
                exit(0);
                break;
        }
    }while(choice != 5);
}
