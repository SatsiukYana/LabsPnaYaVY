#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sto; // ������������� �����
class Automobile
{
private:
    double mileage;// ������
    string name;// ��� ���������
    int id;

public:
    friend void printInfo(Automobile& automobile); // ������������� ������� ������ ���� ���������� 
    friend class Sto;// ������������� ����� ���

    Automobile(const int _id, const string _name, const double _mileage) {
        id = _id;
        name = _name;
        mileage = _mileage;
    }; // ����������� �������������
    
    Automobile() {
        id = 0;
        name = "Not entered";
        mileage = 0;
    };
    ~Automobile() {
        name.clear();
    }; // ����������

    void setId(const int _id);// ��������� id
    void setName(const string _name);// ��������� ������
    friend int checkNumber(Automobile* car, int carNumber); // ������� �������� �� ���� ������ ���������� �� ������
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
        //cout << car.id << ": " << car.mileage << endl;// �����
        car.mileage = _mileage; // ��������� �������
        //cout << car.id << ": " << car.mileage << endl;// ������
    }
    ~Sto() {};
};

void printInfo(Automobile& automobile)
{
    cout << "-----------------------------" << endl;
    cout << "id - " << automobile.id << endl // ����� id
        << "Name - " << automobile.name << endl // ����� ����� ���������
        << "mileage - " << automobile.mileage << endl; // ����� �������
    cout << "-----------------------------" << endl;
}

double inputMileage(double _mileage)// �������� �� ����
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
    int carNumber = 0; // ���������� ����� ������� �� ����� ����� � ������

    while (true)
    {
        cout << "Please, enter a number of the automobiles: ";
        fflush(stdin); // ���� ����� ������������� ������ ������
        cin >> carNumber; // ���� ���������� ����� � ������������ ����� �������� � carNum
        if (carNumber > 0) // �������� �� ���� (��� ����� ������������� � �� ����� 0)
            break;
        else cout << "Wrong number of the automobiles" << endl; // ���� ����� ����������� ������������
    }

    Automobile* car = new Automobile[carNumber];
    Sto sto;
    double _mileage = 0;
    for (int i = 0; i < carNumber; i++) // ���� �� ����� ���������� ��� ���� �����(���������� carNum)
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
        cout << "Num - " << i + 1 << endl; // ����� ������ � ������
        printInfo(car[i]);
    }

    cout << "Do you want to change sb mileage ?" << endl // ���� ����� �������� ������ � �����-�� ������
        << "1 - yes, 0 - no" << endl;

    int oneortwo = 0;
    cin >> oneortwo; // ������ 1 ��� 0
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
        int num = checkNumber(car, carNumber) - 1; // ������� �� �������� ����� ������ ���������� � ������
        _mileage = inputMileage(_mileage);
        sto.setMileage(car[num], _mileage);
    }

    cout << "Edited:" << endl
        << endl;
    for (int i = 0; i < carNumber; i++)
    {
        cout << "Number - " << i + 1 << endl; // ����� ������ ����������
        printInfo(car[i]); // ������� ������ ���� ���������� � ������
    }
    delete[] car; //����������� car ����� ������, �.�. ��������� ���������� � ��������� ������
    return 0;
}

int checkNumber(Automobile* car, int carNumber)// ������� �������� �� ���� ������ ���������� � ������
{
    int n = 0;

    while (true)
    {
        cout << "Choose num of editable auto" << endl;
        fflush(stdin); // ���� ����� ������������� ������ ������
        // ����  ����� � ������������ ����� �������� � carNum
        while (!(cin >> n))
        {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Incorrect : ";
        }
        cout << "change mileage" << endl;
        if (n - 1 < 0 || n - 1 > carNumber) {// �������� �� ���� (��� ����� ������������� � �� ����� 0)
            cout << "Wrong number, try again" << endl;
        }
        else break; // ���� ����� ����������� ������������
    }
    return n;
}
