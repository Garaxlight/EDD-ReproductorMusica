#include <iostream>
#include "../estructuras/LinkedList.hpp"
#include "../estructuras/Queue.hpp"
#include "../estructuras/Stack.hpp"
#include "../clases/Song.hpp"
#include "FileManager.hpp"
#include "../estructuras/Status.hpp"

using namespace std;

void mostrarMenu(){
    cout << "=== Reproductor de Música ===" << endl;
    cout << "W - Reproducir/Pausar" << endl;
    cout << "Q - Pista Anterior" << endl;
    cout << "E - Pista Siguiente" << endl;
    cout << "S - Modo Aleatorio" << endl;
    cout << "R - Repeticion" << endl;
    cout << "A - Ver lista actual" << endl;
    cout << "L - Lista de Canciones" << endl;
    cout << "X - Salir" << endl;
    cout << "============================" << endl;

    cout << "Ingrese una opción: ";
}

int main(){
    // Estructura

    LinkedList<Song> listaCanciones;
    Queue<Song> reproduccion;
    Stack<Song> historial;

    Status status;

    // Cargar datos
    FileManager::loadMusic("musicSource.txt", listaCanciones);
    status = FileManager::loadStatus("status.cfg");

    bool ejecutando = true;
    char opcion;

    while (ejecutando){
        mostrarMenu();
        cin >> opcion;

        switch (opcion){
            case 'W':
            case 'w':
                cout << "Reproduciendo/Pausando..." << endl;
                break;
            case 'Q':
            case 'q':
                cout << "Pista anterior..." << endl;
                break;
            case 'E':
            case 'e':
                cout << "Pista siguiente..." << endl;
                break;
            case 'S':
            case 's':
                cout << "Modo aleatorio..." << (status.shuffle ? "ON" : "OFF") << endl;
                break;
            case 'R':
            case 'r':
                cout << "Modo repetición..." << (status.repeatMode ? "ON" : "OFF") << endl;
                break;
            case 'A':
            case 'a':
                cout << "Ver lista actual..." << endl;
                break;
            case 'L':
            case 'l':{
                cout << "\n=== CANCIONES ===\n";

                Node<Song>* actual = listaCanciones.getHead();
                int i = 1;

                while (actual != nullptr){
                    cout << i << ". " << actual->data.nombre 
                    << " - " << actual->data.artista << endl;
                    actual = actual->next;
                    i++;
                }
                break;
            }
            case 'X':
            case 'x':
                ejecutando = false;
                FileManager::saveStatus("status.cfg", status);
                cout << "Saliendo del reproductor..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente\n" << endl;
        }
    }

    return 0;
}