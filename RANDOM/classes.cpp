#include <iostream>
#include <cstring>
using namespace std;
#define print(x) cout << x << endl;


// I am Asad
// dasa ma I
// Asad am I

class ReverseWords{
    public:
        int arrayInput(char arr[100]){
            int i = 0;
            char ch;
            cout << "Enter the string: ";
            while(1){
                ch = getchar();
                if(ch == '\n'){
                    arr[i] = '\0';
                    break;
                }
                arr[i] = ch;
                i++;
            }
            return strlen(arr);
        }

        void displayString(char arr[100], int len){
            cout << "The string is: ";
            for(int i = 0; i < len; i++){
                cout << arr[i];
            }
            cout << endl;
        }

        void reverseWholeString(char arr[100], int len){
            for (int i = 0; i < len/2; i++){
                char temp = arr[i];
                arr[i] = arr[len - i - 1];
                arr[len - i - 1] = temp;
            }
        }

        void reverseWordsOnly(char arr[100], int len){
            int start = 0;
            for (int i = 0; i <= len; i++){
                if (arr[i] == ' ' || arr[i] == '\0'){
                    int end = i - 1;
                    while (start < end){
                        char temp = arr[start];
                        arr[start] = arr[end];
                        arr[end] = temp;
                        start++;
                        end--;
                    }
                    start = i + 1; 
                }
            }
        }
            
};

int main (){
    ReverseWords rw;
    char arr[100];
    int len = rw.arrayInput(arr);
    rw.displayString(arr, len);
    rw.reverseWholeString(arr, len);
    rw.displayString(arr, len);
    rw.reverseWordsOnly(arr, len);
    rw.displayString(arr, len);
    print ("End of the program");
    return 0;
}



