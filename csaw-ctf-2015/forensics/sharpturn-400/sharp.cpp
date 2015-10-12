#include <string>
#include <algorithm>

#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <openssl/sha.h>

using namespace std;

std::string calculate_flag(
		std::string &part1,
		int64_t part2,
		std::string &part4,
		uint64_t factor1,
		uint64_t factor2) {
	std::transform(part1.begin(), part1.end(), part1.begin(), ::tolower);
	std::transform(part4.begin(), part4.end(), part4.begin(), ::tolower);

	SHA_CTX ctx;
	SHA1_Init(&ctx);

	unsigned int mod = factor1 % factor2;
	for (unsigned int i = 0; i < mod; i += 2) {
		SHA1_Update(&ctx,
					reinterpret_cast<const unsigned char *>(part1.c_str()),
					part1.size());
	}


	while (part2-- > 0) {
		SHA1_Update(&ctx,
					reinterpret_cast<const unsigned char *>(part4.c_str()),
					part1.size());
	}

	unsigned char *hash = new unsigned char[SHA_DIGEST_LENGTH];
	SHA1_Final(hash, &ctx);

	std::string rv;
	for (unsigned int i = 0; i < SHA_DIGEST_LENGTH; i++)
	{
		char *buf;
		asprintf(&buf, "%02x", hash[i]);
		rv += buf;
		free(buf);
	}
	return rv;
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv; //unused

	std::string part1 = "flag";
//	cout << "Part1: Enter flag:" << endl;
//	cin >> part1;

	int64_t part2 = 31337;
//	cout << "Part2: Input 31337:" << endl;
//	cin >> part2;
//
//	std::string part3;
//	cout << "Part3: Watch this: https://www.youtube.com/watch?v=PBwAxmrE194" << endl;
//	cin >> part3;

	std::string part4 = "money";
//	cout << "Part4: C.R.E.A.M. Get da _____: " << endl;
//	cin >> part4;


//	cout << "Part5: Input the two prime factors of the number 272031727027." << endl;
//	cin >> first;
//	cin >> second;
	uint64_t first = 31357;
	uint64_t second = 8675311;

	uint64_t factor1, factor2;
	if (first < second) {
		factor1 = first;
		factor2 = second;
	}
	else {
		factor1 = second;
		factor2 = first;
	}

	std::string flag = calculate_flag(part1, part2, part4, factor1, factor2);
	cout << "flag{";
	cout << flag;
	cout << "}" << endl;

	return 0;
}
