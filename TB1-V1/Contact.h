#pragma once
#include "Intro.h"

template<typename T>
class Contact
{
private:
	T id;
	T nombre;
	T apellido;
	T email;
	int telefono;
	T empresa;
	T cargo;   //seria el puesto en su empresa 
	bool estado;
	Tag Tipo;  //es lo que es el para nosotros
	Etapa AvanceVenta;

public:
	Contact() {
		id = generateId();
		estado = true;
	};
	~Contact() {};


	void setId(T a) { id = a; }
	void setNombre(T a) { nombre = a; }
	void setApellido(T a) { apellido = a; }
	void setEmail(T a) { email = a; }
	void setEmpresa(T a) { empresa = a; }
	void setCargo(T a) { cargo = a; }
	void setTelefono(int a) { telefono = a; }
	void setEstado(bool a) { estado = a; }
	void setTipo(Tag a) { Tipo = a; }
	void setAvance(Etapa a) { AvanceVenta = a; }

	T getId() { return id; }
	T getNombre() { return nombre; }
	T getApellido() { return apellido; }
	T getEmail() { return email; }
	T getEmpresa() { return empresa; }
	T getCargo() { return cargo; }
	int getTelefono() { return telefono; }
	bool getEstado() { return estado; }
	Tag getTipo() { return Tipo; }
	Etapa getAvance() { return AvanceVenta; }


	int generateId() {
		//nose si hacer automaticamente o tipo meter las 2 letras del nombre, 3 letras del apellido y asi aa
	};
};

