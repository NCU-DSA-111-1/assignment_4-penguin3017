#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <time.h> 
#include "huffman.h"
#include "arc.h"

using namespace std;


int main(){

    cout<<"      <Following is Huffman Coding>      "<<endl;
    char arr1[] = { 'a', 'b', 'c', 'd', 'e' };
    int freq[] = { 5, 10, 19, 32, 51};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    //execute and calculate huf code 
    double STARTHUF = clock();
    HuffmanCodes(arr1, freq, size);
    double ENDHUF = clock();
    double timehuf=ENDHUF-STARTHUF;
    //end of huf

    
    cout<<"      <Following is Arithmetic Coding>      "<<endl;
    int n = 5 ;
	unordered_map<char, node> arr2;
	vector<char> ar;
	double range_from = 0;
	cout<<"Enter probability of each character:\n";
	double fre[] = { 0.05, 0.1, 0.2, 0.25, 0.4};
	for(int i=0; i<n; i++){
		ar.push_back(arr1[i]);
		arr2[arr1[i]].prob = fre[i];
		arr2[arr1[i]].range_from = range_from;
		arr2[arr1[i]].range_to = range_from + arr2[arr1[i]].prob;
		range_from = arr2[arr1[i]].range_to;
	}
	cout<<"Symbol\tProbability\tRange_from\tRange_to\n";
	cout<<"----------------------------------------------------\n";
	for(int i=0; i<ar.size(); i++){
		char ch= ar[i];
		cout<<ch<<"\t"<<arr2[ch].prob<<"\t\t"<<arr2[ch].range_from<<"\t\t"<<arr2[ch].range_to<<endl;
	}
	cout<<endl;
	string s;

    cout <<"Please enter abcde within length of 5, for example:abcde ";
    cin >> s;

    //execute and calculate arc code
    double STARTARC = clock();
    double code_word= encoding(arr2, s);
    double ENDARC = clock();
    double timearc=ENDARC-STARTARC;

    
	cout<<"Code word for "<<s<<" is: "<<code_word<<endl;
	string text= decoding(arr2, code_word, s.size());
	cout<<"Text for "<<code_word<<" is: "<<text<<endl;
    //-------------------------------------------------------------------------------------------------------//
    cout<<"The time of two algorithm is:"<<endl<<endl;
    cout<<"Huffman Coding: "<< timehuf / CLOCKS_PER_SEC << "seconds" <<endl;
    cout<<"Arithmetic Coding: "<< timearc / CLOCKS_PER_SEC <<"seconds" <<endl;
}