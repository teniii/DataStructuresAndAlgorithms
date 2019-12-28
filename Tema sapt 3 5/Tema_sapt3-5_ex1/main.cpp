#include <iostream>

using namespace std;

//de rezolvat: 7 daca se sterge toata lista; 8 de reparata.- nu modifica lista ; 9 cred ca sterge, dar de vazut ce sa afiseze

struct nod
{
    int info;//
    struct nod *urm;
};

void adaugare_final(int val, struct nod *inc)
{
    struct nod* p, *q = new nod;
    p=inc;
    q->info=val;
    q->urm=NULL;
    while(p->urm!=NULL)
        p=p->urm;
    p->urm=q;

}

struct nod* add_inceput(int val, struct nod *inc)
{
    struct nod *p=new nod;
    p->info=val;
    p->urm=inc;
    return p;
}

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
//delete p;
//delete q;
}

void afisare(struct nod *inc)
{
    struct nod *p;
    p=inc;
    for(int i=0; p!=NULL; i++)

    {
        cout<<p->info<<" ";
        p=p->urm;

    }
    cout<<endl;
}

void cautare_val(struct nod *inc, int val)
{
    struct nod *p=new nod;
    p=inc;
    int poz=1;
    while(p!=NULL)

    {
        if(p->info==val)
        {
            cout<<"Elementul cautat se afla pe pozitia "<<poz<<endl;
//delete p;
            return;
        }
        poz++;
        p=p->urm;

    }
    cout<<"Elementul nu a putut fi gasit!"<<endl;
//delete p;
}

void cautare_poz(struct nod *inc, int index)
{
    if(index<1)
    {
        cout<<"Indexul este prea mic!"<<endl;
        return;
    }
    struct nod *p;
    p=inc;
    int poz=1;
    while(p->urm!=NULL)

    {
        if(index==poz)
        {
            cout<<"Elementul cautat are valoarea "<<p->info<<endl;
            return;
        }
        poz++;
        p=p->urm;

    }
    if(index==poz)
    {
        cout<<"Elementul cautat are valoarea "<<p->info<<endl;
        return;
    }
    if(index>poz)
    {
        cout<<"Lista nu are atat de multe elemente!"<<endl;
        return;
    }

//delete p;
}

nod* stergere_lista(struct nod*);

nod* stergere_val(struct nod *inc, int val)
{
    struct nod *p,*aux,*q;
    int eliminare=0;
    p=inc;

    if(p->urm==NULL && p->info==val)
    {
        //stergere_lista(inc);
        cout<<"Daca doriti stergerea singurului element, apelati functia de stergere a listei!!";
        return inc;
    }

    aux=p;
    for(; p->urm; p=p->urm)
    {
        if(p->info==val && p==inc)
        {
            q=p;
            p=p->urm;
            delete q;
            inc=p;
            eliminare++;
        }
        if(p->info==val)
        {
            eliminare++;
            aux->urm=aux->urm->urm;
            delete p;
            p=aux;

        }
        aux=p;
    }
    if(p->info==val)
    {
        aux->urm=NULL;
        delete p;
        eliminare++;
    }
    if(!eliminare)
    {cout<<"Valoarea nu se afla in lista!";return inc;}
    return inc;

}

nod* stergere_poz(struct nod *inc, int index)
{
    if(index<1)
    {
        cout<<"Lista are doar pozitii cel putin egale cu 1!!";
        return inc;
    }

    struct nod *p, *q;
    p=inc;
    int poz=1;

    for(;p->urm!=NULL;p=p->urm,poz++);

    if(poz<index)
    {cout<<"Indexul e prea mare!";
    return inc;}

    if(index==1 && p->urm==NULL)
    {
        //stergere_lista(inc);
        cout<<"Daca doriti stergerea singurului element, apelati functia de stergere a listei!!";
        return inc;
    }

    p=inc;
    if(index==poz)
    {
        while(p->urm->urm)
            p=p->urm;
        q=p->urm;
        p->urm=NULL;
        delete q;
        return inc;
    }

    p=inc;


    if(index==1)
    {
        q=p;
        p=p->urm;
        delete q;
        inc=p;
        return inc;
    }

    while(p->urm!=NULL)

    {
        if(poz+1==index )//&& p->urm->urm!=NULL)
        {
            q=p->urm;
            p->urm=p->urm->urm;
            delete q;
            return inc;
        }
        p=p->urm;

    }

    return inc;


}

struct nod* stergere_lista(struct nod *inc)
{
    struct nod *p;
    p=inc;
    while(p!=NULL)

    {
        inc=inc->urm;
        delete p;
        p=inc;

    }
    return NULL;

}


int main()
{

    struct nod *prim=new nod;
    int val;
    cout<<"introduceti primul element: ";
    cin>>val;
    prim->info=val;
    prim->urm=NULL;
    cout<<endl;

    int c,param,param2;

    cout<<"MENIU:\n1-Introd sfarsit\t2-Introd inceput\t3-Introd pe poz\n4-Afisare\t\t5-Cautare val\t\t6-Cautare poz\n7-Eliminare val\t\t8-Elim index\t\t9-Stergere lista\n";
    cout<<"\nLa apelarea functiei 9, programul se va opri!\n";
    while(c!=9)

    {
        cout<<"\nIntroduceti comanda: ";
        cin>>c;
        cout<<endl;
        switch(c)
        {
        case 1:
            cout<<"introduceti nr de pus la final: ";
            cin>>param;
            adaugare_final(param,prim);
            cout<<endl;
            break;
        case 2:
            cout<<"introduceti nr de pus la inceput: ";
            cin>>param;
            prim=add_inceput(param,prim);
            cout<<endl;
            break;
        case 3:
            cout<<"introduceti nr si pozitia: ";
            cin>>param>>param2;
            prim=add_pe_poz(param,prim,param2);
            cout<<endl;
            break;
        case 4:
            afisare(prim);
            cout<<endl;
            break;
        case 5:
            cout<<"introduceti nr de cautat: ";
            cin>>param;
            cautare_val(prim,param);
            cout<<endl;
            break;
        case 6:
            cout<<"introduceti indexul de cautat: ";
            cin>>param;
            cautare_poz(prim,param);
            cout<<endl;
            break;
        case 7:
            cout<<"introduceti nr de eliminat: ";
            cin>>param;
            prim=stergere_val(prim,param);
            cout<<endl;
            break;
        case 8:
            cout<<"introduceti indexul de eliminat: ";
            cin>>param;
            prim=stergere_poz(prim,param);
            cout<<endl;
            break;
        case 9:
            prim=stergere_lista(prim);
            cout<<"Gata!";
            break;

        }

    }

    return 0;
}
