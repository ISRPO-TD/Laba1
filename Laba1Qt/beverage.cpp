#include "beverage.h"

QString Beverage::getDescription(){
    return  description;
}
double Beverage::getCost(){
    return 0;
}

Americano::Americano(){
    description = "Американо";
}
double Americano::getCost(){
    return 15;
}

Capuchino::Capuchino(){
    description = "Капучино";
}
double Capuchino::getCost(){
    return 20;
}

Espresso::Espresso(){
    description = "Эспрессо";
}
double Espresso::getCost(){
    return 10;
}

Cacao::Cacao(){
    description = "Какао";
}
double Cacao::getCost(){
    return 12;
}

double CondimentDecorator::getCost(){
    return beverage.getCost() + 5;
}

QString Sugar::getDescription(){
    return beverage.getDescription() + ", с сахаром";
}

QString Milk::getDescription(){
    return beverage.getDescription() + ", с молоком";
}
