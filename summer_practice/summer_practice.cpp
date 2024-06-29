#include <iostream>
#include <string>
#include <conio.h>
using namespace std; // не явл однозначным

//Базовый интерфейс
class Item {
public:
    virtual ~Item() {};
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
};

//Реализация заказа пиццы
class Pizza : public Item {
public:
    ~Pizza() {
        std::cout << "Pizza dtor\n";
    }
    string getDescription() const override {
        return "Pizza";
    }
    double getCost() const override {
        return 5.0; //базовая стоимость пиццы
    }
};

//Реализация заказа чая
class Tea : public Item {
public:
    ~Tea() {
        std::cout << "Tea dtor\n";
    }
    string getDescription() const override {
        return "Tea";
    }
    double getCost() const override {
        return 2.0; //базовая стоимость чая
    }
};

//Базовый декоратор 
class ItemDecorator : public Item {
public:
    ItemDecorator(Item* currentItem) {
        myItem = currentItem;
    }
    ~ItemDecorator() {
        delete myItem;
    }
    string getDescription() const override {
        return myItem->getDescription();
    }
    double getCost() const override {
        return myItem->getCost();
    }
protected:
    Item* myItem;
};

//Декораторы для добавок к Пицце (яблоко, брокколи, ветчина, томат, сыр)
class Pineapple : public ItemDecorator {
public:
    Pineapple(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Pineapple";
    }
    double getCost() const override {
        return myItem->getCost() + 1.0;
    }
};

class Broccoli : public ItemDecorator {
public:
    Broccoli(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Broccoli";
    }
    double getCost() const override {
        return myItem->getCost() + 1.0;
    }
};

class Ham : public ItemDecorator {
public:
    Ham(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Ham";
    }
    double getCost() const override {
        return myItem->getCost() + 1.5;
    }
};

class Tomato : public ItemDecorator {
public:
    Tomato(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Tomato";
    }
    double getCost() const override {
        return myItem->getCost() + 2.0;
    }
};

class Cheese : public ItemDecorator {
public:
    Cheese(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Cheese";
    }
    double getCost() const override {
        return myItem->getCost() + 2.0;
    }
};

//Декораторы для добавок к Чаю (мята, жасмпин, черная смородина, шиповник, лаванда)
class Mint : public ItemDecorator {
public:
    Mint(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Mint";
    }
    double getCost() const override {
        return myItem->getCost() + 0.5;
    }
};

class Jasmine : public ItemDecorator {
public:
    Jasmine(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Jasmine";
    }
    double getCost() const override {
        return myItem->getCost() + 0.7;
    }
};

class Blackcurrant : public ItemDecorator {
public:
    Blackcurrant(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Blackcurrant";
    }
    double getCost() const override {
        return myItem->getCost() + 0.7;
    }
};

class Rosehip : public ItemDecorator {
public:
    Rosehip(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Rosehip";
    }
    double getCost() const override {
        return myItem->getCost() + 0.7;
    }
};

class Lavender : public ItemDecorator {
public:
    Lavender(Item* currentItem) : ItemDecorator(currentItem) {}
    string getDescription() const override {
        return myItem->getDescription() + ", Lavender";
    }
    double getCost() const override {
        return myItem->getCost() + 0.7;
    }
};

//очистка терминала
void clearScreen() {
#ifdef _WIN32
    // Для Windows
    system("cls");
#else
    // Для других операционных систем (Linux, macOS)
    system("clear");
#endif
}

void menu() {
    Item* tmpTea = new Tea();
    Item* tmpPizza = new Pizza();
    start:
    clearScreen();
    std::cout << "\tMenu\n";
    std::cout << "1 - TEA,\t2 - PIZZA\n";
    do {
        if (_kbhit()) {
            int ch = _getch(); // получаем код ASCII клавиши
            // std::cout << ch << " ";
            if (ch == 8) {
                std::cout << "Shutdown\n";
                delete tmpPizza;
                delete tmpTea;
                break;
            }
            std::cout << static_cast<char>(ch) << " ";
            switch (static_cast<char>(ch)) {
            case '1': {
                clearScreen();
                std::cout << "\t\tTEA\n";
                std::cout << "Supplements:\n\tM - mint\n\tJ - jasmpine\n\tB - black currant\n\tR - rosehip\n\tL - lavender\n";
                do {
                    int ch_tea = _getch();
                    switch (static_cast<char>(ch_tea)) {
                        case 'm': {
                            tmpTea = new Mint(tmpTea);
                            break;
                        }
                        case 'j': {
                            tmpTea = new Jasmine(tmpTea);
                            break;
                        }
                        case 'b': {
                            tmpTea = new Blackcurrant(tmpTea);
                            break;
                        }
                        case 'r': {
                            tmpTea = new Rosehip(tmpTea);
                            break;
                        }
                        case 'l': {
                            tmpTea = new Lavender(tmpTea);
                            break;
                        }
                        case 'q': {
                            goto start;
                        }
                        default:
                            std::cout << "Invalid supplement choice." << endl;
                        }
                    std::cout << "Your order " << tmpTea->getDescription() << endl;
                    std::cout << "Order cost " << tmpTea->getCost() << endl;
                } while (1);
                break;
            }
            case '2': {
                clearScreen();
                std::cout << "\t\tPIZZA\n";
                std::cout << "Supplements:\n\tA - apple\n\tB - broccoli\n\tH - ham\n\tT - tomato\n\tC - cheese\n";
                do {
                    int ch_pizza = _getch();
                    switch (static_cast<char>(ch_pizza)) {
                    case 'a': {
                        tmpPizza = new Pineapple(tmpPizza);
                        break;
                    }
                    case 'b': {
                        tmpPizza = new Broccoli(tmpPizza);
                        break;
                    }
                    case 'h': {
                        tmpPizza = new Ham(tmpPizza);
                        break;
                    }
                    case 't': {
                        tmpPizza = new Tomato(tmpPizza);
                        break;
                    }
                    case 'c': {
                        tmpPizza = new Cheese(tmpPizza);
                        break;
                    }
                    case 'q': {
                        goto start;
                    }
                    default:
                        std::cout << "Invalid supplement choice." << endl;
                    }
                    std::cout << "Your order " << tmpPizza->getDescription() << endl;
                    std::cout << "Order cost " << tmpPizza->getCost() << endl;
                } while (1);
                break;
            }
            default:
                std::cout << "Invalid choice" << endl;
            }
        }
    } while (1);
}


int main() {
    menu();
    return 0;
}