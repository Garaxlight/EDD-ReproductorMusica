#include <iostream>
#include <string>
#include "../estructuras/LinkedList.hpp"
#include "../estructuras/Queue.hpp"
#include "../estructuras/Stack.hpp"
#include "../clases/Song.hpp"
#include "../clases/Player.hpp"
#include "../nucleo/FileManager.hpp"

using namespace std;

void mostrarCanciones(LinkedList<Song>& lista){
    Node<Song>* actual = lista.getHead();

    int i = 1;

    cout << "\n=== CANCIONES REGISTRADAS ===" << endl;
    

    while(actual != nullptr){
        cout << i << ". " << actual->data.nombre 
        << " - " << actual->data.artista << endl;
        actual = actual->next;
        i++;
    }
}


void menuCanciones(LinkedList<Song>& lista, 
    Player& player){
    string input;
    bool enMenu = true;

    while(enMenu){
        cout << "\n=== OPCIONES ===" << endl;
        cout << "R<num> - Reproducir canción" << endl;
        cout << "A<num> - Agregar canción a cola" << endl;
        cout << "N - Nueva canción" << endl;
        cout << "D<num> - Eliminar canción" << endl;
        cout << "V - Volver" << endl;
        cout << "Ingrese una opción: ";

        cin >> input;
        char opcion = toupper(input[0]);

        switch (opcion){
            case 'R':{
                int index = stoi(input.substr(1)) - 1;

                try{
                    Song s = lista.getAt(index);
                    player.song = s;
                    player.isPlaying = true;
                    cout << "Reproduciendo: " << s.nombre << " - " << s.artista << endl;

                    while(!player.queue.isEmpty()){
                        player.queue.dequeue();
                    }

                    while (!player.history.isEmpty()){
                        player.history.pop();
                    }

                    player.history.push(s);
                }catch (...){
                    cout << "Índice no válido." << endl;
                }
                break;
            }


            case 'A':{
                int index = stoi(input.substr(1)) - 1;

                try{
                    Song s = lista.getAt(index);
                    player.queue.enqueue(s);
                    cout << "Canción agregada a la cola." << endl;
                }catch (...){
                    cout << "Índice no válido." << endl;
                }
                break;
            }


            case 'N':{
                Song nueva;

                cin.ignore();

                cout << "Ingrese nombre: ";
                getline(cin, nueva.nombre);

                cout << "Ingrese artista: ";
                getline(cin, nueva.artista);

                cout << "Ingrese album: ";
                getline(cin, nueva.album);

                cout << "Ingrese año: ";
                cin >> nueva.año;

                cout << "Ingrese duración (segundos): ";
                cin >> nueva.duracion;

                cin.ignore();
                cout << "Ingrese ubicación: ";
                getline(cin, nueva.ubicacion);

                nueva.id = lista.size() + 1;

                lista.insertEnd(nueva);
                FileManager::saveMusic("musicSource.txt", lista);

                cout << "Canción agregada: " << endl;
                break;
            }


            case 'D':{
                int index = stoi(input.substr(1)) - 1;

                try{
                    lista.removeAt(index);
                    FileManager::saveMusic("musicSource.txt", lista);
                    cout << "Canción eliminada." << endl;
                }catch (...){
                    cout << "Índice no válido." << endl;
                }
                break;
            }

            case 'V':
                enMenu = false;
                break;
            default:
                cout << "Opción no válida, intente de nuevo." << endl;
        }
    }
}