#pragma once
#include "Intro.h"
#include "header.h"
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
	Tag Tipo;  //es lo que es el para nosotros
	

public:
	Contact() {};
	Contact(T n, T a, T e,int t, T emp, T c, Tag tag)
		: nombre(n), apellido(a), email(e), empresa(emp), cargo(c),
		telefono(t), Tipo(tag) {
		id = generateId();
	};
	~Contact() {};


	void setId() { id = generateId(); }
	void setId(T i) { id = i; }
	void setNombre(T a) { nombre = a; }
	void setApellido(T a) { apellido = a; }
	void setEmail(T a) { email = a; }
	void setEmpresa(T a) { empresa = a; }
	void setCargo(T a) { cargo = a; }
	void setTelefono(int a) { telefono = a; }
	void setTipo(Tag a) { Tipo = a; }
	

	T getId() { return id; }
	T getNombre() { return nombre; }
	T getApellido() { return apellido; }
	T getEmail() { return email; }
	T getEmpresa() { return empresa; }
	T getCargo() { return cargo; }
	int getTelefono() { return telefono; }
	Tag getTipo() { return Tipo; }
	

	T generateId() {
		//nose si hacer automaticamente o tipo meter las 2 letras del nombre, 3 letras del apellido y asi aa
		T idNew = nombre.substr(0, 2) + apellido.substr(0, 2) + empresa.substr(0, 2) + cargo.substr(0, 2);
		return idNew;
	};
};


