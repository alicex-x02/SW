#include <iostream>
#include <string>

using namespace std;

void func(int* arr, int pos){
    int tmp = arr[pos + 1];

    while (pos >= 0){
        if (arr[pos] >= tmp){
            arr[pos] -= tmp;
            return;
        }
        else{
            arr[pos] = arr[pos] - tmp + 10;
            tmp = 1;
            pos--;
        }
    }
}


int main(){
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++){
        string str;
        cin >> str;
        int* arr = new int[str.length()];
       
        if (str.length() < 2){
            cout << 0 << endl;
            continue;
        }

        for (int k = 0; k < str.length(); k++){
            arr[k] = str[k] - 48;
        }

        for (int i = str.length() - 2; i >= 0; i--) {
            func(arr, i);
        }
        

        if (arr[0]){
            cout << 0 << endl;
            continue;
        }

        int j = 0;
        while (!arr[j]){
            j++;
        }

        for (j; j < str.length(); j++){
            cout << arr[j];
        }
        cout << endl;

        delete[] arr;
    }
}