#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     vector<string> ones = {
        "", "One", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen", "Seventeen","Eighteen",
         "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty","Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string solve(long long n){
        if(n==0){
            return "";
        }
   
      if(n<20){
            return ones[n];
        }

        if(n < 100){
            string ans =tens[n / 10];
            if (n % 10){
                ans += " "+ solve(n % 10);
            }
              return ans;
        }

        if(n < 1000){
            string ans = solve(n / 100) + " Hundred";
             if (n % 100){
                ans +=" " + solve(n % 100);
            }
        return ans;
        }

        if(n < 100000){
            string ans = solve(n / 1000) + " Thousand";

            if (n % 1000){
                ans += " " + solve(n % 1000);
            }
            return ans;
        }

        if(n < 10000000){
            string ans = solve(n / 100000) + " Lakh";
            if (n % 100000){
                    ans += " " + solve(n % 100000);
                }
            return ans;
        }

        string ans =solve(n/10000000) + " Crore";
          if(n %10000000){
            ans += " "+ solve(n % 10000000);
}
        return ans;
    }

    string numberToWords(int num){
        if(num == 0)
            return "Zero";
        if(num < 0){
            return "Negative " +solve(-(long long)num);
        }
        return solve(num);
    }
};

int main() {
    Solution obj;
    int num;
    cin >> num;
    cout << obj.numberToWords(num);

    return 0;
}
