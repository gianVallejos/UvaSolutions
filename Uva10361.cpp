//Uva10361 - Automatic Poetry
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a) for(int i = 0; i < a; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void generateSolution(string &line1, string &line2){
    string s1, s2, s3, s4, s5, aux;
    bool firstLeft = false, firstRight = false;
    aux = "";
    REP(i, line1.length()){
        if( line1[i] == '<' && !firstLeft ){
            s1 = aux; aux = ""; firstLeft = true;
        }else if( line1[i] == '>' && !firstRight ){
            s2 = aux; aux = ""; firstRight = true;
        }else if( line1[i] == '<' && firstLeft ){
            s3 = aux; aux = "";
        }else if( line1[i] == '>' && firstRight ){
            s4 = aux; aux = "";
        }else{
            aux += line1[i];
        }
    }
    s5 = aux;
    aux = "";
    REP(i, line2.length()-2){
        if( line2[i] == '.' && line2[i+1] == '.' && line2[i+2] == '.' )
            break;
        aux += line2[i];
    }
    cout << s1 << s2 << s3 << s4 << s5 << endl << aux << s4 << s3 << s2 << s5 << endl;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    string line1, line2;

    scanf("%d\n", &n);
    while( n-- ){
        getline(cin, line1);
        getline(cin, line2);

        generateSolution(line1, line2);
    }
    return 0;
}
