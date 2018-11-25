#include<bits/stdc++.h>
using namespace std;

class Calculator{

    string input;
    string output;
    string Operation(string s1, string s2, char op);
    public:
    void take_input();
    void output_ans();

    void Calculate();
};

void Calculator::take_input(){
    cin>>input;
}
void Calculator::output_ans(){
    cout<<output;
}
void Calculator::Calculate(){

    int n = input.length();

    int i=0;
    string s="";
    string prev="";
    while(i<n){
        if(input[i]<'0'||input[i]>'9'){
            break;
        }
        prev+=input[i];
        i++;
    }
   // cout<<prev<<'\n';
    while(i<n){
        string s1="";
        char op;
        op = input[i];
        i++;
        while(i<n && (input[i]>='0'&&input[i]<='9')){
            s1+=input[i];
            i++;
        }
        if(op=='+'||op=='-'){
            s+=prev;
            s+=op;
            prev = s1;
        }
        else{
            //cout<<prev<<" "<<s1<<'\n';
            prev = Operation(prev, s1, op);
        }
    }
    s+=prev;
    //cout<<s<<' ';
    prev = "";
    i=0;
    n = s.length();
    while(i<n){
        if(s[i]<'0'||s[i]>'9'){
            break;
        }
        prev+=s[i];
        i++;
    }
    //cout<<prev<<'\n';
    while(i<n){
        string s1="";
        char op;
        op = s[i];
        i++;
        while(i<n && (s[i]>='0'&&s[i]<='9')){
            s1+=s[i];
            i++;
        }
        //cout<<prev<<" "<<s1<<'\n';
        prev = Operation(prev, s1, op);
    }

    output = prev;
}

string Calculator::Operation(string s1, string s2, char op){
    //cout<<s1<<' '<<s2<<'\n';
    int a = stoi(s1);
    int b = stoi(s2);
    int c;

    switch(op){
        case '+':
            c=a+b;
            break;
        case '-':
            c = a-b;
            break;
        case '*':
            c = a*b;
            break;
        case '/':
            c = a/b;
            break;
        default:
            break;
    }
    return to_string(c);
}

int main(){

    Calculator cal1;

    cal1.take_input();

    cal1.Calculate();

    cal1.output_ans();
    return 0;
}
