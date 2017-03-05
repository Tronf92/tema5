//Nicorici Adrian, 19.05.2014
/*Creati o lista simplu inlantuita cu elemente de tip int, elementele fiind in ordine crescatoare. Faceti si un mic program de test al listei create. 
*/

#include <iostream>
using namespace std;

typedef struct nod{
	int x;
	nod *urm;
}NOD;

NOD *varf,*cursor;

void adauga_ultim(int a);
void adauga_inainte(int a,int b);

void creaza(){
	varf=NULL;
	varf=cursor;
}

void adauga_cap(int a){
	NOD *p=new nod;
	p->x=a;
	p->urm=varf;
	varf=p;
	cursor=p;
}

void adauga_dupa(int a){
	NOD *p,*q,*prec;
	q=new nod;
	p=varf;
	prec=NULL;
	bool exista = true;
	int c=0,m=0;
	if(varf==NULL){
		adauga_cap(a);
	}
	else{
		if(p->urm==NULL){
			if(a<p->x){
				q->x=a;
				q->urm=varf;
				varf=q;
				cursor=q;
			}
			else{
				q->x=a;
				prec=p;
				p=p->urm;
				q->urm=p;
				prec->urm=q;
			}
		}
		else{
			while(exista){
				if(p->urm==NULL){
					if(a>p->x){
						adauga_ultim(a);
						exista = false;
					}
					else{
						adauga_cap(a);
						exista=false;
					}
				}
				else{
					if(a>p->x && a<p->urm->x){
						adauga_inainte(a,p->urm->x);
						exista=false;
					}
				}
				p=p->urm;
			}
		}
	}
}

void adauga_ultim(int a){
	NOD *p,*q;
	q=new nod;
	p=varf;
	cursor=varf;
	while(p->urm!=NULL){
		p=p->urm;
		cursor=p;
	}
	q->x=a;
	q->urm=cursor->urm;
    cursor->urm=q;
    cursor=q;
}

void adauga_inainte(int a,int b){
	NOD *p,*prec,*q=new NOD;
	p=varf;
	prec=NULL;
	while ((p!=NULL)&&(b!=p->x)){
		prec=p;
		p=p->urm;
	}
	q->x=a;
	q->urm=p;
	prec->urm=q;
}

void afisare(){
	NOD *p=varf;
	cout << "Lista creata: " << endl;
	while(p!=NULL){
		cout << p->x << "---> ";
		p=p->urm;
	}
	cout << "NULL";
}

void citire(){
	int a;
	cout << "Introduceti un nr: " << endl;
	cin >> a;
	while(a!=0){
		adauga_dupa(a);
		cout << "Alt numar" << endl;
		cin >> a;
	}
}

int main(){
	creaza();
	citire();
	afisare();
	cout << endl;
	system("pause");
	return 0;
}