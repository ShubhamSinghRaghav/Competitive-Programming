/*
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, 
not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

int countPalindromeSubstrings(char s[]){
    int n = -1;
    while(s[++n]);
    int c = 0;
    //if(n%2!=0){
        for(int i=0;i<n;i++){
            int l = i-1;
            int r = i+1;
           // if(s[i]==s[l])c++;
            //if(s[i]==s[r])c++;
            while(l>=0 and r<n and s[l]==s[r]){
                c++;
                l--;
                r++;
            }
        }
       // if(s[0]==s[1]) c++;
       // if(s[n-1]==s[n-2]) c++;
    //}else{
        for(int i=0;i<n;i++){
            int l = i-1;
            int r = i+2;
            if(i+1<n and s[i]==s[i+1]){
                c++;
            	while(l>=0 and r<n and s[l]==s[r]){
                    c++;
                    l--;
                    r++;
                }
            }
        }
        //if(s[0]==s[1]) c++;
        //if(s[n-1]==s[n-2]) c++;
    //}
    return c+n;
}
