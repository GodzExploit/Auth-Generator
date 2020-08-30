#include <iostream> 
#include <array>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n


using namespace std;

/*
To-do:
1) make login/generate it self
2) unique generator(pass and login should be same)
*/

/*
string stringcreate()
{
	char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int)
	
	
	return alphabet;
}
*/

typedef vector<char> char_array;
char_array charset()
{
	//Change this to suit for length of string
	return char_array(
		{ '0','1','2','3','4',
		'5','6','7','8','9',
		'A','B','C','D','E','F',
		'G','H','I','J','K',
		'L','M','N','O','P',
		'Q','R','S','T','U',
		'V','W','X','Y','Z',
		'a','b','c','d','e','f',
		'g','h','i','j','k',
		'l','m','n','o','p',
		'q','r','s','t','u',
		'v','w','x','y','z'
		});
};

string random_string(int length, function<char(void)> rand_char)
{
	string str(length, 0);
	generate_n(str.begin(), length, rand_char);
	return str;
}
string Login() {

	cout << "Enter your login: ";
	string login;
	cin >> login;
	return login;
}

string Password() {

	cout << "Enter your Password: ";
	string password;
	cin >> password;
	return password;
}

string nums(string x,string y) {
	return y = x;
}
int main() {
	const auto ch_set = charset();

	default_random_engine rng(random_device{}());

	uniform_int_distribution<> dist(0, ch_set.size() - 1);

	auto randchar = [ch_set, &dist, &rng]() {return ch_set[dist(rng)]; };

	auto length = 40; //set how many words

	cout << "Computer Generated: " << endl;

	std::cout << "Login: " << random_string(length, randchar) << std::endl;

	string num = random_string(length, randchar);
	cout <<"Password: "<< num << endl;


	bool isTrue = true;
	while (isTrue) { // loop for user input
		cout << "" << endl; //space
		cout << "User Generated: " << endl;
			if (Login() == Password()) { //checks if pass and login is right
				cout << "Logged in!" << endl;
				break;
			}
			cout << "incorrect, try again!" << endl; // if pass and login not same print this.
	}
}
