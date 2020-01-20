//#include "stdafx.h"
#include "Comp_or.h"
#include "Serie.h"

using namespace std;

Comp_or::Comp_or(float mini, float maxi, int bits, int bitEct, int bitYp, int codageEct) {
	// parametres normalistion
	MINI		= mini;					//plage mini et maxi des mesures prise en compte(�cr�tage sinon)
	MAXI		= maxi;					//plage mini et maxi des mesures prise en compte(�cr�tage sinon)
	// param�tres internes
	BITS		= bits;
	BITECT		= bitEct;				// nb de bits pour l'�cart-type ex. 8
	BITYP		= bitYp;				// nb de bits pour l'�cart-type ex. 8
	calculKo	= true;
	// param�tres codage
	CODAGEECT	= codageEct;
}
		Comp_or::~Comp_or()			{ }
float	Comp_or::precisionCodage()	{ return precCod; }
int		Comp_or::taillePayload()	{ return BITS; }
float	Comp_or::tauxCompression()	{ return float(BITS) / float(y0.len()) / 16.0f; }
Serie	Comp_or::simul()			{ return yr0; }
Serie	Comp_or::compressEct()		{ return paylEct; }
Serie	Comp_or::compressYp()		{ return paylYp; }

String	Comp_or::check() {
	String resultat = "ok";
	if (MINI > MAXI)						resultat = " seuils mini - maxi incoh�rents";
	if (BITECT < 1)							resultat = " nombre de bits insuffisant";
	if (CODAGEECT == 1 and BITS < BITECT)	resultat = " nombre de bits incoh�rents";
	return resultat;
}
Serie	Comp_or::ecartTypeSimul(bool codec) {
	if (calculKo) return 0;
	Serie ect(1, "ect", Serie::etDiff(y0, yr0));
	Serie ects(ect);
	if (codec) ect = ect.normalisation(MINI, MAXI).codage(1, BITECT).decodage(1, BITECT).denormalisation(MINI, MAXI);
	return ects;
}
Serie	Comp_or::compress() {
	Serie payl(paylYp);
	if (CODAGEECT == 1) payl |= paylEct;
	payl.setNom("payl");
	return payl;
}
//# fonctions � utiliser uniquement en mode r�cepteur
Serie	Comp_or::decompressEct(Serie payl) {
	Serie serieEct(1, "ect", 0.0f);
	if (CODAGEECT == 0) return serieEct;
	serieEct = payl.sousSerie(BITS - BITECT, BITECT).decodage(1, BITECT).denormalisation(MINI, MAXI);
	return serieEct;
}

