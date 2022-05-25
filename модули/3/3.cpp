#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char str[] = "Hello i am Roman!";
	vector<char *> words;

	cout << "Исходная строка: " << endl;
	cout << str << endl;

    char *token = strtok(str, " ");
   
    while (token != NULL)
    {
		words.push_back(token);
        token = strtok(NULL, " ");
    }

	int minIndex;
	int minValue;

	int maxIndex;
	int maxValue = 0;
	
	for(int i = 0; i < words.size(); i++) 
	{
		char *el = words.at(i);
		int length = strlen(el);

		if(length > maxValue) 
		{
			maxValue = length;
			maxIndex = i;
		}
		if(length < minValue) 
		{
			minValue = length;
			minIndex = i;
		}
	}
	
	char *minString = words.at(minIndex);
	char *maxString = words.at(maxIndex);

	words.at(minIndex) = maxString;
	words.at(maxIndex) = minString;

	string resultStr = "";

	for(int i = 0; i < words.size(); i++) 
	{
		char *word = words.at(i);
		resultStr += word;
		resultStr += " ";
	}

	cout << "Результат: " << endl;
	cout << resultStr << endl;
}