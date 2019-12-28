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
        cout<<p->coef<<"*x^"<<p->gr<<"+";
        p=p->urm;

    }
    cout<<p->coef<<"*x^"<<p->gr<<"\n";
    cout<<endl;
}

int main()
{
    pol* prim=new pol,*ultim=prim,*p;
    int grad,coef;
    cout<<"Introduceti cel mai mare grad al polinomului si coeficientul:";
    cin>>prim->gr>>prim->coef;
    cout<<endl;
    grad=prim->gr;
    coef=prim->coef;
    prim->urm=NULL;
    ultim=prim;
    do
    {
        cout<<"Gradul si coeficientul:";
        cin>>grad>>coef;

        if(coef){
        p=new pol;
        p->coef=coef;
        p->gr=grad;
        p->urm=NULL;
        ultim->urm=p;
        ultim=p;}

        cout<<endl;
    }while(grad);
    cout<<"\nIntoduceti scalarul:";
    int scalar;
    cin>>scalar;
    p=prim;
    while(p!=ultim)
    {
        int aux=p->coef;
        aux*=scalar;
        p->coef=aux;
        p=p->urm;
    }
    p->coef*=scalar;

    afisare(prim,ultim);


    return 0;
}
