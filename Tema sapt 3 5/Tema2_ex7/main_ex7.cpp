#include <iostream>
#include <math.h>

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
    long val=0;
    cout<<"Introduceti cel mai mare grad al polinomului si coeficientul:";
    cin>>prim->gr>>prim->coef;
    cout<<endl;
    grad=prim->gr;
    coef=prim->coef;
    prim->urm=NULL;
    ultim=prim;

    while(grad)
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
    }

    int punct;
    cout<<"Introduceti valoarea in care sa se calculeze polinomul:";
    cin>>punct;
    p=prim;
    while(p!=ultim)
    {
        val+=pow(punct,p->gr)*p->coef;
        p=p->urm;
    }
    val+=pow(punct,p->gr)*p->coef;
    cout<<"Valoarea polinomului este:"<<val;


    return 0;
}
