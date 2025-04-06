#include <iostream>
#include <queue>

using namespace std;

// just like the stack example, I used a temporary queue to 
//display all the people in the queue
// because I don't want to modify the original queue.

void showQueue(queue<string> q) {
    if (q.empty()) {
        cout << "🎢 The queue is empty! No one is waiting.\n";
    } else {
        cout << "👥 Current queue lineup:\n";
        int position = 1;
        while (!q.empty()) {
            cout << position << ". " << q.front() << endl;
            q.pop();
            position++;
        }
    }
}

int main() {
    queue<string> rideQueue;
    char choice;
    int num;
    string name;

    cout << "🎡 Welcome to the Amusement Park Ride Queue System 🎢\n";
    cout << "[A] Enter Ride Queue\n";
    cout << "[B] Let the First Person Ride\n";
    cout << "[C] Show Who's Next\n";
    cout << "[D] Show Who's Last\n";
    cout << "[E] Show Full Queue\n";
    cout << "[F] Close Ride\n";

    do {
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 'A': 
            cout << "Enter how many people are joining the queue: ";
            cin >> num;
            for (int i = 0; i < num; i++) { 
                    cout << "Enter name: ";
                    cin >> name;
                    rideQueue.push(name);
                    cout << "✅ " << name << " has joined the queue!\n";
                }
                break;
            
            case 'B':
                if (rideQueue.empty()) {
                    cout << "⚠️ No one is in the queue!\n";
                } else {
                    cout << "🎢 " << rideQueue.front() << " is now riding!\n";
                    rideQueue.pop();
                }
                break;

            case 'C':
                if (rideQueue.empty()) {
                    cout << "⚠️ No one is waiting!\n";
                } else {
                    cout << "👤 Next to ride: " << rideQueue.front() << endl;
                }
                break;

            case 'D':
                if (rideQueue.empty()) {
                    cout << "⚠️ No one is in the queue!\n";
                } else {
                    cout << "🛑 Last person in line: " << rideQueue.back() << endl;
                }
                break;

            case 'E':
                showQueue(rideQueue);
                break;

            case 'F':
                cout << "🎡 Ride is closing. Final queue lineup:\n";
                showQueue(rideQueue);
                cout << "🎢 The ride is now closed!\n";
                break;

            default:
                cout << "⚠️ Invalid choice! Please enter a valid option.\n";
                break;
        }

    } while (choice != 'F');

    return 0;
}
