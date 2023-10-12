//
// Created by furfa on 7/10/2023.
//

#include "validaciones.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int obtenerRespuestaValida() {//comento solo esta funcion por que en las demas se repite la logica pero con otras variables
    int numero;             // Variable para almacenar la respuesta válida
    string entrada;         // Variable para almacenar la entrada del usuario
    while (true) {          // Un bucle infinito para obtener una respuesta válida
        cout << "Respuesta(1/2/3/4): ";
        // Lee la entrada del usuario como una línea
        if (getline(cin, entrada)) {
            stringstream ss(entrada); // Convierte la entrada en un flujo de stringstream
            // Intenta extraer un número de la stringstream y verifica si no hay más datos
            if (ss >> numero && ss.eof()) {
                // Verifica si el número es 1, 2, 3 o 4
                if (numero == 1 || numero == 2 || numero == 3 || numero == 4) {
                    // Si el número es válido, sale del bucle
                    break;
                } else {
                    // Si el número no es válido, muestra un mensaje de error
                    cout << "El numero debe ser 1, 2, 3 o 4. Intente de nuevo." << endl;
                }
            } else {
                // Si la entrada no es un número válido, muestra un mensaje de error
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            // Si hay un error en la entrada, muestra un mensaje de error y limpia la entrada
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    // Retorna el número válido
    return numero;
}

int obtenerPosicionValida() {
    int numero;
    string entrada;
    while (true) {
        cout << "Respuesta(0-9): ";
        if (getline(cin, entrada)) {
            stringstream ss(entrada);
            if (ss >> numero && ss.eof()) {
                if (numero>=0 && numero<=9) {
                    break;
                } else {
                    cout << "El numero debe estar entre 0 y 9. Intente de nuevo." << endl;
                }
            } else {
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numero;
}

int obtenerRatonValido() {
    int numero;
    string entrada;
    while (true) {
        cout << "Respuesta(1-7): ";
        if (getline(cin, entrada)) {
            stringstream ss(entrada);
            if (ss >> numero && ss.eof()) {
                if (numero>=1 && numero<=7 ) {
                    break;
                } else {
                    cout << "El numero debe estar entre 1-7. Intente de nuevo." << endl;
                }
            } else {
                cout << "Entrada invalida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Error de entrada. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numero;
}


