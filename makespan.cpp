#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> 
#include <fstream>
#include <math.h>  
#include <time.h>
#include <stdlib.h>

using namespace std;

struct instance 
{ 
	int nbMachine; 
	int nbJob;
	vector<int> durees;
};



void affichageModes()
{
	cout << "Modes :" << endl;
	cout << "1 - Depuis un ficher" << endl;
	cout << "2 - Au clavier" << endl;
	cout << "3 - Génératon aléatoire de plusieurs instances" << endl;
	cout << "4 - Quittez le programme" << endl;
	cout << "Choissisez le modes de saisie des instances d'entrée" << endl;
}




int LSA(instance inst)
{
	vector<int> chaipas (inst.nbMachine, 0);
	int min = 999999;
	int max = 0;
	int indice = 0;
	for (unsigned i=0; i<inst.nbJob; i++)
	{
		for (unsigned j=0; j<inst.nbMachine; j++)
		{
				if(chaipas[j] < min)
				{
					min = chaipas[j];
					indice = j;
				}
		}
		chaipas[indice] = chaipas[indice] + inst.durees[i];
		min = 999999;
	}
	for (unsigned j=0; j<inst.nbMachine; j++)
	{
		if(chaipas[j] > max)
		{
			max = chaipas[j];
		}
	}
	return max;
}

bool myfunction (int i,int j) { return (i>j); }

int LPT(instance inst)
{
	vector<int> chaipas (inst.nbMachine, 0);
	int min = 999999;
	int max = 0;
	int indice = 0;

	sort (inst.durees.begin(), inst.durees.end(), myfunction);

	for (unsigned i=0; i<inst.nbJob; i++)
	{
		for (unsigned j=0; j<inst.nbMachine; j++)
		{
				if(chaipas[j] < min)
				{
					min = chaipas[j];
					indice = j;
				}
		}
		chaipas[indice] = chaipas[indice] + inst.durees[i];
		min = 999999;
	}
	for (unsigned j=0; j<inst.nbMachine; j++)
	{
		if(chaipas[j] > max)
		{
			max = chaipas[j];
		}
	}
	return max;
}

<<<<<<< HEAD
int MyAlgo(instance inst, int m, int n, int durees[])
{
	int TmyAlgo;
	int dureeMax;
	int i;
	int Tmachines[inst.nbMachine];
	int debut;
	int fin;
	int milieu;
	int pleine;
	bool estPleine[inst.nbMachine];
	int valMax;
	int temp1;
	int temp2;
	int temp3;

	tri_fusion(inst.durees,inst.nbJob);

	for (i=0; i<inst.nbMachine; ++i)
	{
		estPleine[i] = false;
		Tmachines[i] = 0;
	}

	valMax = 0;

	for (i=0; i<inst.nbJob; ++i)
	{
		valMax += inst.durees[i];
	}
	valMax = valMax/inst.nbMachine;

	debut = 0;
	fin = inst.nbJob-1;
	i = 0;
	pleine = 0;
	dureeMax = 0;
	TmyAlgo = 0;


	while (debut < fin and pleine != inst.nbMachine)
	{
		temp1 = inst.durees[debut] + inst.durees[fin];
		temp2 = inst.durees[debut];
		temp3 = inst.durees[fin];

		if (!estPleine[i%inst.nbMachine])
		{
			if (Tmachines[i%inst.nbMachine] + temp1 <= valMax)
			{
				Tmachines[i%inst.nbMachine] = Tmachines[i%inst.nbMachine] + temp1;
				++debut;
				--fin;
			}
			else if (Tmachines[i%inst.nbMachine] + temp3 <= valMax)
			{
				Tmachines[i%inst.nbMachine] = Tmachines[i%inst.nbMachine] + temp3;
				--fin;
			}
			else if (Tmachines[i%inst.nbMachine] + temp2 <= valMax)
			{
				Tmachines[i%inst.nbMachine] = Tmachines[i%inst.nbMachine] + temp2;
				++debut;
			}
			else
			{
				estPleine[i%inst.nbMachine] = true;
				++pleine;
			}	
		}
		++i;
	}

	if (debut < fin)
	{
		for (i=debut; i<=fin; ++i)
		{
			Tmachines[plusPetit(Tmachines, inst.nbMachine)] += inst.durees[i];
		}
	}

	dureeMax = Tmachines[0];
	for (i=1; i<inst.nbMachine; ++i)
	{
		if (Tmachines[i] > dureeMax)
		{
			dureeMax = Tmachines[i];
		}
	}
	TmyAlgo = dureeMax;
		
return TmyAlgo;
=======
int MyAlgo()
{

>>>>>>> ddb0afca8bdf6459c60e28ecd5a2e2d30b564cdf
}

int maximum(instance &inst)
{
	int max = 0;
	for (unsigned j=0; j<inst.durees.size(); j++)
	{
		if(inst.durees[j] > max)
		{
			max = inst.durees[j];
		}
	}
	return max;
}

int moyenne(instance &inst)
{
	int somme = 0;
	for (unsigned j=0; j<inst.durees.size(); j++)
	{
		somme = somme + inst.durees[j];
	}
	return somme/inst.nbMachine;
}

void convert(string chaine, instance &inst)
{
	int i = 0;
	while(chaine[i] != 32)
	{
		i++;
	}
	inst.nbMachine = 0;
	for(int j = 0; j<i; j++)
	{
		inst.nbMachine = inst.nbMachine + pow(10,i-1-j)*(chaine[j]-48);
	}

	int k = i + 3;
	while(chaine[k] != 32)
	{
		k++;
	}
	inst.nbJob = 0;
	for(int j = i+3; j<k; j++)
	{
		inst.nbJob = inst.nbJob + pow(10,k-1-j)*(chaine[j]-48);
	}

	int deb = k + 3;
	int fin, ajout, duree;
	while(deb < chaine.length())
	{
		fin = deb;
		ajout = 0;
		duree = 0;
		while(chaine[fin] != 32 && fin < chaine.length())
		{
			fin++;
		}
		for(int j = deb; j<fin; j++)
		{
			duree = duree + pow(10,fin-1-j)*(chaine[j]-48);

		}
		inst.durees.push_back(duree);

		deb = fin + 3;
	}
}

void clavier()
{
	string chaine = "";
	instance inst;
	cout << "Entrez votre chaine de la forme m : n : d1 : d2 : ... : dn (oubliez pas les espaces" << endl;

	getline(cin, chaine);
	
	convert(chaine, inst);

	cout << "Borne inférieure maximum = " << maximum(inst) << endl;
	cout << "Borne inférieure moyenne = " << moyenne(inst) << endl;
	cout << "Résultat LSA = " << LSA(inst) << endl;
	cout << "Résultat LPT = " << LPT(inst) << endl;
<<<<<<< HEAD
	cout << "Résultat MyAlgo = " << MyAlgo(inst) << endl;
=======
	cout << "Résultat MyAlgo = " << endl;
>>>>>>> ddb0afca8bdf6459c60e28ecd5a2e2d30b564cdf
	cout << endl;
}

void fichier()
{
	string chaine = "";
	cout << "Entrez le nom du fichier situé à la racine de l'exécutable" << endl;
	getline(cin, chaine);

	ifstream fichier(chaine, ios::in);

	if(fichier)
	{
		string contenu;
		getline(fichier, contenu);

		instance inst;
		convert(contenu, inst);

		cout << "Borne inférieure maximum = " << maximum(inst) << endl;
		cout << "Borne inférieure moyenne = " << moyenne(inst) << endl;
		cout << "Résultat LSA = " << LSA(inst) << endl;
		cout << "Résultat LPT = " << LPT(inst) << endl;
<<<<<<< HEAD
		cout << "Résultat MyAlgo = " << MyAlgo(inst) << endl;
=======
		cout << "Résultat MyAlgo = " << endl;
>>>>>>> ddb0afca8bdf6459c60e28ecd5a2e2d30b564cdf
		cout << endl;

		fichier.close();
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}
}

void generation()
{
	instance inst;
	int k, min, max;

	string input = "";
	cout << "Entrez le nombre de machines" << endl;
	getline(cin, input);

	// This code converts from string to number safely.
	stringstream myStream(input);
	if (!(myStream >> inst.nbMachine))
	{
		cout << "Nombre invalide, essayez encore" << endl;
		return;
	}
	cout << endl;

	cout << "Entrez le nombre de tâches" << endl;
	getline(cin, input);

	// This code converts from string to number safely.
	stringstream myStream2(input);
	if (!(myStream2 >> inst.nbJob))
	{
		cout << "Nombre invalide, essayez encore" << endl;
		return;
	}
	cout << endl;

	cout << "Entrez le nombre d'instances" << endl;
	getline(cin, input);

	// This code converts from string to number safely.
	stringstream myStream3(input);
	if (!(myStream3 >> k))
	{
		cout << "Nombre invalide, essayez encore" << endl;
		return;
	}
	cout << endl;

	cout << "Entrez la durée minimale" << endl;
	getline(cin, input);

	// This code converts from string to number safely.
	stringstream myStream4(input);
	if (!(myStream4 >> min))
	{
		cout << "Nombre invalide, essayez encore" << endl;
		return;
	}
	cout << endl;

	cout << "Entrez la durée maximale" << endl;
	getline(cin, input);

	// This code converts from string to number safely.
	stringstream myStream5(input);
	if (!(myStream5 >> max))
	{
		cout << "Nombre invalide, essayez encore" << endl;
		return;
	}
	cout << endl;

	cout << "Entrez le nom de fichier" << endl;
	getline(cin, input);

	ofstream fichier(input, ios::out | ios::trunc );
 

	int duree;
	if(fichier)  
	{       
		srand(time(NULL));
		for(int j = 0; j<k; j++)
		{
			for(int i = 0; i<inst.nbJob ; ++i)
			{
				duree = rand() % (max+1-min) + min;
				cout << duree << endl;
				inst.durees.push_back(duree);
			}

			fichier << "=====================================================================================" << endl;
			fichier << "Borne inférieure maximum = " << maximum(inst) << endl;
			fichier << "Borne inférieure moyenne = " << moyenne(inst) << endl;
			fichier << "Résultat LSA = " << LSA(inst) << endl;
			fichier << "Résultat LPT = " << LPT(inst) << endl;
<<<<<<< HEAD
			fichier << "Résultat MyAlgo = " << MyAlgo(inst) << endl;
=======
			fichier << "Résultat MyAlgo = " << endl;
			cout << endl;
>>>>>>> ddb0afca8bdf6459c60e28ecd5a2e2d30b564cdf

			inst.durees.erase(inst.durees.begin(), inst.durees.end());
		}

		fichier.close();
	}
	else  
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void choixMode()
{
	int choix = 0;
	string input = "";

	while (choix != 4)
	{
		affichageModes();
		getline(cin, input);

	   // This code converts from string to number safely.
		stringstream myStream(input);
		if (!(myStream >> choix))
		{
			cout << "Nombre invalide, essayez encore" << endl;
			break;
		}
 

		switch(choix)
		{
			case 1: fichier();
					break;
			case 2: clavier();
					break;
			case 3: generation();
					break;
			default:
					break;
		}
	}
}

int main()
{

	choixMode();
	// 3 : 11 : 2 : 7 : 1 : 3 : 2 : 6 : 2 : 3 : 6 : 2 : 5 

	return 0;
}
