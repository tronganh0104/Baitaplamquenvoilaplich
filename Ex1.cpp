#include <bits/stdc++.h>

using namespace std;

int c[7] = {2, 3, 3, 5, 1, 2, 4};
int d[7] = {15, 11, 18, 16, 20, 20, 20};
int a[7] = {0, 0, 0, 0, 0, 0, 0};
int f[7] = {0, 0, 0, 0, 0, 0, 0};
int L[7] = {0, 0, 0, 0, 0, 0, 0};
int E[7] = {0, 0, 0, 0, 0, 0, 0};

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

//Hàm xác định arrival time và finish time của từng tác vụ để thời gian trả về trung bình là nhỏ nhất
//Ta sẽ cho các tác vụ có sự ước tính thời gian nhỏ hơn chạy trước
void findArrivalFinish() {
    int temp[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 7; i++) {
        temp[i] = c[i];
    }
    int curTime = 0;
    for (int i = 0; i < 7; i++) {
        int minIndex = 0;
        for (int j = 0; j < 7; j++) {
            if (temp[minIndex] >= temp[j]) {
                minIndex = j;
            }
        }
        a[minIndex] = curTime;
        curTime += temp[minIndex];
        f[minIndex] = curTime;
        temp[minIndex] = 9999;
    }
}

//Hàm dùng để tính độ trễ lớn nhất
void findMaxLateness() {
    int maxL = -1;
    for (int i = 0; i < 7; i++) {
        L[i] = f[i] - d[i];
        if (L[i] > maxL && L[i] >= 0) {
            maxL = L[i];
        }
    }
    cout << "Max lateness: " << maxL << "\n";
}

//Hàm tìm ra thời gian vượt trội của từng tác vụ
void findExceedingTime() {
    cout << "Exceeding time\n";
    for (int i = 0; i < 7; i++) {
        E[i] = max(0, L[i]);
        cout << E[i] << " ";
    }
    cout << "\n";
}

int main() {
    
    findArrivalFinish();
    run();
    findMaxLateness();
    findExceedingTime();
    return 0;
}