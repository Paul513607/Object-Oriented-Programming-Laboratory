#include <iostream>
#include <iomanip>

#define MAX 100

class Car
{
protected:
    double fuel_consump,fuel_cap;
    double avg_rain,avg_sunny,avg_snow;
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
private:
    int id=1;
public:
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Dacia(){};
};

class Toyota: public Car
{
private:
    int id=2;
public:
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Toyota(){};
};

class Mercedes: public Car
{
private:
    int id=3;
public:
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Mercedes(){};
};

class Ford: public Car
{
private:
    int id=4;
public:
    void SetFuelConsump(double value){fuel_consump=value;}
    void SetFuelCap(double value){fuel_cap=value;}
    void SetAvgRain(double value){avg_rain=value;}
    void SetAvgSunny(double value){avg_sunny=value;}
    void SetAvgSnow(double value){avg_snow=value;}
    ~Ford(){};
};

class Mazda: public Car
{
private:
    int id=5;
public:
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
        if (lenght<v[i]->fuel_cap/v[i]->fuel_consump) race[i]=-1;
    switch(weat)
    {
    case Rain:
        for (i=0; i<n; ++i)
            race[i]=lenght/v[i]->avg_rain;
        break;
    case Sunny:
        for (i=0; i<n; ++i)
            race[i]=lenght/v[i]->avg_sunny;
        break;
    case Snow:
        for (i=0; i<n; ++i)
            race[i]=lenght/v[i]->avg_snow;
        break;
    }
    bubble(race,v,n);
}

void Circuit::ShowFinalRanks()
{
    int i;
    for (i=0; i<n && race[i]!=-1; ++i)
    {
        std::cout << race[i] << " finished" << '\n';
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    int i=0;
    while (race[i]!=-1) i++;
    for (; i<n && race[i]!=-1; ++i)
    {
        std::cout << race[i] << " did not finish" << '\n';
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
