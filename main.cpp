#include <iostream>

using namespace std;

int n;
int cartiSalvate;

struct Carte {
    int cod_carte;
    string autor_carte;
    string nume_carte;
    int an_publicatie;
    string imprumutat_de;
};

void adauga(Carte* bibleoteca[]) {

    int cod_carte;
    string autor_carte;
    string nume_carte;
    int an_publicatie;

    if (cartiSalvate == n){
        cout << "Bibleoteca este plina."<<endl;
        return;
    }
    cout << "Codul de identificare al cartii: ";
    cin >> cod_carte;
    cout << "Autorul cartii: ";
    cin.get(); // Folosim cin.get pentru a putea citi un string folosind getline
    getline(cin, autor_carte);
    cout << "Numele cartii: ";
    getline(cin, nume_carte);
    cout << "Anul in care a fost publicata cartea: ";
    cin >> an_publicatie;

    // alocare memorie carte
    Carte *carteNoua = new Carte;
    carteNoua->cod_carte = cod_carte;
    carteNoua->autor_carte = autor_carte;
    carteNoua->nume_carte = nume_carte;
    carteNoua->an_publicatie = an_publicatie;

    // adaugare carte in bibleoteca
    // bibleoteca[id] = carteNoua;
    // sau

    for (int i = 0; i < n; i++) {
        if (bibleoteca[i] == NULL) {
            bibleoteca[i] = carteNoua;
            cartiSalvate++;
            cout << "A fost adaugata cartea cu id-ul " << cod_carte << "."<< endl;
            return;// incheie functina dupa primul loc liber gasit
        }
    }
}

void listare(Carte* bibleoteca[]) {
    if(cartiSalvate != 0){
        cout << "Bibleoteca detine urmatoarele carti: " << endl;
    }
    for (int i = 0; i < n; i++) {
      if (bibleoteca[i] != NULL) {
        cout << bibleoteca[i] -> cod_carte << " ";
        cout << bibleoteca[i] -> autor_carte << " ";
        cout << bibleoteca[i] -> nume_carte << " ";
        cout << bibleoteca[i] -> an_publicatie << " ";
        cout << bibleoteca[i] -> imprumutat_de << " "<<endl;
        }
    }
    if(cartiSalvate == 0){
        cout << "Bibleoteca este goala." << endl;
    }
}

void eliminare(Carte* bibleoteca[]) {
    bool detinemCarte = true;
    int cod_carte;
    cout << "Introduceti id-ul cartii: ";
    cin >> cod_carte;
    for (int i = 0; i < n; i++) {
        if (bibleoteca[i] != NULL && bibleoteca[i]->cod_carte == cod_carte) {
            // eliminare student
            delete bibleoteca[i];
            bibleoteca[i] = NULL;
            cartiSalvate--;
            detinemCarte = false;
            }
        }
    if(detinemCarte == false){
        cout << "A fost eliminata cartea cu id-ul: " << cod_carte << endl;
    }
    else{
        cout << "Nu detinem aceasta carte." << endl;
    }
}

void imprumut(Carte* bibleoteca[]) {
    // citire id carte de imprumutat + eliminat
    int cod_carte;
    string persoana;
    cout << "Id-ul cartii dorite: ";
    cin >> cod_carte;

    // cautare carte cu id-ul citit
    for (int i = 0; i < n; i++) {
        if (bibleoteca[i] != NULL && bibleoteca[i]->cod_carte == cod_carte) { // (*clasa[i]).id
            if(bibleoteca[i]->imprumutat_de == "") {
                cout << "Numele persoanei ce o imprumuta: ";
                cin.get();
                getline(cin, persoana);
                bibleoteca[i]->imprumutat_de = persoana;
            }else{
                cout<< "Cartea a fost deja imprumutata." << endl;
            }
        }
    }
}

void inf_carte(Carte* bibleoteca[]) {
    bool detinemCarte = false;
    int cod_carte;
    cout << "Introduceti codul cartii: ";
    cin >> cod_carte;
    for (int i = 0; i < n; i++) {
        if (bibleoteca[i] != NULL && bibleoteca[i]->cod_carte == cod_carte) {
            cout << bibleoteca[i] -> cod_carte << " ";
            cout << bibleoteca[i] -> autor_carte << " ";
            cout << bibleoteca[i] -> nume_carte << " ";
            cout << bibleoteca[i] -> an_publicatie << " ";
            cout << bibleoteca[i] -> imprumutat_de << " " << endl;
            detinemCarte = true;
            return;
        }
    }
    if (detinemCarte == false){
        cout << "Nu detinem aceasta carte." <<  endl;
    }
}

void inf_persoana(Carte* bibleoteca[]) {
    bool persoanaAreCartiImprumutate = false;
    string persoana;
    cout << "Introduceti persoana pe care o cautati: ";
    cin.get();
    getline(cin, persoana);
    for (int i = 0; i < n; i++) {
        if (bibleoteca[i] != NULL && bibleoteca[i]->imprumutat_de == persoana) {
            cout << bibleoteca[i] -> autor_carte << " ";
            cout << bibleoteca[i] -> nume_carte << " ";
            cout << bibleoteca[i] -> an_publicatie << " " <<endl;
            persoanaAreCartiImprumutate = true;
        }
    }
    if (persoanaAreCartiImprumutate == false){
        cout << "Nu exista aceasta persoana." <<  endl;
    }
}

int main()
{
    char op;
    cartiSalvate = 0;
    cout << "Dimensiunea bibleotecii: ";
    cin >> n;

    Carte *bibleoteca[n];

    for (int i = 0; i < n; i++) {
        bibleoteca[i] = NULL;
    }
    do {
        cout << "Introduceti optiunea: " << endl;
        cout << "   A - Adauga" << endl;
        cout << "   L - Listeaza" << endl;
        cout << "   E - Elimina" << endl;
        cout << "   I - Imprumuta" << endl;
        cout << "   C - Carte" << endl;
        cout << "   P - Persoana" << endl;
        cin >> op;

        switch (op) {
            case 'A':
                adauga(bibleoteca);
                break;
            case 'L':
                listare(bibleoteca);
                break;
            case 'E':
                eliminare(bibleoteca);
                break;
            case 'I':
                imprumut(bibleoteca);
                break;
            case 'C':
                inf_carte(bibleoteca);
                break;
            case 'P':
                inf_persoana(bibleoteca);
                break;
            default:
                cout << "Ati introdus o comanda gresita." << endl;
                break;
        }
    } while (op != 'Q');

    return 0;
}

