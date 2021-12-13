#pragma once
#include "pch.h"
#include<assert.h>
#include <iostream>
using namespace std;
namespace vecteur {
    template<class T>
    class Vecteur3D
    {
    private:
        T vect[3];
    public:
        Vecteur3D(T x = 0.0, T y = 0.0, T z = 0.0)//constructeur
        {
            this->vect[0] = x;
            this->vect[1] = y;
            this->vect[2] = z;
        }
        Vecteur3D(const Vecteur3D& a) = delete;//constructeur de recopie (delete pour ne pas travailler nik avec le constructeur par default ni avec celui ci
        Vecteur3D& operator=(const Vecteur3D& a) = delete;//operateur d'affectation
        void print() const //afficher les information du vecteur
        {
            for (int i = 0; i < 3; i++)
            {
                cout << "vect[" << i << "]=" << at(i) << "\n";
            }
        }
        T at(unsigned int i) const //retourner ce qui est dans la case i (different du get/set)
        {
            assert(i >= 0 && i < 3);
            try
            {
                if (i < 0 || i >= 3) throw "rang erre";
                return this->vect[i];
            }
            catch (char* e)
            {
                cout << e << endl;
            }
        }
        bool operator==(const Vecteur3D& v) const//(passage par réfference pour protéger l'objet v')
        {
            bool res = true;
            for (int i = 0; i < 3; i++)
            {
                res = res && (this->at(i) == v.at(i));
            }
            return res;
        }
        bool operator!=(const Vecteur3D& v) const
        {
            bool res = !(*this == v);
            return res;
        }
        T& operator[](unsigned int i)// retourner et(ou) modifier la valeur
        {
            assert(i >= 0 && i < 3);
            try //release
            {
                if (i < 0 || i >= 3) throw "rang erre";
                return this->vect[i];
            }
            catch (char* e)
            {
                cout << e << endl;
            }
        }
        // la différence entre at et [] est le passage par réference qui offre la possibilité de modifier la valeur existe dans la case i
        Vecteur3D* operator*(T v) const//produit par un entier
        {
            Vecteur3D* k = new Vecteur3D();
            for (int i = 0; i < 3; i++) k->vect[i] = this->vect[i] * v;
            return k;
        }
        T operator*(const Vecteur3D& v) const//produit scalaire
        {
            T a = 0;
            for (int i = 0; i < 3; i++) a += this->vect[i] * v.vect[i];
            return a;
        }
        T operator~() const// le module d'un vecteur
        {
            T a = 0;
            for (int i = 0; i < 3; i++) a += pow(this->vect[i], 2);
            return sqrt(a);
        }
        Vecteur3D* operator^(const Vecteur3D& v) const//produit scalaire
        {
            Vecteur3D* tmp = new Vecteur3D();
            tmp->vect[0] = this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1];
            tmp->vect[1] = this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2];
            tmp->vect[2] = this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0];
            return tmp;
        }
        Vecteur3D* operator+(const Vecteur3D& v) const//la somme 
        {
            Vecteur3D* tmp = new Vecteur3D();
            for (int i = 0; i < 3; i++)
                tmp->vect[i] = this->vect[i] + v.vect[i];
            return tmp;
        }
        Vecteur3D<T>* operator/(T v) const// division par un entier
        {
            Vecteur3D* tmp = new Vecteur3D();
            for (int i = 0; i < 3; i++) tmp->vect[i] = (this->vect[i] / v);
            return tmp;
        }
    };
}