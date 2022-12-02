#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "windows.h"
int tArr[100], tm1;
int t, t1;
#define clear() system("cls")
int Array[10][10];
int arr[5][5];
int N;
int *ptArray = &Array[0][0];
using namespace std;

void PrintArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << Array[i][j];
        cout << endl;
    }
    cout << endl;
}

void Copy1d4(int x, int y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++)
            arr[i][j] = Array[i + x * (N / 2)][j + y * (N / 2)];
    }
}

void Move1d4(int x1, int y1, int x2, int y2) { //откуда - куда
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++)
            Array[i + x2 * (N / 2)][j + y2 * (N / 2)] = Array[i + x1 * (N / 2)][j + y1 * (N / 2)];
    }
}

void Write1d4(int x, int y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++)
            Array[i + x * (N / 2)][j + y * (N / 2)] = arr[i][j];
    }
}

void WriteSnail() {
    int k = 1;
    int i = 0;
    int j = 0;
    while (k <= N * N) {

        Array[i][j] = 1 + rand() % 100;
        if (i <= j + 1 && i + j < N - 1)
            j++;
        else if (i < j && i + j >= N - 1)
            i++;
        else if (i >= j && i + j > N - 1)
            --j;
        else
            --i;
        ++k;
        clear();
        PrintArr();
        Sleep(100);
        cout << endl;
    }
}

void WriteSnake() {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                Array[j][i] = 1 + rand() % 100;
                clear();
                PrintArr();
                Sleep(100);
            }
        } else {
            for (int j = N - 1; j >= 0; --j) {
                Array[j][i] = 1 + rand() % 100;
                clear();
                PrintArr();
                Sleep(100);
            }
        }

    }
}

void ClearArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            Array[i][j] = 0;
    }
}

void SortArr() {
    tm1=0;
    for (int i = 0; i < 100;i++){
        tArr[i] = 99999;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tArr[tm1] = Array[i][j];
            tm1++;
        }
    }
        int key = 0;
        int i = 0;
        for(int j = 1;j<100;j++){
            key = tArr[j];
            i = j-1;
            while(i>=0 && tArr[i]>key){
                tArr[i+1] = tArr[i];
                i = i-1;
                tArr[i+1]=key;
            }
        }
    tm1 = 0;
    for (int x = 0; x < N; x++) {
        for (int j = 0; j < N; j++) {
            Array[x][j] = tArr[tm1];
            tm1++;
        }
    }
}


int main() {

    cout << "Set the size of the array" << endl;
    cout << "N = ";
    cin >> N;
    cout << endl;
    cout << "Specify how to populate an array\n1. Snail\n2. Snake";
    cin >> t;
    switch (t) {
        case 1: {
            ClearArr();
            WriteSnail();
            break;
        }
        case 2: {
            ClearArr();
            WriteSnake();
            break;
        }
    }
    while (true) {
        cout << "Choose what to do:\n"
                "1.Fill in the matrix\n"
                "2.Rearrange the blocks\n"
                "3.Sorting\n"
                "4.Change numbers\n";
        cin >> t;
        switch (t) {
            case 1: {
                cout << "Specify how to populate an array\n1. Snail\n2. Snake";
                cin >> t;
                switch (t) {
                    case 1: {
                        ClearArr();
                        WriteSnail();
                        break;
                    }
                    case 2: {
                        ClearArr();
                        WriteSnake();
                        break;
                    }
                }
                break;
            }
            case 2: {
                cout << "Choose a permutation method";
                cin >> t;
                switch (t) {
                    case 1: {
                        Copy1d4(0, 0);
                        Move1d4(0, 1, 0, 0);
                        Move1d4(1, 1, 0, 1);
                        Move1d4(1, 0, 1, 1);
                        Write1d4(1, 0);
                        PrintArr();
                        break;
                    }
                    case 2: {
                        Copy1d4(0, 0);
                        Move1d4(1, 1, 0, 0);
                        Write1d4(1, 1);
                        Copy1d4(0, 1);
                        Move1d4(1, 0, 0, 1);
                        Write1d4(1, 0);
                        PrintArr();
                        break;
                    }
                    case 4: {
                        Copy1d4(0, 0);
                        Move1d4(0, 1, 0, 0);
                        Write1d4(1, 1);
                        Copy1d4(0, 1);
                        Move1d4(1, 0, 0, 1);
                        Write1d4(1, 0);
                        PrintArr();
                        break;
                    }
                    case 3: {
                        Copy1d4(0, 0);
                        Move1d4(1, 0, 0, 0);
                        Write1d4(1, 0);
                        Copy1d4(0, 1);
                        Move1d4(1, 1, 0, 1);
                        Write1d4(1, 1);
                        PrintArr();
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "Sort\n";
                SortArr();
                PrintArr();
                break;
            }
            case 5: {
                PrintArr();
                break;
            }
            case 4: {
                cout << "what to do with the array?\n"
                        "1. reduce\n"
                        "2. enlarge\n"
                        "3. multiply\n"
                        "4. split";
                cin >> t;
                cout << "enter the number";
                cin >> t1;
                switch (t) {
                    case 1: {
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < N; j++) {
                                Array[i][j] = Array[i][j] - t1;
                            }
                        }
                        break;
                    }
                    case 2: {
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < N; j++) {
                                Array[i][j] = Array[i][j] + t1;
                            }
                        }
                        break;
                    }
                    case 3: {
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < N; j++) {
                                Array[i][j] = Array[i][j] * t1;
                            }
                        }
                        break;
                    }
                    case 4: {
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < N; j++) {
                                Array[i][j] = Array[i][j] / t1;
                            }
                        }
                        break;
                    }
                }
                PrintArr();
                break;
            }
        }
    }
}
