#ifndef PROPOSAL_H
#define PROPOSAL_H

#include "Product.h"
#include <vector>

class Proposal
{
private:
	string Name;
	string Text;
	vector<Product> RelatedProducts;
	int Specifications;
public:
	void SetName(string name);
	string GetName();
	void SetText(string text);
	string GetText();
	void SetSpecifications(int specifications);
	string GetSpecifications();
};

#endif