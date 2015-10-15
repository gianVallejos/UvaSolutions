//UVa 10940 - Throwing cards away II
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a) for(int i = 0; i < a; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi cardsAns;
const int _size = 500000 + 1;
void generateAllCardsAns(){
	int exponente, aux, exp;
	vi prev;
	cardsAns.pb(2);
	exponente = 0;
	while( cardsAns.size() < _size ){
        exp = (int)pow(2, exponente);
		cardsAns.insert(cardsAns.end(), cardsAns.end() - exp , cardsAns.end());
		aux = cardsAns[cardsAns.size()-1];
		REP(i, exp){
		   aux += 2;
		   cardsAns.pb(aux);
		}
		exponente++;
	}
	cardsAns.insert(cardsAns.begin(), 1);
}

int main(){

    generateAllCardsAns();

    int nro;
    while( scanf("%d", &nro) && nro != 0 ){
        printf("%d\n", cardsAns[nro-1]);
    }
    return 0;
}
