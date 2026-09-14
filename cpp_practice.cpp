#include <iostream>

using namespace std;

void BaiKiemTra() {
    long long n, k, p, q;
    if (!(cin >> n >> k >> p >> q)) return;

    
    long long alice_seat = 2 * (p - 1) + q;
    long long bob_front = alice_seat - k;
    long long bob_behind = alice_seat + k;

    bool valid_front = (bob_front >= 1);
    bool valid_behind = (bob_behind <= n);
    long long chosen_seat = -1;
    if (valid_front && valid_behind) {
        chosen_seat = bob_front;
    } else if (valid_front) {
        chosen_seat = bob_front;
    } else if (valid_behind) {
        chosen_seat = bob_behind;
    }

    if (chosen_seat == -1) {
        cout << -1 << "\n";
    } else {
        long long v = (chosen_seat + 1) / 2;       
        long long u = (chosen_seat % 2 == 1) ? 1 : 2; 
        cout << v << " " << u << "\n";
    }
}

void LaiTienGui(){
    long long x,y,z;
    cin >> x >> y >> z;
     long long LaiXuat = x + (x*y*z)/(100*12);
     long long result = (long long)LaiXuat;
     cout << result;

}

void CatAndAnt(){
    long long xxx, yy;
    cin >> xxx >> yy;
    long long m = (6*xxx - yy) / 2;
    long long k = xxx - m;

    cout << m << " " << k;

}







int main() {
   
    return 0;
}