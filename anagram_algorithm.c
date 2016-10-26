/*Code by John Kaehler*/

#include <string>
#include <iostream>

using namespace std;

int number_needed(string a, string b) {
   int returnVal = 0;
   int a_length = a.length();
   int b_length = b.length();
   int a_occurrences[26];
   int b_occurrences[26];


   /*First we need to initialize each array index to 0*/
   for(int i=0; i < 26; i++){
        a_occurrences[i] = 0;
        b_occurrences[i] = 0;
   }

   for(int i=0; i < a_length; i++){
        int index = a[i]%26;
        a_occurrences[index]++;
   }
   for(int i=0; i < b_length; i++){
        int index = b[i]%26;
        b_occurrences[index]++;
   }
   for(int i=0; i < 26; i++){
        if(a_occurrences[i] > b_occurrences[i]) returnVal+= (a_occurrences[i]-b_occurrences[i]);
        else if(b_occurrences[i] > a_occurrences[i]) returnVal += b_occurrences[i]-a_occurrences[i];
   }
   return returnVal;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
