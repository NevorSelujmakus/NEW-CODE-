#include <iostream>
#include <stack>

using namespace std;

//I used a temporary stack to display all the cargo in the rocket 
//because I don't want to modify the original stack.
//I used an integer variable x to keep track of the cargo number 
//and emphasize the order of the cargo(LIFO).
void showcargo(stack<string> cargoStack) {
    if (cargoStack.empty()) {
        cout << "⚠️ No cargo in the rocket!" << endl;
    } else {
        cout << "📦 Current cargo in the rocket:" << endl;
        stack<string> tempStack = cargoStack; // Copy to avoid modifying original stack
        int x = 1;
        while (!tempStack.empty()) {
            cout << "Cargo (" << x << "): " << tempStack.top() << endl;
            tempStack.pop();
            x++;
        }
    }
}

void exitlucnh(stack<string>& cargoStack) {
    if (cargoStack.empty()) {
        cout << "🚀 Rocket is empty. Mission aborted!" << endl;
    } else {
        cout << "🚀 Launching rocket! Deploying all cargo..." << endl;
        int x = 1;
        while (!cargoStack.empty()) {
            cout << "Deploying Cargo (" << x << "): " << cargoStack.top() << endl;
            cargoStack.pop();
            x++;
        }
        cout << "🔥 Rocket launched successfully!" << endl;
    }
}

int main() {
    stack<string> cargoStack;
    char item[50];
    int num;
    char input = ' ';

    cout << "🚀 Space Mission Control 🚀" << endl;
    cout << "[A] Load Cargo" << endl;
    cout << "[B] Deploy Cargo" << endl;
    cout << "[C] View Top Cargo" << endl;
    cout << "[D] Check Cargo Count" << endl;
    cout << "[E] View All Cargo" << endl;
    cout << "[F] Launch Rocket (Exit)" << endl;

    while (input != 'F') {
        cout << "\nEnter your choice: ";
        cin >> input;

        switch (input) {
            case 'A':
                cout << "Enter how much cargo you want to load: ";
                cin >> num;
                for (int i = 0; i < num; i++) {
                    cout << "Enter cargo name: ";
                    cin >> item;
                    cargoStack.push(item);
                    cout << "📦 Cargo '" << item << "' loaded into the rocket!" << endl;
                }
                break;
            case 'B':
                if (cargoStack.empty()) {
                    cout << "⚠️ No cargo left to deploy!" << endl;
                } else {
                    cout << "🚀 Deploying '" << cargoStack.top() << "' into space!" << endl;
                    cargoStack.pop();
                }
                break;
            case 'C':
                if (cargoStack.empty()) {
                    cout << "⚠️ No cargo in the rocket!" << endl;
                } else {
                    cout << "🛰️ Top cargo: " << cargoStack.top() << endl;
                }
                break;
            case 'D':
                cout << "📦 Cargo count: " << cargoStack.size() << endl;
                break;
            case 'E':
                showcargo(cargoStack);
                break;
            case 'F':
                exitlucnh(cargoStack);
                break;
            default:
                cout << "⚠️ Invalid input! Try again." << endl;
                break;
        }
    }

    return 0;
}
