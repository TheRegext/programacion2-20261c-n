class Fecha{
public:
  Fecha();
  Fecha(int dia, int mes, int anio);

  /// getters y setters
  void setDia(int dia);
  void setMes(int mes);
  void setAnio(int anio);

  int getDia() const;
  int getMes() const;
  int getAnio() const;

  void setCurrentDate(); // Método para cargar la fecha actual del sistema

private:
    int _dia, _mes, _anio;
};
