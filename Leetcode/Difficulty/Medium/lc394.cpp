#include <bits/stdc++.h>
using namespace std;

//Decode String

string decodeString(string s) {
    //Use 2 stacks, 1 to store the number and another to store the character
    stack<int> num;
    stack<string> chars;
    int n = s.length();
    int i = 0;
    string res = "";
    while (i < n){
        //Check if it is a number
        if (s[i] == '[') {
            //This is how you convert a character to a string
            chars.push("[");
            i++;
        }
        else if (isalpha(s[i])) {
            //add to the result if the chars is empty
            if (chars.empty()) res += string(1, s[i]);
            else chars.push(string(1, s[i]));
            i++;
        }
        else if (s[i] == ']'){
            string temp = "";
            while (chars.top() != "["){
                temp = chars.top() + temp;
                chars.pop();
            }
            //Take the '['
            chars.pop();
            string made = "";
            int no_of_times = num.top();
            num.pop();
            for (int j=0; j<no_of_times; j++){
                made += temp;
            }
            //If it is empty
            if (chars.empty()) res += made;
            //If it is not empty (There is an outer bracket)
            else chars.push(made);
            i++;
        }
        //If it is a number
        else{
            //Can be multiple digits as well
            int pot_num = 0;
            while (isdigit(s[i])){
                int digit = s[i] - '0';
                pot_num = pot_num*10 + digit;
                i++;
            }
            num.push(pot_num);
        }
    }
    return res;
}