#include <iostream>
#include <string>
using namespace std;

class Array{
    
    public:
    unsigned char a_arr[100];
    void fill(int value, int n){
        for(int i = 0; i < 100; i++){
            a_arr[i] = 0;
        }
        for(int i = 0; i < n; i++){
            a_arr[i] = value;
        }
    }
    
    virtual string summa(){
        int summa = 0, a;
        for(int i = 0; i < sizeof(a_arr); i++){
            if(a_arr[i] != 0){
                a = (int)a_arr[i] - 48;
            }
            summa += a;
            a = 0;
        }
        auto tmp = to_string(summa);
        return tmp;
    }
};

class Money : Array{
public:
long rub;
unsigned char kop[2];
Money(){
    rub = 123;
    kop[0] = 1; kop[1] = 2;
}
virtual string summa(){
    float summa, kops;
    kops = (float)(((int)kop[0] - 48)*10 + ((int)kop[1] - 48)) / 100;
    summa = float(rub + kops);
    auto tmp_2 = to_string(summa);
    return tmp_2;
}
};

class String : Array{
public:
int count;
unsigned char str[100];
String(){
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
}
virtual string summa(){
    string sum = "";
    for(int i = 0; i < count; i++){
        sum.push_back(str[i]);
    }
    return sum;
}
};

int main(){
    int size;
    Array a;
    a.fill(5, 5);
    cout << a.summa() << endl;
    Money m = Money();
    cout << m.summa() << endl;
    String str = String();
    cout << str.summa() << endl;
}