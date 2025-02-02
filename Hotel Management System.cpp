#include <iostream>
using namespace std;

bool rooms[5] = {false};
bool premiumSuites[2] = {false};
bool billPaid[7] = {false};

void bookRoom() {
    int roomNum;
    cout << "Enter room number (1-5 for regular, 6-7 for premium suite): ";
    cin >> roomNum;
    
    if (roomNum >= 1 && roomNum <= 5) {
        if (rooms[roomNum - 1]) {
            cout << "Room already booked!\n";
        } else {
            rooms[roomNum - 1] = true;
            cout << "Regular Room booked!\n";
        }
    } else if (roomNum >= 6 && roomNum <= 7) {
        if (premiumSuites[roomNum - 6]) {
            cout << "Premium Suite already booked!\n";
        } else {
            premiumSuites[roomNum - 6] = true;
            cout << "Premium Suite booked!\n";
        }
    } else {
        cout << "Invalid room number!\n";
    }
}

void checkRooms() {
    cout << "Available regular rooms: ";
    for (int i = 0; i < 5; i++) {
        if (!rooms[i]) cout << i + 1 << " ";
    }
    cout << "\nAvailable premium suites: ";
    for (int i = 0; i < 2; i++) {
        if (!premiumSuites[i]) cout << i + 6 << " ";
    }
    cout << "\n";
}

void roomService() {
    int roomNum, serviceType;
    cout << "Enter room number for service: ";
    cin >> roomNum;
    if ((roomNum >= 1 && roomNum <= 5 && rooms[roomNum - 1]) || (roomNum >= 6 && roomNum <= 7 && premiumSuites[roomNum - 6])) {
        cout << "Select service: 1. Food  2. Room Cleaning  3. Other: ";
        cin >> serviceType;
        if (serviceType == 1) cout << "Food service provided to room " << roomNum << "\n";
        else if (serviceType == 2) cout << "Room cleaning service provided to room " << roomNum << "\n";
        else cout << "Other service provided to room " << roomNum << "\n";
    } else {
        cout << "Room not booked or invalid number!\n";
    }
}

void generateBill() {
    int roomNum, paymentMethod;
    cout << "Enter room number for billing: ";
    cin >> roomNum;
    if (roomNum >= 1 && roomNum <= 5 && rooms[roomNum - 1]) {
        cout << "Bill for room " << roomNum << ": $100\n";
    } else if (roomNum >= 6 && roomNum <= 7 && premiumSuites[roomNum - 6]) {
        cout << "Bill for premium suite " << roomNum << ": $200\n";
    } else {
        cout << "Room not booked or invalid number!\n";
        return;
    }
    
    cout << "Choose payment method: 1. Cash  2. Card: ";
    cin >> paymentMethod;
    if (paymentMethod == 1 || paymentMethod == 2) {
        billPaid[roomNum - 1] = true;
        cout << "Payment successful!\n";
    } else {
        cout << "Invalid payment method!\n";
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n1. Book Room\n2. Check Available Rooms\n3. Room Service\n4. Generate Bill\n5. Exit\nChoose: ";
        cin >> choice;
        
        if (choice == 1) bookRoom();
        else if (choice == 2) checkRooms();
        else if (choice == 3) roomService();
        else if (choice == 4) generateBill();
        else if (choice == 5) cout << "Goodbye!\n";
        else cout << "Invalid choice!\n";
        
    } while (choice != 5);
    
    return 0;
}
