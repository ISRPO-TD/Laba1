#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <QString>



class Beverage
{
protected:
    QString description;
public:
    Beverage() : description("Нет описания") {}
    virtual ~Beverage() {}
    virtual QString getDescription();
    virtual double getCost();
};

class Americano : public Beverage{
public:
    Americano();
    double getCost() override;
};
class Capuchino : public Beverage{
public:
    Capuchino();
    double getCost();
};
class Espresso : public Beverage{
public:
    Espresso();
    double getCost();
};
class Cacao : public Beverage{
public:
    Cacao();
    double getCost();
};

class CondimentDecorator : public Beverage{
protected:
    Beverage& beverage;
public:
    CondimentDecorator(Beverage& beverage) : beverage(beverage) {}
    virtual QString getDescription() override = 0;
    virtual double getCost() override;
};

class Sugar : public CondimentDecorator{
public:
    Sugar(Beverage& beverage) : CondimentDecorator(beverage) {}
    QString getDescription() override;
};

class Milk : public CondimentDecorator{
public:
    Milk(Beverage& beverage) : CondimentDecorator(beverage) {}
    QString getDescription() override;
};



#endif // BEVERAGE_H
