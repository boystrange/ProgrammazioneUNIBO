
#include <iostream>

struct Prodotto {
  int codice;
  std::string nome;
  int disponibilita; // >= 0
  Prodotto* next;
};

class Magazzino {
protected:
  Prodotto* prodotti;

public:
  Magazzino();
  virtual int decrementa_disponibilita(int codice, int q);
};

Magazzino::Magazzino() : prodotti(nullptr) { }

int Magazzino::decrementa_disponibilita(int codice, int q) {
  int i = 0;
  Prodotto* p = prodotti;
  while (p != nullptr && p->codice != codice) {
    i++;
    p = p->next;
  }
  if (p != nullptr && p->disponibilita >= q) {
    p->disponibilita -= q;
    return i;
  } else return -1;
}

class MagazzinoPlus : public Magazzino {
private:
  int soglia;
  int conteggio; // prodotti da approvvigionare

public:
  MagazzinoPlus(int soglia);
  virtual int decrementa_disponibilita(int codice, int q);
  void da_approvvigionare(int codice[]) const;
  void aggiorna_disponibilita(int codice[], int quantita[], int n);
};

MagazzinoPlus::MagazzinoPlus(int soglia) : Magazzino() {
  this->soglia = soglia;
}

int MagazzinoPlus::decrementa_disponibilita(int codice, int q) {
  int indice = Magazzino::decrementa_disponibilita(codice, q);
  if (indice != -1) {
    Prodotto* p = prodotti;
    for (int i = 0; i < indice; i++) p = p->next;
    if (p->disponibilita < soglia) conteggio++;
  }
  return indice;
}

void MagazzinoPlus::da_approvvigionare(int codice[]) const {
  int i = 0;
  for (Prodotto* p = prodotti; p != nullptr; p = p->next)
    if (p->disponibilita < soglia) codice[i++] = p->codice;
}

void MagazzinoPlus::aggiorna_disponibilita(int codice[], int quantita[], int n) {
  for (int i = 0; i < n; i++) {
    Prodotto* p = prodotti;
    while (p != nullptr && p->codice != codice[i]) p = p->next;
    if (p != nullptr) p->disponibilita += quantita[i];
  }
}
