#include <iostream>
using namespace std;

struct nod
{
    float info;
    struct nod* urm;
};

struct nod* add_pe_poz(int val, struct nod *inc, int index)
{
    if(index<1)
    {
        cout<<"Pozitia este prea mica!"<<endl;
        return inc;
    }
    if(index==1)
    {
        struct nod*p=new nod;
        p->info=val;
        p->urm=inc;
        inc=p;
        return inc;
    }
    struct nod *p;
    struct nod *q=new nod;
    p=inc;
    int nr_nod=1;
    for(; p->urm; p=p->urm)
        nr_nod++;
    if(nr_nod+1<index)
    {
        cout<<"Indexul e prea mare"<<endl;
        return inc;
    }

    p=inc;
    for(int i=1; i<index-1; i++)
        p=p->urm;

    q->info=val;
    q->urm=p->urm;
    p->urm=q;
    return inc;

}

void afisare(struct nod *inc)
{
    struct nod *p;
    p=inc;
    for(int i=0; p->urm!=NULL; i++)

    {
        cout<<p->info<<"";
        p=p->urm;

    }
    cout<<endl;
}

int main()
{
    char c='0';
    nod *prim1=new nod,*prim2=new nod;
    const int index=1;
    cout<<"Introduceti cele doua numere, separate printr-un + si cand ati terminat, introduceti =\n";
    cin>>c;

    while(c!='+')
    {
        prim1=add_pe_poz(c-48,prim1,index);
        cin>>c;
    }

    cin>>c;
    while(c!='=')
    {
        prim2=add_pe_poz(c-48,prim2,index);

        cin>>c;
    }
    nod* rez=new nod,*p1=prim1,*p2=prim2;
    int aux=0;
    while(p1->urm &&p2->urm)
    {
        aux+=p1->info+p2->info;
        rez=add_pe_poz(aux%10,rez,index);
        aux/=10;
        p1=p1->urm;
        p2=p2->urm;
    }
    while(p1->urm)
    {
        aux+=p1->info;
        rez=add_pe_poz(aux%10,rez,index);
        aux/=10;
        p1=p1->urm;
    }

    while(p2->urm)
    {
        aux+=p2->info;
        rez=add_pe_poz(aux%10,rez,index);
        aux/=10;
        p2=p2->urm;
    }
    if(aux)
    {
        rez=add_pe_poz(aux,rez,index);
    }

    //afisare(prim1);
    //afisare(prim2);
    afisare(rez);

    p1=prim1;
    while(prim1)
    {
        prim1=prim1->urm;
        delete p1;
        p1=prim1;
    }
    p1=prim2;
        while(prim2)
    {
        prim2=prim2->urm;
        delete p1;
        p1=prim2;
    }
    p1=rez;
        while(rez)
    {
        rez=rez->urm;
        delete p1;
        p1=rez;
    }

}
