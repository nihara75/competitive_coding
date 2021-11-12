/*
AlphaCode-Question
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code
*/







#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000000 + 7;

ll numcodes(int* arr,int size,int* temp){
    if(size == 0){
        return 1;
    }
    if(size == 1){
        return 1;
    }
    if(temp[size] > 0){
        return temp[size];
    }
    ll output = 0;
    if(arr[size-1] != 0){
        output = numcodes(arr,size-1,temp)%mod;
    }
    
    
    if(arr[size-2]*10 + arr[size-1] <= 26 && arr[size-2] != 0){
        output += numcodes(arr,size-2,temp)%mod;
        output %= mod;
    }
    
    temp[size] = output;
    return output;
} 

int main()
{
    while(true){
        string s;
        cin >> s;
        int* temp = new int[s.size()+1]();
        if(s == "0"){
            break;
        }else{
            int* arr = new int[s.length()];
            for(int i=0;i<s.length();i++){
                arr[i] = s[i]-'0';
            }
            cout << numcodes(arr,s.size(),temp) << endl;
        }
        
    }
    return 0;
}