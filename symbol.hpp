#ifndef SYMBOL_HPP_
#define SYMBOL_HPP_

#include "lista_d_enla.hpp"
#include <iostream>


 enum Line{L, R, U, D}; // LEFT ,RIGHT, UP, DOWN
const char l[4] ={'L','R','U','D'};

class Symbol
{

public:

	Symbol();
	void add(Line);
	void del(std::size_t);
	Symbol sym_x();
	Symbol sym_y();
	Symbol sym_xy();
	// ~Symbol(){lines.~Lista();}

	friend std::ostream& operator<<(std::ostream& os, const Symbol& s);

private:

	Lista<Line> lines;

};

Symbol::Symbol():lines{}{}


inline void Symbol::add(Line l)
{
	lines.insertar(l,lines.fin());

}

void Symbol::del(std::size_t n)
{

	
	while(lines.fin()!= lines.primera() && n > 0)
	{
		lines.eliminar(lines.fin());
		n--;
	}

	if(n>0 && lines.primera()!= lines.fin())
		lines.eliminar(lines.fin());
}

Symbol Symbol::sym_y()
{
	Symbol res{*this};

	

	for(Lista<Line>::posicion p = res.lines.primera(); p != res.lines.fin(); p = res.lines.siguiente(p))
	{
		switch(res.lines.elemento(p))
		{
			case L: res.lines.elemento(p) = R;
			break;
			case R: res.lines.elemento(p)= L;
			break;

			default:
			break;

		}
	}

	return res;

}

Symbol Symbol::sym_x()
{
	Symbol res{*this};



	for(Lista<Line>::posicion p = res.lines.primera(); p != res.lines.fin(); p = res.lines.siguiente(p))
	{
		switch(res.lines.elemento(p))
		{
			case U: res.lines.elemento(p) = D;
			break;
			case D: res.lines.elemento(p)= U;
			break;
			default:
			break;

		}
	}

	return res;



}

Symbol Symbol::sym_xy()
{


	Symbol res = sym_x();
	res = res.sym_y();

	return res;
}


std::ostream& operator<<(std::ostream& os, const Symbol& s)
{


	os<<"- ";


	for(Lista<Line>::posicion p = s.lines.primera(); p != s.lines.fin(); p = s.lines.siguiente(p))
		os<<l[s.lines.elemento(p)]<<" - ";



	return os;

	
}










#endif // SYMBOL_HPP_