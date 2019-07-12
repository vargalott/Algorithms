// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Prototype.hpp"

#pragma region ConcretePrototype
ConcretePrototype::ConcretePrototype(void)
{
	this->some_field_1 = "ConcretePrototype: some_field_1";
	this->some_field_2 = 65536;
	this->some_field_3 = 3.141592;
}
IPrototype* ConcretePrototype::Clone(void) noexcept
{
	IPrototype* cloned = new ConcretePrototype();
	cloned = this; // do necessary things to copy itself
	return cloned;
}
void ConcretePrototype::PrintData(void) const noexcept
{
	std::cout << "\nfield_1: " << this->some_field_1;
	std::cout << "\nfield_2: " << this->some_field_2;
	std::cout << "\nfield_3: " << this->some_field_3;
}
#pragma endregion

#pragma region TEST
void TEST::DO_TEST(void)
{
	ConcretePrototype existing;
	std::cout << "\nexisting data:";
	existing.PrintData();

	ConcretePrototype* cloned = dynamic_cast<ConcretePrototype*>(existing.Clone());
	std::cout << "\ncloned data:";
	cloned->PrintData();
};
#pragma endregion