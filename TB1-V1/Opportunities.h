#pragma once
#include "header.h"


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
	Opportunity(T ttl, float vlr, Etapa etp, T fi, T fc, T vdAs, T contactoId) :
		titulo(ttl), valor(vlr), AvanceVenta(etp), fechaInicio(fi),
		fechaCierre(fc), vendedorAsignado(vdAs), contactoId(contactoId)
	{
		id = generateId();
	};
	~Opportunity() {};

	void setId() { id = generateId(); }
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

	T generateId() {
		
		T idNew = titulo.substr(0, 2) + vendedorAsignado.substr(0, 2) + fechaInicio.substr(0, 2)+fechaCierre.substr(0, 2);
		return idNew;
	};
};

