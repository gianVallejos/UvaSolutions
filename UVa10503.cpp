//UVa 10503 - The Dominoes Solitarie
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a) for(int i = 0; i < a; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class Piece{
public:
 	int head, tail;
	Piece(int h, int t){
	   head = h;
	   tail = t;
	}
};
vector <Piece> pieces;
int m, i1, i2, d1, d2;
bool flag;
void isPossible(int n, int nroActual, bool hashPieces[] ){
    if( n == 0 ){
        if( nroActual == i2 )
            flag = true;
    }
    else if( n < 0 ){ return; }
    else{
        for( int i = 0; i < m; i++ ){
           if( !hashPieces[i] ){
               if( nroActual == pieces[i].head ){
                    hashPieces[i] = true;
                    isPossible(n - 1, pieces[i].tail, hashPieces);
                    hashPieces[i] = false;
               }else if( nroActual == pieces[i].tail){
                    hashPieces[i] = true;
                    isPossible(n - 1, pieces[i].head, hashPieces);
                    hashPieces[i] = false;
               }
           }
        }
    }
}

int main(){
    int n, a, b;
    while( scanf("%d", &n), n){
    	scanf("%d %d %d %d %d", &m, &i1, &i2, &d1, &d2);
        pieces.clear();
        REP(i, m){
            scanf("%d %d", &a, &b);
            Piece p(a, b);
            pieces.pb(p);
        }

        flag = false;

        bool hashPieces[m+5];
        memset(hashPieces, false, sizeof(hashPieces));

        isPossible(n, d1, hashPieces);
        (flag) ? printf("YES\n") : printf("NO\n");

    }
    return 0;
}
