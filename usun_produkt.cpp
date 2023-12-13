#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Produkt{
    string nazwa;
    int ilosc;
    string termin_przydatnosci;
};

vector<Produkt> wczytajDaneZBazy();
void usunProduktZLodowki(int numerProduktu);
void usunProduktZLodowki(int numerProduktu, vector<Produkt>& produkty, string nazwaPliku);
void wyswietlZawartoscLodowki(vector<Produkt> produkty);

int main()
{
    vector<Produkt> produktyUzytkownika = wczytajDaneZBazy();
    int numerDoUsuniecia;
    
    cout << "-------- Twoja lodowka --------" << endl;
    cout << "Numer, Nazwa produktu, Ilosc, Data przydatnosci" << endl;
    
    wyswietlZawartoscLodowki(produktyUzytkownika);
    
    cout << "Podaj numer produktu ktory chcesz usunac: " ;    
    cin >> numerDoUsuniecia;
    
    if(numerDoUsuniecia) usunProduktZLodowki(numerDoUsuniecia, produktyUzytkownika, "produkty.txt");
    
    wyswietlZawartoscLodowki(produktyUzytkownika);    
    
    return 0;
}

vector<Produkt> wczytajDaneZBazy(){
    vector<Produkt> produkty;
    string nazwaPliku = "produkty.txt";
    
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie mo¿na otworzyæ pliku: " << nazwaPliku << endl;
        return produkty;
    }

    while (!plik.eof()) {
        Produkt nowyProdukt;
        plik >> nowyProdukt.nazwa >> nowyProdukt.ilosc >> nowyProdukt.termin_przydatnosci;
        produkty.push_back(nowyProdukt);
    }

    plik.close(); 
    
    return produkty;
}

void usunProduktZLodowki(int numerProduktu, vector<Produkt>& produkty, string nazwaPliku){
    if(numerProduktu >= 1 && numerProduktu <= produkty.size()) {
        produkty.erase(produkty.begin() + numerProduktu - 1);

        ofstream nowyPlik(nazwaPliku, ios::trunc);
        
        if(nowyPlik.is_open()) {
            for(int i = 0; i < produkty.size(); i++) {
                string nowaLinia = i + 1 == produkty.size() ? "" : "\n"; 
                
                nowyPlik << produkty[i].nazwa << " " << produkty[i].ilosc 
                         << " " << produkty[i].termin_przydatnosci << nowaLinia;
            }

            cout << "Produkt usuniêty." << endl;
        } else {
            cerr << "Nie mo¿na otworzyæ pliku do zapisu." << endl;
        }
    } else {
        cerr << "Nieprawid³owy numer linii do usuniêcia." << endl;
    }    
}

void wyswietlZawartoscLodowki(vector<Produkt> produkty){
    for(int i = 0; i < produkty.size(); i++){
        cout << i + 1 << " " << produkty[i].nazwa << " " << produkty[i].ilosc 
             << " " << produkty[i].termin_przydatnosci << endl;
    }    
}