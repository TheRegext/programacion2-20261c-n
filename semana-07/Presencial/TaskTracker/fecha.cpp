#include "fecha.h"
#include <ctime>

Fecha::Fecha()
{
    std::time_t now = std::time(0); // Get current time as time_t
    std::tm* localTime = std::localtime(&now); // Convert to local time

    _dia = localTime->tm_mday;
    _mes = localTime->tm_mon + 1;
    _anio = localTime->tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

/// getters y setters
void Fecha::setDia(int dia) {
    _dia = dia;
}

void Fecha::setMes(int mes) {
    _mes = mes;
}

void Fecha::setAnio(int anio) {
    _anio = anio;
}

int Fecha::getDia() const {
    return _dia;
}

int Fecha::getMes() const {
    return _mes;
}

int Fecha::getAnio() const {
    return _anio;
}

std::string Fecha::toString(){
    std::string fecha;
    std::string diaAux, mesAux;

    diaAux = (_dia < 10 && _dia >=1 ? "0" + std::to_string(_dia) : std::to_string(_dia));
    mesAux = (_mes < 10 && _mes >= 1 ? "0" + std::to_string(_mes) : std::to_string(_mes));

    fecha = diaAux + "/" + mesAux+ "/" + std::to_string(_anio);
    return fecha;
}

