#include <iostream>
using namespace std;

struct nod
{
    float info;
    struct nod* urm;
};

struct nod* add_pe_poz(float val, struct nod *inc, int index)
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
        cout<<p->info<<" ";
        p=p->urm;

    }
    cout<<endl;
}

int main()
{
    int index=1;
    float val;
    struct nod* prim=new nod,*p;
    cout<<"Introduceti orice valoare nenula din intervalul [-2147483648,2147483647].\nCand considerati ca sunt suficiente numere, introduceti 0.\n"<<endl;
    cin>>val;
    if(val==0) return 0;
    prim->info=val;
    prim->urm=NULL;
    cout<<endl;
    while(val)
    {
        prim=add_pe_poz(val,prim,index);
        index++;
        cin>>val;
    }
    index=2;
    p=prim;
    while(p->urm->urm)
    {
        prim=add_pe_poz((float)p->info/2+(float)p->urm->info/2,prim,index);
        index+=2;
        p=p->urm->urm;
    }
    afisare(prim);

    while(p!=NULL)
    {
        prim=prim->urm;
        delete p;
        p=prim;

    }
}
