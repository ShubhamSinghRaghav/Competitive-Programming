/*
Crossword Problem

CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/
#include<bits/stdc++.h>
using namespace std;
#define N 10
char crossWord[N][N];
 
bool isValidHorizontal(int row, int col, string word){
	if(N - col < word.length())
		return false;
	for (int i = 0, j = col; i < word.length(); ++i,j++){
		if (crossWord[row][j] != '-' && crossWord[row][j] != word[i]){
			return false;
		}
	}
	return true;
}
 
bool isValidVertical(int row, int col, string word){
	if(N - row < word.length())
		return false;
	for (int i = row, j = 0; j < word.length(); ++i,j++){
		if (crossWord[i][col] != '-' && crossWord[i][col] != word[j]){
			return false;
		}
	}
	return true;
}
 
void setHorizontal(int row, int col, string word, bool state[]){
	for (int i = 0, j = col; i < word.size(); ++i, j++){
		if (crossWord[row][j] != '+'){
			if(crossWord[row][j] == word[i])
				state[i] = false;
			else
				state[i] = true;
			crossWord[row][j] = word[i];
		}
	}
}
 
void setVertical(int row, int col, string word, bool state[]){
	for (int i = 0, j = row; i < word.size(); ++i, j++){
		if (crossWord[j][col] != '+'){
			if(crossWord[j][col] == word[i])
				state[i] = false;
			else
				state[i] = true;
			crossWord[j][col] = word[i];
		}
	}
}
 
void resetHorizontal(int row, int col, bool state[], int size){
	for (int i = 0, j = col; i < size; ++i,j++){
		if(state[i] == true)
			crossWord[row][j] = '-';
	}
}
 
void resetVertical(int row, int col, bool state[], int size){
	for (int i = 0, j = row; i < size; ++i,j++){
		if(state[i] == true)
			crossWord[j][col] = '-';
	}
}


 
bool crossWordHelper(vector<string> input,int size, int index){
  //  cout<<index<<"->";
	if(index == size){
		for(int i =0; i<N; i++){
			for(int j=0; j<N; j++){
				cout<<crossWord[i][j] ;
			}
			cout<<"\n";
		}
		return true;
	}
 
	for(int i =0; i<N; i++){
		for(int j=0; j<N; j++){
 
			if(crossWord[i][j] == '-' || crossWord[i][j] == input[index][0]){
				
                int length = input[index].size();
				bool state[length];
                for(int k=0;k<length;k++) state[k]=false;
 
				if(isValidHorizontal(i, j, input[index])){
					setHorizontal(i, j, input[index], state);
					if(crossWordHelper(input, size, index+1)){
						return true;
					}
					resetHorizontal(i, j, state, length);
				}
 
				if(isValidVertical(i, j, input[index])){
					setVertical(i, j, input[index], state);
					if(crossWordHelper(input, size, index+1)){
						return true;
					}
					resetVertical(i, j, state, length);
				}
 
			}
		}
	}
	return false;
}
 
vector<string> splitter(string ss){
    vector<string> input;
	int pos = 0, word = 0,len=0;
	for(int i=0;i<ss.size();i++){
	    len++;
	    if(ss[i]==';'){
	       input.push_back(ss.substr(pos,len-1));
	       len=0;
	       pos=i+1;
	    }
	}
	return input;
}

int main(){
	string ss;
	for(int i = 0; i<N; i++){
		cin >>ss;
		for(int j = 0; j < ss.size(); j++){
			crossWord[i][j] =  ss[j];
		}
	}
    string s;
	cin >> s;
    s+=";";
    vector<string> inp = splitter(s);
    crossWordHelper(inp, inp.size(), 0);
return 0;
}
//0->1->2->3->2->3->
//0->1->2->3->2->3->4->