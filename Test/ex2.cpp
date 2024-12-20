
#include <iostream>

struct Tavolo {
  int persone; // >= 0
  double orario;
  bool interno;
  Tavolo* next;
};

Tavolo* prenota_tavolo(Tavolo* p, int persone) {
  if (p == nullptr) return nullptr;
  else if (p->persone >= persone) {
    Tavolo* q = p->next;
    delete p;
    return q;
  } else {
    p->next = prenota_tavolo(p->next, persone);
    return p;
  }
}

double quale_orario(Tavolo* p, int persone, bool interno) {
  if (p == nullptr)
    return -1;
  else if (p->persone >= persone && p->interno == interno)
    return p->orario;
  else
    return quale_orario(p->next, persone, interno);
}

int quanti_tavoli(Tavolo* p, bool interno) {
  if (p == nullptr)
    return 0;
  else if (p->interno == interno)
    return 1 + quanti_tavoli(p->next, interno);
  else
    return quanti_tavoli(p->next, interno);
}
