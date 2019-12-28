#include <iostream>

using namespace std;

struct pol
{
    int gr,coef;
    pol* urm;
};

void afisare(struct pol *inc,pol*final)
{
    struct pol *p;
    p=inc;
    for(int i=0; p!=final; i++)
    {
        if(p->coef)
            cout<<p->coef<<"*x^"<<p->gr<<" + ";
        p=p->urm;

    }
    if(p->gr==0){cout<<p->coef<<"\n\n";return;}
    cout<<p->coef<<"*x^"<<p->gr<<"\n";
    cout<<endl;
}

pol* add_final(pol* sf, int gr, int coef)
{
    pol *p=new pol;
    p->urm=NULL;
    p->coef=coef;
    p->gr=gr;
    sf->urm=p;
    sf=p;
    return sf;
}

int main()
{
    pol* prim1=new pol,*ultim1=prim1,*p,*prim2=new pol, *ultim2=prim2,*p1,*p2;
    int grad,coef;

    cout<<"Introduceti cel mai mare grad al primului polinom si coeficientul:";
    cin>>prim1->gr>>prim1->coef;
    cout<<endl;
    grad=prim1->gr;
    coef=prim1->coef;
    prim1->urm=NULL;
    ultim1=prim1;

    while(grad)
    {
        cout<<"Gradul si coeficientul:";
        cin>>grad>>coef;


        if(coef){
        p=new pol;
        p->coef=coef;
        p->gr=grad;
        p->urm=NULL;
        ultim1->urm=p;
        ultim1=p;}

        cout<<endl;
    }
    cout<<"Introduceti cel mai mare grad al polinomului 2 si coeficientul:";
    cin>>prim2->gr>>prim2->coef;
    cout<<endl;
    grad=prim2->gr;
    coef=prim2->coef;
    prim2->urm=NULL;
    ultim2=prim2;

    while(grad)
    {
        cout<<"Gradul si coeficientul:";
        cin>>grad>>coef;

        if(coef){
        p=new pol;
        p->coef=coef;
        p->gr=grad;
        p->urm=NULL;
        ultim2->urm=p;
        ultim2=p;}

        cout<<endl;
    }
    p1=prim1;p2=prim2;
    pol* rez=new pol,*ultim0=rez;
    //int index=1;
    afisare(prim1,ultim1);
    afisare(prim2,ultim2);


    while(p1 && p2)
    {
        if(p1->gr>p2->gr)
        {
            ultim0=add_final(ultim0,p1->gr,p1->coef);
            p1=p1->urm;
        }
        else
        {
            if(p1->gr<p2->gr)
            {
                ultim0=add_final(ultim0,p2->gr,p2->coef);
                p2=p2->urm;
            }
            else
            {
                ultim0=add_final(ultim0,p1->gr,p1->coef+p2->coef);
                p1=p1->urm;
                p2=p2->urm;
            }
        }
    }

    while(p1)
    {
        ultim0=add_final(ultim0,p1->gr,p1->coef);
        p1=p1->urm;
    }

    while(p2)
    {
        ultim0=add_final(ultim0,p2->gr,p2->coef);
        p2=p2->urm;
    }

    p1=rez;
    rez=rez->urm;
    delete p1;
    afisare(rez,ultim0);

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
