# Summer-practice, pattern Decorator
 Данный паттерн позволяет динамически добавлять новую функциональность объектам, оборачивая его в цепочку объектов-декораторов. Это структурный паттерн, который предоставляет альтернативу созданию подклассов для расширения функциональности.
### Преимущества: 
- Гибкость добавления функциональности;
- Комбинирование декораторов для создания сложных объектов.
### Недостатки:
- Может увеличивать сложность кода за счёт большого числа маленьких классов;
- Труднее отладка, так как объект обёрнут в несколько слоёв.

## Структура паттерна
- Компонент. Базовый интерфейс компонента определяет поведение, которое изменяется декораторами;
- Конкретный компонент. Данный класс представляет собой реализацию поведения по умолчанию. Может быть несколько вариаций классов;
- Декоратор. Базовый декоратор определяет интерфейс обёртки для всех конкретных декораторов. По умолчанию может включать в себя поле для хранения завернутого компонента и средства его инициализации;
- Конкретный декоратор. Данные классы вызывают обёрнутый объект и изменяют его результат некоторым образом.

## Структура паттерна в программном коде
- Компонент. Класс Item;
```cpp
class Item {
public:
virtual ~Item() {};
virtual string getDescription() const = 0;
virtual double getCost() const = 0;
};
```
- Конкретный компонент. Класс Pizza, Tea;
```cpp
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
```
- Декоратор. Класс ItemDecorator;
```cpp
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
```
- Конкретный декоратор. Остальные классы, добавляющие "обертку". 
```cpp
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
```

![struct code](https://github.com/finesko1/summer-practice/blob/main/sources/img/struct.png)

![Интерфейс работы приложения](https://github.com/finesko1/summer-practice/blob/main/sources/mp/interface.gif)