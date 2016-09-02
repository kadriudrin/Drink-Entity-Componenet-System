#pragma once
#ifndef Entity_h
#define Entity_h

class Entity
{
private:
	int ID;
	string Name;
	string Tag;
	vector <Component*> AllComponents;
public:
	friend bool operator==(const Entity& left, const Entity& right){
		return ((left.Name == right.Name) && (left.Tag == right.Tag));
	}
	friend bool operator!=(const Entity& left, const Entity& right){
		return !(left == right);
	}
	Entity& operator=(const Entity& other);
	Entity(string name = "lol", string tag = "lol");
	~Entity();
	int GetID();
	string GetName();
	string GetTag();
	void AddComponent(Component*);

	//template <typename T>
	//T* GetComponent();

	template <typename T>
	T* GetComponent(){
		T t;
		for (int i = 0; i < AllComponents.size(); i++)
			if (AllComponents.at(i)->Type == t.Type)
				return dynamic_cast<T*>(AllComponents.at(i));
			else
				cout << "Entity: \"" << this->Name << "\" Does not have Component of type: \"" << t.Type << "\" !" << endl;
	}
	template <typename T>
	void RemoveComponent(){
		T t;
		for (int i = 0; i < AllComponents.size(); i++)
			if (AllComponents.at(i)->Type == t.Type){
				AllComponents.erase(AllComponents.begin() + i);
			}
	}

	int GetAllCompsSize();
	void Start();
	void Update();
	void SetAll(string, string);
	void PrintAll();
};
#endif