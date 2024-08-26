#include <iostream>
using namespace std;
#define RED "\033[31m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
float sumar(float a, float b) { return a + b; }
float restar(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) { return a / b; }
void showMenu() {
    int menuWidth = 20;
    char firstCorner = 201;
    char secondCorner = 187;
    char thirdCorner = 200;
    char fourthCorner = 188;
    char widthCharacter = 205;
    char lengthCharacter = 186;
    char firstCharacterDivider = 204;
    char secondCharacterDivider = 185;
    string header = "   RPN CALCULATOR   ";
    cout << BLUE << firstCorner;
    for (int i = 0; i < menuWidth; i++) {
        cout << widthCharacter;
    }
    cout << secondCorner << endl << lengthCharacter << CYAN << header << BLUE << lengthCharacter << endl << firstCharacterDivider;
    for (int i = 0; i < menuWidth; i++) {
        cout << widthCharacter;
    }
    cout << secondCharacterDivider << endl << lengthCharacter << PURPLE << "1. " << GREEN << "Instructions     ";
    cout << BLUE << lengthCharacter << endl << lengthCharacter << PURPLE << "2. " << GREEN << "Instrucciones    ";
    cout << BLUE << lengthCharacter << endl << lengthCharacter << PURPLE << "3. " << GREEN << "RPN Calc         " << BLUE;
    cout << lengthCharacter << endl << lengthCharacter << PURPLE << "4. " << GREEN << "Exit             " << BLUE;
    cout << lengthCharacter << endl << thirdCorner;
    for (int i = 0; i < menuWidth; i++) {
        cout << widthCharacter;
    }
    cout << fourthCorner << RESET << endl;
}
void rpnCalculator() {
    float number1 = 0, number2 = 0, result = 0;
    string operators = " ";
    cout << CYAN << "RPN CALCULATOR (FORMAT: NUM1 NUM2 OPERATOR)" << RESET << endl; 
    cin >> number1;
    while (operators != "=") {
        cin >> number2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000000000000000000, '\n');
            cout << RED << "Entry not valid ." << RESET << endl;
            continue;
        }
        cin >> operators;
        if (operators == "+") {
            result = sumar(number1, number2);
        }
        else if (operators == "-") {
            result = restar(number1, number2);
        }
        else if (operators == "*") {
            result = multiplicar(number1, number2);
        }
        else if (operators == "/") {
            result = dividir(number1, number2);
        }
        else if (operators == "=") {
            cout << "The result is: " << result << endl;
        }
        else {
            cout << RED << "Value not valid" << RESET << endl;
        }
        number1 = result;
    }
}
int main() {
    int option = 0;
    while (true) {
        showMenu();
        cout << RED << "SELECT AN OPTION" << RESET << endl;
        cin >> option;
        switch (option) {
        case 1:
            cout << GREEN << "Instructions:" << RESET << endl;
            cout << YELLOW << "1. Enter two numbers followed by an operator (+, -, *, /)." << endl;
            cout << "2. Continue entering numbers and operators as needed." << endl;
            cout << "3. Enter '=' to display the final result." << RESET << endl;
            break;
        case 2:
            cout << GREEN << "Instrucciones:" << RESET << endl;
            cout << YELLOW << "1. Ingrese dos numeros seguidos de un operador (+, -, *, /)." << endl;
            cout << "2. Continue ingresando los numeros y operadores que desee." << endl;
            cout << "3. Ingrese '=' para mostrar el resultado final." << RESET << endl;
            break;
        case 3:
            rpnCalculator();
            break;
        case 4:
            cout << RED << "Exit....." << RESET << endl;
            return 0;
        default:
            cout << RED << "Option not valid. Enter an option from 1 to 4." << RESET << endl;
            break;
        }
    }
    return 0;
}

