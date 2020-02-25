#ifndef CLASE_03_H
#define CLASE_03_H 

class Factor {
  double factor;
  void imprCons();
public:
  Factor();
  Factor(double factor);
  virtual ~Factor();
  double obtFactor() const;
  void modFactor(double factor);
  double multFactor(double value) const;
};
#endif
