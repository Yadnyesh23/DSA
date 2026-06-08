// If marks are less than 35:
// Output: "Fail"
// Else if marks are greater than or equal to 90 and attendance is at least 75:
// Output: "Grade A+"
// Else if marks are greater than or equal to 75 and attendance is at least 75:
// Output: "Grade A"
// Else if marks are greater than or equal to 60 or attendance is at least 90:
// Output: "Grade B"
// Else:
// Output: "Grade C"

#include<iostream>
using namespace std;

int main(){
int age;
int marks, attendance;
cin >> marks;
cin >> attendance;

if (marks < 35){
   cout << "Fail";
}
else if(marks >= 90 && attendance >= 75){
    cout << "Grade A+";
}
else if(marks >= 75 && attendance >= 75){
    cout << "Grade A";
}
else if(marks >= 60 || attendance >= 90){
    cout << "Grade B";
}
else {
    cout << "Grade C";
}


    return 0;
}

//  Nested If-Else

// Take input:

// Account Balance
// Withdrawal Amount
// PIN Entered (1 = Correct, 0 = Incorrect)
// Rules
// First check whether the PIN is correct.

// If not, print:

// Invalid PIN
// If the PIN is correct:
// Check whether the withdrawal amount is less than or equal to the balance.
// If yes:
// Check whether the withdrawal amount is a multiple of 100.

// If yes:

// Transaction Successful

// Else:

// Enter amount in multiples of 100

// If no:

// Insufficient Balance

#include<iostream>
using namespace std;

int main(){
int balance, withdraw_amount, pin_correct;
cin >> balance >> withdraw_amount >> pin_correct;
cout << "Balance : " << balance << '\n' << "Withdraw Amount : " << withdraw_amount << '\n' << "Pin correct : " << pin_correct << '\n';
if(pin_correct == 1){
    if(withdraw_amount <= balance){
        if(withdraw_amount % 100 == 0){
            cout << "Transaction Successful";
        }
        else {
        cout << "Withdraw amount should be multiple of 100";
    }
    }
    else {
        cout << "Insufficient Balance";
    }
}
else{
    cout << "Incorrect pin";
}

    
    return 0;
}