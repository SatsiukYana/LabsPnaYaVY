
#include <iostream>
using namespace std;

class Complex {

private:
    double real;


public:
    Complex() {
        real = 0;
    }

    Complex(double real) {
        this->real = real;
    }

    Complex(const Complex& other) {
        this->real = other.real;
    }

    Complex operator + (const Complex& other) const {
        return { this->real + other.real };
    }

    Complex operator - (const Complex& other) const {
        return { this->real - other.real };
    }
    Complex operator ++ (int) {
        return { real++ };
    }
    Complex operator -- (int) {
        return { real-- };
    }

    Complex& operator ++ () {
        real++;
        return *this;
    }
    Complex& operator -- () {
        real--;
        return *this;
    }

    friend bool operator !=(const Complex& first, const Complex& second)
    {
        return first.getReal() != second.getReal();
    }

    double getReal() const {
        return real;
    }
    void setReal(double reall) {
        Complex::real = reall;
    }

    friend class ComplexMatrix;
    friend ostream& operator << (ostream& out, const Complex& a);
    operator int() const { return (int)this->real; };
    operator double() const { return (double)this->real; };
    ~Complex() = default;
};
ostream& operator << (ostream& out, const Complex& a) {
    out << "Real: " << a.real << endl;
    return out;
}

class ComplexMatrix {

private:
    Complex matrix[10][10];
    int size;
public:

    ComplexMatrix() {
        size = 9;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j].real = 0;
            }
        }
    }

    explicit ComplexMatrix(int size) {
        this->size = size - 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << "[" << i + 1 << "][" << j + 1 << "]real:";   cin >> matrix[i][j].real;
                cout << endl;
            }

        }
    }

    ComplexMatrix(int size, int flag) {
        this->size = size - 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j].real = 0;
                cout << endl;
            }

        }
    }

    ComplexMatrix operator + (const ComplexMatrix& other) {
        ComplexMatrix temp;

        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                temp[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return temp;
    }

    ComplexMatrix operator - (const ComplexMatrix& other) {
        ComplexMatrix temp;

        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                temp[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }
        return temp;
    }


    ComplexMatrix operator ++ (int) const {
        ComplexMatrix temp;

        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                temp[i][j]++;
            }
        }
        return temp;
    }

    ComplexMatrix operator -- (int) const {
        ComplexMatrix temp;

        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                temp[i][j]--;
            }
        }
        return temp;
    }


    Complex* operator [](const int index)
    {
        return matrix[index];
    }

    friend bool operator ==(const ComplexMatrix& first, const ComplexMatrix& second)
    {
        bool equal = true;
        for (int i = 0; i <= first.size; i++)
        {
            for (int j = 0; j <= first.size; j++)
            {
                if (first.matrix[i][j] != second.matrix[i][j])
                    equal = false;
            }
        }
        return equal;
    }

    ComplexMatrix operator = (const ComplexMatrix& other) {
        ComplexMatrix temp;

        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                temp[i][j] = this->matrix[i][j] = other.matrix[i][j];
            }
        }
        return temp;
    }

    
        void PrintMatrix(int sizeToPrint) {
        for (int i = 0; i <= sizeToPrint - 1; i++) {
            cout << endl;
            for (int j = 0; j <= sizeToPrint - 1; j++) {
                cout << "[" << i + 1 << "][" << j + 1 << "] = " << matrix[i][j].real;
            }
        }
    }
};


void menuChoice() {
    cout << endl << endl << "1. Choose operation to do with matrix" << endl << "2. Show source matrix" << endl << "3. exit" << endl;
}
void optionToDo() {
    cout << endl << "Operations with matrix: "
        << endl << "1. +"
        << endl << "2. -"
        << endl << "3. ++(postfix) /for complex number"
        << endl << "4. --(postfix) /for complex number"
        << endl << "5. operator <<"
        << endl << "6. == "
        << endl << "7. = "
        << endl << "8. from double to int"
        << endl << endl;
}

int main() {

    int size;
    cout << "Enter the size of matrix: ";
    cin >> size;
    cout << "Input of matrix 1" << endl;
    ComplexMatrix matrix1(size);

    cout << "Matrix 1:" << endl << endl;
    matrix1.PrintMatrix(size);

    cout << endl << endl << "Input of matrix 2" << endl;
    ComplexMatrix matrix2(size);

    cout << endl << endl << "Matrix 2:" << endl << endl;
    matrix2.PrintMatrix(size);
    Complex complexShow(5);
    ComplexMatrix resultMatrixSum(size, 1);
    ComplexMatrix resultMatrixExtract(size, 1);
    ComplexMatrix resultMatrixRavno(size, 1);
    Complex  result(3.4);
    int menuchoice = 0;

    do {
        menuChoice();
        cin >> menuchoice;
        Complex a(2), b(1), c, number(10);
        switch (menuchoice) {
        case 1:
            optionToDo();
            int optiontodo; cin >> optiontodo;

            switch (optiontodo) {
            case 1:
                resultMatrixSum = matrix1 + matrix2;
                cout << endl << "Result matrix:" << endl << endl;
                resultMatrixSum.PrintMatrix(size);
                break;

            case 2:
                resultMatrixExtract = matrix1 - matrix2;
                cout << endl << "Result matrix:" << endl << endl;
                resultMatrixExtract.PrintMatrix(size);
                break;

            case 3:
                cout << "ComplexNumber: " << complexShow << endl;
                cout << "ComplexNumber++" << endl;
                complexShow++;
                cout << "ComplexNumber: " << complexShow << endl;
                break;

            case 4:
                cout << "ComplexNumber: " << complexShow << endl;
                cout << "ComplexNumber--" << endl;
                complexShow--;
                cout << "ComplexNumber: " << complexShow << endl;
                break;

            case 5:
                cout << "Example of overloading << :" << endl;
                cout << number << endl;
                break;
            case 6:
                if (matrix1 == matrix2)
                    cout << "The same\n";
                else
                    cout << "Not the same\n";
                break;
            case 7:
                matrix1 = matrix2;
                resultMatrixRavno = matrix1;
                cout << endl << "Result matrix:" << endl << endl;
                resultMatrixRavno.PrintMatrix(size);
                break;
            case 8:
                cout << "ComplexNumber: " << result << endl;
                cout << "ComplexNumber(int)" << endl;
                (int)result;
                cout << "ComplexNumber: " << (int)result << endl;
                break;
            default:
                break;
            }
            break;
        case 2:
            cout << "Matrix 1:" << endl << endl;
            matrix1.PrintMatrix(size);
            cout << endl << endl << "Matrix 2:" << endl << endl;
            matrix2.PrintMatrix(size);
            break;
        default:
            break;
        }
    } while (menuchoice != 3);
    return 0;
}