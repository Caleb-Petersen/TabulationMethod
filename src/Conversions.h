/*
 * Conversions.h
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */
#include <vector>
#include <string>

#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

std::vector<unsigned int> parseMinterms (std::string const minterms);
std::vector<char> convertToBinary(unsigned const int numDigits, unsigned const int n);
unsigned int mintermBinaryDiff(std::vector<char> a, std::vector<char> b);
std::vector<char> combineMinterms(std::vector<char> a, std::vector<char> b);

#endif /* CONVERSIONS_H_ */
