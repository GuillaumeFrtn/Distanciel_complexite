
//https://github.com/GuillaumeFrtn/Distanciel_complexite.git
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

void fusion(int tableau[],int deb1,int fin1,int fin2)
        {
        int *table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;
        
        table1=(int*)malloc((fin1-deb1+1)*sizeof(int));

        //on recopie les éléments du début du tableau
        for(i=deb1;i<=fin1;i++)
            {
            table1[i-deb1]=tableau[i];
            }
                        
        for(i=deb1;i<=fin2;i++)
            {        
            if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
                {
                break; //tous les éléments ont donc été classés
                }
            else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute les éléments restants du premier tableau
                compt1++;
                }
            else if (table1[compt1-deb1]<tableau[compt2])
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute un élément du premier tableau
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2]; //on ajoute un élément du second tableau
                compt2++;
                }
            }
        free(table1);
        }
        

void tri_fusion_bis(int tableau[],int deb,int fin)
        {
        if (deb!=fin)
            {
            int milieu=(fin+deb)/2;
            tri_fusion_bis(tableau,deb,milieu);
            tri_fusion_bis(tableau,milieu+1,fin);
            fusion(tableau,deb,milieu,fin);
            }
        }

void tri_fusion(int tableau[],int longueur)
     {
     if (longueur>0)
            {
            tri_fusion_bis(tableau,0,longueur-1);
            }
     }

void inverseTableau(int tableau[], int tailleTableau)
{
	int i = 0, temp = 0;
	for (i = 0 ; i < tailleTableau / 2 ; i++)
	{
	        temp = tableau[i];
	        tableau[i] = tableau[tailleTableau - i - 1];
	        tableau[tailleTableau - i - 1] = temp;
	}
}

int plusPetit(int T[], int taille)
{
	int min = T[0];
	int indiceMin = 0;
	for (int i=1; i<taille; ++i)
	{
		if (T[i] < min)
		{
			min = T[i];
			indiceMin = i;
		}
	}
	return indiceMin;
}

int LPT(int m, int n, int durees[])
{
	int Tlpt;
	int dureeMax;
	int i;
	int Tmachines[m];
	
	tri_fusion(durees,n);
	inverseTableau(durees,n);
	
	if (n<=m)
	{
		Tlpt = durees[n-1];
	}
	else
	{
		for (i=0; i<m; ++i)
		{
			Tmachines[i] = durees[i];
		}
		Tmachines[m-1] += durees[m];
		
		for (i=m+1; i<n; ++i)
		{
			Tmachines[plusPetit(Tmachines, m)] += durees[i];
		}
		
		dureeMax = Tmachines[0];
		for (i=1; i<m; ++i)
		{
			if (Tmachines[i] > dureeMax)
			{
				dureeMax = Tmachines[i];
			}
		}
		Tlpt = dureeMax;
	}
	return Tlpt;
}

int LSA(int m, int n, int durees[])
{
	int Tlsa;
	int dureeMax;
	int i;
	int Tmachines[m];
	
	for (i=0; i<m; ++i)
	{
		Tmachines[i] = durees[i];
	}
	Tmachines[m-1] += durees[m];
	
	for (i=m+1; i<n; ++i)
	{
		Tmachines[plusPetit(Tmachines, m)] += durees[i];
	}
	
	dureeMax = Tmachines[0];
	for (i=1; i<m; ++i)
	{
		if (Tmachines[i] > dureeMax)
		{
			dureeMax = Tmachines[i];
		}
	}
	Tlsa = dureeMax;
	
	return Tlsa;
}

int myAlgo(int m, int n, int durees[])
{
	int TmyAlgo;
	int dureeMax;
	int i;
	int Tmachines[m];
	int debut;
	int fin;
	int milieu;
	int pleine;
	bool estPleine[m];
	int valMax;
	int temp1;
	int temp2;
	int temp3;

	tri_fusion(durees,n);

	for (i=0; i<m; ++i)
	{
		estPleine[i] = false;
		Tmachines[i] = 0;
	}

	valMax = 0;

	for (i=0; i<n; ++i)
	{
		valMax += durees[i];
	}
	valMax = valMax/m;

	debut = 0;
	fin = n-1;
	i = 0;
	pleine = 0;
	dureeMax = 0;
	TmyAlgo = 0;


	while (debut < fin and pleine != m)
	{
		temp1 = durees[debut] + durees[fin];
		temp2 = durees[debut];
		temp3 = durees[fin];

		if (!estPleine[i%m])
		{
			if (Tmachines[i%m] + temp1 <= valMax)
			{
				Tmachines[i%m] = Tmachines[i%m] + temp1;
				++debut;
				--fin;
			}
			else if (Tmachines[i%m] + temp3 <= valMax)
			{
				Tmachines[i%m] = Tmachines[i%m] + temp3;
				--fin;
			}
			else if (Tmachines[i%m] + temp2 <= valMax)
			{
				Tmachines[i%m] = Tmachines[i%m] + temp2;
				++debut;
			}
			else
			{
				estPleine[i%m] = true;
				++pleine;
			}	
		}
		++i;
	}

	if (debut < fin)
	{
		for (i=debut; i<=fin; ++i)
		{
			Tmachines[plusPetit(Tmachines, m)] += durees[i];
		}
	}

	dureeMax = Tmachines[0];
	for (i=1; i<m; ++i)
	{
		if (Tmachines[i] > dureeMax)
		{
			dureeMax = Tmachines[i];
		}
	}
	TmyAlgo = dureeMax;
		
	return TmyAlgo;
	
}

int main()
{
	bool run = true;
	string chaine;
	int choix;
	while(run)
	{
		cout << "make a choice" << endl;
		cout << "1" << endl;
		cout << "2" << endl;
		cin >> choix;
		switch (choix)
		{
			case 1 : 
			{
				cout << "cas 1" << endl;
				int tab[] = {2, 7, 1, 3, 2, 6, 2, 3, 6, 2, 5};
				cout << "LSA : " << LSA(3,11,tab) << endl;
				cout << "LPT : " << LPT(3,11,tab) << endl;
				cout << "myAlgo : " << myAlgo(3,11,tab) << endl;
				
			}
				break;
			case 2 :
				chaine = "";
				cout << "cas 2" << endl;
				cin >> chaine;
				cout << chaine << endl;
				break;
			default :
				run = false;
				break;
		}
	}
	return 0;
}
