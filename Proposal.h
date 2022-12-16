#pragma once
#include "User.h"
class Proposal
{
private:
	string Name;
	string Text;
	vector<Product>RelatedProducts;
	int Specifications;
public:
	void SetName(string name);
	string GetName();
	void SetText(string text);
	string GetText();
	void SetSpecifications(int specifications);
	string GetSpecifications();


};

