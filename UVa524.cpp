//UVa 524 - Prime Ring Problem
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a) for(int i = 0; i < a; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, cases;
inline bool isPrime(int number){
    if( number == 1 ) return false;
    for( int i = 2; i <= sqrt(number); i++ ){
        if( number % i == 0 ) return false;
    }
    return true;
}

inline bool existsInArray(vi array, int number){
    int bits = 0;
    REP(i, array.size()){
        bits |= (1<<array[i]);
    }
    return (bits & (1<<number));
}

void rings(vi &array, int &_size){
    if( _size == n ){
        if( isPrime(array[0] + array[array.size()-1]) ){
            REP(i, array.size()){
                if( i != 0 ) printf(" ");
                printf("%d", array[i]);
            }
            printf("\n");
        }
    }else{
        const int ind = _size - 1;
        for( int i = 2; i <= n; i++ ){
            if( !existsInArray(array, i) && isPrime(array[ind] + i ) ){
                array.pb(i);
                _size++;
                rings(array, _size);
                array.pop_back();
                _size--;
            }
        }
    }
}

int main(){
    cases = 1;
    int _size;
    while( ~scanf("%d", &n) ){
        vi array;
        array.pb(1);
        if( cases != 1 ) printf("\n");
        printf("Case %d:\n", cases++);
        _size = 1;
        rings(array, _size);
    }
    return 0;
}
