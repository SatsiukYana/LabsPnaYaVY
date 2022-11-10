#include <iostream>
using namespace std;

class Computer {
public:

    Computer(int ReleaseDate = 0, string Manufacturer = "Manufacturer not entered", double Cost = 0.0) : ReleaseDate(ReleaseDate), Manufacturer(Manufacturer), Cost(Cost) {
    }

    Computer(Computer& other) {
        this->ReleaseDate = other.ReleaseDate;
        this->Manufacturer = other.Manufacturer;
        this->Cost = other.Cost;
    }

    int getReleaseDate() const {
        return ReleaseDate;
    }

    void setReleaseDate(int releaseDate) {
        ReleaseDate = releaseDate;
    }

    const string& getManufacturer() const {
        return Manufacturer;
    }

    void setManufacturer(const string& manufacturer) {
        Manufacturer = manufacturer;
    }

    double getCost() const {
        return Cost;
    }

    void setCost(double cost) {
        Computer::Cost = cost;
    }
    double inputSMTH(double cost)// проверка на ввод
    {
        {
            while (true)
            {
                rewind(stdin);
                if ((cin >> cost) && cost >= 1 && !cin.fail())
                    break;
                cin.clear();
                cin.ignore(32767, '\n');
            }
            return (cost);
        }
    }
    virtual void output() {
        cout << "ReleaseDate: " << ReleaseDate
            << endl << "Manufacturer: " << Manufacturer
            << endl << "Cost: " << Cost << "$"
            << endl;
    }

    ~Computer() = default;

protected:
    double Cost;
    int ReleaseDate;
    string Manufacturer;
};

class Inside : virtual public Computer {
private:

    string InsideCriteria = "InsideCriteria";

public:

    Inside(int ReleaseDate, string Manufacturer, double Cost, int CoresNumber = 0)
        : Computer(ReleaseDate, Manufacturer, Cost), CoresNumber(CoresNumber) {

    }

    const string& getInsideCriteria() const {
        return InsideCriteria;
    }

    void setInsideCriteria(const string& insideCriteria) {
        InsideCriteria = insideCriteria;
    }

    int getCoresNumber() const {
        return CoresNumber;
    }

    void setCoresNumber(int coresNumber) {
        CoresNumber = coresNumber;
    }

    virtual void output() {
        cout << "ReleaseDate: " << ReleaseDate
            << endl << "Manufacturer: " << Manufacturer
            << endl << "Cost: " << Cost << "$"
            << endl << "******************"
            << endl << InsideCriteria
            << endl
            << "CoresNumber: " << CoresNumber
            << endl;
    }

    ~Inside() = default;

protected:
    int CoresNumber;
};

class Outside : virtual public Computer {
private:

    string OutsideCriteria = "OutsideCriteria";

public:

    Outside(int ReleaseDate, string Manufacturer, double Cost, string ScreenResolution)
        : Computer(ReleaseDate, Manufacturer, Cost), ScreenResolution(ScreenResolution) {

    }

    const string& getOutsideCriteria() const {
        return OutsideCriteria;
    }

    void setOutsideCriteria(const string& outsideCriteria) {
        OutsideCriteria = outsideCriteria;
    }

    string getScreenResolution() const {
        return ScreenResolution;
    }

    void setScreenResolution(string screenResolution) {
        ScreenResolution = screenResolution;
    }

    virtual void output() override {
        cout << "ReleaseDate: " << ReleaseDate
            << endl << "Manufacturer: " << Manufacturer
            << endl << "Cost: " << Cost << "$"
            << endl << "******************"
            << endl << OutsideCriteria
            << endl
            << "ScreenResolution: " << ScreenResolution
            << endl;
    }

    ~Outside() = default;

protected:

    string ScreenResolution;

};

class InsideDates : virtual public Inside {
public:

    InsideDates(int ReleaseDate, string Manufacturer, double Cost, int CoresNumber, int RAM = 0)
        : Computer(ReleaseDate, Manufacturer, Cost),
        Inside(ReleaseDate, Manufacturer, CoresNumber), RAM(RAM) {

    }

    int getRAM() const {
        return RAM;
    }

    void setRAM(double ram) {
        RAM = ram;
    }

    virtual void output() override {
        cout << "ReleaseDate: " << ReleaseDate
            << endl << "Manufacturer: " << Manufacturer
            << endl << "Cost: " << Cost << "$"
            << endl << "******************"
            << endl << getInsideCriteria()
            << endl
            << "CoresNumber: " << CoresNumber
            << endl << "RAM: " << RAM << " GB"
            << endl;
    }

    ~InsideDates() = default;

protected:

    int RAM;
};

class OutsideDates : virtual public Outside {
public:

    OutsideDates(int ReleaseDate, string Manufacturer, double Cost, string ScreenResolution, double ScreenInchSize = 13.0)
        : Computer(ReleaseDate, Manufacturer, Cost),
        Outside(ReleaseDate, Manufacturer, Cost, ScreenResolution), MonitorDiameter(MonitorDiameter) {

    }

    double getMonitorDiameter() const {
        return MonitorDiameter;
    }

    void setMonitorDiameter(double monitorDiameter) {
        MonitorDiameter = monitorDiameter;
    }

    virtual void output() override {
        cout << "ReleaseDate: " << ReleaseDate
            << endl << "Manufacturer: " << Manufacturer
            << endl << "Cost: " << Cost << "$"
            << endl << "******************"
            << endl << getOutsideCriteria()
            << endl << "ScreenResolution: " << ScreenResolution
            << endl << "Monitor size: " << MonitorDiameter << " dm"
            << endl;
    }

    ~OutsideDates() = default;

protected:

    double MonitorDiameter;
};

class SetInformation : public InsideDates, public OutsideDates {
public:

    SetInformation(SetInformation& other) : OutsideDates(other), InsideDates(other), Outside(other), Inside(other), Computer(other) {
        this->ReleaseDate = other.ReleaseDate;
        this->Manufacturer = other.Manufacturer;
        this->Cost = other.Cost;
        this->CoresNumber = other.CoresNumber;
        this->ScreenResolution = other.ScreenResolution;
        this->RAM = other.RAM;
        this->MonitorDiameter = other.MonitorDiameter;
        this->Color = other.Color;
    }

    SetInformation(int ReleaseDate = 0, string Manufacturer = "Not entered", double Cost = 10.0, int CoresNumber = 5, string ScreenResolution = "4k", int RAM = 0, double MonitorDiameter = 13.0, string Color = "enter color please")
        : Computer(ReleaseDate, Manufacturer, Cost),
        Inside(ReleaseDate, Manufacturer, Cost, CoresNumber),
        Outside(ReleaseDate, Manufacturer, Cost, ScreenResolution),
        InsideDates(ReleaseDate, Manufacturer, Cost, CoresNumber, RAM),
        OutsideDates(ReleaseDate, Manufacturer, Cost, ScreenResolution, MonitorDiameter), Color(Color) {

    }

    string getColor() const {
        return Color;
    }

    void setColor(string color) {
        Color = color;
    }

    void inputData() {
        cout << endl << "Enter ReleaseDate: ";
        cin >> ReleaseDate;
        cout << endl << "Enter Cost: ";
        Cost = inputSMTH(Cost);
        cout << endl << "Enter Manufacturer: ";
        cin >> Manufacturer;
        cout << endl << "Enter CoresNumber: ";
        CoresNumber = inputSMTH(CoresNumber);
        cout << endl << "Enter Screen Resolution: ";
        cin >> ScreenResolution;
        cout << endl << "Enter RAM: ";
        RAM = inputSMTH(RAM);
        cout << endl << "Enter Monitor Size: ";
        MonitorDiameter = inputSMTH(MonitorDiameter);
        cout << endl << "Enter Color: ";
        cin >> Color;
        cout << endl;
    }

    virtual void output() override {
        cout << "ReleaseDate: " << ReleaseDate
            << endl << "Manufacturer: " << Manufacturer
            << endl << "Cost: " << Cost << "$"
            << endl << "******************"
            << endl << getInsideCriteria()
            << endl
            << "CoresNumber: " << CoresNumber
            << endl << "RAM: " << RAM << " GB"
            << endl << "******************"
            << endl << getOutsideCriteria()
            << endl << "ScreenResolution: " << ScreenResolution
            << endl << "Monitor size: " << MonitorDiameter << " dm"
            << endl << "Color: " << Color
            << endl;
    }

    virtual ~SetInformation() {
        //cout << "Destructor was activated" << endl;
    };

protected:
    string Color;
};

int main() {

    int Number = 0;
    char* Massiv;
    cout << "Enter number of computers please: ";
    cin >> Number;

    SetInformation* num = new SetInformation[Number]();

    for (int i = 0; i < Number; i++) {
        cout << "Enter Data for number" << i << ":" << endl;
        num[i].inputData();
    }

    for (int i = 0; i < Number; i++) {
        cout << endl << endl << "number" << i << ":" << endl;
        num[i].output();
    }

    return 0;
}
