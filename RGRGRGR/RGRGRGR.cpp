/*���� ������ � ��� ��� ����� �����������, � ������� ������ ������ � �������� ������ ����������
�������� ����������� �� ��������� ���������� ����� ������� ����� ��� ������ ���� � ��������.*/

#include <iostream>
using namespace std;

void cezar(char str[100])
{
    int lenth;

    lenth = strlen(str);

    for (int i = 0; i < lenth; i++) {
        if (str[i] >= 119) {
            str[i] = str[i] - 25;
            str[i] += 3;
        }
        else {
            if (str[i] == 32) {
                str[i] = 32;
            }
            else {
                str[i] += 3;
            }

        }
    }
    cout << str;
}

void dcezar(char str[100]) {

    int lenth;

    lenth = strlen(str);

    for (int i = 0; i < lenth; i++) {

        if ((str[i] <= 99) && (str[i] != 32)) {
            str[i] = str[i] + 25;
            str[i] -= 3;
        }
        else {
            if (str[i] == 32) {
                str[i] = 32;
            }
            else {
                str[i] -= 3;
            }

        }
    }
    cout << str;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char str[100];
    int a;

    cout << "������� ������ �� ���������� �����:";
    cin.get(str, 100);

    cout << "�� ������ 1)������������ ����� ��� 2)������������� ���?: ";
    cin >> a;
    if (a == 1) {
        cezar(str);
        return 0;
    }
    if (a == 2) {
        dcezar(str);
        return 0;
    }
}