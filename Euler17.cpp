/******************************************
*AUTHOR : AdheshR*
*Euler Problem: 017*
*Problem Statement: Convert Number to Words*
******************************************/
#include <bits/stdc++.h>
using namespace std;

string number2Word(string N);
string getHundredWords(char unit,char tens,char hundreds);
int wordLength(string res);
string getUnitWord(int unitD);

// Fails just one test case. TE 3. Have to figure out why.

int main()
{
	int T;
	cin >> T;

	string N,res;
	// Is Optional. Todo the eulerproject.net problem
	int countLength =0;
	for(int t=0;t<T;++t)
	{
		cin>>N;
		// N = to_string(t+1);
		res = number2Word(N);
		cout <<res<<endl;
		// countLength = countLength + wordLength(res);
	}

	// cout<<countLength<<endl;
}


// For EulerProject.net purposes.
int wordLength(string res)
{
	int count = 0,i=0;
	while(i<int(res.length()))
	{
		if(res[i++]!=32)
			++count;
	}
	return count;
}

string number2Word(string N)
{
	string trillion = "";
	string billion = "";
	string million = "";
	string thousand = "";
	string hundreds = "";

	while(N.length()!=13)
		N = "0" + N;

	billion = getHundredWords(N[1],N[2],N[3]);
	million = getHundredWords(N[4],N[5],N[6]);
	thousand = getHundredWords(N[7],N[8],N[9]);
	hundreds = getHundredWords(N[10],N[11],N[12]);

	int trillionD = N[0] - 48;

	if(trillionD!=0)
		trillion.append(getUnitWord(trillionD)+" Trillion ");

	if(billion.compare("") != 0)
		billion.append(" Billion ");
	else
		billion = "";
	if(million.compare("") != 0)
		million.append(" Million ");
	else
		million = "";
	if(thousand.compare("") != 0)
		thousand.append(" Thousand ");
	else
		thousand = "";

	if((billion.compare("") == 0) && (million.compare("") == 0) && (thousand.compare("") == 0) && (hundreds.compare("") == 0) && trillionD == 0)
		return "Zero";

	string finalWord = trillion + billion + million + thousand + hundreds;
	return finalWord;
}

string getHundredWords(char hundreds,char tens,char unit)
{
	int unitD = unit - 48;
	int tensD = tens - 48;
	int hundredsD = hundreds - 48;

	string word;

	if(hundredsD!=0)
		word.append(getUnitWord(hundredsD));

	if(hundredsD != 0)
		word.append(" Hundred");

	if(tensD == 1)
	{
		if(hundredsD != 0 && unitD!=0)
			word.append(" ");

		switch(unitD)
		{
			case 0:
				word.append("Ten");
				break;
			case 1:
				word.append("Eleven");
				break;
			case 2:
				word.append("Twelve");
				break;
			case 3:
				word.append("Thirteen");
				break;
			case 4:
				word.append("Fourteen");
				break;
			case 5:
				word.append("Fifteen");
				break;
			case 6:
				word.append("Sixteen");
				break;
			case 7:
				word.append("Seventeen");
				break;
			case 8:
				word.append("Eighteen");
				break;
			case 9:
				word.append("Nineteen");
				break;
		} 
	}
	else
	{
		if(hundredsD != 0 && tensD!=0)
			word.append(" ");

		switch(tensD)
		{
			case 2:
				word.append("Twenty");
				break;
			case 3:
				word.append("Thirty");
				break;
			case 4:
				word.append("Forty");
				break;
			case 5:
				word.append("Fifty");
				break;
			case 6:
				word.append("Sixty");
				break;
			case 7:
				word.append("Seventy");
				break;
			case 8:
				word.append("Eighty");
				break;
			case 9:
				word.append("Ninety");
				break;
		} 

		if((tensD!=0 || hundredsD!=0) && unitD!=0) 
			word.append(" ");
		
		if(unitD!=0)
			word.append(getUnitWord(unitD));
	}
	// cout << word<<endl;
	return word;
}

string getUnitWord(int unitD)
{
	switch(unitD)
	{
		case 1:
			return "One";
			break;
		case 2:
			return "Two";
			break;
		case 3:
			return "Three";
			break;
		case 4:
			return "Four";
			break;
		case 5:
			return "Five";
			break;
		case 6:
			return "Six";
			break;
		case 7:
			return "Seven";
			break;
		case 8:
			return "Eight";
			break;
		case 9:
			return "Nine";
			break;
	} 
	return "";
}
