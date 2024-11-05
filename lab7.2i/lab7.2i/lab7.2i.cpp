#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SwapMaxMin(int** a, const int n, int& sum);

int main() {
    srand((unsigned)time(NULL));
    int Low = -50; // ����� ���� ��� ��������� ��������
    int High = 50; // ������ ���� ��� ��������� ��������
    int n;

    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);

    // �������� ��������� �������
    cout << "Initial matrix:" << endl;
    Print(a, n);

    int sum = 0; // ����� ��� ��������� ����
    SwapMaxMin(a, n, sum);

    // �������� ����
    cout << "Sum of max element above and min element below diagonal = " << sum << endl;

    // ��������� ���'��
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SwapMaxMin(int** a, const int n, int& sum) {
    int maxVal = INT_MIN; // ����� ��� ��������� ������������� ��������
    int minVal = INT_MAX; // ����� ��� ��������� ���������� ��������
    int maxRow, maxCol; // ������� ������������� ��������
    int minRow, minCol; // ������� ���������� ��������

    // ����������� ������������� �������� ��� �������� ���������
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // ����������� ���������� �������� �� �������� ���������
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] < minVal) {
                minVal = a[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    // ���������� ����
    sum = maxVal + minVal;

    // ̳����� ������ ������������ � ��������� ��������
    if (maxVal != INT_MIN && minVal != INT_MAX) {
        a[maxRow][maxCol] = minVal;
        a[minRow][minCol] = maxVal;
    }

    // �������� ������������ �������
    cout << "Modified matrix after swapping max and min elements:" << endl;
    Print(a, n);
}
