
#ifndef COMP_OR
#define COMP_OR
#include "Serie.h"

/*#include <iostream>
#pragma once
#include <algorithm>
#include <string>*/

class Comp_or {
protected:
	// parametres normalistion
	float	MINI;					//plage mini et maxi des mesures prise en compte(�cr�tage sinon)
	float	MAXI;					//plage mini et maxi des mesures prise en compte(�cr�tage sinon)
	// param�tres internes
	int		BITS;
	int		BITECT;					// nb de bits pour l'�cart-type ex. 8
	int		BITYP;					// nb de bits pour l'�cart-type ex. 8
	int		CODAGEECT;				// prise encompte de l'�cart-type dans le codage (0: non, 1: oui)
	Serie	y0;						// valeurs � compresser
	Serie	yr0;					// r�sultat non normalis�
	bool	calculKo;
	// param�tres codage
	Serie	paylEct;
	Serie	paylYp;
	float	precCod;
public:
	Comp_or(float mini, float maxi, int bits, int bitEct, int bitYp, int codageEct);
	~Comp_or();
	float		precisionCodage();
	int			taillePayload();
	float		tauxCompression();
	String		check();
	Serie		simul();
	Serie		ecartTypeSimul(bool codec);
	Serie		compressEct();
	Serie		compressYp();
	Serie		compress();
	Serie		decompressEct(Serie payl);
};
#endif

