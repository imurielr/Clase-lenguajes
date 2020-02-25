#pragma once
#include "estado.h"

class Punto{
 public:
  Punto(int x, int y);
  int obtX() const;
  int obtY() const;
  Estado obtEstado() const;
  void activar();
  void inactivar();
  void avanzarNorte();
}
