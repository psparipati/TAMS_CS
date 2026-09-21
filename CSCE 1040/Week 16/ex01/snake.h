#include <string>
#include <iostream>

using namespace std;

class Snake {
	public:
		Snake();
		Snake(string breed, float weight, string name, char gender, int length, string food, string color_desc, string comments);
		string GetBreed();
		float GetWeight();
		string GetName();
		char GetGender();
		int GetLength();
		string* GetFood();
		string GetColor();
		string GetComments();
		void SetBreed(string breed);
		void SetWeight(float weight);
		void SetName(string name);
		void SetGender(char gender);
		void SetLength(int length);
		void SetFood(string food);
		void SetColor(string color_desc);
		void SetComments(string comments);
		~Snake();
		Snake(Snake& rhs);
		void PrintInfo();
	private:
		string breed;
		float weight;
		string name;
		char gender;
		int length;
		string* fav_food;
		string color_desc;
		string comments;
};