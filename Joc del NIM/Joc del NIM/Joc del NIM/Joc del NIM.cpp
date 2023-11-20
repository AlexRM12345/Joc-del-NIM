// Joc del NIM.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {


    //////////Variables/////////

    int fila1 = 3; // Variable que controla la fila 1 
    int fila2 = 4; // Variable que controla la fila 2
    int fila3 = 5; // Variable que controla la fila 3
    int jugador = 1; // Variable que controla los jugadores
    int total = (fila1 + fila2 + fila3);

    srand(time(0)); // Semilla para números aleatorios basada en el tiempo actual


    //////////////////////////////////////////////////////////////////// Bucle del joc //////////////////////////////////////////////////////////////  

    
    
                                                                       // Arte ASCII////////////////////////////////////////////////////////////////

    cout << "       __        __    ____  _____  _____  ____    ____  " << endl;
    cout << "   |_   _|                    |  ]      [  |  |_   \\|_   _||_   _||_   \\  /   _| " << endl;
    cout << "     | |  .--.   .---.    .--.| | .---.  | |    |   \\ | |    | |    |   \\/   |   " << endl;
    cout << " _   | |/ .'`\\ \\/ /'`\\] / /'`\\' |/ /__\\\\ | |    | |\\ \\| |    | |    | |\\  /| |   " << endl;
    cout << "| |__' || \\__. || \\__.  | \\__/  || \\__., | |   _| |_)\\   |_  _| |_  _| |_\\/_| |_  " << endl;
    cout << "`.____.' '.__.' '.___.'  '.__.;__]'.__.'[___] |_____||\\____||_____||_____||_____| " << endl;
    cout << endl;


     
 //////////////////////////////////////////////////////////////////////Dibuixa les files/////////////////////////////////////////////////////////////

    do { 
        cout << "Estat actual del tauler:\n"; // Avisamos del estado por pantalla
        cout << "Fila 1"; // Dibujamos la fila 1
        for (int i = 0; i < fila1; ++i) { // Dibujar | hasta que se cumpla la condición
            cout << "|";
        }
        cout << "\n";

        cout << "Fila 2"; // Dibujamos la fila 2
        for (int i = 0; i < fila2; ++i) {// Dibujar | hasta que se cumpla la condición
            cout << "|";
        }
        cout << "\n";

        cout << "Fila 3"; // Dibujo de la fila 3
        for (int i = 0; i < fila3; ++i) {// Dibujar | hasta que se cumpla la condición
            cout << "|";
        }
        cout << "\n";


 //////////////////////////////////////////////////////////////// Torn de preguntes al jugador/////////////////////////////////////////////////////////

        if (jugador == 1) {
            cout << "Torn del jugador " << jugador << ", de quina fila vols treure la ficha ? (1, 2 o 3) ? "; // Cout que alternará el jugador y preguntará qué fila quiere restar
            int respostafila; // Variable para guardar la respuesta del jugador
            cin >> respostafila;// Preguntamos la respuesta al jugador

            cout << "Cuantes fiches vols treure de la fila seleccionada?? (1,2 o 3)?";// Preguntem cuantes fiches vol treure de la columna seleccionada
            int respostaficha; // Variable para guardar la respuesta del jugador
            cin >> respostaficha;// Preguntem la resposta al jugador

            if ((respostafila == 1 && fila1 >= respostaficha) || // En aquest apartat es valida la resposta escollida per el jugador
                (respostafila == 2 && fila2 >= respostaficha) || // a les 3 columnes
                (respostafila == 3 && fila3 >= respostaficha)) {

                switch (respostafila) { // Seguidament, resta el numero de fiches desitjades al restant de la fila seleccionada
                case 1:
                    fila1 -= respostaficha;// Restem a la fila 1
                    break;
                case 2:
                    fila2 -= respostaficha;// Restem a la fila 2
                    break;
                case 3:
                    fila3 -= respostaficha;// Restem a la fila 3
                    break;
                }
            }
        }

 ////////////////////////////////////////////////////////////////////////Torn de la maquina/////////////////////////////////////////////////////////////

        else {
            int fila_maquina, fichas_maquina;

            do {
                fila_maquina = (rand() % 3) + 1;             // La maquina escull aleatoriament
            } while ((fila_maquina == 1 && fila1 == 0) ||   // entre la fila 1
                    (fila_maquina == 2 && fila2 == 0) ||    // fila 2
                    (fila_maquina == 3 && fila3 == 0));     // Fila 3 depenen si quede

            do {
                fichas_maquina = (rand() % 3) + 1; 
            } while ((fila_maquina == 1 && fila1 < fichas_maquina) ||//La maquina tria aleatoriament el numero de fiches que treu
                    (fila_maquina == 2 && fila2 < fichas_maquina) ||//, ja que amb rand() %3 + 1, el rand 
                    (fila_maquina == 3 && fila3 < fichas_maquina));//comença al 1 en comptes del 0

            switch (fila_maquina) {// Seguidament, resta el numero de fiches desitjades al restant de la fila seleccionada per la maquina
            case 1:
                fila1 -= fichas_maquina;// Restem a la fila 1
                break;
            case 2:
                fila2 -= fichas_maquina;// Restem a la fila 2
                break;
            case 3:
                fila3 -= fichas_maquina;// Restem a la fila 3
                break;
            }

            cout << "La maquina ha tret: " << fichas_maquina << " fichas de la fila " << fila_maquina << endl;
        }

        total = fila1 + fila2 + fila3; // Calculem el total de fiches restants cada ronda
        if (total > 0)  // Amb aquest If comprobem que la partida segueix o a acabat per fer el canvi de jugadors o no
        {
            if (jugador == 1) {// Realitzem el canvi de torn entre el jugador o la maquina
                jugador = 2;
            }
            else {
                jugador = 1;
            }
        }
    } while (total != 0); // Trenca el bucle cuan les fiches arriben a 0 i tria el guanyador segons l'ultima jugada


    ////////////////////////////////////////////////////////////////////Comprobació///////////////////////////////////////////////////////////////////


    if (jugador == 1) { // amb aquest if mostrem el misatge de guanyador al jugador o a la maquina segons l'ultima jugada

        cout << "¡Has guanyat!";
    }
    else {
        cout << "La maquina ha guanyat!";
    }

    return 0;
}