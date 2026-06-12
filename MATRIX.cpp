// Create a Matrix class and overload + operator. 

#include <iostream> 
using namespace std;

class Matrix {
private:
    int row, col;
    int arr[10][10];
public:
    void input() {
        cout << "Enter rows: ";
        cin >> row;
        cout << "Enter columns: ";
        cin >> col;

        cout << "Enter matrix values horizontally: " << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j];
            }
        }
    }
    void display() {
        for (int i = 0; i < row; i++) {
            cout << "|";
            for (int j = 0; j < col; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
    Matrix operator+(const Matrix& obj) {
        Matrix m;
        m.row = row;
        m.col = col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                m.arr[i][j] = arr[i][j] + obj.arr[i][j];
            }
        }
        return m;
    }

};

int main()
{
    Matrix m1, m2, m3;

    cout << "MATRIX 1" << endl;
    m1.input();
    m1.display();

    cout << "MATRIX 2" << endl;
    m2.input();
    m2.display();

    cout << "MATRIX 3" << endl;
    m3 = m1 + m2;
    m3.display();

    return 0;
}
