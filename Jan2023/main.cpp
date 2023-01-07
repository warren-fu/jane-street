#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// int gcd(int a, int b)
// {
//   if (a == 0)
//     return b;
//   return gcd(b % a, a);
// }
int recur(int a, int b, int c, int d, int count){
    if (a == 0 && b == 0 && c == 0 && d == 0)
        return count;
    return recur(a < b ? b-a : a-b, c < b ? b-c : c-b, c < d ? d-c : c-d, a < d ? d-a : a-d, count + 1);
}
// int GcdOfArray(vector<int>& arr, int idx)
// {
//     if (idx == arr.size() - 1) {
//         return arr[idx];
//     }
//     int a = arr[idx];
//     int b = GcdOfArray(arr, idx + 1);
//     return gcd(a, b);
// }
int main(){
    int a = 0, b, c, d, sum, M, gcd = 1;
    map<int, map<int,vector<int>>> m;
    // unordered_map<vector<int>, int> fuck;
    // for(a=0;a<69;a++){
        for(b=3000;b<3500;b++){
            for(c=b*2;c<7000;c++){
                for(d=c*2;d<14000;d++){
                    vector<int> v = {a,b,c,d};
                    // gcd = GcdOfArray(v,0);
                    // vector<int> temp = {a/gcd, b/gcd, c/gcd, d/gcd};
                    // if (fuck[temp] == 0){
                        // fuck[temp] = 1;
                        if (a%2 != 0 && b%2 != 0 && c%2 != 0 && d%2 !=0){
                            sum = a+b+c+d;
                            M = recur(a,b,c,d,1);
                            m[M][sum] = v;
                        }
                        
                    // }
                    
                }
            }
        }
    // }
    for (auto a: m){
            cout << a.first << "    " << a.second.begin()->first<< "     ";
            for (auto c: a.second.begin()->second)
                cout << c << ", ";
            cout << endl;
    }
    return 0;
}