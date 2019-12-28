#include <iostream>
#include <climits>
using namespace std;

struct nod
{
    int info;//
    struct nod *urm;
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
        return inc;;
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
    for(int i=0; p!=NULL; i++)

    {
        cout<<p->info<<" ";
        p=p->urm;

    }
    cout<<endl;
}

int main()
{
    nod* prim=new nod, *p;
    prim=NULL;
    cout<<"Introduceti orice valoare nenula din intervalul [-2147483648,2147483647].\nCand considerati ca sunt suficiente numere, introduceti 0.\nLista va fi afisata in ordine crescatoare"<<endl;
    int val=1,poz=0,i=0;
    cin>>val;
    while(val)
    {
        p=prim;
        poz=0;
        for(i=0,poz=0; p!=NULL; i++)

    {
        if(p->info>val)
            {poz=i;break;}
        p=p->urm;
    }
    if(poz==0)poz=i;
        prim=add_pe_poz(val,prim,poz+1);
        cin>>val;
    }
    afisare(prim);

    return 0;
}
