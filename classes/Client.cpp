//
// Created by Administrateur on 15/11/2022.
//

#include "Client.h"

Client::Client(std::string nom, std::string prenom, std::string adresse,
               std::string numero_tel, std::string mail) {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    this->numero_client = uuid;

    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->numero_tel=numero_tel;
    this->mail=mail;

}

boost::uuids::uuid Client::get_numero_client() {


}


string Client::get_nom() {

}

string Client::get_prenom() {

};


string Client::get_adresse() {

};

string Client::get_numero_tel() {

};

string Client::get_mail() {

};
