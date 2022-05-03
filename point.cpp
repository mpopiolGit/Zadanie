#include "point.hpp"

Point::Point() {
	state = false;
}

void Point::setState(bool st) {
	state = st;
}

bool Point::getState() {
	return state;
}