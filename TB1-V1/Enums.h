#pragma once
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include "Letras.h"

struct User {
	string usuario;
	string password;
	User() : usuario(""), password("") {}
	User(string usuario, string password) : usuario(usuario), password(password) {}
};

enum class Tag {
	LEAD,
	PROSPECTO,
	CLIENTE,
	VIP,
	INACTIVO,
	FRECUENTE,
	CORPORATIVO
};

enum class Etapa {
	PROPUESTA,
	NEGOCIACION,
	CERRADO_GANADO,
	CERRADO_PERDIDO
};
struct Sonidos {
	void SonidoExito() {
		PlaySound(TEXT("C:\\Windows\\Media\\tada.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoNotificacion() {
		PlaySound(TEXT("C:\\Windows\\Media\\notify.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoArranque() {
		PlaySound(TEXT("C:\\Windows\\Media\\chord.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoError() {
		PlaySound(TEXT("sonidos\\Fah.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
};