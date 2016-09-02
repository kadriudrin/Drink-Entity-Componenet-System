#include "Public.h"

//static void AddToAllENT(Entity* newE){
//}

int counter = 0;
int NamCounter = 0;
int TagCounter = 0;
vector <string> AllNames;
vector <string> AllTags;

vector <Entity*> AllEntities;

Entity* lastEntity;

Entity* GetEntityName(string name){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name)
			return AllEntities.at(i);
}
Entity* GetEntityTag(string tag){
	string teg = tag;
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetTag() == teg)
			return AllEntities.at(i);
}
Entity* GetEntity(string name, string tag){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name && AllEntities.at(i)->GetTag() == tag)
			return AllEntities.at(i);
}
Entity* GetEntity(int id){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetID() == id)
			return AllEntities.at(i);
}
void Kill(Entity* entitytokill){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i) == entitytokill){
			AllEntities.erase(AllEntities.begin() + i);
			entitytokill->~Entity();
		}
}
void KillName(string name){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name)
			AllEntities.erase(AllEntities.begin() + i);
}
void KillTag(string tag){
	string teg = tag;
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetTag() == teg)
			AllEntities.erase(AllEntities.begin() + i);
}
void Kill(string name, string tag){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name && AllEntities.at(i)->GetTag() == tag)
			AllEntities.erase(AllEntities.begin() + i);
}
void Kill(int id){
	for (int i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetID() == id)
			AllEntities.erase(AllEntities.begin() + i);
}
void PrintNumberOfEntities(){
	cout << "Number of Entities: " << AllEntities.size() << endl;
}
int NumberOfEntities(){
	int nice = AllEntities.size();
	return nice;
}

int GetCounter(){
	return counter++;
}
int GetNamCounter(){
	return TagCounter++;
}
int GetTagCounter(){
	return NamCounter++;
}
string UniqueName(string uN){
	if (uN == "lol")
		return "_Entity" + to_string(GetNamCounter());
	for (int i = 0; i < AllTags.size(); i++){
		if (AllTags.at(i) == uN)
			return "Entity" + to_string(GetNamCounter());
	}
	AllNames.push_back(uN);
	return uN;
}
string UniqueTag(string uT){
	if (uT == "lol")
		return "Tag" + to_string(GetTagCounter());
	for (int i = 0; i < AllTags.size(); i++){
		if (AllTags.at(i) == uT)
			return "_EntityTag" + to_string(GetTagCounter());
	}
	AllTags.push_back(uT);
	return uT;
}
