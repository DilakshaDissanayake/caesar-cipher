/*Program    : Assignment 02 - The Caesar Cipher
  programmer : Dilaksha Dissanayaka - GAM/IT/2020/P/0047
  Date       : 11/13/2022 - end of the code 11/18/2022
*/
#include <iostream>
using namespace std;

class CaesarCipher{  //01. create class and protected variables

    protected:
        string plain_text ;
        int shift_key;

    public: //02. create public method
        string Encrypt(string a , int b){
            plain_text =a;
            shift_key = b;

            string result="";

            if(shift_key > 25){ // 04. user input number Greater than 25 check
                return "\n Invalid Key!";
            }
            else if(shift_key < 0){ //user input number lesthan 0 check
                return "\n Invalid Key!";
            }
            else{
                cout << "line " << plain_text.length() <<endl;
                for(int i = 0; i<plain_text.length(); i++){
                    if (isspace(plain_text[i])){           //05.add to check space 
                        result += char(32);
                    }
                    if (isupper(plain_text[i])){
                        result += char(int(plain_text[i] + shift_key - 65) % 26 + 65);  //palin text check one by one leters uppercase 
                    }
                    else{
                        result += char(int(plain_text[i] + shift_key - 97) % 26 + 97);  //palin text check one by one leters lowercase 
                    }
                
                }
                cout <<"\n"<<endl;
                cout <<"Text- "<<plain_text<<endl; 
                cout <<"Shift Key- "<<shift_key<<endl;
            return result;
            }
        }

};

int main()
{
    string a; //Assign user input Plain text
    int b; //Assign user input shift key

    CaesarCipher Cipher; // 03.a Create Objects

    cout <<"Please Enter the you wont Encrypted text  := ";
    getline(cin, a);  //03.b user enter encrypted text

    cout <<"Please Enter the Shift Key (______Caution system must be accepted 1 to 25!________)  := ";
    cin >>b; //03.c user enter Shift key


    string result = Cipher.Encrypt(a,b);    //03.d call encryption with parameters
    cout <<"Encrypt Text is: "<<result<<endl;

    return 0 ;
}
