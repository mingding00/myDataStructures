#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalParamentValue
{
private:
	string myString;
public:
	illegalParamentValue(string theMessage = "illegalParamentValue") {
		myString = theMessage;
	}
	void output() { cout << myString; }
};
class illegalIndex
{
private:
	string myString;
public:
	illegalIndex(string theMessage = "illegalIndex") {
		myString = theMessage;
	}
	void output() { cout << myString; }
};
class stackEmpty
{
public:
	stackEmpty(string myMessage=
		"Invalid operation on empty stack") 
	{message = myMessage;}
	void outputMessage() { cout << message << endl; }
	

private:
	string message;
};
