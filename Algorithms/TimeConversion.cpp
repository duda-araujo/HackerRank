#include <bits/stdc++.h>


using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    char ampm = s[8]; //A ou P
    
    string hora_str = s.substr(0, 2);
    int hora_int = stoi(hora_str);
    
    //1-11h am e 12pm nao precisa alterar
    //12am = 00:00
    //1-11pm = hora +12
    if(ampm == 'P' && hora_int != 12)
        hora_int += 12;
    else if(ampm == 'A' && hora_int == 12)
        hora_int = 0;
        
    if(hora_int < 10)
        hora_str = "0" + to_string(hora_int);
    else
        hora_str = to_string(hora_int);
    
    s.erase(8, 2); //apagar AM ou PM da string para imprimir
    s.replace(0, 2, hora_str); //substituir a hora no formato 24h
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
