#include <iostream>
#include <iomanip>

#define MAX 100

class Car
{
protected:
    double fuel_consump,fuel_cap;
    double avg_rain,avg_sunny,avg_snow;
    int id;
public:
    friend class Circuit;
    virtual void SetFuelConsump(double value){};
    virtual void SetFuelCap(double value){};
    virtual void SetAvgRain(double value){};
    virtual void SetAvgSunny(double value){};
    virtual void SetAvgSnow(double value){};
    virtual ~Car() {};
};

class Dacia: public Car
{
public:
    Dacia()
    {
        id=1;
        fuel_cap=10000;
        fuel_consump=100;
        avg_rain=100;
        avg_sunny=150;
        avg_snow=200;
    }
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Dacia(){};
};

class Toyota: public Car
{
public:
    Toyota()
    {
        id=2;
        fuel_cap=10000;
        fuel_consump=100;
        avg_rain=180;
        avg_sunny=100;
        avg_snow=150;
    }
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Toyota(){};
};

class Mercedes: public Car
{
public:
    Mercedes()
    {
        id=3;
        fuel_cap=1000;
        fuel_consump=800;
        avg_rain=100;
        avg_sunny=150;
        avg_snow=200;
    }
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Mercedes(){};
};

class Ford: public Car
{
public:
    Ford()
    {
        id=4;
        fuel_cap=10000;
        fuel_consump=100;
        avg_rain=50;
        avg_sunny=150;
        avg_snow=200;
    }
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Ford(){};
};

class Mazda: public Car
{
public:
    Mazda()
    {
        id=5;
        fuel_cap=100;
        fuel_consump=100;
        avg_rain=100;
        avg_sunny=150;
        avg_snow=200;
    }
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Mazda(){};
};

enum Weather{Rain,Sunny,Snow};


class Circuit
{
private:
    int n=0;
    double lenght;
    Weather weat;
    double race[MAX];
    Car *v[MAX];
public:
    void SetLength(int value){lenght=value;}
    void SetWeather(Weather w){weat=w;}
    void AddCar(Car *ca)
    {
        race[n]=0;
        v[n++]=ca;
    }
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

void bubble(double v[], Car *w[], int n)
{
    int ok,m=n,i;
    do
    {
        ok=0;
        for (i=0; i<m-1; ++i)
            if (v[i]>v[i+1])
            {
                std::swap(v[i],v[i+1]);
                std::swap(w[i],w[i+1]);
                ok=1;
            }
        m--;
    }
    while (ok==1);
}
void Circuit::Race()
{
    int i;
    for (i=0; i<n; ++i)
        if (lenght>v[i]->fuel_cap/v[i]->fuel_consump) race[i]=-1;
    switch(weat)
    {
    case Rain:
        for (i=0; i<n; ++i)
            if (race[i]==0) race[i]=lenght/v[i]->avg_rain;
        break;
    case Sunny:
        for (i=0; i<n; ++i)
            if (race[i]==0) race[i]=lenght/v[i]->avg_sunny;
        break;
    case Snow:
        for (i=0; i<n; ++i)
            if (race[i]==0) race[i]=lenght/v[i]->avg_snow;
        break;
    }
    bubble(race,v,n);
}

void print_placement(int i)
{
    if (i%10==1 && i%100!=11) std::cout << "st";
    else if (i%10==2 && i%100!=12) std::cout << "nd";
    else if (i%10==3 && i%100!=13) std::cout << "rd";
    else std::cout << "th";
}
void Circuit::ShowFinalRanks()
{
    int i=0,j;
    while (race[i]==-1) i++;
    for (j=1; i<n; ++i, ++j)
    {
        if (v[i]->id==1) std::cout << "Dacia finished the race in ";
        else if (v[i]->id==2) std::cout << "Toyota finished the race in ";
        else if (v[i]->id==3) std::cout << "Mercedes finished the race in ";
        else if (v[i]->id==4) std::cout << "Ford finished the race in ";
        else if (v[i]->id==5) std::cout << "Mazda finished the race in ";
        std::cout << std::fixed << std::setprecision(2) << race[i] << " hours in " << j;
        print_placement(j);
        std::cout << " place.\n";
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    int i;
    for (i=0; i<n && race[i]==-1; ++i)
    {
        if (v[i]->id==1) std::cout << "Dacia ";
        else if (v[i]->id==2) std::cout << "Toyota ";
        else if (v[i]->id==3) std::cout << "Mercedes ";
        else if (v[i]->id==4) std::cout << "Fors ";
        else if (v[i]->id==5) std::cout << "Mazda ";
        std::cout << "did not finish the race.\n";
    }
}

int main()
{
    Circuit c;
    c.SetLength(100);
    c.SetWeather(Weather::Rain);
    c.AddCar(new Dacia());
    c.AddCar(new Toyota());
    c.AddCar(new Mercedes());
    c.AddCar(new Ford());
    c.AddCar(new Mazda());
    c.Race();
    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
    c.ShowWhoDidNotFinish();
}
