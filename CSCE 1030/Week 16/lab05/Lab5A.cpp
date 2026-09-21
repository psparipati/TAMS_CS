#include <iostream>
#include <cctype>

using namespace std;

int main() {
	//Define constants
	enum seasons {SUMMER = 'S', WINTER = 'W', SPRING = 'G', FALL = 'F'};
	char userSeason;

	//Extract Variables
	cout << "Key:\n\tSpring ==> G\n\tSummer ==> S\n\tFall ==> F\n\tWinter ==> W\nEnter your season: ";
	cin >> userSeason;
        userSeason = static_cast<seasons>(toupper(userSeason));

	//Switch-Case Statement
	switch(userSeason) {
		case SUMMER:
            cout << "It is rather hot outside." << endl;
            break;
        case WINTER:
            cout << "It is rather cold outside." << endl;
            break;
        case SPRING:
            cout << "The flowers are blooming." << endl;
            break;
        case FALL:
            cout << "The weather looks good." << endl;
            break;
        default:
            cout << "Wrong choice." << endl;
            break;
	}

	return 0;
}
