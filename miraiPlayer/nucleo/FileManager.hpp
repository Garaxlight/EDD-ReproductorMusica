#pragma once
#include <string>
#include <fstream> 
#include <sstream>
#include "Status.hpp"
#include "../clases/Song.hpp"
#include <../estructuras/LinkedList.hpp>

class FileManager{
    public:

    static void loadMusic(const std::string& filename, LinkedList<Song>& lista){
        std::ifstream file(filename);

        if(!file.is_open()){
            return; // Archivo no existe
        }

        std::string line;

        while(std::getline(file,line)){
            if(line.empty()) continue; // Saltar líneas vacías

            std::stringstream ss(line);
            std::string token;

            Song s;

            std::getline(ss, token, ',');
            s.id = std::stoi(token);

            std::getline(ss, s.nombre, ',');
            std::getline(ss, s.artista, ',');
            std:getline(ss, s.album, ',');

            std::getline(ss, token, ',');
            s.año = std::stoi(token);

            std::getline(ss, token, ',');
            s.duracion = std::stoi(token);

            std::getline(ss, s.ubicacion, ',');

            lista.insertEnd(s);
        }

        file.close();
    }


    static Status loadStatus(const std::string& filename){
        std::ifstream file(filename);

        Status s;
        s.currentSongId = -1;
        s.shuffle = false;
        s.repeatMode = 0;

        if (!file.is_open()){
            return s; //retornar default si no existe el archivo
        }

        std::string line;


        while(std::getline(file,line)){
            std::stringstream ss(line);
            std::string key, value;
            std::getline(ss, key, '=');
            std::getline(ss, value);

            if (key == "CURRENT"){
                s.currentSongId = std::stoi(value);
            }else if (key == "SHUFFLE"){
                s.shuffle = (value == "1");
            }else if (key == "REPEAT"){
                s.repeatMode = std::stoi(value);
            }
        }

        file.close();
        return s;
    }




    static void saveStatus(const std::string& filename, const Status& s){
        std::ofstream file(filename);

        if (!file.is_open()) return;

        file << "CURRENT=" << s.currentSongId << std::endl;
        file << "SHUFFLE=" << (s.shuffle ? "1" : "0") << std::endl;
        file << "REPEAT=" << s.repeatMode << std::endl;

        file.close();
    }
};