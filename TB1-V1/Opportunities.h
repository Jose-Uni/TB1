#pragma once
#include "Header.h"

template<typename T>
class Opportunity
{
private:
	T id;
	T titulo;
	float valor;
	Etapa AvanceVenta;
	T fechaInicio;
	T fechaCierre;
	T vendedorAsignado;
	T contactoId;
public:
	Opportunity() {};
	~Opportunity() {};

	void setId(T i) { id = i; }
	void setTitulo(T i) { titulo = i; }
	void setFechaI(T i) { fechaInicio = i; }
	void setFechaC(T i) { fechaCierre = i; }
	void setVendedor(T i) { vendedorAsignado = i; }
	void setContacto(T i) { contactoId = i; }
	void setValor(float i) { valor = i; }
	void setAvance(Etapa i) { AvanceVenta = i; }

	T getId() { return id; }
	T getTitulo() { return titulo; }
	T getFechaI() { return fechaInicio; }
	T getFechaC() { return fechaCierre; }
	T getVendedor() { return vendedorAsignado; }
	T getContacto() { return contactoId; }
	float getValor() { return valor; }
	Etapa getAvance() { return AvanceVenta; }


};

