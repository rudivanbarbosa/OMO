#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y)
{
    return (x-3)*(x-3) + (y+2)*(y+2) + 3*x*x*y*y;
}

double fx(double x, double y)
{
    return 2*(x-3) + 6*x*y*y;
}

double fy(double x, double y)
{
    return 2*(y+2) + 6*x*x*y;
}

double theta(double alpha, double x, double y)
{
double cx;
double cy;
    cx =  x - alpha*fx(x,y);
    cy =  y - alpha*fy(x,y);

    return f(cx,cy);
}

double d(double xL, double xu)
{
double ouro = (1 + sqrt(5) )/2;

return  (ouro - 1)*(xu-xL);
}

double razaoaurea( double x, double y, double xL, double xu, double epsilon1)
{
    double x1 = xL + d(xL, xu);
    double x2 = xu - d(xL, xu);

while( abs( theta(x2, x, y) - theta(x1, x, y) ) > epsilon1 )
{
    x1 = xL + d(xL,xu);
    x2 = xu - d(xL,xu);

    if( theta(x1, x, y) < theta(x2, x, y))
    {            xL = x2;

    }
    else
    {
            xu = x1;
    }
}
return (x1+x2)/2;
}

void MetodoGradiente( double x, double y, double xL, double xu, double epsilon1, double epsilon2)
{
    double aux_x;
    double aux_y;

do{

    aux_x = x - razaoaurea(x, y, xL, xu, epsilon1)*fx(x,y);
    aux_y = y - razaoaurea(x, y, xL, xu, epsilon1)*fy(x,y);
    x = aux_x;
    y = aux_y;
    aux_x = aux_y = 0;


}while( sqrt( pow(fx(x,y),2) +  pow(fy(x,y),2) ) > epsilon2 );

    cout << x << " " << y << " " << f(x,y) <<  "\n";

}



int main()
{

 double epsilon1 = 0.0000001;
 double epsilon2 = 0.01;
 double xL = -10000;
 double xu = 10000;
 double  x = 1;
 double  y = 1;

MetodoGradiente( x, y, xL, xu, epsilon1, epsilon2);


}





