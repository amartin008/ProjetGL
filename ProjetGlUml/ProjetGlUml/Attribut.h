#include <string>
class Attribut{
	public:
		std::string getId();
		std::string getUnit();
		std::string getDescription();

		Attribut(std::string Id, std::string unit, std::string description);
		~Attribut();

	private:
		std::string Id;
		std::string unit;
		std::string description;
};

