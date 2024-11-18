#include <iostream>
#include "Angle.h"
#include "Triangle.h"
using namespace std;
#include <windows.h> 

void printLogo() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    cout<<"Triangle" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void pause() {
    bool flag = true;
    int way;
    do {
        cout << "Enter 0 to go back" << endl;
        cin >> way;
        switch (way) {
        case 0:
            flag = false;
            break;
        default:
            break;
        }
    } while (flag);
}

void method1(Triangle& tr) {
    double a;
    cin >> a;
    tr.setA(a);
}
void method2(Triangle& tr) {
    double a;
    cin >> a;
    tr.setB(a);
}
void method3(Triangle& tr) {
    double a;
    cin >> a;
    tr.setC(a);
}
void method4(Triangle& tr) {
    cout << "Height to A: " << tr.heightA() << "\t" << "Height to B: " << tr.heightB() << "\t" << "Height to C: " << tr.heightC() << endl;
    pause();
}
void method5(Triangle& tr) {
    cout << "Square:  " << tr.square() << endl;
    pause();
}
void method6(Triangle& tr) {
    cout << tr.perimeter() << endl;
    pause();
}
void method7(Triangle& tr) {
    cout << "Is Euilateral? " << tr.isEuilateral() << endl;
    cout << "Is Isosceles? " << tr.isIsosceles() << endl;
    cout << "Is Rectangular? " << tr.isRectangular() << endl;
    pause();
}
void method8(Triangle& tr) {

}
void method9(Triangle& tr) {

}

void method10(Triangle& tr) {

}

void showMenu() {
    cout << "Select a method to execute:" << endl;
    cout << "1. Set a side" << endl;
    cout << "2. Set b side" << endl;
    cout << "3. Set c side" << endl;
    cout << "4. Get all height" << endl;
    cout << "5. Get square" << endl;
    cout << "6. Get perimetr" << endl;
    cout << "7. Get type" << endl;
    cout << "0. Exit" << endl;
}


int main() {
    printLogo();
    double a, b, c;
    /*cin >> len;
    a = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }
    Set set;
    set = Set(a, len);
    cout << set;*/
    ////float X, Y, Z;
    int way = 0;
    cout << "Let's start!" << endl;
    cout << "How do you want to create Triangle?" << endl;
    cout << "1. Enter it sides" << endl;
    cout << "Enter 1" << endl;
    cin >> way;
    system("cls");
    printLogo();
    bool flag = false;
    while (!flag) {
        switch (way)
        {
        case 1:
            cout << "Enter a, b, c by space" << endl;
            //cin >> X >> Y >> Z;
            cin >> a >> b >> c;
            flag = true;
            break;
        default:
            cout << "Try again later" << endl;
            int o = 1;
            while (o != 0) {
                cout << "Enter 0 if you want to Escape from the Set" << endl;
                cin >> o;
            }
            return 0;
            break;
        }
    }
    ////Vector3D vector = Vector3D();
    Triangle tr{2,2,3};
    switch (way)
    {
    case 1:
        //vector = Vector3D(X, Y, Z);
        //cout << len << endl;
        tr = Triangle(a,b,c);
        break;
    default:
        break;
    }

    system("cls");
    int choice = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do {
        system("cls");
        printLogo();
        cout << "Current triangle:" << '\t';
        SetConsoleTextAttribute(hConsole, 12);
        cout << tr << endl;
        SetConsoleTextAttribute(hConsole, 15);
        showMenu();

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            method1(tr);
            break;
        case 2:
            method2(tr);
            break;
        case 3:
            method3(tr);
            break;
        case 4:
            method4(tr);
            break;
        case 5:
            method5(tr);
            break;
        case 6:
            method6(tr);
            break;
        case 7:
            method7(tr);
            break;
        case 0:
            cout << "Leaving the programm." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

}


