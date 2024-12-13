#include <iostream>
#include <fstream>
#include <map>
#include <thread>
#include <chrono>

using namespace std;

// Constants for car rental rates
const map<string, int> CAR_RATES = {
    {"A", 56},
    {"B", 60},
    {"C", 75}
};

class Customer {
  protected:
    string customerName;
    string carModel;
    string carNumber;
    int rentalDays = 0;

  public:
    void inputCustomerDetails();
    string getCarModel() const { return carModel; }
    int getRentalDays() const { return rentalDays; }
    string getCustomerName() const { return customerName; }
    string getCarNumber() const { return carNumber; }
};

void Customer::inputCustomerDetails() {
    cout << "\nEnter your Name: ";
    cin >> customerName;

    cout << "\nAvailable Cars:\n";
    cout << "A: Tesla 2023\n";
    cout << "B: Hyundai 2020\n";
    cout << "C: Ford 2022\n";

    do {
        cout << "\nChoose a car model (A/B/C): ";
        cin >> carModel;
        if (CAR_RATES.find(carModel) == CAR_RATES.end()) {
            cout << "Invalid car model. Please try again." << endl;
        }
    } while (CAR_RATES.find(carModel) == CAR_RATES.end());

    cout << "\nEnter Car Number: ";
    cin >> carNumber;

    cout << "\nEnter the number of days you wish to rent the car: ";
    cin >> rentalDays;
}

class Rent : public Customer {
  private:
    int rentalFee = 0;

  public:
    void calculateRental();
    void displayInvoice();
};

void Rent::calculateRental() {
    int rate = CAR_RATES.at(carModel);
    rentalFee = rentalDays * rate;
}

void Rent::displayInvoice() {
    cout << "\n\nCar Rental - Customer Invoice\n";
    cout << "-----------------------------------\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "Car Model: " << carModel << endl;
    cout << "Car Number: " << carNumber << endl;
    cout << "Number of Rental Days: " << rentalDays << endl;
    cout << "Rental Fee: " << rentalFee << endl;
    cout << "-----------------------------------\n";
    cout << "Total Amount: " << rentalFee << endl;
}

void displayFile(const string &fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open file " << fileName << endl;
    }
}

void welcomeMessage() {
    displayFile("welcome.txt");
    cout << "\nStarting the program, please wait...\n";
    this_thread::sleep_for(chrono::seconds(1));
}

bool login() {
    string password;
    cout << "\nLOGIN\n";
    cout << "Enter Password: ";
    cin >> password;

    if (password == "admin") {
        cout << "\nAccess Granted!\n";
        return true;
    } else {
        cout << "\nAccess Denied. Try Again.\n";
        return false;
    }
}

int main() {
    welcomeMessage();

    while (!login()) {
        // Repeat login until correct
    }

    Rent rentObj;
    rentObj.inputCustomerDetails();
    rentObj.calculateRental();
    rentObj.displayInvoice();

    return 0;
} 