#include <bits/stdc++.h>

using namespace std;

int c[7] = {2, 3, 3, 5, 1, 2, 4};
int d[7] = {15, 11, 18, 16, 20, 20, 20};
int a[7] = {0, 0, 0, 0, 0, 0, 0};
int f[7] = {0, 0, 0, 0, 0, 0, 0};

//Hàm để thể hiện sự hoạt động của các tác vụ
void run() {
    cout << "Arrival time\n";
    for (int i = 0; i < 7; i++) {
        cout << a[i] << " ";
    }
    cout << "\nComputation time\n";
    for (int i = 0; i < 7; i++) {
        cout << c[i] << " ";
    }
    cout << "\nFinish time\n";
    for (int i = 0; i < 7; i++) {
        cout << f[i] << " ";
    }
    cout << "\n";
}

//Hàm tính toán thời gian bắt đầu và kết thúc của từng tác vụ theo thuật toán EDD 
void EDD() {
    int curTime = 0;
    int temp[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 7; i++) {
        temp[i] = d[i];
    }
    for (int i = 0; i < 7; i++) {
        int minIndex = 0;
        for (int j = 0; j < 7; j++) {
            if (temp[j] <= temp[minIndex]) {
                minIndex = j;
            }
        }
        a[minIndex] = curTime;
        curTime += c[minIndex];
        f[minIndex] = curTime;
        temp[minIndex] = 9999;
    }
}

int main() {
    EDD();
    run();
    return 0;
}