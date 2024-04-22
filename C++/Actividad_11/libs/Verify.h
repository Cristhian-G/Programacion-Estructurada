#include <iostream>
#include <string>
#include<algorithm>
#include <cctype>
#include "colors.h"
using namespace std;

int Verify_int(){
    while(true){
        string input;
        getline(cin, input);

        // Elimina los espacios en blanco al principio y al final de la entrada
        input.erase(0, input.find_first_not_of(' ')); // prefijo
        input.erase(input.find_last_not_of(' ') + 1); // sufijo

        bool isInteger = true;
        for (size_t i = 0; i < input.length(); i++) {
            if (i == 0 && input[i] == '-') continue; 
            if (!isdigit(input[i])) {
                isInteger = false;
                break;
            }
        }

        if(isInteger){
            try {
                return stoi(input);
            } catch (std::invalid_argument& e) {
                cerr << RED << "Error: entrada inválida. Por favor, introduce un número entero válido." << endl;
                cout << WHITE;
            }
        }else{
            cerr << RED << "Entrada inválida, por favor intenta de nuevo con un número entero válido." << endl;
            cout << WHITE;
        }
    }
}

float Verify_float(){
    while(true){
        string input;
        getline(cin, input);

        bool isFloat = true;
        int dotCount = 0;
        for (size_t i = 0; i < input.length(); i++) {
            if (i == 0 && input[i] == '-') continue;
            if (!isdigit(input[i])) {
                if (input[i] == '.' && dotCount == 0) {
                    dotCount++;
                } else {
                    isFloat = false;
                    break;
                }
            }
        }

        if(isFloat){
            return stof(input);
        }else{
            cerr << "Invalid input, please try again with a valid float number." << endl;
        }
    }
}

double Verify_double(){
    while(true){
        string input;
        getline(cin, input);

        bool isDouble = true;
        int dotCount = 0;
        for (size_t i = 0; i < input.length(); i++) {
            if (i == 0 && input[i] == '-') continue; 
            if (!isdigit(input[i])) {
                if (input[i] == '.' && dotCount == 0) {
                    dotCount++;
                } else {
                    isDouble = false;
                    break;
                }
            }
        }

        if(isDouble){
            return stod(input);
        }else{
            cerr << "Invalid input, please try again with a valid double number." << endl;
        }
    }
}

string Verify_string(){
    while(true){
        string input;
        getline(cin, input);

        if(!input.empty()){
            if(input == "S" || input == "s" || input == "N" || input == "n"){
                return input;
            }else{
                cerr << RED << "Invalid input, please try again whit a \"S\" or \"N\" opcion" << endl;
            }
        }else{
            cerr << RED << "Invalid input, please try again with a non-empty string." << endl;
        }
    }
}

char Verify_char(){
    while(true){
        string input;
        getline(cin, input);

        if(input.length() == 1){
            return input[0];
        }else{
            cerr << RED << "Invalid input, please try again with a single character." << endl;
        }
    }
}