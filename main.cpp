#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

class ATMMachine
{
private:
     long int accountNumber;
     string accountHolderName;
     int pin;
     double accountBalance;
     string mobileNumber;

public:
     // Function to set ATM user data
     void setUserData(long int accountNumber_a, string accountHolderName_a, int pin_a, double accountBalance_a, string mobileNumber_a)
     {
          accountNumber = accountNumber_a;
          accountHolderName = accountHolderName_a;
          pin = pin_a;
          accountBalance = accountBalance_a;
          mobileNumber = mobileNumber_a;
     }

     // Function to get account number
     long int getAccountNumber()
     {
          return accountNumber;
     }

     // Function to get account holder name
     string getAccountHolderName()
     {
          return accountHolderName;
     }

     // Function to get PIN
     int getPin()
     {
          return pin;
     }

     // Function to get account balance
     double getAccountBalance()
     {
          return accountBalance;
     }

     // Function to get mobile number
     string getMobileNumber()
     {
          return mobileNumber;
     }

     // Function to update mobile number
     void updateMobileNumber(string oldMobileNumber, string newMobileNumber)
     {
          if (oldMobileNumber == mobileNumber)
          {
               mobileNumber = newMobileNumber;
               cout << endl
                    << "Successfully Updated Mobile Number.";
               _getch();
          }
          else
          {
               cout << endl
                    << "Incorrect !!! Old Mobile Number";
               _getch();
          }
     }

     // Function to withdraw cash from ATM
     void withdrawCash(int amount)
     {
          if (amount > 0 && amount < accountBalance)
          {
               accountBalance -= amount;
               cout << endl
                    << "Please Collect Your Cash";
               cout << endl
                    << "Available Balance: " << accountBalance;
               _getch();
          }
          else
          {
               cout << endl
                    << "Invalid Input or Insufficient Balance";
               _getch();
          }
     }
};

int main()
{
     int choice = 0, enterPin;
     long int enterAccountNumber;

     system("cls");

     ATMMachine user1;
     user1.setUserData(123456789, "Ashish", 9876, 100000, "9876543210");

     do
     {
          system("cls");

          cout << endl
               << "**** Welcome to ATM *****" << endl;
          cout << endl
               << "Enter Your Account Number: ";
          cin >> enterAccountNumber;

          cout << endl
               << "Enter PIN: ";
          cin >> enterPin;

          if ((enterAccountNumber == user1.getAccountNumber()) && (enterPin == user1.getPin()))
          {
               do
               {
                    int amount = 0;
                    string oldMobileNumber, newMobileNumber;

                    system("cls");

                    cout << endl
                         << "**** Welcome to ATM *****" << endl;
                    cout << endl
                         << "Select Options ";
                    cout << endl
                         << "1. Check Balance";
                    cout << endl
                         << "2. Cash Withdraw";
                    cout << endl
                         << "3. Show User Details";
                    cout << endl
                         << "4. Update Mobile Number";
                    cout << endl
                         << "5. Exit" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                         cout << endl
                              << "Your Bank balance is: " << user1.getAccountBalance();
                         _getch();
                         break;

                    case 2:
                         cout << endl
                              << "Enter the amount: ";
                         cin >> amount;
                         user1.withdrawCash(amount);
                         break;

                    case 3:
                         cout << endl
                              << "*** User Details are :- ";
                         cout << endl
                              << "-> Account Number: " << user1.getAccountNumber();
                         cout << endl
                              << "-> Name: " << user1.getAccountHolderName();
                         cout << endl
                              << "-> Balance: " << user1.getAccountBalance();
                         cout << endl
                              << "-> Mobile Number: " << user1.getMobileNumber();
                         _getch();
                         break;

                    case 4:
                         cout << endl
                              << "Enter Old Mobile Number: ";
                         cin >> oldMobileNumber;

                         cout << endl
                              << "Enter New Mobile Number: ";
                         cin >> newMobileNumber;

                         user1.updateMobileNumber(oldMobileNumber, newMobileNumber);
                         break;

                    case 5:
                         exit(0);

                    default:
                         cout << endl
                              << "Enter Valid Data !!!";
                    }

               } while (1);
          }
          else
          {
               cout << endl
                    << "User Details are Invalid !!! ";
               _getch();
          }
     } while (1);

     return 0;
}
