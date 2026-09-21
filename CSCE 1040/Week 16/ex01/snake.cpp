#include "snake.h"

Snake::Snake() {
	breed = "";
	weight = 0;
	name = "";
	gender = ' ';
	length = 0;
	fav_food = new string;
	*fav_food = "";
	color_desc = "";
	comments = "";
}

Snake::Snake(string breed, float weight, string name, char gender, int length, string food, string color_desc, string comments) {
	this->breed = breed;
	this->weight = weight;
	this->name = name;
	this->gender = gender;
	this->length = length;
	this->fav_food = new string;
	this->fav_food = &food;
	this->color_desc = color_desc;
	this->comments = comments;
}

string Snake::GetBreed() {
	return breed;
}

float Snake::GetWeight() {
	return weight;
}

string Snake::GetName() {
	return name;
};

char Snake::GetGender() {
	return gender;
};

int Snake::GetLength() {
	return length;
};

string* Snake::GetFood() {
	return fav_food;
};

string Snake::GetColor() {
	return color_desc;
};

string Snake::GetComments() {
	return comments;
};

void Snake::SetBreed(string breed) {
	this->breed = breed;
};

void Snake::SetWeight(float weight) {
	this->weight = weight;
};

void Snake::SetName(string name) {
	this->name = name;
};

void Snake::SetGender(char gender) {
	this->gender = gender;
};

void Snake::SetLength(int length) {
	this->length = length;
};

void Snake::SetFood(string food) {
	this->fav_food = &food;
}

void Snake::SetColor(string color_desc) {
	this->color_desc = color_desc;
};

void Snake::SetComments(string comments) {
	this->comments = comments;
};

Snake::~Snake() {
	if (fav_food != nullptr) {
		delete fav_food;
	}
};

Snake::Snake(Snake& rhs) {
	delete fav_food;
	fav_food = new string;
	fav_food = rhs.GetFood();
	// length = rhs.GetLength();
	// breed = rhs.GetBreed();
	// name = rhs.GetName();
	// color_desc = rhs.GetColor();
	// weight = rhs.GetWeight();
	// gender = rhs.GetGender();
	// comments = rhs.GetComments();
}

void Snake::PrintInfo() {
	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
	cout << "Gender: " << ((gender == 'm') ? ("Male") : ("Female")) << endl;
	cout << "Length: " << length / 12 << " ft. " << length % 12 << " in." << endl;
	cout << "Weight: " << weight << endl;
	cout << "Favorite Food: " << *fav_food << endl;
	cout << "Colorization: " << color_desc << endl;
	cout << "Comments: " << comments << endl;
};