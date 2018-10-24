#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalParameterValue
{
private:
	string message;
public:
	illegalParameterValue(string myMessage = "illegalParameterValue") {
		message = myMessage;
	}
	void output() {
		cout << message;
	}
};

class illegalIndexValue
{
private:
	string message;
public:
	illegalIndexValue(string myMessage = "illegalIndexValue") {
		message = myMessage;
	}
	void output() {
		cout << message;
	}

};