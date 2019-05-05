#include <iostream>
#include <chrono>
#include <random>
using namespace std;

int main()
{
    unsigned generate_in_time = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(generate_in_time);
    normal_distribution <double> dis (1000,100);


    double Averagerevenue=0, Bestaveragerevenue=0, Bestprice=0, Demande=0, Sales=0 ;
    for (int i=90 ; i<=100 ; i++)
    {

        double Revenue=0;
        int Price = i ;

        for (int j=0 ; j<1000 ; j++)
        {
            Demande=dis(gen);
            Sales=Demande/((Price/100)*(Price/100));
            Revenue+=Sales*Price;
        }
        Averagerevenue=Revenue/1000;
        if(Averagerevenue>Bestaveragerevenue)
        {
            Bestaveragerevenue=Averagerevenue;
            Bestprice=Price;
        }
    }
    cout<<"The best price is: "<<Bestprice<<endl<<"The best average revenue: "<<Bestaveragerevenue<<endl<<"The best demande is: "<<Demande<<endl;

    return 0;
}
