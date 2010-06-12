#include "Card.h"

Card::Card(const Color color, const std::string& marker,
		   const std::string& model, const std::string& texture,
		   const std::string& name, const double scale,
		   const core::vector3df& position)
		   : color_(color), marker_(marker), model_(model),
		   texture_(texture), name_(name), scale_(scale), position_(position)
{ }

Card::~Card() { }
