//Uva 729 - The Hamming Distance Problem

#include <bits/stdc++.h>
using namespace std;
#define REP(i, a) for(int i = 0; i < a; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool haveNOnes(int number, int n){
    int cnt = 0;
    while( number != 0 ){
        if( (number & 1) == 1 )
            cnt++;
        number = number>>1;
    }

    return (cnt == n);
}

string toBits(int number, int n){
   string res = "", aux;
   while( number >= 2 ){
        if( number % 2 == 1 ) res += "1";
        else res += "0";
        number /= 2;
   }
   if( number == 1 ) res += "1";
   else res += "0";

   while( res.length() != n ){
        res += "0";
   }
   aux = "";
   for(int i = res.length() - 1; i >=0; i-- ){
        aux += res[i];
   }

   return aux;
}

void HammingDistance(int n, int h){
    for( int i = 0; i < (int)pow(2, n); i++ ){
       if( haveNOnes(i, h) )
            cout << toBits(i, n) << endl;
    }
}

int main(){
    int cases, n, h;

    scanf("%d", &cases);

    REP(k, cases){
        if( k != 0 ) printf("\n");
        scanf("%d %d", &n, &h);
        HammingDistance(n, h);
    }

    return 0;
}
