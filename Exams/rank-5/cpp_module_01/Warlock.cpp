#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;

	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() 
{
	std::cout << this->name << ": My job here is done!\n";
	std::map<std::string, ASpell *>::iterator it_begin = this->arr.begin();
	std::map<std::string, ASpell *>::iterator it_end = this->arr.end();

	while(it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->arr.clear();
}

std::string const &Warlock::getName() const {return this->name;}
std::string const &Warlock::getTitle() const {return this->title;}

void Warlock::setTitle(std::string const &title) { this->title = title;}
void Warlock::introduce() const {std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";}

void Warlock::learnSpell(ASpell *aspell_ptr)
{
	if (aspell_ptr)
		arr.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void Warlock::forgetSpell(std::string aspell_name)
{
	std::map<std:string, ASpell *>::iterator iter = arr.find(aspell_name);
	if (iter != arr.end())
		delete iter->second;
	arr.erase(aspell_name);
}


void Warlock::launchSpell(std::string aspell_name, ATarget const &target_ref)
{
	ASpell *aspell = arr[aspell_name];
	if (aspell)
		aspell->launch(target_ref);
}
