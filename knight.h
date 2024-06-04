#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
int levelio(int i);
float basedamage(int HP,int x,int levelio);
int mushmario(int level,int phoenixdown,int HP);
int mushfibo(int HP);
float timmaxmin( ifstream &ifs,int HP);
float mush2( ifstream &ifs,int HP);
float mush3( ifstream &ifs,int n,int HP);
float mush4(ifstream &ifs,int n,int HP);
int merlinkhochiu(ifstream &file_merlin_pack,int HP);
int demtihon1(bool tihon,int demtihon);
int demech1(bool ech,int demech);
int chuyendoi(string k);
int chuyendoi2(string k);

#endif // __KNIGHT_H__
