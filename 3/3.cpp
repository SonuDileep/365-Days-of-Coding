//
//  main.cpp
//  C++_Code
//
//  C++ program to find occurance of a string in a document
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

///Case insensitive string comparison function
int case_insensitive_match(string s1, string s2) 
{
   int token_length = s2.size(); 
   //convert s1 and s2 into lower case strings
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   if(s1.compare(s2) == 0)
      {
 //     cout<<s1<<s2<<endl;
      return 1; //The strings are same
      }     
   else if (s1.rfind(s2)!= string::npos)
      {
	int pos = s1.rfind(s2);
      if (pos==0)
      {
	      char input_char = s1[token_length];
            if (!((input_char >= 65 && input_char <= 90) || (input_char >= 97 && input_char <= 122)))
      {	
	            return 1;
      }}
	else
      {
            char input_char = s1[0];
            if (!((input_char >= 65 && input_char <= 90) || (input_char >= 97 && input_char <= 122)))
      {	
	            return 1;
      }}
}
      return 0;
}

      	




bool check_string(string s1, string s2)
{	
	size_t index = s2.find(s1);
	if (index!= string::npos)
{
	int token_length = s1.size();
         char input_char = s2[token_length];
         if (!((input_char >= 65 && input_char <= 90) || (input_char >= 97 && input_char <= 122)))
{
	return true;
}}
	return false; 
}


int main(int argc, const char * argv[]) {
    string filename = argv[1]; // Store the filename
    string token = argv[2]; //Token to be looked for in document
    string words;
    int count = 0; // To store count of token
    ifstream readfile;
    readfile.open(filename); //Open File
    if (readfile.is_open()) //Read File
{
     cout<<"File Read Successfully"<<endl;
     while (readfile >> words) // Read each word in the file
{
      int x = case_insensitive_match(words, token); // Compares each word to the token
      if (x==1) // x will be 0 when the word exactly matches token
{
//      cout<<x<<words<<endl;
      count++;
}

}}
     cout<<"Frequency of word \""<<token<<"\" = "<<count<<endl;
     return 0;
}
