#include <iostream>

using namespace std;

int main() {

  // Get two numbers from the user
  float num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  // Get the operation to perform from the user
  char op;
  cout << "Choose an operation (+, -, *, or /): ";
  cin >> op;

  // Perform the operation
  float result;
  switch (op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    default:
      cout << "Invalid operation." << endl;
      return 1;
  }

  // Display the result
  cout << "The result is: " << result << endl;

  return 0;
}
