#include <iostream>
using namespace std;


void mostrarProgreso(string progreso) {
    for (int i = 0; progreso[i] != '\0'; i++) {
        cout << progreso[i] << ' ';
    }
    cout << endl;
}


bool adivinarLetra(char letra, string palabra, string &progreso) {
    bool acierto = false;
    for (int i = 0; palabra[i] != '\0'; i++) {
        if (palabra[i] == letra && progreso[i] == '_') {
            progreso[i] = letra;
            acierto = true;
        }
    }
    return acierto;
}


void mostrarParteDelCuerpo(int errores) {
    switch (errores) {
        case 1: cout << "Pierde pierna derecha\n"; break;
        case 2: cout << "Pierde pierna izquierda\n"; break;
        case 3: cout << "Pierde brazo derecho\n"; break;
        case 4: cout << "Pierde brazo izquierdo\n"; break;
        case 5: cout << "Pierde tronco\n"; break;
        case 6: cout << "Pierde cabeza\n"; break;
    }
}

int main() {
    string palabra, progreso;
    char letra;
    int errores = 0, maxErrores = 6;

    cout << "Ingrese la palabra secreta (sin espacios): ";
    cin >> palabra;

    
    for (int i = 0; palabra[i] != '\0'; i++) {
        progreso += '_';
    }

    cout << "Comienza el juego!\n";

    while (errores < maxErrores && progreso != palabra) {
        mostrarProgreso(progreso);
        cout << "Ingrese letra: ";
        cin >> letra;

        if (!adivinarLetra(letra, palabra, progreso)) {
            errores++;
            mostrarParteDelCuerpo(errores);
        }
    }

    if (progreso == palabra) {
        cout << "\nFelicidades Has adivinado la palabra: " << palabra << endl;
    } else {
        cout << "\nHas perdido el juego. La palabra era: " << palabra << endl;
    }

    return 0;
}
