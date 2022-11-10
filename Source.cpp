#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sto; // дружественный класс
class Automobile
{
private:
    double mileage;// пробег
    string name;// имя владельца
    int id;

public:
    friend void printInfo(Automobile& automobile); // дружественная функция вывода всей информации 
    friend class Sto;// дружественный класс СТО

    Automobile(const int _id, const string _name, const double _mileage) {
        id = _id;
        name = _name;
        mileage = _mileage;
    }; // конструктор инициализации
    
    Automobile() {
        id = 0;
        name = "Not entered";
        mileage = 0;
    };
    ~Automobile() {
        name.clear();
    }; // деструктор

    void setId(const int _id);// установка id
    void setName(const string _name);// установка именри
    friend int checkNumber(Automobile* car, int carNumber); // функция проверки на ввод номера автомобиля из списка
};


void Automobile::setName(const string _name)
{
    name = _name;
}
void Automobile::setId(const int _id)
{
    id = _id;
}

class Sto
{
public:
    void setMileage(Automobile& car, const double _mileage)
    {
        //cout << car.id << ": " << car.mileage << endl;// плохо
        car.mileage = _mileage; // установка пробега
        //cout << car.id << ": " << car.mileage << endl;// хорошо
    }
    ~Sto() {};
};

void printInfo(Automobile& automobile)
{
    cout << "-----------------------------" << endl;
    cout << "id - " << automobile.id << endl // вывод id
        << "Name - " << automobile.name << endl // вывод имени владельца
        << "mileage - " << automobile.mileage << endl; // вывод пробега
    cout << "-----------------------------" << endl;
}

double inputMileage(double _mileage)// проверка на ввод
{
    {
        while (true)
        {
            rewind(stdin);
            if ((cin >> _mileage) && _mileage >= 1 && !cin.fail())
                break;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        return (_mileage);
    }
}

int main()
{
    int carNumber = 0; // количество машин которые мы хотим иметь в списке

    while (true)
    {
        cout << "Please, enter a number of the automobiles: ";
        fflush(stdin); // если число отрицательное вводим заново
        cin >> carNumber; // ввод количества машин и присваивание этого значения в carNum
        if (carNumber > 0) // проверка на ввод (что число положительное и не равно 0)
            break;
        else cout << "Wrong number of the automobiles" << endl; // если число автомобилей неправильное
    }

    Automobile* car = new Automobile[carNumber];
    Sto sto;
    double _mileage = 0;
    for (int i = 0; i < carNumber; i++) // пока не введём информацию для всех машин(количество carNum)
    {
        string _name;
        int _id;
        while (true)
        {
            rewind(stdin);
            cout << "Please, enter id: ";
            if ((cin >> _id) && _id >= 1 && !cin.fail())
                break;
            cin.clear();
            cin.ignore(32767, '\n');
        }
       

        car[i].setId(_id);
        cout << "Car's mileage: " << endl;
        _mileage = inputMileage(_mileage);
        sto.setMileage(car[i], _mileage);
        cout << "name:" << endl;
        cin >> _name;
        car[i].setName(_name);
    }

    for (int i = 0; i < carNumber; i++)
    {
        cout << "Num - " << i + 1 << endl; // номер машины в списке
        printInfo(car[i]);
    }

    cout << "Do you want to change sb mileage ?" << endl // если хотим поменять пробег в какой-то машине
        << "1 - yes, 0 - no" << endl;

    int oneortwo = 0;
    cin >> oneortwo; // вводим 1 или 0
    while (oneortwo != 1 && oneortwo != 0)
    {
        cout << "Wrong number, try again" << endl;
        cout << "1 - yes, 0 - no" << endl;
        fflush(stdin); // 
        cin >> oneortwo;
    }
    if (oneortwo == 1)
    {
        //cin.clear();
        int num = checkNumber(car, carNumber) - 1; // функция на праверку ввода номера автомобиля в списке
        _mileage = inputMileage(_mileage);
        sto.setMileage(car[num], _mileage);
    }

    cout << "Edited:" << endl
        << endl;
    for (int i = 0; i < carNumber; i++)
    {
        cout << "Number - " << i + 1 << endl; // вывод номера автомобиля
        printInfo(car[i]); // функция вывода всей информации о машине
    }
    delete[] car; //уничтожение car после вывода, т.к. выводится информация о следующей машине
    return 0;
}

int checkNumber(Automobile* car, int carNumber)// функция проверки на ввод номера автомобиля в списке
{
    int n = 0;

    while (true)
    {
        cout << "Choose num of editable auto" << endl;
        fflush(stdin); // если число отрицательное вводим заново
        // ввод  машин и присваивание этого значения в carNum
        while (!(cin >> n))
        {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Incorrect : ";
        }
        cout << "change mileage" << endl;
        if (n - 1 < 0 || n - 1 > carNumber) {// проверка на ввод (что число положительное и не равно 0)
            cout << "Wrong number, try again" << endl;
        }
        else break; // если число автомобилей неправильное
    }
    return n;
}
