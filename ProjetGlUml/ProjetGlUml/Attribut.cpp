#include <string>
#include "Attribut.h"

using namespace std;



string Attribut::getId() {
	return Id;
}

string Attribut::getUnit() {
	return unit;
}

string Attribut::getDescription() {
	return description;
}

Attribut::Attribut(string Id, string unit, string description)
	:Id(Id), unit(unit), description(description)
{}

Attribut::~Attribut()
{}
