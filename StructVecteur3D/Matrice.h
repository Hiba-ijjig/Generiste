#pragma once
#include "pch.h"
namespace traitMatrice {
	template<class T>
	class Matrice
	{

	private:
		unsigned int col;
		unsigned int lig;
		template<class T>** mat;
	public:
		Matrice(unsigned int i, unsigned int j)//constructeur
		{

			try
			{
				if (i <= 0 || j <= 0) throw "le nombre de ligne et de colonne doivent �tre strictement positifs";
				this->lig = i;
				this->col = j;
				this->mat = new int* [this->lig];
				for (int i = 0; i < this->lig; i++) this->mat[i] = new int[this->col];
				for (int i = 0; i < this->lig; i++)
					for (int j = 0; j < this->col; j++)
						this->mat[i][j] = 0;
			}
			catch (char* e)
			{
				cout << e << endl;
			}
		}
		Matrice(const Matrice& m) = delete;//constructeur de recopie
		~Matrice()// destructeur
		{
			for (int i = 0; i < this->lig; i++) delete this->mat[i];
			delete this->mat;
		}
		void remplissage(T k)// remplire la matrice
		{
			for (int i = 0; i < this->lig; i++)
				for (int j = 0; j < this->col; j++)
					this->mat[i][j] = k;
		}

		Matrice& operator=(const Matrice& m)=delete;
		Matrice* operator+(const Matrice& m) const
		{
			/*try
		   {
			   if (this->lig!= m.lig || this->col !=m.lig) throw "Les deux matrices n'ont pas la m�me taille";
		   }
		   catch (string e)
		   {
			   cout << e << endl;
		   }*/
			Matrice* tmp = new Matrice(this->lig, this->col);

			assert(this->lig == m.lig && this->col == m.col);
			for (int i = 0; i < this->lig; i++)
				for (int j = 0; j < this->col; j++)
					tmp->mat[i][j] = this->mat[i][j] + m.mat[i][j];
			return tmp;
		}
		Matrice* operator-(const Matrice& m) const
		{
			try
			{
				if (this->lig != m.lig || this->col != m.col) throw "Les deux matrices n'ont pas la m�me taille";
				Matrice* tmp = new Matrice(this->lig, this->col);
				for (int i = 0; i < this->lig; i++)
					for (int j = 0; j < this->col; j++)
						tmp->mat[i][j] = this->mat[i][j] - m.mat[i][j];
				return tmp;
			}
			catch (char* e)
			{
				cout << e << endl;
			}
		}
		Matrice* operator*(const Matrice& m) const
		{
			try
			{
				if (this->col != m.lig) throw "Le nombre de ligne de la matrice doit �tre le m�me que le nombre de colonne de la matrice courante";
				Matrice* tmp = new Matrice(this->lig, m.col);
				for (unsigned int i = 0; i < this->lig; i++)
					for (unsigned int j = 0; j < m.col; j++)
					{
						tmp->mat[i][j] = 0;
						for (unsigned int k = 0; k < this->col; k++)
							tmp->mat[i][j] += this->mat[i][k] * m.mat[k][j];
					}
				return tmp;
			}
			catch (char* e)
			{
				cout << e << endl;
			}
		}
		void operator*(T k) const// multiplication par un entier
		{
			for (int i = 0; i < this->lig; i++)
				for (int j = 0; j < this->col; j++) this->mat[i][j] *= k;
		}
		void print() const// afficher la patrice
		{
			for (int i = 0; i < this->lig; i++)
			{
				cout << "\n";
				for (int j = 0; j < this->col; j++) cout << this->mat[i][j];
			}
		}
	};

}