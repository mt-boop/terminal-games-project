2#include<bits/stdc++.h>
using namespace std;

int main() {
    int h,p;
    int thoigiantroiqua;
    cin >> h >> p;
    if (h < 0 || h >= 24 || p < 0 || p >= 60 ) {
        cout << "sai roi bn oi";
        return 0;
    }
    	thoigiantroiqua = h * 60 + p;
    cout << "thoi gian da troi qua: " << thoigiantroiqua << " phut";
    return 0;
}