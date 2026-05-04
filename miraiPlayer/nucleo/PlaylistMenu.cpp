#include <iostream>
#include "PlaylistMenu.hpp"

using namespace std;

void PlaylistMenu(Player& player){
    bool enMenu = true;
    string input;


    while (enMenu){

        cout << "Actual: " << player.song.nombre << " - " 
        << player.song.artista << endl;

        cout << "\nLista de reproducción actual:" << endl;

        Node<Song>* actual = player.queue.getHead();
        int i = 1;

        if (player.queue.isEmpty()){
            cout << "Lista vacía." << endl;
        }else{
            while (actual != nullptr){
                cout << i << ". " << actual->data.nombre 
                << " - " << actual->data.artista << endl;
                actual = actual->next;
                i++;
            }
        }

        cout << "\nOpciones:" << endl;
        cout << "S<num> - Saltar a la canción" << endl;
        cout << "V - Volver" << endl;
        cout << "Ingrese una opción: ";

        cin >> input;
        char opcion = toupper(input[0]);

        switch (opcion){
            case 'S':{
                try{
                    int index = stoi(input.substr(1)) - 1;

                    Node<Song>* temp = player.queue.getHead();

                    for (int j = 0 ; j < index && temp != nullptr; j++){
                        temp = temp->next;
                    }

                    if (temp == nullptr){
                        throw runtime_error("Índice inválido");
                    }

                    player.song = temp->data;

                    for (int j = 0; j<= index; j++){
                        player.queue.dequeue();
                    }

                    cout << "Saltando a: " << player.song.nombre << endl;

                    enMenu = false;
                }
                catch (...){
                    cout << "Índice inválido" << endl;
                }
                break;
            }

            case 'V':
                enMenu = false;
                break;

            default:
                cout << "Opción inválida" << endl;
        }
    }
}

 
