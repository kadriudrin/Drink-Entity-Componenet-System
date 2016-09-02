#include "Public.h"
#include "Entity.h"

Entity::Entity(string name, string tag)
{
	ID = GetCounter();
	this->Name = UniqueName(name);
	this->Tag = UniqueTag(tag);
	AllEntities.push_back(this);
	lastEntity = this;
}

int Entity::GetID(){ return this->ID; }
string Entity::GetName(){ return this->Name; }
string Entity::GetTag(){ return this->Tag; }
void Entity::PrintAll(){
	
	cout << "NAME: \"" << Entity::Name << "\" TAG: \"" << Entity::Tag << "\" ID: \"" << Entity::ID << "\"" << endl;
}
void Entity::SetAll(string newn, string newt){
	this->Name = UniqueName(newn);
	this->Tag = UniqueTag(newt);
}
Entity& Entity::operator=(const Entity& other){
	this->Name = other.Name;
	this->Tag = other.Tag;
	//if (this->ID = other.ID)
	//	this->ID = GetCounter();
	return *this;
}
void Entity::AddComponent(Component* newC){
	AllComponents.push_back(newC);
}

int Entity::GetAllCompsSize(){
	return AllComponents.size();
}

void Entity::Start(){
	for (int i = 0; i < AllComponents.size(); i++)
		AllComponents.at(i)->Start();
}
void Entity::Update(){
	for (int i = 0; i < AllComponents.size(); i++)
		AllComponents.at(i)->Update();
}

Entity::~Entity()
{
}
