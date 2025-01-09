

#include <iostream>
#include<conio.h>
#include <cstdlib>
using namespace std;
void Alive(int& rh, int& ch, int re, int  ce, char x[][130], int& flagalive1, int& flagalive2, int& flagalive4, int& flagmove4, int& flagdir4, int& flag7bl, int re2, int ce2, int re3, int ce3, int& flagwon, int rb, int cb, int cbullet[1000], int rbullet[1000], int& flagdead1, int& flagdead2, int& flagalive3, int re4, int ce4)
{
	for (int i = 0; i < 1000; i++)
	{
		if ((cbullet[i] == ce3 || cbullet[i] == ce3 + 1 || cbullet[i] == ce3 + 2 || cbullet[i] == ce3 + 3 || cbullet[i] == ce3 + 4 || cbullet[i] == ce3 - 1 || cbullet[i] == ce3 - 2 || cbullet[i] == ce3 - 3 || cbullet[i] == ce3 - 4 || cbullet[i] == ce3 - 5) && (rbullet[i] > 0 && rbullet[i] < 10))
		{
			flagalive3 = 1;
			flagwon = 1;
		}
	}
	if ((ce4 - 1 == cb && (rb >= 0 && rb <= 19)) || (ce4 - 2 == cb && (rb >= 0 && rb <= 19)) || (ce4 + 2 == cb && (rb >= 0 && rb <= 19)) || (ce4 + 1 == cb && (rb >= 0 && rb <= 19)) || (ce4 + 3 == cb && (rb >= 0 && rb <= 19)) || (ce4 + 4 == cb && (rb >= 0 && rb <= 19)) || (ce4 + 5 == cb && (rb >= 0 && rb <= 19)) || (ce4 + 6 == cb && (rb >= 0 && rb <= 19)))
	{
		flagalive4 = 1;
	}
	if ((ce + 4 == cb && (rb >= 47 && rb <= 56)) || (ce + 3 == cb && (rb >= 47 && rb <= 56)) || (ce + 2 == cb && (rb >= 47 && rb <= 56)))
	{
		flagalive1 = 1;
		flag7bl = 1;
	}
	if ((ce + 1 == cb && (rb >= 47 && rb <= 56)) || (ce == cb && (rb >= 47 && rb <= 56)) || (ce - 1 == cb && (rb >= 47 && rb <= 56)))
	{
		flagalive1 = 1;
		flag7bl = 1;
	}
	if (rh == 19)
	{
		flagmove4 = 1;
		flagdir4 = 1;
	}
	if (flagdead1 == 1)
	{
		if ((ce2 + 12 == cb && (rb >= 32 && rb <= 40)) || (ce2 + 11 == cb && (rb >= 32 && rb <= 40)) || (ce2 + 10 == cb && (rb >= 32 && rb <= 40)))
		{
			flagdead2 = 2;
			flagdead1 = 2;
		}
		if ((ce2 + 9 == cb && (rb >= 32 && rb <= 40)) || (ce2 + 8 == cb && (rb >= 32 && rb <= 40)) || (ce2 + 7 == cb && (rb >= 32 && rb <= 40)))
		{
			flagdead2 = 2;
			flagdead1 = 2;
		}
	}
	if ((ce2 + 1 == cb && (rb >= 32 && rb <= 40)) || (ce2 == cb && (rb >= 32 && rb <= 40)) || (ce2 - 1 == cb && (rb >= 32 && rb <= 40)))
	{
		flagalive2 = 1;
		if (flagdead1 == 0 || flagdead2 == 0)
		{
			flagdead1 = 1;
			flagdead2 = 1;
		}
	}
	if ((ce2 + 4 == cb && (rb >= 32 && rb <= 40)) || (ce2 + 3 == cb && (rb >= 32 && rb <= 40)) || (ce2 + 2 == cb && (rb >= 32 && rb <= 40)))
	{
		flagalive2 = 1;
		if (flagdead1 == 0 || flagdead2 == 0)
		{
			flagdead1 = 1;
			flagdead2 = 1;
		}
	}
}
void Asanser(int rs, int cs, char x[][130])
{
	int r, c;
	c = cs - 8;
	for (r = rs - 7; r <= rs; r++)
	{
		x[r + 1][c - 1] = '|';
	}
	c += 9;
	for (r = rs - 7; r <= rs; r++)
	{
		x[r + 1][c] = '|';
	}
	for (c = cs - 8; c < cs + 1; c++)
	{
		x[rs - 6][c] = 196;
	}
	for (c = cs - 8; c <= cs; c++)
	{
		x[rs + 2][c] = 196;
	}
	for (c = cs - 8; c <= cs; c++)
	{
		x[rs + 1][c] = 196;
	}
	x[rs + 2][cs + 1] = 217;
	x[rs + 2][cs - 9] = 192;
	x[rs - 6][cs + 1] = 191;
	x[rs - 6][cs - 9] = 218;
	x[rs + 1][cs - 9] = 195;
	x[rs + 1][cs + 1] = 180;
}
void Apear(int& rh, int& ch, int& ctapear, int flagalive2, int& startrow, int& endrow, int flagdead1, int& flagfall)
{
	if (flagdead1 == 2)
	{
		ctapear++;
		if (ctapear == 15)
		{
			rh = 19;
			ch = 20;
			startrow = 0;
			endrow = 35;
			flagfall = 1;
		}
	}
}
void Asanser2(int& cs2, int& rs2, char x[][130], int& rh, int& ch, int& sr, int& er)
{

	for (int b = cs2; b < cs2 + 24; b++)
	{
		x[rs2][b] = 220;
	}
	for (int b = cs2; b < cs2 + 23; b++)
	{
		x[rs2 + 2][b] = 196;
	}
	x[rs2 + 1][cs2] = 179;
	x[rs2 + 1][cs2 + 23] = 179;
	x[rs2 + 2][cs2] = 192;
	x[rs2 + 2][cs2 + 23] = 217;

	for (int i = cs2 + 1; i < cs2 + 23; i++)
	{
		x[rs2 + 1][i] = 176;
	}
}
void mvasanser(int& cs2, int& rs2, char x[][130], int& rh, int& ch, int& sr, int& er)
{
	if ((ch > 45 && ch < 69) && (rh < 61 && rh>56))
	{
		rh -= 1;
		rs2--;
		sr--;
		er--;
	}
	else
	{
		if (rs2 < 61 && rh + 1 != rs2)
		{
			rs2++;
		}
	}
}
void Draw(char x[][130])
{
	for (int r = 0; r < 80; r++)
	{
		for (int c = 0; c < 130; c++)
		{
			x[r][c] = ' ';
		}
	}
}
int  randNum(int min, int max)
{
	return ((rand() % ((max - min) + 1)) + min);
}
void Disp(int startrow, int endrow, char x[][130], int startcol, int endcol)
{
	system("cls");
	for (int r = startrow; r < endrow; r++)
	{
		for (int c = startcol; c < endcol; c++)
		{
			cout << x[r][c];
		}
		cout << endl;
	}
}
void DispInt(char x[][130])
{
	system("cls");
	for (int r = 0; r < 25; r++)
	{
		for (int c = 0; c < 130; c++)
		{
			cout << x[r][c];
		}
		cout << endl;
	}
}
void DispLs(char x[][130])
{
	system("cls");
	for (int r = 0; r < 25; r++)
	{
		for (int c = 0; c < 130; c++)
		{
			cout << x[r][c];
		}
		cout << endl;
	}
}
void DrBullet(int& star, char x[][130], int flagB[1000], int cbullet[1000], int rbullet[1000], int flagdir[1000], int flagBd[1000], int cbulletd[1000], int rbulletd[1000], int flagdird[1000])
{
	for (int i = 0; i < star; i++)
	{
		if (flagB[i] == 1 || flagBd[i] == 1)
		{
			if (x[rbullet[i] - 1][cbullet[i] + 1] == ' ')
			{
				x[rbullet[i]][cbullet[i]] = '*';
			}
			else
			{
				flagB[i] = 0;
			}
			if (x[rbulletd[i] + 1][cbulletd[i] + 1] == ' ')
			{
				x[rbulletd[i]][cbulletd[i]] = '*';
			}
			else
			{
				flagBd[i] = 0;
			}

		}
	}
}
void DrBull(char x[][130], int& flagbullet, int& flagmove, int& cb, int& rb, int xdirbull, int& ctbullet)
{
	if (flagbullet == 0)
	{
		if (xdirbull == 1)
		{

			if (ctbullet >= 1)
			{
				if (x[rb][cb + 2] == ' ' && x[rb][cb + 3] == ' ')
				{
					x[rb][cb] = '=';
					x[rb][cb + 1] = '*';
				}
			}
			if (ctbullet >= 20)
			{
				if (x[rb - 1][cb + 2] == ' ' && x[rb - 1][cb + 3] == ' ')
				{
					x[rb - 1][cb] = '=';
					x[rb - 1][cb + 1] = '*';
				}
				if (x[rb + 1][cb + 2] == ' ' && x[rb + 1][cb + 3] == ' ')
				{
					x[rb + 1][cb] = '=';
					x[rb + 1][cb + 1] = '*';
				}

			}
			if (ctbullet >= 40)
			{
				if (x[rb - 2][cb + 2] == ' ' && x[rb - 2][cb + 3] == ' ')
				{
					x[rb - 2][cb] = '=';
					x[rb - 2][cb + 1] = '*';
				}
				if (x[rb + 2][cb + 2] == ' ' && x[rb + 2][cb + 3] == ' ')
				{
					x[rb + 2][cb] = '=';
					x[rb + 2][cb + 1] = '*';
				}
			}
			if (ctbullet >= 60)
			{
				if (x[rb - 3][cb + 2] == ' ' && x[rb - 3][cb + 3] == ' ')
				{
					x[rb - 3][cb] = '=';
					x[rb - 3][cb + 1] = '*';
				}
				if (x[rb + 3][cb + 2] == ' ' && x[rb + 3][cb + 3] == ' ')
				{
					x[rb + 3][cb] = '=';
					x[rb + 3][cb + 1] = '*';
				}
			}
			if (ctbullet >= 80)
			{
				if (x[rb - 4][cb + 2] == ' ' && x[rb - 4][cb + 3] == ' ')
				{
					x[rb - 4][cb] = '=';
					x[rb - 4][cb + 1] = '*';
				}
				if (x[rb + 4][cb + 2] == ' ' && x[rb + 4][cb + 3] == ' ')
				{
					x[rb + 4][cb] = '=';
					x[rb + 4][cb + 1] = '*';
				}
			}
			if (ctbullet >= 100)
			{

				if (x[rb][cb + 2] == ' ' && x[rb][cb + 3] == ' ')
				{
					x[rb - 5][cb] = '=';
					x[rb - 5][cb + 1] = '*';
				}
				if (x[rb][cb + 2] == ' ' && x[rb][cb + 3] == ' ')
				{
					x[rb + 5][cb] = '=';
					x[rb + 5][cb + 1] = '*';
				}
			}

		}
		if (xdirbull == -1)
		{

			if (ctbullet >= 1)
			{
				if (x[rb][cb - 2] == ' ' && x[rb][cb - 3] == ' ')
				{
					x[rb][cb] = '=';
					x[rb][cb - 1] = '*';
				}
			}
			if (ctbullet >= 20)
			{
				if (x[rb - 1][cb - 2] == ' ' && x[rb - 1][cb - 3] == ' ')
				{
					x[rb - 1][cb] = '=';
					x[rb - 1][cb + -1] = '*';
				}
				if (x[rb + 1][cb - 2] == ' ' && x[rb + 1][cb - 3] == ' ')
				{
					x[rb + 1][cb] = '=';
					x[rb + 1][cb - 1] = '*';
				}

			}
			if (ctbullet >= 40)
			{

				if (x[rb - 2][cb - 2] == ' ' && x[rb - 2][cb - 3] == ' ')
				{
					x[rb - 2][cb] = '=';
					x[rb - 2][cb - 1] = '*';
				}
				if (x[rb + 2][cb - 2] == ' ' && x[rb + 2][cb - 3] == ' ')
				{
					x[rb + 2][cb] = '=';
					x[rb + 2][cb - 1] = '*';
				}
			}
			if (ctbullet >= 60)
			{

				if (x[rb - 3][cb - 2] == ' ' && x[rb - 3][cb - 3] == ' ')
				{
					x[rb - 3][cb] = '=';
					x[rb - 3][cb - 1] = '*';
				}
				if (x[rb + 3][cb - 2] == ' ' && x[rb + 3][cb - 3] == ' ')
				{
					x[rb + 3][cb] = '=';
					x[rb + 3][cb - 1] = '*';
				}
			}
			if (ctbullet >= 80)
			{

				if (x[rb - 4][cb - 2] == ' ' && x[rb - 4][cb - 3] == ' ')
				{
					x[rb - 4][cb] = '=';
					x[rb - 4][cb - 1] = '*';
				}
				if (x[rb + 4][cb - 2] == ' ' && x[rb + 4][cb - 3] == ' ')
				{
					x[rb + 4][cb] = '=';
					x[rb + 4][cb - 1] = '*';
				}
			}
			if (ctbullet >= 100)
			{

				if (x[rb - 5][cb - 2] == ' ' && x[rb - 5][cb - 3] == ' ')
				{
					x[rb - 5][cb] = '=';
					x[rb - 5][cb - 1] = '*';
				}
				if (x[rb + 5][cb - 2] == ' ' && x[rb + 5][cb - 3] == ' ')
				{
					x[rb + 5][cb] = '=';
					x[rb + 5][cb - 1] = '*';
				}
			}

		}
	}
}
void Drplat1(int rplat, int cplat, char x[][130])
{
	//frame;
	int i = 0, r = 79;
	r = 0;
	for (i = 1; i < 129; i++)
	{
		x[r][i] = 205;
	}
	for (i = 1; i < 129; i++)
	{
		x[r][i] = 205;
	}
	i = 0;
	x[r][i] = 201;
	i = 129;
	x[r][i] = 187;
	for (r = 1; r < 79; r++)
	{
		x[r][i] = 186;
	}
	i = 0;
	for (r = 1; r < 79; r++)
	{
		x[r][i] = 186;
	}
	r = 79;
	x[r][i] = 200;
	i = 129;
	x[r][i] = 188;
	//1stblocks 
	int z = 1;
	for (int i = 0; i < 20; i++)
	{
		x[rplat - 7][z] = 220;
		z++;
	}
	x[rplat - 6][z - 1] = 219;
	x[rplat - 6][z] = 220;
	x[rplat - 6][z + 1] = 220;
	x[rplat - 6][z + 2] = 220;
	x[rplat - 6][z + 3] = 220;
	x[rplat - 6][z + 4] = 220;
	x[rplat - 6][z + 5] = 220;
	x[rplat - 6][z + 6] = 220;
	x[rplat - 5][z + 6] = 219;
	x[rplat - 5][z + 7] = 220;
	x[rplat - 5][z + 8] = 220;
	x[rplat - 5][z + 9] = 220;
	x[rplat - 5][z + 10] = 220;
	x[rplat - 5][z + 11] = 220;
	x[rplat - 5][z + 12] = 220;
	x[rplat - 5][z + 13] = 220;
	x[rplat - 4][z + 13] = 219;


	z = rplat - 3;
	for (z = 1; z < 20; z++)
	{
		x[rplat - 6][z] = 176;
	}
	for (z = 1; z < 27; z++)
	{
		x[rplat - 5][z] = 176;
	}
	for (z = 1; z < 34; z++)
	{
		x[rplat - 4][z] = 176;
	}
	i = rplat - 3;
	for (z = 1; z < 41; z++)
	{
		x[i][z] = 176;
	}
	i = rplat - 2;
	for (z = 1; z < 41; z++)
	{
		x[i][z] = 176;
	}
	i = rplat - 1;
	for (z = 1; z < 41; z++)
	{
		x[i][z] = 176;
	}
	z = cplat + 35;
	for (int i = 0; i < 7; i++)
	{
		x[rplat - 4][z] = 220;
		z++;
	}
	z = rplat - 3;
	for (i = 0; i < 3; i++)
	{
		x[z][cplat + 41] = 219;
		z++;
	}
	//shok nu1
	z = cplat + 43;

	for (int k = 0; k < 6; k++)
	{
		r = rplat - 3;
		for (i = 0; i < 3; i++)
		{
			x[r][z] = '*';
			r++;
		}
		z++;
	}

	//2nd block 
	z = 50;
	for (int i = 0; i < 8; i++)
	{
		x[rplat - 4][z] = 220;
		z++;
	}
	r = rplat - 3;
	for (i = 0; i < 3; i++)
	{
		x[r][cplat + 50] = 219;
		r++;
	}
	r = rplat - 3;
	for (i = 0; i < 3; i++)
	{
		x[r][cplat + 57] = 219;
		r++;
	}
	z = cplat + 51;
	for (int k = 0; k < 6; k++)
	{
		r = rplat - 3;
		for (i = 0; i < 3; i++)
		{
			x[r][z] = 176;
			r++;
		}
		z++;
	}
	//ashwak2;
	z = cplat + 59;

	for (int k = 0; k < 3; k++)
	{
		r = rplat - 3;
		for (i = 0; i < 3; i++)
		{
			x[r][z] = '*';
			r++;
		}
		z++;
	}
	//block number 3;
	z = 63;
	for (int i = 0; i < 7; i++)
	{
		x[rplat - 5][z] = 220;
		z++;
	}
	r = rplat - 4;
	for (i = 0; i < 4; i++)
	{
		x[r][cplat + 63] = 219;
		r++;
	}
	r = rplat - 4;
	for (i = 0; i < 4; i++)
	{
		x[r][cplat + 69] = 219;
		r++;
	}
	z = cplat + 64;
	for (int k = 0; k < 5; k++)
	{
		r = rplat - 4;
		for (i = 0; i < 4; i++)
		{
			x[r][z] = 176;
			r++;
		}
		z++;
	}
	z--;
	x[r - 5][z + 7] = 220;
	x[r - 5][z + 8] = 220;
	x[r - 5][z + 9] = 220;
	x[r - 5][z + 10] = 220;
	x[r - 5][z + 11] = 220;
	x[r - 5][z + 12] = 220;
	x[r - 4][z + 12] = 219;
	x[r - 3][z + 12] = 219;
	x[r - 2][z + 12] = 219;
	x[r - 1][z + 12] = 219;
	x[r - 4][z + 7] = 219;
	x[r - 3][z + 7] = 219;
	x[r - 2][z + 7] = 219;
	x[r - 1][z + 7] = 219;
	x[r - 4][z + 5] = '*';
	x[r - 4][z + 4] = '*';
	x[r - 4][z + 3] = '*';
	x[r - 3][z + 5] = '*';
	x[r - 3][z + 4] = '*';
	x[r - 3][z + 3] = '*';
	x[r - 2][z + 5] = '*';
	x[r - 2][z + 4] = '*';
	x[r - 2][z + 3] = '*';
	x[r - 1][z + 5] = '*';
	x[r - 1][z + 4] = '*';
	x[r - 1][z + 3] = '*';
	z += 11;

	x[r - 4][z + 8] = '*';
	x[r - 4][z + 7] = '*';
	x[r - 4][z + 6] = '*';
	x[r - 4][z + 5] = '*';
	x[r - 4][z + 4] = '*';
	x[r - 4][z + 3] = '*';
	x[r - 3][z + 8] = '*';
	x[r - 3][z + 7] = '*';
	x[r - 3][z + 6] = '*';
	x[r - 3][z + 5] = '*';
	x[r - 3][z + 4] = '*';
	x[r - 3][z + 3] = '*';
	x[r - 2][z + 8] = '*';
	x[r - 2][z + 7] = '*';
	x[r - 2][z + 6] = '*';
	x[r - 2][z + 5] = '*';
	x[r - 2][z + 4] = '*';
	x[r - 2][z + 3] = '*';
	x[r - 1][z + 8] = '*';
	x[r - 1][z + 7] = '*';
	x[r - 1][z + 6] = '*';
	x[r - 1][z + 5] = '*';
	x[r - 1][z + 4] = '*';
	x[r - 1][z + 3] = '*';

	x[r - 4][z + 10] = 219;
	x[r - 3][z + 10] = 219;
	x[r - 2][z + 10] = 219;
	x[r - 1][z + 10] = 219;
	for (i = z; i < z + 40; i++)
	{
		x[r - 5][i + 10] = 220;
	}
	for (int b = r - 1; b > r - 3; b--)
	{
		for (i = z; i < z + 39; i++)
		{
			x[b][i + 11] = 176;
		}
	}
	int b = r - 4;
	for (i = z; i < z + 39; i++)
	{
		x[b][i + 11] = 176;
	}
	for (i = z; i < z + 39; i++)
	{
		x[b + 1][i + 11] = 176;
	}
	for (i = z; i < z + 39; i++)
	{
		x[b + 2][i + 11] = 176;
	}
	for (i = z; i < z + 39; i++)
	{
		x[b + 3][i + 11] = 176;
	}
	z -= 3;
	r -= 6;
	for (int k = 0; k < 4; k++)
	{
		r = rplat - 4;
		for (i = 0; i < 4; i++)
		{
			x[r][z] = 176;
			r++;
		}
		z++;
	}

	//block lmeen 1st
	z = cplat + 120;
	r = rplat - 16;
	x[r][z - 1] = 220;
	x[r][z] = 220;
	x[r][z + 1] = 220;
	x[r][z + 2] = 220;
	x[r][z + 3] = 220;
	x[r][z + 4] = 220;
	x[r][z + 5] = 220;
	x[r][z + 6] = 220;
	x[r][z + 7] = 220;
	x[r][z + 8] = 220;
	x[r + 1][z - 1] = 179;
	x[r + 1][z + 8] = 179;
	x[r + 2][z - 1] = 192;
	x[r + 2][z] = 196;
	x[r + 2][z + 1] = 196;
	x[r + 2][z + 2] = 196;
	x[r + 2][z + 3] = 196;
	x[r + 2][z + 4] = 196;
	x[r + 2][z + 5] = 196;
	x[r + 2][z + 6] = 196;
	x[r + 2][z + 7] = 196;
	x[r + 2][z + 8] = 217;
	r = rplat - 15;
	z = cplat + 120;
	for (i = 0; i < 8; i++)
	{
		x[r][z] = 176;
		z++;
	}
	//selm
	r = rplat - 16;
	z = cplat + 122;
	int a = r, h = z;
	x[r][z] = 218;
	x[r][z + 1] = '-';
	x[r][z + 2] = '-';
	x[r][z + 3] = '-';
	x[r][z + 4] = '-';

	x[r][z + 5] = 191;
	for (i = 0; i < 10; i++)
	{
		x[r + 1][z] = 221;
		r++;
	}
	r = rplat - 15;
	for (i = 0; i < 10; i++)
	{
		z = cplat + 123;
		x[r][z] = '-';
		x[r][z + 1] = '-';
		x[r][z + 2] = '-';
		x[r][z + 3] = '-';
		r++;
	}

	x[a][h + 1] = '-';
	x[a][h + 1 + 1] = '-';
	x[a][h + 1 + 2] = '-';
	x[a][h + 1 + 3] = '-';

	r = rplat - 15;
	z = cplat + 127;
	for (i = 0; i < 10; i++)
	{
		x[r][z] = 222;
		r++;
	}
	//block al enemy;
	r = rplat - 22;
	z = cplat + 2;
	for (i = 0; i < 43; i++)
	{
		x[r][z] = 220;
		z++;
	}
	r = rplat - 21;
	z = cplat + 2;
	for (i = 0; i < 3; i++)
	{
		x[r][z] = 179;
		r++;
	}
	x[r][z] = 192;
	for (i = 0; i < 41; i++)
	{
		x[r][z + 1] = 196;
		z++;
	}
	x[r][z + 1] = 217;
	for (i = 0; i < 3; i++)
	{
		x[r - 1][z + 1] = 179;
		r--;
	}
	z = cplat + 3;
	r = rplat - 21;
	for (int k = 0; k < 41; k++)
	{
		r = rplat - 21;
		for (i = 0; i < 3; i++)
		{
			x[r][z] = 176;
			r++;
		}
		z++;
	}
	//shmal asanser
	z = cplat + 71;
	r = rplat - 16;

	for (int b = z - 1; b < z + 9; b++)
	{
		x[r][b] = 220;
	}
	for (int b = z; b < z + 8; b++)
	{
		x[r + 2][b] = 196;
	}
	for (i = z; i < z + 8; i++)
	{
		x[r + 1][i] = 176;
	}
	x[r + 1][z - 1] = 179;
	x[r + 1][z + 8] = 179;
	x[r + 2][z - 1] = 192;
	x[r + 2][z + 8] = 217;
	//block shmal shmal asanser

	//laser
	x[62][90 - 52] = 205;
	x[62][91 - 52] = 205;
	x[62][92 - 52] = 205;
	x[62][89 - 52] = 186;
	x[62][93 - 52] = 186;
	x[63][89 - 52] = 200;
	x[63][93 - 52] = 188;
	x[63][91 - 52] = 219;
}
void Drplat2(int rplat2, int cplat, char x[][130], int rand[130], int& flagdisapear)
{

	int i = 0, r = 0, c = 0, z = 0;
	i = rplat2 - 1;
	for (z = 1; z < 41; z++)
	{
		x[i][z] = 176;
	}
	z = cplat + 1;
	for (int i = 0; i < 69; i++)
	{
		x[rplat2 - 2][z] = 219;
		z++;
	}
	x[rplat2 - 2][z] = 219;
	x[rplat2 - 1][z] = 219;
	z = cplat + 41;
	for (i = 0; i < 29; i++)
	{
		x[rplat2 - 1][z] = 176;
		z++;
	}
	z = 1;
	for (i = 0; i < 70; i++)
	{
		x[rplat2][z] = 219;
		z++;
	}
	//plat fo2 alslem;

	if (flagdisapear == 0)
	{
		z = cplat + 60;
		r = rplat2 - 10;
		for (i = 0; i < 18; i++)
		{
			x[r][z] = 220;
			z++;
		}
		z = cplat + 60;
		x[r + 1][z] = 179;
		x[r + 2][z] = 192;
		for (i = 0; i < 17; i++)
		{
			x[r + 2][z + 1] = 196;
			z++;
		}
		x[r + 2][z] = 217;
		x[r + 1][z] = 179;
		z = cplat + 61;
		for (i = 0; i < 16; i++)
		{
			x[r + 1][z] = 176;
			z++;
		}

		//selm;
		r = rplat2 - 10;
		z = cplat + 63;
		x[r][z] = 218;
		x[r][z + 1] = '-';
		x[r][z + 2] = '-';
		x[r][z + 3] = '-';
		x[r][z + 4] = '-';
		x[r][z + 5] = 191;
		for (i = 0; i < 7; i++)
		{
			x[r + 1][z] = 221;
			r++;
		}
		r = rplat2 - 9;
		for (i = 0; i < 7; i++)
		{
			z = cplat + 64;
			x[r][z] = '-';
			x[r][z + 1] = '-';
			x[r][z + 2] = '-';
			x[r][z + 3] = '-';
			//x[r][z + 4] = '-';
			r++;
		}
		r = rplat2 - 9;
		z = cplat + 68;
		for (i = 0; i < 7; i++)
		{
			x[r][z] = 222;
			r++;
		}
	}
	//block lmeen alslem;
	z = cplat + 83;
	r = rplat2 - 9;
	for (i = 0; i < 10; i++)
	{
		x[r][z] = 220;
		z++;
	}
	z = cplat + 83;
	x[r + 1][z] = 179;
	x[r + 2][z] = 192;
	for (i = 0; i < 9; i++)
	{
		x[r + 2][z + 1] = 196;
		z++;
	}
	x[r + 2][z] = 217;
	x[r + 1][z] = 179;
	z = cplat + 84;
	for (i = 0; i < 8; i++)
	{
		x[r + 1][z] = 176;
		z++;
	}
	//block aly tht
	z = cplat + 95;
	r = rplat2 - 6;
	for (i = 0; i < 24; i++)
	{
		x[r][z] = 220;
		z++;
	}
	z = cplat + 95;
	x[r + 1][z] = 179;
	x[r + 2][z] = 192;
	for (i = 0; i < 23; i++)
	{
		x[r + 2][z + 1] = 196;
		z++;
	}
	x[r + 2][z] = 217;
	x[r + 1][z] = 179;
	z = cplat + 96;
	for (i = 0; i < 22; i++)
	{
		x[r + 1][z] = 176;
		z++;
	}
	//dor4
	r = rplat2 - 22, z = cplat + 1;
	for (int i = 0; i < 127; i++)
	{
		x[r][z] = 219;
		for (int j = 0; j < 127; j++)
		{
			x[r][rand[j]] = ' ';
		}
		z++;
	}
}
void Dr7bl(int r7bl, int c7bl, char x[][130], int flag7bl)
{
	if (flag7bl == 1)
	{
		x[r7bl - 2][c7bl] = 191;
		for (int r = r7bl - 1; r < 56; r++)
		{
			x[r][c7bl] = 179;
		}
		for (c7bl--; c7bl > 113; c7bl--)
		{
			x[r7bl - 2][c7bl] = 196;
		}
	}
}
void Enemy1(int re, int ce, char x[][130], int flagmoveenemy, int flagalive)
{
	if (flagalive == 0)
	{
		if (flagmoveenemy == 1)
		{
			x[re][ce] = '_';
			x[re + 1][ce] = '_';
			x[re + 2][ce] = ':';
			x[re + 3][ce] = 92;
			x[re + 4][ce] = '`';
			x[re + 4][ce + 1] = '-';
			x[re + 4][ce + 2] = '`';
			x[re + 5][ce + 2] = '"';
			x[re + 5][ce + 3] = '.';
			x[re + 5][ce - 2] = '.';
			x[re + 6][ce - 2] = '`';
			x[re + 7][ce - 2] = 92;
			x[re + 8][ce - 1] = 92;
			x[re + 9][ce - 1] = '`';
			x[re + 9][ce] = '-';
			x[re + 9][ce + 1] = '`';
			x[re + 8][ce - 3] = 47;
			x[re + 9][ce - 3] = '`';
			x[re + 9][ce - 4] = 92;
			x[re + 3][ce + 1] = '-';
			x[re + 3][ce + 2] = '.';
			x[re + 3][ce + 3] = '_';
			x[re + 4][ce + 3] = '`';
			x[re + 4][ce + 4] = '"';
			x[re + 2][ce - 1] = '_';
			x[re + 3][ce - 1] = '(';
			x[re + 3][ce - 2] = '/';
			x[re + 4][ce - 2] = 92;
			x[re + 4][ce - 1] = '_';
			x[re + 2][ce + 1] = ' ';
			x[re + 2][ce + 2] = '"';
			x[re][ce + 1] = '_';
			x[re + 1][ce - 1] = '(';
			x[re + 1][ce + 1] = 'o';
			x[re + 1][ce + 2] = '`';
		}
		if (flagmoveenemy == 2)
		{
			x[re][ce] = '_';
			x[re][ce - 1] = '_';
			x[re + 1][ce + 1] = ')';
			x[re + 1][ce] = '_';
			x[re + 1][ce - 1] = 'o';
			x[re + 1][ce - 2] = 39;
			x[re + 2][ce + 1] = '_';
			x[re + 2][ce] = ':';
			x[re + 2][ce - 2] = '"';
			x[re + 3][ce + 1] = ')';
			x[re + 3][ce + 2] = 92;
			x[re + 3][ce] = '/';
			x[re + 3][ce - 1] = '-';
			x[re + 3][ce - 2] = '.';
			x[re + 3][ce - 3] = '_';
			x[re + 4][ce + 1] = '_';
			x[re + 4][ce + 2] = '/';
			x[re + 4][ce - 3] = 39;
			x[re + 4][ce - 4] = '"';
			x[re + 4][ce] = 39;
			x[re + 4][ce - 1] = '-';
			x[re + 4][ce - 2] = 39;
			x[re + 5][ce - 2] = '"';
			x[re + 5][ce - 3] = '.';
			x[re + 5][ce + 2] = '.';
			x[re + 6][ce + 2] = 39;
			x[re + 7][ce + 2] = '/';
			x[re + 8][ce + 1] = '/';
			x[re + 8][ce + 3] = 92;
			x[re + 9][ce + 4] = '/';
			x[re + 9][ce + 3] = 39;
			x[re + 9][ce + 1] = 39;
			x[re + 9][ce] = '-';
			x[re + 9][ce - 1] = 39;
		}
	}
}
void Enemy2(int renemy2, int  cenemy2, int flagenemy2, char x[][130], int flagalive2, int flagdead1, int flagdead2)
{
	if (flagalive2 == 0)
	{
		if (flagenemy2 == 2)
		{
			x[renemy2 - 2][cenemy2 - 1] = ' ';
			x[renemy2 - 2][cenemy2] = ' ';
			x[renemy2 - 2][cenemy2 + 1] = ' ',
				x[renemy2 - 2][cenemy2 + 2] = ' ';
			x[renemy2 - 1][cenemy2 - 2] = '(';
			x[renemy2 - 1][cenemy2 - 1] = 'o';
			x[renemy2 - 1][cenemy2 + 1] = 'O';
			x[renemy2 - 1][cenemy2 + 3] = ')';
			x[renemy2][cenemy2] = '0';
			x[renemy2][cenemy2 - 3] = '/';
			x[renemy2][cenemy2 + 4] = '\\';
			x[renemy2 + 1][cenemy2 - 4] = '/';
			x[renemy2 + 1][cenemy2 - 3] = '/';
			x[renemy2 + 1][cenemy2 - 2] = '|';
			x[renemy2 + 1][cenemy2 + 3] = '|';
			x[renemy2 + 1][cenemy2 + 4] = '\\';
			x[renemy2 + 1][cenemy2 + 5] = '\\';
			x[renemy2 + 2][cenemy2 - 5] = '(';
			x[renemy2 + 2][cenemy2 - 4] = '"';
			x[renemy2 + 2][cenemy2 - 3] = ')';
			x[renemy2 + 2][cenemy2 - 1] = '|';
			x[renemy2 + 2][cenemy2 + 2] = '|';
			x[renemy2 + 2][cenemy2 + 4] = '(';
			x[renemy2 + 2][cenemy2 + 5] = '"';
			x[renemy2 + 2][cenemy2 + 6] = ')';
			x[renemy2 + 3][cenemy2 - 2] = '/';
			x[renemy2 + 3][cenemy2 + 3] = '\\';
		}
		if (flagenemy2 == 0 || flagenemy2 == 1)
		{
			x[renemy2 - 2][cenemy2 - 1] = '_';
			x[renemy2 - 2][cenemy2] = '_';
			x[renemy2 - 2][cenemy2 + 1] = '_';
			x[renemy2 - 2][cenemy2 + 2] = '_';
			x[renemy2 - 2][cenemy2 - 4] = '(';
			x[renemy2 - 2][cenemy2 - 2] = ')';
			x[renemy2 - 2][cenemy2 + 3] = '(';
			x[renemy2 - 2][cenemy2 + 5] = ')';
			x[renemy2 - 1][cenemy2 - 2] = '(';
			x[renemy2 - 1][cenemy2 - 1] = 'O';
			x[renemy2 - 1][cenemy2 + 1] = 'o';
			x[renemy2 - 1][cenemy2 + 3] = ')';
			x[renemy2 - 1][cenemy2 - 4] = '/';
			x[renemy2 - 1][cenemy2 - 3] = '/';
			x[renemy2 - 1][cenemy2 + 4] = '\\';
			x[renemy2 - 1][cenemy2 + 5] = '\\';
			x[renemy2][cenemy2] = '0';
			x[renemy2][cenemy2 - 3] = '\\';
			x[renemy2][cenemy2 - 2] = '\\';
			x[renemy2][cenemy2 + 4] = '/';
			x[renemy2][cenemy2 + 5] = '/';
			x[renemy2 + 1][cenemy2 - 2] = '|';
			x[renemy2 + 1][cenemy2 + 3] = '|';
			x[renemy2 + 2][cenemy2 - 1] = '|';
			x[renemy2 + 2][cenemy2 + 2] = '|';
			x[renemy2 + 3][cenemy2 - 2] = '/';
			x[renemy2 + 3][cenemy2 + 3] = '\\';
		}
	}
	if (flagdead1 == 1)
	{
		renemy2 += 2;
		x[renemy2 - 2][cenemy2] = 196;
		x[renemy2 - 2][cenemy2 - 1] = 196;
		x[renemy2 - 2][cenemy2 + 1] = 196;
		x[renemy2 - 1][cenemy2] = ' ';
		x[renemy2 - 1][cenemy2 - 1] = '0';
		x[renemy2 - 1][cenemy2 + 1] = 'o';
		x[renemy2 - 1][cenemy2 + 2] = ')';
		x[renemy2 - 1][cenemy2 - 2] = '(';
		x[renemy2][cenemy2] = 'o';
		x[renemy2][cenemy2 - 1] = ' ';
		x[renemy2][cenemy2 + 1] = ' ';
		x[renemy2][cenemy2 + 2] = '\\';
		x[renemy2][cenemy2 - 2] = '/';
		x[renemy2 + 1][cenemy2] = '~';
		x[renemy2 + 1][cenemy2 - 1] = '~';
		x[renemy2 + 1][cenemy2 + 1] = '~';
		x[renemy2 + 1][cenemy2 + 2] = '~';
		x[renemy2 + 1][cenemy2 - 2] = '~';
		x[renemy2 + 1][cenemy2 - 3] = '/';
		x[renemy2 + 1][cenemy2 + 3] = '\\';
		renemy2 -= 2;
	}
	if (flagdead2 == 1)
	{
		cenemy2 += 8;
		renemy2 += 2;
		x[renemy2 - 2][cenemy2] = 196;
		x[renemy2 - 2][cenemy2 - 1] = 196;
		x[renemy2 - 2][cenemy2 + 1] = 196;
		x[renemy2 - 1][cenemy2] = ' ';
		x[renemy2 - 1][cenemy2 - 1] = '0';
		x[renemy2 - 1][cenemy2 + 1] = 'o';
		x[renemy2 - 1][cenemy2 + 2] = ')';
		x[renemy2 - 1][cenemy2 - 2] = '(';
		x[renemy2][cenemy2] = 'o';
		x[renemy2][cenemy2 - 1] = ' ';
		x[renemy2][cenemy2 + 1] = ' ';
		x[renemy2][cenemy2 + 2] = '\\';
		x[renemy2][cenemy2 - 2] = '/';
		x[renemy2 + 1][cenemy2] = '~';
		x[renemy2 + 1][cenemy2 - 1] = '~';
		x[renemy2 + 1][cenemy2 + 1] = '~';
		x[renemy2 + 1][cenemy2 + 2] = '~';
		x[renemy2 + 1][cenemy2 - 2] = '~';
		x[renemy2 + 1][cenemy2 - 3] = '/';
		x[renemy2 + 1][cenemy2 + 3] = '\\';
		cenemy2 -= 8;
	}
}
void Enemy3(int re3, int ce3, char x[][130], int flagalive3)
{
	if (flagalive3 == 0)
	{
		x[re3][ce3] = '_';
		x[re3][ce3 + 1] = '/';
		x[re3][ce3 + 2] = ')';
		x[re3 + 1][ce3 + 2] = ')';
		x[re3 + 2][ce3 + 2] = 92;
		x[re3 + 2][ce3 + 3] = '=';
		x[re3 + 3][ce3 + 5] = '_';
		x[re3 + 3][ce3 + 6] = '_';
		x[re3 + 3][ce3 + 7] = '/';
		x[re3 + 2][ce3 + 7] = 92;
		x[re3 + 3][ce3 + 8] = '`';
		x[re3 + 2][ce3 + 9] = '_';
		x[re3 + 2][ce3 + 10] = '/';
		x[re3 + 1][ce3 + 11] = '|';
		x[re3][ce3 + 11] = 92;
		x[re3 - 1][ce3 + 10] = 92;
		x[re3 - 1][ce3 + 9] = '/';
		x[re3][ce3 + 9] = '/';
		x[re3 + 1][ce3 + 9] = 39;
		x[re3 + 1][ce3 + 8] = 39;
		x[re3][ce3 + 8] = 39;
		x[re3][ce3 + 7] = '.';
		x[re3][ce3 + 6] = '_';
		x[re3 + 1][ce3 + 10] = '.';
		x[re3 + 1][ce3 + 6] = '_';
		x[re3 + 2][ce3 + 5] = '`';
		x[re3 + 2][ce3 + 4] = '.';
		x[re3 + 1][ce3 + 4] = ',';
		x[re3 + 3][ce3 + 2] = '/';
		x[re3 + 4][ce3 + 2] = ')';
		x[re3 + 4][ce3 + 3] = '/';
		x[re3 + 3][ce3 + 4] = '|';
		x[re3 + 3][ce3 - 4] = '|';
		x[re3 + 4][ce3 - 3] = 92;
		x[re3 + 5][ce3 + 2] = '"';
		x[re3 + 5][ce3 - 2] = '"';
		x[re3 + 4][ce3 + 1] = '_';
		x[re3 + 4][ce3] = '|';//
		x[re3 + 4][ce3 - 1] = '_';
		x[re3 + 3][ce3 + 1] = '_';
		x[re3 + 3][ce3 - 1] = '_';
		x[re3 + 3][ce3 - 2] = 92;
		x[re3 + 4][ce3 - 2] = '(';
		x[re3 + 2][ce3 - 2] = '/';
		x[re3 + 3][ce3] = '_';
		x[re3 + 1][ce3 + 3] = '-';
		x[re3 + 1][ce3 + 4] = '-';
		x[re3 + 1][ce3 + 5] = 39;
		x[re3][ce3 - 1] = 92;
		x[re3][ce3 - 2] = '(';
		x[re3 + 1][ce3 - 3] = '-';
		x[re3 + 1][ce3 - 4] = '-';
		x[re3 + 1][ce3 - 5] = 39;
		x[re3 + 1][ce3 - 2] = '(';
		x[re3 + 1][ce3 - 1] = 'O';
		x[re3 + 2][ce3 - 3] = '=';
		x[re3 + 2][ce3 - 4] = '.';
		x[re3 + 2][ce3 - 5] = '`';
		x[re3 + 1][ce3 - 6] = '_';
		x[re3][ce3 - 6] = '_';
		x[re3][ce3 - 7] = '.';
		x[re3][ce3 - 8] = 39;
		x[re3 + 1][ce3 - 8] = 39;
		x[re3 + 1][ce3 - 9] = 39;
		x[re3][ce3 - 9] = 92;
		x[re3 - 1][ce3 - 9] = 92;
		x[re3 - 1][ce3 - 10] = '/';
		x[re3][ce3 - 11] = '/';
		x[re3 + 1][ce3 - 11] = '|';
		x[re3 + 1][ce3 - 10] = '.';
		x[re3 + 2][ce3 - 10] = 92;
		x[re3 + 2][ce3 - 9] = '_';
		x[re3 + 2][ce3 - 8] = '`';
		x[re3 + 3][ce3 - 7] = '/';
		x[re3 + 3][ce3 - 6] = '_';
		x[re3 + 3][ce3 - 5] = '_';
		x[re3 + 3][ce3 - 7] = 92;
		x[re3 + 1][ce3 - 7] = '.';
		x[re3 + 1][ce3 + 1] = 'O';
		x[re3 + 1][ce3] = '.';
		x[re3 + 2][ce3] = '"';


		x[re3 + 5][ce3 + 1] = 191;
		x[re3 + 5][ce3] = 196;
		x[re3 + 5][ce3 - 1] = 218;
		x[re3 + 6][ce3] = 196;
		x[re3 + 6][ce3 + 1] = 217;
		x[re3 + 6][ce3 - 1] = 192;
	}
}
void Enemy4(int re, int ce, int flagalive4, char x[][130])
{
	if (flagalive4 == 0)
	{
		x[re][ce + 2] = '<';
		x[re][ce + 3] = '=';
		x[re][ce + 4] = '=';
		x[re][ce + 5] = '=';
		x[re][ce + 6] = '=';
		x[re][ce + 7] = '=';
		x[re][ce + 8] = '=';
		x[re][ce + 9] = '=';
		x[re][ce + 10] = ']';
		x[re][ce + 11] = '}';
		x[re][ce + 12] = '=';
		x[re][ce + 13] = '=';
		x[re][ce + 14] = '=';
		x[re][ce + 15] = '=';
		x[re][ce + 16] = '=';
		x[re][ce + 17] = '=';
		x[re + 1][ce + 4] = '-';
		x[re + 1][ce + 5] = '-';
		x[re + 1][ce + 6] = '.';
		x[re + 1][ce + 10] = '/';
		x[re + 1][ce + 11] = '|';
		x[re + 2][ce + 3] = '_';
		x[re + 2][ce + 4] = '\\';
		x[re + 2][ce + 5] = '"';
		x[re + 2][ce + 6] = '/';
		x[re + 2][ce + 7] = '_';
		x[re + 2][ce + 8] = '.';
		x[re + 2][ce + 9] = '\'';
		x[re + 2][ce + 10] = '/';
		x[re + 3][ce + 1] = '.';
		x[re + 3][ce + 2] = '\'';
		x[re + 3][ce + 3] = '.';
		x[re + 3][ce + 4] = '_';
		x[re + 3][ce + 5] = '.';
		x[re + 3][ce + 6] = '_';
		x[re + 3][ce + 7] = ',';
		x[re + 3][ce + 8] = '.';
		x[re + 3][ce + 9] = '\'';
		x[re + 4][ce + 1] = ':';
		x[re + 4][ce + 2] = '/';
		x[re + 4][ce + 4] = '\\';
		x[re + 4][ce + 5] = '{';
		x[re + 4][ce + 6] = '}';
		x[re + 4][ce + 7] = '/';
		x[re + 5][ce + 0] = '(';
		x[re + 5][ce + 1] = 'L';
		x[re + 5][ce + 4] = '/';
		x[re + 5][ce + 5] = '-';
		x[re + 5][ce + 6] = '-';
		x[re + 5][ce + 7] = '\'';
		x[re + 5][ce + 8] = ',';
		x[re + 5][ce + 9] = '-';
		x[re + 5][ce + 10] = '-';
		x[re + 5][ce + 11] = '-';
		x[re + 5][ce + 12] = '-';
		x[re + 5][ce + 13] = '.';
		x[re + 5][ce + 14] = '_';
		x[re + 6][ce + 4] = '|';
		x[re + 6][ce + 15] = '\\';
		x[re + 6][ce + 16] = '\\';
		x[re + 7][ce + 3] = ':';
		x[re + 7][ce + 5] = '/';
		x[re + 7][ce + 6] = '-';
		x[re + 7][ce + 7] = '\\';
		x[re + 7][ce + 9] = '.';
		x[re + 7][ce + 10] = '\'';
		x[re + 7][ce + 11] = '-';
		x[re + 7][ce + 12] = '\'';
		x[re + 7][ce + 13] = '\\';
		x[re + 7][ce + 15] = '/';
		x[re + 7][ce + 17] = '|';
		x[re + 8][ce + 4] = '\\';
		x[re + 8][ce + 5] = '\\';
		x[re + 8][ce + 6] = ',';
		x[re + 8][ce + 8] = '|';
		x[re + 8][ce + 9] = '|';
		x[re + 8][ce + 14] = '\\';
		x[re + 8][ce + 15] = '|';
		x[re + 9][ce + 5] = '\\';
		x[re + 9][ce + 6] = '/';
		x[re + 9][ce + 8] = '|';
		x[re + 9][ce + 9] = '|';
		x[re + 9][ce + 14] = '|';
		x[re + 9][ce + 15] = '|';
	}
}
void MvEnemy4(int re, int& ce, int flagalive4, char x[][130], int& flagdir4, int flagmove4)
{
	if (flagalive4 == 0)
	{
		if (flagmove4 == 1)
		{
			if (flagdir4 == 1)
			{
				ce -= 4;
			}
		}
	}
}
void DrArrow(int rhero, int chero, int& ebr1, int& ebc1, int& ebr2, int& ebc2, int& ebr3, int& ebc3, char x[][130], int& flagmoveenemy, int flagalive, int& FlEnBU1, int& FlEnBU2, int& FlEnBU3, int& ctEB, int& d1, int& d2, int& d3)
{
	if (flagalive == 0)
	{
		ctEB++;
		if (FlEnBU1 == 0)
		{
			x[ebr1][ebc1] = '3';
			x[ebr1][ebc1 + 1] = '-';
			x[ebr1][ebc1 + 2] = '>';
		}
		if (FlEnBU2 == 0)
		{
			x[ebr2][ebc2] = '3';
			x[ebr2][ebc2 + 1] = '-';
			x[ebr2][ebc2 + 2] = '>';
		}
		if (FlEnBU3 == 0)
		{
			x[ebr3][ebc3] = '3';
			x[ebr3][ebc3 + 1] = '-';
			x[ebr3][ebc3 + 2] = '>';
		}
	}
}
void EnArrow(int rhero, int chero, int& ebr1, int& ebc1, int& ebr2, int& ebc2, int& ebr3, int& ebc3, char x[][130], int& flagmoveenemy, int flagalive, int& FlEnBU1, int& FlEnBU2, int& FlEnBU3, int& ctEB, int& d1, int& d2, int& d3)
{
	if (flagalive == 0)
	{
		ctEB++;
		if (FlEnBU1 == 0)
		{
			if (x[ebr1][ebc1 + 4] == ' ')
			{
				ebc1 += 2;
			}
			if (x[ebr1][ebc1 + 4] != ' ' || (chero == ebc1 + 4 && rhero < 57 && rhero > 47) || (chero == ebc1 + 3 && rhero < 57 && rhero > 47) || (chero == ebc1 + 5 && rhero < 57 && rhero > 47))
			{
				FlEnBU1 = 1;
			}
		}
		if (FlEnBU2 == 0 && ctEB > 3)
		{
			if (x[ebr2][ebc2 + 4] == ' ')
			{
				ebc2 += 2;
			}
			if (x[ebr2][ebc2 + 4] != ' ' || (chero == ebc2 + 4 && rhero < 57 && rhero > 47) || (chero == ebc1 + 3 && rhero < 57 && rhero > 47) || (chero == ebc1 + 5 && rhero < 57 && rhero > 47))
			{
				FlEnBU2 = 1;
			}
		}
		if (FlEnBU3 == 0 && ctEB > 6)
		{
			if (x[ebr3][ebc3 + 4] == ' ')
			{
				ebc3 += 2;
			}
			if (x[ebr3][ebc3 + 4] != ' ' || (chero == ebc3 + 4 && rhero < 57 && rhero > 47) || (chero == ebc1 + 3 && rhero < 57 && rhero > 47) || (chero == ebc1 + 5 && rhero < 57 && rhero > 47))
			{
				FlEnBU3 = 1;
				ctEB = 0;
			}
		}
	}
}
void EnBooms(int& En3BoCo1, int& En3BoRo1, int& FlEn3BO1, char x[][130], int flagalive3)
{
	if (flagalive3 == 0)
	{
		if (x[En3BoRo1 + 1][En3BoCo1] == ' ')
		{
			x[En3BoRo1 - 1][En3BoCo1 + 1] = 191;
			x[En3BoRo1 - 1][En3BoCo1] = 196;
			x[En3BoRo1 - 1][En3BoCo1 - 1] = 218;
			x[En3BoRo1][En3BoCo1] = 196;
			x[En3BoRo1][En3BoCo1 + 1] = 217;
			x[En3BoRo1][En3BoCo1 - 1] = 192;
			En3BoRo1++;
		}
		if (x[En3BoRo1 + 1][En3BoCo1] != ' ')
		{
			FlEn3BO1 = 1;
		}
	}
}
void Grv(int& ch, int& rh, char x[][130], int& flag, int& sr, int& er, int& ctloop, int& sc, int& rc)
{
	if (flag == 1)
	{
		if (x[rh + 1][ch] == ' ' && x[rh + 1][ch + 2] == ' ')
		{
			rh++;
			if (sr > 0 && er < 80)
			{
				sr++;
				er++;
			}
		}
		if (x[rh + 1][ch] != ' ')
		{
			ctloop = 0;
		}

	}
	if (flag == 5)
	{
		if (x[rh + 1][ch + 1] == ' ' && x[rh + 1][ch + 3] == ' ')
		{
			rh++;
			ch++;
			if (sr > 5 && er < 80)
			{
				sr++;
				er++;
			}
		}
		if (x[rh + 1][ch] != ' ')
		{
			ctloop = 0;
		}
	}
	if (flag == 6)
	{
		if (x[rh + 1][ch - 1] == ' ' && x[rh + 1][ch + 1] == ' ')
		{
			rh++;
			ch--;
			if (sr > 5 && er < 80)
			{
				sr++;
				er++;
			}
		}
		if (x[rh + 1][ch] != ' ')
		{
			ctloop = 0;
		}
	}
}
void Hero(int ch, int rh, char x[][130], int flagmove, int& HeDir)
{
	if (flagmove == 1)
	{
		HeDir = 1;
		x[rh][ch] = '/';
		x[rh][ch + 2] = 92;
		x[rh - 1][ch] = '(';
		x[rh - 1][ch + 1] = '=';
		x[rh - 1][ch + 2] = '=';
		x[rh - 1][ch + 3] = '}';
		x[rh - 1][ch + 4] = 240;
		x[rh - 1][ch + 5] = 240;
		x[rh - 2][ch + 1] = '.';
		x[rh - 2][ch + 3] = 39;
		x[rh - 2][ch - 1] = 96;
		x[rh - 3][ch - 1] = '(';
		x[rh - 3][ch + 3] = ')';
		x[rh - 3][ch + 1] = 39;
		x[rh - 3][ch + 2] = 39;
		x[rh - 4][ch - 1] = '_';
		x[rh - 4][ch] = '|';
		x[rh - 4][ch + 1] = '_';
		x[rh - 4][ch + 2] = '|';
		x[rh - 4][ch + 3] = '_';
		x[rh - 5][ch + 1] = '_';
	}
	if (flagmove == 3 && HeDir == 1)
	{
		x[rh][ch] = '/';
		x[rh][ch + 2] = 92;
		x[rh - 1][ch] = '(';
		x[rh - 1][ch + 1] = '=';
		x[rh - 1][ch + 2] = ')';
		x[rh - 2][ch + 4] = '/';
		x[rh - 1][ch + 4] = 196;
		x[rh - 1][ch + 5] = 179;
		x[rh][ch + 5] = 179;
		x[rh - 3][ch + 5] = 179;
		x[rh - 4][ch + 5] = 179;
		x[rh][ch + 6] = '/';
		x[rh - 1][ch + 6] = 179;
		x[rh - 2][ch + 6] = 179;
		x[rh - 3][ch + 6] = 179;
		x[rh - 4][ch + 6] = 92;
		x[rh - 2][ch + 5] = 179;
		x[rh - 1][ch + 5] = 179;
		x[rh - 2][ch + 1] = '.';
		x[rh - 2][ch + 3] = 39;
		x[rh - 2][ch - 1] = 96;
		x[rh - 3][ch - 1] = '(';
		x[rh - 3][ch + 3] = ')';
		x[rh - 3][ch + 1] = 39;
		x[rh - 3][ch + 2] = 39;
		x[rh - 4][ch - 1] = '_';
		x[rh - 4][ch] = '|';
		x[rh - 4][ch + 1] = '_';
		x[rh - 4][ch + 2] = '|';
		x[rh - 4][ch + 3] = '_';
		x[rh - 5][ch + 1] = '_';
	}
	if (flagmove == 2)
	{
		HeDir = -1;
		x[rh][ch] = '/';
		x[rh][ch + 2] = 92;
		x[rh - 1][ch - 1] = '{';
		x[rh - 1][ch - 2] = 240;
		x[rh - 1][ch - 3] = 240;
		x[rh - 1][ch] = '=';
		x[rh - 1][ch + 1] = '=';
		x[rh - 1][ch + 2] = ')';
		x[rh - 2][ch + 1] = '.';
		x[rh - 2][ch + 3] = 39;
		x[rh - 2][ch - 1] = 96;
		x[rh - 3][ch - 1] = '(';
		x[rh - 3][ch + 3] = ')';
		x[rh - 3][ch + 1] = 39;
		x[rh - 3][ch] = 39;
		x[rh - 4][ch - 1] = '_';
		x[rh - 4][ch] = '|';
		x[rh - 4][ch + 1] = '_';
		x[rh - 4][ch + 2] = '|';
		x[rh - 4][ch + 3] = '_';
		x[rh - 5][ch + 1] = '_';
	}
	if (flagmove == 3 && HeDir == -1)
	{
		x[rh][ch] = '/';
		x[rh][ch + 2] = 92;
		x[rh - 1][ch] = '(';
		x[rh - 1][ch - 2] = 196;
		x[rh - 2][ch - 3] = 179;
		x[rh - 3][ch - 3] = 179;
		x[rh - 1][ch - 3] = 179;
		x[rh - 2][ch - 4] = 179;
		x[rh][ch - 4] = 92;
		x[rh - 3][ch - 4] = 179;
		x[rh - 1][ch - 4] = 179;
		x[rh][ch - 3] = 179;
		x[rh - 4][ch - 4] = '/';
		x[rh - 4][ch - 3] = 179;
		x[rh - 2][ch - 2] = 92;
		x[rh - 1][ch + 1] = '=';
		x[rh - 1][ch + 2] = ')';
		x[rh - 2][ch + 1] = '.';
		x[rh - 2][ch + 3] = 39;
		x[rh - 2][ch - 1] = 96;
		x[rh - 3][ch - 1] = '(';
		x[rh - 3][ch + 3] = ')';
		x[rh - 3][ch + 1] = 39;
		x[rh - 3][ch] = 39;
		x[rh - 4][ch - 1] = '_';
		x[rh - 4][ch] = '|';
		x[rh - 4][ch + 1] = '_';
		x[rh - 4][ch + 2] = '|';
		x[rh - 4][ch + 3] = '_';
		x[rh - 5][ch + 1] = '_';
	}
	if (flagmove == 4)
	{

		x[rh][ch] = '/';
		x[rh][ch + 2] = 92;
		x[rh - 1][ch] = '/';
		x[rh - 1][ch + 1] = '=';
		x[rh - 1][ch + 2] = 92;
		x[rh - 2][ch + 1] = '.';
		x[rh - 2][ch + 3] = 39;
		x[rh - 2][ch - 1] = 96;
		x[rh - 3][ch - 1] = '(';
		x[rh - 3][ch + 3] = ')';
		x[rh - 3][ch + 1] = 39;
		x[rh - 3][ch] = 39;
		x[rh - 4][ch - 1] = '_';
		x[rh - 4][ch] = '|';
		x[rh - 4][ch + 1] = '_';
		x[rh - 4][ch + 2] = '|';
		x[rh - 4][ch + 3] = '_';
		x[rh - 5][ch + 1] = '_';
	}
}
void Intro(char x[][130])
{
	int r = 0, c = 0, i = 0;
	//d
	for (r = 3; r < 13; r++)
	{
		for (c = 4; c < 6; c++)
		{
			x[r][c] = 219;
		}
	}
	r = 3;
	for (c = 6; c < 14; c++)
	{
		x[r][c] = 219;
	}
	c--;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	r = 12;
	for (c = 6; c < 14; c++)
	{
		x[r][c] = 219;
	}
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	//e
	for (r = 3; r < 13; r++)
	{
		for (c = 18; c < 20; c++)
		{
			x[r][c] = 219;
		}
	}
	r = 3;
	for (c = 20; c < 27; c++)
	{
		x[r][c] = 219;
	}
	r = 7;
	for (c = 20; c < 25; c++)
	{
		x[r][c] = 219;
	}
	r = 12;
	for (c = 19; c < 27; c++)
	{
		x[r][c] = 219;
	}
	//a
	for (r = 4; r < 13; r++)
	{
		for (c = 30; c < 32; c++)
		{
			x[r][c] = 219;

		}
	}
	x[3][31] = 219;
	r = 3;
	for (c = 32; c < 40; c++)
	{
		x[r][c] = 219;

	}
	c--;
	for (r = 4; r < 13; r++)
	{
		x[r][c] = 219;
	}
	c++;
	for (r = 4; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 8;
	for (c = 32; c < 40; c++)
	{
		x[r][c] = 219;
	}
	//t
	r = 3;
	for (c = 43; c < 55; c++)
	{
		x[r][c] = 219;
	}
	c = 49;
	for (r = 4; r < 13; r++)
	{
		for (c = 48; c < 50; c++)
		{
			x[r][c] = 219;

		}
	}
	//h
	for (r = 3; r < 13; r++)
	{
		for (c = 57; c < 59; c++)
		{
			x[r][c] = 219;

		}
	}
	r = 7;
	for (c = 59; c < 66; c++)
	{
		x[r][c] = 219;

	}
	for (r = 3; r < 13; r++)
	{
		for (c = 66; c < 68; c++)
		{
			x[r][c] = 219;

		}
	}
	//b
	for (r = 3; r < 13; r++)
	{
		for (c = 76; c < 78; c++)
		{
			x[r][c] = 219;

		}
	}
	r = 3;
	for (c = 78; c < 86; c++)
	{
		x[r][c] = 219;

	}
	c--;
	for (r = 4; r < 13; r++)
	{
		x[r][c] = 219;

	}
	r--;
	for (c = 78; c < 86; c++)
	{
		x[r][c] = 219;

	}
	r = 7;
	for (c = 78; c < 85; c++)
	{
		x[r][c] = 220;

	}
	r = 8;
	for (c = 78; c < 85; c++)
	{
		x[r][c] = 223;

	}
	//o;
	c = 87;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	c = 88;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 3;
	for (c = 88; c < 97; c++)
	{
		x[r][c] = 219;

	}
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r--;
	for (c = 88; c < 97; c++)
	{
		x[r][c] = 219;

	}
	c = 98;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	//y;
	i = 99;
	r = 3;
	x[r][i] = 219;
	x[r][i + 1] = 219;
	x[r + 1][i + 1] = 219;
	x[r + 1][i + 2] = 219;
	x[r + 2][i + 2] = 219;
	x[r + 2][i + 3] = 219;
	x[r + 3][i + 3] = 219;
	x[r + 3][i + 4] = 219;
	x[r + 3][i + 5] = 219;
	x[r + 3][i + 6] = 219;
	x[r + 3][i + 7] = 219;
	x[r + 3][i + 8] = 219;

	for (r = 7; r < 13; r++)
	{
		x[r][i + 6] = 219;
	}
	for (r = 7; r < 13; r++)
	{
		x[r][i + 7] = 219;
	}
	r = 3;
	x[r][i + 12] = 219;
	x[r][i + 11] = 219;
	x[r + 1][i + 11] = 219;
	x[r + 1][i + 10] = 219;
	x[r + 2][i + 10] = 219;
	x[r + 2][i + 9] = 219;
	x[r + 3][i + 9] = 219;
}
void Jump(int& ch, int& rh, char x[][130], int& flag, int& ct, int& sr, int& er, int& flagtouch, int ctloop, int& sc, int& rc)
{
	if (flag == 2)
	{
		ct++;
		if (ct == 6)
		{
			flag = 1;
			ct = 0;
		}
		if (ctloop < 4)
		{
			if (x[rh - 6][ch + 1] == ' ' || x[rh - 6][ch + 1] == '-')
			{
				if (x[rh - 5][ch + 2] == ' ' && x[rh - 5][ch] == ' ' && x[rh - 5][ch + 3] == ' ' && x[rh - 5][ch - 1] == ' ' || x[rh - 5][ch + 2] == '-' || x[rh - 5][ch] == '-' || x[rh - 2][ch + 4] == '-' && x[rh - 5][ch + 3] == '-' && x[rh - 5][ch - 1] == '-')
				{
					rh--;
					if (sr >= 1 && er <= 80)
					{
						sr--;
						er--;
					}
				}
			}
		}
		else
		{
			flag = 1;
			ct = 0;
		}
	}

	if (flag == 3)
	{
		ct++;
		if (ct == 6)
		{
			flag = 5;
			ct = 0;
		}
		if (ctloop < 4)
		{
			if (x[rh - 6][ch + 1] == ' ' && x[rh - 5][ch + 3] == ' ' && x[rh - 5][ch + 4] == ' ' && x[rh - 4][ch + 4] == ' ')
			{
				rh--;
				ch++;
				if (sr > 5 && er < 80)
				{
					sr--;
					er--;
				}
			}
		}
		else
		{
			flag = 5;
			ct = 0;
		}
	}
	if (flag == 4)
	{
		ct++;
		if (ct == 6)
		{
			flag = 6;
			ct = 0;
		}
		if (ctloop < 4)
		{
			if (x[rh - 6][ch] == ' ' && x[rh - 5][ch - 2] == ' ' && x[rh - 2][ch - 4] == ' ')
			{
				rh--;
				ch--;
				if (sr > 5 && er < 80)
				{
					sr--;
					er--;
				}
			}
		}
		else
		{
			flag = 6;
			ct = 0;
		}
	}
}
void Lose(char x[][130])
{
	//g
	int c = 0, r = 0, i = 0;
	c = 3;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	c++;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 3;
	for (c = 4; c < 13; c++)
	{
		x[r][c] = 219;
	}
	r = 12;
	for (c = 4; c < 13; c++)
	{
		x[r][c] = 219;
	}
	r = 8;
	for (c = 9; c < 13; c++)
	{
		x[r][c] = 219;
	}
	for (r = 9; r < 13; r++)
	{
		for (c = 11; c < 13; c++)
		{
			x[r][c] = 219;
		}
	}
	//a
	c = 14;
	for (r = 4; r < 13; r++)
	{
		x[r][c] = 219;
	}
	c++;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 3;
	for (c = 16; c < 22; c++)
	{
		x[r][c] = 219;

	}
	c--;
	for (r = 4; r < 13; r++)
	{
		x[r][c] = 219;
	}
	c++;
	for (r = 4; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 8;
	for (c = 15; c < 21; c++)
	{
		x[r][c] = 219;
	}
	//m;
	c = 24;
	for (r = 3; r < 13; r++)
	{
		for (c = 24; c < 26; c++)
		{
			x[r][c] = 219;
		}

	}
	i = 26, r = 3;
	x[r][i] = 219;
	x[r + 1][i] = 219;
	x[r + 1][i + 1] = 219;
	x[r + 2][i + 1] = 219;
	x[r + 2][i + 2] = 219;
	x[r + 3][i + 2] = 219;
	x[r + 3][i + 3] = 219;
	x[r + 4][i + 3] = 219;
	x[r + 4][i + 4] = 219;
	//
	x[r + 3][i + 5] = 219;
	x[r + 3][i + 6] = 219;
	x[r + 2][i + 6] = 219;
	x[r + 2][i + 7] = 219;
	x[r + 1][i + 7] = 219;
	x[r + 1][i + 8] = 219;
	x[r][i + 8] = 219;
	x[r][i + 9] = 219;
	for (r = 3; r < 13; r++)
	{
		for (c = 35; c < 37; c++)
		{
			x[r][c] = 219;
		}
	}
	//e
	for (r = 3; r < 13; r++)
	{
		for (c = 39; c < 41; c++)
		{
			x[r][c] = 219;
		}
	}
	r = 3;
	for (c = 41; c < 48; c++)
	{
		x[r][c] = 219;
	}
	r = 7;
	for (c = 41; c < 46; c++)
	{
		x[r][c] = 219;
	}
	r = 12;
	for (c = 40; c < 48; c++)
	{
		x[r][c] = 219;
	}
	//o;
	c = 55;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	c = 56;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 3;
	for (c = 56; c < 63; c++)
	{
		x[r][c] = 219;

	}
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r--;
	for (c = 56; c < 63; c++)
	{
		x[r][c] = 219;

	}

	c = 64;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	//v
	c = 66;
	for (r = 3; r < 11; r++)
	{
		x[r][c] = 219;
	}
	c = 67;
	for (r = 3; r < 12; r++)
	{
		x[r][c] = 219;
	}
	i = 11, c = 68;
	x[i][c] = 219;
	x[i][c + 1] = 219;
	x[i + 1][c + 1] = 219;
	x[i + 1][c + 2] = 219;
	x[i + 1][c + 3] = 219;
	x[i + 1][c + 4] = 219;
	x[i][c + 4] = 219;
	x[i][c + 5] = 219;
	x[i][c + 6] = 219;
	c += 6;
	for (r = 3; r < 11; r++)
	{
		x[r][c] = 219;
	}
	c++;
	for (r = 3; r < 11; r++)
	{
		x[r][c] = 219;
	}
	//e;
	for (r = 3; r < 13; r++)
	{
		for (c = 77; c < 79; c++)
		{
			x[r][c] = 219;
		}
	}
	r = 3;
	for (c = 77; c < 86; c++)
	{
		x[r][c] = 219;
	}
	r = 7;
	for (c = 77; c < 83; c++)
	{
		x[r][c] = 219;
	}
	r = 12;
	for (c = 77; c < 86; c++)
	{
		x[r][c] = 219;
	}
	//r
	//r
	c = 88;
	for (r = 3; r < 13; r++)
	{
		for (c = 88; c < 90; c++)
		{
			x[r][c] = 219;
		}
	}
	r = 3;
	for (c = 90; c < 96; c++)
	{
		x[r][c] = 219;
	}
	for (r = 3; r < 8; r++)
	{
		x[r][c] = 219;
	}
	r = 7;
	for (c = 90; c < 96; c++)
	{
		x[r][c] = 219;
	}
	for (r = 8; r < 13; r++)
	{
		x[r][c] = 219;
	}
	c++;
	for (r = 8; r < 13; r++)
	{
		x[r][c] = 219;
	}
	x[4][c] = 219;
	x[6][c] = 219;


}
void laser(char x[][130], int& inv, int& ctL, int& ctk, int& RL, int& CL)


{
	ctL++;
	if (ctk == 0)
	{
		if (ctL == 30)
		{
			inv = 1;
			ctL = 0;
			ctk = 1;
		}
	}
	if (ctk == 1)
	{
		if (ctL == 30)
		{
			inv = 0;
			ctL = 0;
			ctk = 0;
		}
	}
	if (inv == 0)
	{
		RL = 64;
		CL = 40;
		for (int i = 0; i < 11; i++)
		{
			x[RL][CL] = '.';
			x[RL][CL - 2] = '.';
			RL++;
		}
	}
	else
	{
		RL = 64;
		CL = 40;
		for (int i = 0; i < 11; i++)
		{
			x[RL][CL] = 179;
			x[RL][CL - 2] = 179;
			RL++;
		}
	}
}
void MvEnemy1(int& re, int& ce, char x[][130], int& xdirE1, int& flagmoveenemy, int flagalive)

{
	if (flagalive == 0)
	{
		if (xdirE1 == -1)
		{
			flagmoveenemy = 2;
			if (ce == 8 || ce == 9 || ce == 10)
			{
				xdirE1 *= -1;
			}
			ce += -3;
		}
		else
		{
			flagmoveenemy = 1;
			if (ce + 7 == 40)
			{
				xdirE1 *= -1;
			}
			ce += xdirE1;
		}
	}
}
void MvEnemy2(int chero, int rhero, int& cenemy2, int& flagenemy2, int& flagdir2, char x[][130], int& renemy2)
{
	if (flagenemy2 != 2)
	{
		if (flagdir2 == 1)
		{
			if (cenemy2 >= 69)
			{
				flagdir2 = 0;
			}

			cenemy2 += 3;
		}
		if (flagdir2 == 0)
		{
			cenemy2 -= 3;
			if (cenemy2 == 10)
			{
				flagdir2 = 1;
			}

		}
	}
	if (rhero == 39 && chero < 69)
	{
		flagenemy2 = 0;
		//flagdir2 = 1;
	}
}
void MvEnemy3(int& ce3, int& xdirE3)
{
	if (xdirE3 == -1)
	{
		if (ce3 == 13 || ce3 == 14 || ce3 == 15)
		{
			xdirE3 *= -1;
		}
		ce3 += -2;
	}
	else
	{
		if (ce3 == 116 || ce3 == 115)
		{
			xdirE3 *= -1;
		}
		ce3 += 2;
	}
}
void MvAsanser(int& rs, int& cs, int& rh, int& ch, char x[][130], int& xdir2)
{
	if (xdir2 == -1)
	{
		if (cs == 87)
		{
			xdir2 *= -1;
		}
	}
	else
	{
		if (cs == 119)
		{
			xdir2 *= -1;
		}
	}
	if (xdir2 == -1)
	{
		cs += xdir2;
		if ((unsigned char)(x[rh + 1][ch]) == 196 || (unsigned char)(x[rh][ch]) == 196 || (unsigned char)(x[rh + 2][ch]) == 196)
		{
			ch--;
		}
	}
	else
	{
		cs += xdir2;
		if ((unsigned char)(x[rh + 1][ch]) == 196 || (unsigned char)(x[rh][ch]) == 196 || (unsigned char)(x[rh + 2][ch]) == 196)
		{
			ch++;
		}
	}
}
void Mvbullet(int& star, char x[][130], int flagB[1000], int cbullet[1000], int rbullet[1000], int flagdir[1000], int flagBd[1000], int cbulletd[1000], int rbulletd[1000], int flagdird[1000])
{

	for (int i = 0; i < star; i++)
	{
		if (flagB[i] == 1 && flagdir[i] == 1)
		{
			cbullet[i]++;
			rbullet[i]--;
		}
		if (flagBd[i] == 1 && flagdird[i] == 1)
		{
			cbulletd[i]++;
			rbulletd[i]++;
		}
		if (flagB[i] == 1 && flagdir[i] == -1)
		{
			cbullet[i]--;
			rbullet[i]--;
		}
		if (flagBd[i] == 1 && flagdird[i] == -1)
		{
			cbulletd[i]--;
			rbulletd[i]++;
		}
	}
}
void Mv7bl(int& rh, int& ch, char x[][130], int& flag, int& flagmove, int& dir7bl, int& sr, int& er)
{
	if (dir7bl == 1)
	{
		if (ch == 121)
		{
			if ((unsigned char)(x[rh - 6][ch + 1]) == 179)
			{
				flagmove = 4;
				flag = 20;
				rh -= 4;
				er -= 4;
				sr -= 4;
			}
		}
		if ((unsigned char)(x[rh - 5][ch]) == 196)
		{
			ch -= 3;
		}
		if (ch == 112 && rh - 5 == 28)
		{
			ch -= 2;
			flag = 1;
			flagmove = 2;
			dir7bl = -1;
		}
	}
	if (dir7bl == -1)
	{
		if ((unsigned char)(x[rh - 6][ch + 1]) == 196)
		{
			flagmove = 4;
			flag = 20;
			ch += 2;
		}
		if ((unsigned char)(x[rh - 6][ch + 1]) == 179 || (unsigned char)(x[rh - 6][ch + 1]) == 191)
		{
			rh += 2;
			er += 2;
			sr += 2;
		}
		if (ch == 121 && rh == 62)
		{
			flag = 1;
			flagmove = 2;
			dir7bl = 1;
		}
	}
}
void MvBull(char x[][130], int& flagbullet, int flagmove, int& rb, int& cb, int xdirbull, int& ctbullet)
{
	if (flagbullet == 0)
	{
		if (xdirbull == 1)
		{
			if (x[rb][cb + 2] == ' ' && x[rb][cb + 3] == ' ' && x[rb][cb + 4] == ' ')
			{
				cb += 3;
				ctbullet += 3;
			}
			else
			{
				flagbullet = 1;
				ctbullet = 0;
			}
		}
		if (xdirbull == -1)
		{
			if (x[rb][cb - 2] == ' ' && x[rb][cb - 3] == ' ' && x[rb][cb - 4] == ' ')
			{
				cb -= 3;
				ctbullet += 3;
			}
			else
			{
				flagbullet = 1;
				ctbullet = 0;
			}
		}
	}
}
void MvHero(int& ch, int& rh, char UserDes, char x[][130], int& flag, int& flagmove, int& ctloop, int& sr, int& er, int& sc, int& ec)
{
	if (UserDes == 'w' || UserDes == 'W')
	{
		flag = 2;
		ctloop++;
	}
	if (UserDes == 'e' || UserDes == 'E')
	{
		flag = 3;
		flagmove = 1;
		ctloop++;
		if (sc >= 0 && ec < 130)
		{
			sc++;
			ec++;
		}
	}
	if (UserDes == 'q' || UserDes == 'Q')
	{
		flag = 4;
		flagmove = 2;
		ctloop++;
		if (sc > 0 && ec <= 130)
		{
			sc--;
			ec--;
		}
	}
	if (UserDes == 's' || UserDes == 'S')
	{
		flag = 1;
		if (x[rh + 1][ch] == '-' || x[rh + 1][ch + 2] == '-')
		{
			rh++;
			if (sr > 0 && er < 80)
			{
				sr++;
				er++;
			}

		}
	}
	if (UserDes == 'a' || UserDes == 'A')
	{
		flagmove = 2;
		flag = 1;
		if (x[rh - 1][ch - 4] == ' ' && x[rh][ch - 1] == ' ')
		{
			ch--;
		}
		if (((unsigned char)(x[rh - 1][ch - 4]) == 222) || ((unsigned char)(x[rh][ch - 1]) == 222))
		{
			ch--;
		}
		if ((x[rh - 1][ch - 4] == '|') || (x[rh][ch - 1] == '|'))
		{
			ch--;
		}
		if (((unsigned char)(x[rh - 1][ch - 4]) == 221) || ((unsigned char)(x[rh][ch - 1]) == 221))
		{
			ch--;
		}
		if (x[rh - 1][ch - 4] == '-' || x[rh][ch - 1] == '-')
		{
			ch--;
		}
		if (sc > 0 && ec <= 130)
		{
			sc--;
			ec--;
		}

	}
	if (UserDes == 'd' || UserDes == 'D')
	{
		flag = 1;
		if (x[rh - 1][ch + 6] == ' ' && x[rh][ch + 3] == ' ')
		{
			ch++;
		}
		if (((unsigned char)(x[rh - 1][ch + 6]) == 222) || ((unsigned char)(x[rh][ch + 3]) == 222))
		{
			ch++;
		}
		if (((unsigned char)(x[rh - 1][ch + 6]) == 221) || ((unsigned char)(x[rh][ch + 3]) == 221))
		{
			ch++;
		}
		if ((x[rh - 1][ch + 6] == '|') || (x[rh][ch + 3] == '|'))
		{
			ch++;
		}
		if (x[rh - 1][ch + 6] == '-' || x[rh][ch + 3] == '-')
		{
			ch++;
		}
		flagmove = 1;
		if (sc >= 0 && ec < 130)
		{
			sc++;
			ec++;
		}
	}
}
void Touch(int& rh, int& ch, char x[][130], int& flagtouch, int& cttouch, int cenemy2, int& endrow, int& startrow, int& re, int& ce, int& ebr1, int& ebc1,
	int& ebr2, int& ebc2, int& ebr3, int& ebc3, int& En3BoRo1, int& En3BoCo1, int& flagdead2, int flagfall, int& flagdis, int& re4, int& ce4, int& sc, int& rc)
{
	if (flagtouch == 2)
	{
		flagdis = 0;
		cttouch++;
		Draw(x);
		Lose(x);
		DispLs(x);
		if (cttouch == 15)
		{
			flagtouch = 1;
			cttouch = 0;
		}
	}
	if (flagtouch == 1)
	{
		rh = 71;
		ch = 4;
		endrow = 80;
		startrow = 55;
		sc = 0;
		rc = 110;
		flagtouch = 0;
	}
	if ((En3BoRo1 + 4 == rh) && (En3BoCo1 == ch - 2 || En3BoCo1 == ch - 1 || En3BoCo1 == ch || En3BoCo1 == ch + 1 || En3BoCo1 == ch + 2 || En3BoCo1 == ch + 3 || En3BoCo1 == ch + 4 || En3BoCo1 == ch + 5))
	{
		flagtouch = 2;
	}
	if ((ebc1 + 4 == ch + 2 || ebc2 + 4 == ch + 2 || ebc3 + 4 == ch + 2 || ebc1 + 4 == ch + 1 || ebc2 + 4 == ch + 1 || ebc3 + 4 == ch + 1) && (rh < 57 && rh > 47))
	{
		flagtouch = 2;
	}
	if (x[rh + 1][ch] == '*' || x[rh + 1][ch + 2] == ' *')
	{
		flagtouch = 2;
	}
	if ((cenemy2 + 6 == ch + 5 && rh == 39) || (cenemy2 + 5 == ch + 3 && rh == 39))
	{
		flagtouch = 2;
	}
	if ((ce4 - 1 == ch && rh == 19) || (ce4 + 1 == ch && rh == 19) || (ce4 == ch && rh == 19) || (ce4 + 2 == ch && rh == 19) || (ce4 + 3 == ch && rh == 19) || (ce4 + 4 == ch && rh == 19) || (ce4 + 5 == ch && rh == 19))
	{
		flagtouch = 2;
	}
	if (flagdead2 == 1)
	{
		if ((cenemy2 + 6 + 5 == ch + 5 && rh == 39) || (cenemy2 + 5 + 5 == ch + 3 && rh == 39))
		{
			flagtouch = 2;
		}
	}
	if (flagfall == 1)
	{
		if (rh > 27)
		{
			flagtouch = 2;
		}
	}
	if ((ch > 36 && ch < 42) && (x[rh - 6][ch + 1] == '/' || x[rh - 6][ch + 1] == '\\' || x[rh - 6][ch + 2] == '/' || x[rh - 6][ch + 2] == '\\' || x[rh - 6][ch + 3] == '/' || x[rh - 6][ch + 3] == '\\'))
	{
		flagtouch = 2;
	}
}
void Won(char x[][130])
{
	int r = 3, i = 3;
	//y
	r = 3, i = 3;
	x[r][i] = 219;
	x[r][i + 1] = 219;
	x[r + 1][i + 1] = 219;
	x[r + 1][i + 2] = 219;
	x[r + 2][i + 2] = 219;
	x[r + 2][i + 3] = 219;
	x[r + 3][i + 3] = 219;
	x[r + 3][i + 4] = 219;
	x[r + 3][i + 5] = 219;
	x[r + 3][i + 6] = 219;
	x[r + 3][i + 7] = 219;
	x[r + 3][i + 8] = 219;

	for (r = 7; r < 13; r++)
	{
		x[r][i + 6] = 219;
	}
	for (r = 7; r < 13; r++)
	{
		x[r][i + 7] = 219;
	}
	r = 3;
	x[r][i + 12] = 219;
	x[r][i + 11] = 219;
	x[r + 1][i + 11] = 219;
	x[r + 1][i + 10] = 219;
	x[r + 2][i + 10] = 219;
	x[r + 2][i + 9] = 219;
	x[r + 3][i + 9] = 219;
	//o
	int c = 18;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 3;
	for (c = 18; c < 27; c++)
	{
		x[r][c] = 219;

	}
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r--;
	for (c = 18; c < 27; c++)
	{
		x[r][c] = 219;

	}
	c = 28;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	c = 17;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	//u
	c = 31;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	c = 32;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	for (c = 33; c < 43; c++)
	{
		x[r][c] = 219;
	}
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	c = 44;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	//w
	r = 3, i = 48;
	x[r][i] = 219;
	x[r][i + 1] = 219;
	x[r + 1][i + 1] = 219;
	x[r + 1][i + 2] = 219;
	x[r + 2][i + 2] = 219;
	x[r + 2][i + 3] = 219;
	x[r + 3][i + 3] = 219;
	x[r + 3][i + 4] = 219;
	x[r + 4][i + 4] = 219;
	x[r + 4][i + 5] = 219;
	x[r + 5][i + 5] = 219;
	x[r + 5][i + 6] = 219;
	x[r + 6][i + 6] = 219;
	x[r + 6][i + 7] = 219;
	x[r + 7][i + 7] = 219;
	x[r + 7][i + 8] = 219;
	x[r + 8][i + 8] = 219;
	x[r + 8][i + 9] = 219;
	x[r + 9][i + 9] = 219;
	x[r + 9][i + 10] = 219;
	//
	c = 58;
	r = 12;
	x[r - 1][c + 1] = 219;
	x[r - 1][c + 2] = 219;
	x[r - 2][c + 2] = 219;
	x[r - 2][c + 3] = 219;
	x[r - 3][c + 3] = 219;
	x[r - 3][c + 4] = 219;
	x[r - 4][c + 4] = 219;
	x[r - 4][c + 5] = 219;
	x[r - 5][c + 5] = 219;
	x[r - 5][c + 6] = 219;
	x[r - 6][c + 6] = 219;
	x[r - 6][c + 7] = 219;
	x[r - 7][c + 7] = 219;
	x[r - 7][c + 8] = 219;
	x[r - 8][c + 8] = 219;
	x[r - 8][c + 9] = 219;
	x[r - 9][c + 9] = 219;
	x[r - 9][c + 10] = 219;
	//
	r = 3, i = 68;
	x[r][i] = 219;
	x[r][i + 1] = 219;
	x[r + 1][i + 1] = 219;
	x[r + 1][i + 2] = 219;
	x[r + 2][i + 2] = 219;
	x[r + 2][i + 3] = 219;
	x[r + 3][i + 3] = 219;
	x[r + 3][i + 4] = 219;
	x[r + 4][i + 4] = 219;
	x[r + 4][i + 5] = 219;
	x[r + 5][i + 5] = 219;
	x[r + 5][i + 6] = 219;
	x[r + 6][i + 6] = 219;
	x[r + 6][i + 7] = 219;
	x[r + 7][i + 7] = 219;
	x[r + 7][i + 8] = 219;
	x[r + 8][i + 8] = 219;
	x[r + 8][i + 9] = 219;
	//
	c = 76;
	r = 12;
	x[r - 2][c + 2] = 219;
	x[r - 2][c + 3] = 219;
	x[r - 3][c + 3] = 219;
	x[r - 3][c + 4] = 219;
	x[r - 4][c + 4] = 219;
	x[r - 4][c + 5] = 219;
	x[r - 5][c + 5] = 219;
	x[r - 5][c + 6] = 219;
	x[r - 6][c + 6] = 219;
	x[r - 6][c + 7] = 219;
	x[r - 7][c + 7] = 219;
	x[r - 7][c + 8] = 219;
	x[r - 8][c + 8] = 219;
	x[r - 8][c + 9] = 219;
	x[r - 9][c + 9] = 219;
	x[r - 9][c + 10] = 219;
	//o
	c = 90;
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r = 3;
	for (c = 91; c < 100; c++)
	{
		x[r][c] = 219;

	}
	for (r = 3; r < 13; r++)
	{
		x[r][c] = 219;
	}
	r--;
	for (c = 91; c < 100; c++)
	{
		x[r][c] = 219;

	}
	c = 101;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	c = 89;
	for (r = 4; r < 12; r++)
	{
		x[r][c] = 219;
	}
	//N
	c = 105;
	r = 11;
	for (int r = 0; r < 10; r++)
	{

		for (int i = 0; i < 2; i++)
		{
			x[r + 3][c + i] = 219;
		}

	}
	//
	r = 2;
	x[r][c] = 219;
	x[r][c + 1] = 219;
	x[r + 1][c + 1] = 219;
	x[r + 1][c + 2] = 219;
	x[r + 2][c + 2] = 219;
	x[r + 2][c + 3] = 219;
	x[r + 3][c + 3] = 219;
	x[r + 3][c + 4] = 219;
	x[r + 4][c + 4] = 219;
	x[r + 4][c + 5] = 219;
	x[r + 5][c + 5] = 219;
	x[r + 5][c + 6] = 219;
	x[r + 6][c + 6] = 219;
	x[r + 6][c + 7] = 219;
	x[r + 7][c + 7] = 219;
	x[r + 7][c + 8] = 219;
	x[r + 8][c + 8] = 219;
	x[r + 8][c + 9] = 219;
	x[r + 9][c + 9] = 219;
	x[r + 9][c + 10] = 219;
	x[r + 10][c + 11] = 219;
	x[r + 10][c + 12] = 219;
	x[r + 10][c + 13] = 219;

	//
	c = 117;
	r = 12;
	for (int r = 0; r < 10; r++)
	{

		for (int i = 0; i < 2; i++)
		{
			x[r + 2][c + i] = 219;
		}

	}

}
void Disapear(int rh, int ch, char x[][130], int& ctdis, int& flagdis)
{
	if (rh == 31 && (ch > 58 && ch < 78))
	{
		ctdis++;
	}
	if (ctdis == 20)
	{
		flagdis = 1;
		ctdis = 0;
	}
}
void Mvlaser(char x[][130], int& flaglaser, int& c, int& ctlaser)
{
	ctlaser++;
	if (ctlaser == 5)
	{
		ctlaser = 0;
		if (c >= 0 && c < 12 && flaglaser == 0)
		{
			c += 2;
		}
		if (c >= 12 && flaglaser == 0)
		{
			flaglaser = 1;
		}
		if (flaglaser == 1)
		{
			c -= 1;
		}
		if (c == 0 && flaglaser == 1)
		{
			flaglaser = 0;
		}
	}
}
void Drlaser(char x[][130], int& c, int& r, int& flagD, int& ctla)
{

	r = 64;
	int col = 39;
	for (int i = 0; i < c; i++)
	{
		if (flagD == 1)
		{
			ctla++;
			x[r][col] = '\\';
			col++;
			if (ctla == 2)
			{
				flagD = -1;
				ctla = 0;
			}
		}
		else
		{
			x[r][col] = '/';
			col--;
			ctla++;
			if (ctla == 2)
			{
				flagD = 1;
				ctla = 0;
			}
		}
		r++;
	}
}
void main()
{
	int randEnCol = 9;
	int randEnColblock = 0;
	char UDes = 'w';
	char x[80][130];
	int dir7bl = 1;
	int ctEB = 0;
	int cplat = 0;
	int chero = 4;
	int ctla = 0;
	int ct = 0;
	int casanser = 90;
	int ctmove = 0;
	int ctElev = 0;
	int ctloop = 0;
	int casanser2 = 45;
	int ctapear = 0;
	int cbullet1 = 0;
	int ctdisapear = 0;
	int ctbullet = 0;
	int cttouch = 0;
	int cenemy3 = 25;
	int cenemy2 = 10;
	int cenemy = 8;
	int herodir = 0;
	int c7bl = 122;
	int cbullet[1000];
	int rbullet[1000];
	int flagB[1000];
	int flagdir[1000];
	int cbulletd[1000];
	int rbulletd[1000];
	int flagBd[1000];
	int flagdird[1000];
	int endrow = 80;
	int flagbullet = 1;
	int flagenemy2 = 2;
	int flagtouch = 0;
	int flaglose = 0;
	int flagdir2 = 1;
	int flag7bl = 0;
	int flagalive1 = 0;
	int flagalive2 = 0;
	int flagalive3 = 0;
	int flagdisapear = 0;
	int flagdirenemy3 = 1;
	int flagmoveenemy = 1;
	int flag = 1;
	int flagmove = 1;
	int flagwon = 0;
	int flagdead1 = 0;
	int flagdead2 = 0;
	int flagfall = 0;
	int rplat2 = 42;
	int rhero = 71;
	int rasanser = 62;
	int rasanser2 = 60;
	int renemy3 = 2;
	int renemy2 = 36;
	int renemy = 47;
	int r7bl = 30;
	int rhel = 18;
	int rbullet1 = 0;
	int rplat = 79;
	int star = 0;
	int startrow = 45;
	int	xdirE1 = -1;
	int xdir2 = -1;
	int xdirbull = 0;
	int	xdirE3 = -1;
	int ctrand = 0;
	int En3BoRo1 = 0;
	int En1BuCo1 = 0;
	int En1BuRo1 = 0;
	int En1BuCo2 = 0;
	int En1BuRo2 = 0;
	int En1BuCo3 = 0;
	int En1BuRo3 = 0;
	int FlEn3BO1 = 1;
	int FlEn1BU1 = 1;//
	int FlEn1BU2 = 1;
	int FlEn1BU3 = 1;
	int rand[130];
	int D1 = 0;
	int D2 = 0;
	int D3 = 0;
	int flagD = 1;
	int flaglaser2 = 0;
	int ctlaser = 0;
	int c = 0;
	int k = 0;
	int cenemy4 = 110;
	int renemy4 = 10;
	int flagalive4 = 0;
	int flagmove4 = 0;
	int flagdir4 = 0;
	int startcol = 0;
	int endcol = 110;
	for (int i = 0; i < 1000; i++)
	{
		cbullet[i] = 0;
		rbullet[i] = 0;
		flagB[i] = 0;
		flagdir[i] = 0;
		cbulletd[i] = 0;
		rbulletd[i] = 0;
		flagBd[i] = 0;
		flagdird[i] = 0;
	}
	for (int i = 0; i < 130; i++)
	{
		rand[i] = 0;
	}
	for (; !_kbhit(); )
	{
		Draw(x);
		Intro(x);
		DispInt(x);
	}
	for (;;)
	{
		for (; !_kbhit();)
		{
			Draw(x);
			Drplat1(rplat, cplat, x);
			Drplat2(rplat2, cplat, x, rand, flagdisapear);
			Dr7bl(r7bl, c7bl, x, flag7bl);
			MvEnemy1(renemy, cenemy, x, xdirE1, flagmoveenemy, flagalive1);
			Alive(rhero, chero, renemy, cenemy, x, flagalive1, flagalive2, flagalive4, flagmove4, flagdir4, flag7bl, renemy2,
				cenemy2, renemy3, cenemy3, flagwon, rbullet1, cbullet1, cbullet, rbullet, flagdead1, flagdead2, flagalive3, renemy4, cenemy4);
			Apear(rhero, chero, ctapear, flagalive2, startrow, endrow, flagdead1, flagfall);
			Enemy2(renemy2, cenemy2, flagenemy2, x, flagalive2, flagdead1, flagdead2);
			Enemy1(renemy, cenemy, x, flagmoveenemy, flagalive1);
			Asanser(rasanser, casanser, x);
			MvAsanser(rasanser, casanser, rhero, chero, x, xdir2);
			MvEnemy2(chero, rhero, cenemy2, flagenemy2, flagdir2, x, renemy2);
			MvBull(x, flagbullet, flagmove, rbullet1, cbullet1, xdirbull, ctbullet);
			DrBull(x, flagbullet, flagmove, cbullet1, rbullet1, xdirbull, ctbullet);
			Jump(chero, rhero, x, flag, ct, startrow, endrow, flagtouch, ctloop, startcol, endcol);
			ctrand++;
			if (En3BoRo1 + 1 == 19)
			{
				randEnCol = randNum(cenemy3 - 10, cenemy3 + 10);
			}
			EnBooms(randEnCol, En3BoRo1, FlEn3BO1, x, flagalive3);//
			if (rhero < 20 && ctrand % 2 == 0)
			{
				randEnColblock = randNum(0, 127);
				rand[randEnColblock] = randEnColblock;
				rand[randEnColblock + 1] = randEnColblock + 1;
			}
			if (FlEn1BU1 == 1)
			{
				En1BuCo1 = cenemy + 5;
				En1BuRo1 = renemy + 7;
				FlEn1BU1 = 0;
			}
			if (FlEn1BU2 == 1)
			{
				En1BuCo2 = cenemy + 5;
				En1BuRo2 = renemy + 9;
				FlEn1BU2 = 0;
			}
			if (FlEn1BU3 == 1)
			{
				En1BuCo3 = cenemy + 5;
				En1BuRo3 = renemy + 6;
				FlEn1BU3 = 0;
			}
			mvasanser(casanser2, rasanser2, x, rhero, chero, startrow, endrow);
			DrArrow(rhero, chero, En1BuRo1, En1BuCo1, En1BuRo2, En1BuCo2, En1BuRo3, En1BuCo3, x, flagmoveenemy, flagalive1, FlEn1BU1, FlEn1BU2, FlEn1BU3, ctEB, D1, D2, D3);
			EnArrow(rhero, chero, En1BuRo1, En1BuCo1, En1BuRo2, En1BuCo2, En1BuRo3, En1BuCo3, x, flagmoveenemy, flagalive1, FlEn1BU1, FlEn1BU2, FlEn1BU3, ctEB, D1, D2, D3);
			MvEnemy3(cenemy3, xdirE3);
			Enemy3(renemy3, cenemy3, x, flagalive3);
			if (FlEn3BO1 == 1)
			{

				En3BoRo1 = renemy3 + 7;
				FlEn3BO1 = 0;
			}
			Drlaser(x, c, k, flagD, ctla);
			MvEnemy4(renemy4, cenemy4, flagalive4, x, flagdir4, flagmove4);
			Enemy4(renemy4, cenemy4, flagalive4, x);
			Mvlaser(x, flaglaser2, c, ctlaser);
			Hero(chero, rhero, x, flagmove, herodir);
			Asanser2(casanser2, rasanser2, x, rhero, chero, startrow, endrow);
			Grv(chero, rhero, x, flag, startrow, endrow, ctloop, startcol, endcol);
			Mv7bl(rhero, chero, x, flag, flagmove, dir7bl, startrow, endrow);
			DrBullet(star, x, flagB, cbullet, rbullet, flagdir, flagBd, cbulletd, rbulletd, flagdird);
			Disapear(rhero, chero, x, ctdisapear, flagdisapear);
			Mvbullet(star, x, flagB, cbullet, rbullet, flagdir, flagBd, cbulletd, rbulletd, flagdird);
			Touch(rhero, chero, x, flagtouch, cttouch, cenemy2, endrow, startrow, renemy, cenemy, En1BuRo1, En1BuCo1, En1BuRo2, En1BuCo2, En1BuRo3, En1BuCo3, En3BoRo1, randEnCol, flagdead2, flagfall, flagdisapear, renemy4, cenemy4, startcol, endcol);
			Disp(startrow, endrow, x, startcol, endcol);
			if (flagwon == 1)
			{
				for (; !_kbhit(); )
				{
					Draw(x);
					Won(x);
					DispLs(x);
				}
			}
		}
		UDes = _getch();
		if (UDes == 'j' || UDes == 'J')
		{
			if (flagmove == 1)
			{
				flagB[star] = 1;
				rbullet[star] = rhero - 1;
				cbullet[star] = chero + 6;
				flagdir[star] = 1;

				flagBd[star] = 1;
				rbulletd[star] = rhero - 1;
				cbulletd[star] = chero + 6;
				flagdird[star] = 1;
				star++;
			}
			if (flagmove == 2)
			{
				flagB[star] = 1;
				rbullet[star] = rhero - 1;
				cbullet[star] = chero - 6;
				flagdir[star] = -1;

				flagBd[star] = 1;
				rbulletd[star] = rhero - 1;
				cbulletd[star] = chero - 6;
				flagdird[star] = -1;
				star++;
			}
		}
		if (UDes == 'f' || UDes == 'F')
		{
			if (flagbullet == 1)
			{
				if (flagmove == 1)
				{
					rbullet1 = rhero - 1;
					cbullet1 = chero + 6;
					flagbullet = 0;
					xdirbull = 1;
				}
				if (flagmove == 2)
				{
					rbullet1 = rhero - 1;
					cbullet1 = chero - 6;
					flagbullet = 0;
					xdirbull = -1;
				}
			}
		}
		if (UDes == 'g' || UDes == 'G')
		{
			flagmove = 3;
		}
		if (UDes == 'z' || UDes == 'Z')
		{
			rhero = 30;
			chero = 60;
			startrow = 15;
			endrow = 40;
		}
		if (UDes == 'x' || UDes == 'X')
		{
			rhero = 19;
			chero = 40;
			startrow = 1;
			endrow = 25;
		}
		if (UDes == 'c' || UDes == 'C')
		{
			rhero = 62;
			chero = 75;
			startrow = 35;
			endrow = 70;
		}
		MvHero(chero, rhero, UDes, x, flag, flagmove, ctloop, startrow, endrow, startcol, endcol);
	}
}


