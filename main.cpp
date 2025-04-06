#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<string> mystack;
    char orders[50];
    char input = ' ';
    cout << "[A] Push Data" << endl;
    cout << "[B] Pop Data" << endl;
    cout << "[C] show top" << endl;
    cout << "[D] show size" << endl;
    cout << "[E] Exit" << endl;
    cout << "[F] Show all orders" << endl;
    

    while (input != 'E'){

        cout << "Enter your choice: ";
        cin >> input;
        
        switch (input){
            case 'A':
                cout << "Enter your order: ";
                cin >> orders;
                mystack.push(orders);
                break;
            case 'B':
                if (mystack.empty()){
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Data " << mystack.top() << " has been removed" << endl;
                    mystack.pop();
                }
                break;
            case 'C':
                if (mystack.empty()){
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Top data: " << mystack.top() << endl;
                }
                break;
            case 'D':
                cout << "Size of stack: " << mystack.size() << endl;
                break;
            case 'E':
                cout << "Exiting program" << endl;
                break;
            case 'F':
                if (mystack.empty()){
                    cout << "Stack is empty" << endl;
                }
                else{
                    int x=1;
                    while (!mystack.empty()){
                        cout << "Order(" << x << "): " << mystack.top() << endl;
                        mystack.pop();
                        x++;} 
                }
                break;     
            default:
                cout << "Invalid input" << endl;
                break;
        }
        
    }
    return 0;
}
