//#pragma once
#ifndef COMPACTOR
#define COMPACTOR
#include "Comp_or.h"

class Compactor : public Comp_or {
protected:
	int		NBREG0;				// nombre de points de la regression
	int		BIT;				// nombre de bits de codage de chaque point de r�gression
	Serie	yp0;				// liste des points de r�gression (normalis�)
public:
	 Compactor(const int nbreg0, const float mini, const float maxi, const int bit, const int bitEct, const int codageEct);
	~Compactor();
	String		check();
	String		calcul(Serie y, bool codec);
	Serie		param();

	// fonctions � utiliser uniquement en mode r�cepteur
	Serie		decompressYp(Serie payload);
	Serie		decompressY0(Serie payload, int taille);
};
#endif