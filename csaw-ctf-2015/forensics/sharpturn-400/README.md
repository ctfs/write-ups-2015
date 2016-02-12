# CSAW QUALS 2015: sharpturn-400

**Category:** Forensics
**Points:** 400
**Solves:** 110
**Description:**

> I think my SATA controller is dying.
>
> HINT: `git fsck -v`
>
> [sharpturn.tar.xz-46753a684d909244e7d916cfb5271a95](sharpturn.tar.xz-46753a684d909244e7d916cfb5271a95)


## Write-up

by [PLWagner](https://github.com/PLWagner)

The git repo was crushed because of a material glitch. So the file sharp.cpp had some wrong inputs in it. To find the flag, start with:

```bash
$ tar xvf sharpturn.tar.xz
$ cd shrapturn
$ git fsck
Checking object directories: 100% (256/256), done.
error: sha1 mismatch 354ebf392533dce06174f9c8c093036c138935f3
error: 354ebf392533dce06174f9c8c093036c138935f3: object corrupt or missing
error: sha1 mismatch d961f81a588fcfd5e57bbea7e17ddae8a5e61333
error: d961f81a588fcfd5e57bbea7e17ddae8a5e61333: object corrupt or missing
error: sha1 mismatch f8d0839dd728cb9a723e32058dcc386070d5e3b5
error: f8d0839dd728cb9a723e32058dcc386070d5e3b5: object corrupt or missing
missing blob 354ebf392533dce06174f9c8c093036c138935f3
missing blob f8d0839dd728cb9a723e32058dcc386070d5e3b5
missing blob d961f81a588fcfd5e57bbea7e17ddae8a5e61333
```

Next, create a python script to make fit the SHA keys (See the script.py file in the repo). Use the three blobs in order one at the time  in the SHA variable of the script and run it.

Here's the output for the blob 354ebf392533dce06174f9c8c093036c138935f3
```bash
VALID! '354ebf392533dce06174f9c8c093036c138935f3'
'blob 520\x00#include <iostream>\n#include <string>\n#include <algorithm>\n\nusing namespace std;\n\nint main(int argc, char **argv)\n{\n\t(void)argc; (void)argv; //unused\n\n\tstd::string part1;\n\tcout << "Part1: Enter flag:" << endl;\n\tcin >> part1;\n\n\tint64_t part2;\n\tcout << "Part2: Input 31337:" << endl;\n\tcin >> part2;\n\n\tstd::string part3;\n\tcout << "Part3: Watch this: https://www.youtube.com/watch?v=PBwAxmrE194" << endl;\n\tcin >> part3;\n\n\tstd::string part4;\n\tcout << "Part4: C.R.E.A.M. Get da _____: " << endl;\n\tcin >> part4;\n\n\treturn 0;\n}\n\n'
```

Here's the output for the blob d961f81a588fcfd5e57bbea7e17ddae8a5e61333
```bash
VALID! 'd961f81a588fcfd5e57bbea7e17ddae8a5e61333'
'blob 806\x00#include <iostream>\n#include <string>\n#include <algorithm>\n\nusing namespace std;\n\nint main(int argc, char **argv)\n{\n\t(void)argc; (void)argv; //unused\n\n\tstd::string part1;\n\tcout << "Part1: Enter flag:" << endl;\n\tcin >> part1;\n\n\tint64_t part2;\n\tcout << "Part2: Input 31337:" << endl;\n\tcin >> part2;\n\n\tstd::string part3;\n\tcout << "Part3: Watch this: https://www.youtube.com/watch?v=PBwAxmrE194" << endl;\n\tcin >> part3;\n\n\tstd::string part4;\n\tcout << "Part4: C.R.E.A.M. Get da _____: " << endl;\n\tcin >> part4;\n\n\tuint64_t first, second;\n\tcout << "Part5: Input the two prime factors of the number 272031727027." << endl;\n\tcin >> first;\n\tcin >> second;\n\n\tuint64_t factor1, factor2;\n\tif (first < second)\n\t{\n\t\tfactor1 = first;\n\t\tfactor2 = second;\n\t}\n\telse\n\t{\n\t\tfactor1 = second;\n\t\tfactor2 = first;\n\t}\n\n\treturn 0;\n}\n\n'
```

Here's the output for the blob f8d0839dd728cb9a723e32058dcc386070d5e3b5
```bash
VALID! 'f8d0839dd728cb9a723e32058dcc386070d5e3b5'
'blob 1880\x00#include <iostream>\n#include <string>\n#include <algorithm>\n\n#include <stdint.h>\n#include <stdio.h>\n#include <openssl/sha.h>\n\nusing namespace std;\n\nstd::string calculate_flag(\n\t\tstd::string &part1, \n\t\tint64_t part2, \n\t\tstd::string &part4,\n\t\tuint64_t factor1,\n\t\tuint64_t factor2)\n{\n\n\tstd::transform(part1.begin(), part1.end(), part1.begin(), ::tolower);\n\tstd::transform(part4.begin(), part4.end(), part4.begin(), ::tolower);\n\n\tSHA_CTX ctx;\n\tSHA1_Init(&ctx);\n\n\tunsigned int mod = factor1 % factor2;\n\tfor (unsigned int i = 0; i < mod; i+=2)\n\t{\n\t\tSHA1_Update(&ctx,\n\t\t\t\treinterpret_cast<const unsigned char *>(part1.c_str()),\n\t\t\t\tpart1.size());\n\t}\n\n\n\twhile (part2-- > 0)\n\t{\n\t\tSHA1_Update(&ctx,\n\t\t\t\treinterpret_cast<const unsigned char *>(part4.c_str()),\n\t\t\t\tpart1.size());\n\t}\n\n\tunsigned char *hash = new unsigned char[SHA_DIGEST_LENGTH];\n\tSHA1_Final(hash, &ctx);\n\n\tstd::string rv;\n\tfor (unsigned int i = 0; i < SHA_DIGEST_LENGTH; i++)\n\t{\n\t\tchar *buf;\n\t\tasprintf(&buf, "%02x", hash[i]);\n\t\trv += buf;\n\t\tfree(buf);\n\t}\n\n\treturn rv;\n}\n\nint main(int argc, char **argv)\n{\n\t(void)argc; (void)argv; //unused\n\n\tstd::string part1;\n\tcout << "Part1: Enter flag:" << endl;\n\tcin >> part1;\n\n\tint64_t part2;\n\tcout << "Part2: Input 31337:" << endl;\n\tcin >> part2;\n\n\tstd::string part3;\n\tcout << "Part3: Watch this: https://www.youtube.com/watch?v=PBwAxmrE194" << endl;\n\tcin >> part3;\n\n\tstd::string part4;\n\tcout << "Part4: C.R.E.A.M. Get da _____: " << endl;\n\tcin >> part4;\n\n\tuint64_t first, second;\n\tcout << "Part5: Input the two prime factors of the number 272031727027." << endl;\n\tcin >> first;\n\tcin >> second;\n\n\tuint64_t factor1, factor2;\n\tif (first < second)\n\t{\n\t\tfactor1 = first;\n\t\tfactor2 = second;\n\t}\n\telse\n\t{\n\t\tfactor1 = second;\n\t\tfactor2 = first;\n\t}\n\n\tstd::string flag = calculate_flag(part1, part2, part4, factor1, factor2);\n\tcout << "flag{";\n\tcout << flag;\n\tcout << "}" << endl;\n\n\treturn 0;\n}\n\n'
```

So, to get the flag, the sharp.cpp file needs to have the following:
```bash
"Part2: Input 31337:"
"Part5: Input the two prime factors of the number 272031727027."
```

Replace and save the file (You can find the fixed and edited sharp.cpp in the repo).

Now, with Wolfram|Alpha, search : prime factors of 272031727027:

```bash
31357
8675311
```

Now, compile sharp.cpp and run it to get the flag. (You need the libssl-dev package to use the openssl/sha.h library):
```bash
$ g++ sharp.cpp -L/usr/lib -lssl -lcrypto -o sharp    
$ ./sharp
```

The flag:
```bash
flag{3b532e0a187006879d262141e16fa5f05f2e6752}
```


## Other write-ups and resources

* <https://cclub.cs.wmich.edu/planet/2015/09/21/csaw-2015-sharpturn.html>
* <https://systemoverlord.com/blog/csaw-quals-2015-sharpturn-aka-forensics-400/>
* <http://geeksspeak.github.io/blog/2015/09/21/csaw-2015-for400-sharpturn/>
* <https://github.com/hypnosec/writeups/blob/master/2015/csaw-ctf/forensics/sharpturn.md>
* <http://nandynarwhals.org/2015/09/21/csaw-2015-sharpturn-forensics-400/>
* <https://github.com/thehobn/sharpturn>
* <http://blog.bitsforeveryone.com/2015/09/writeup-csaw-2015-sharpturn.html>
* <http://conorpp.com/blog/how-to-fix-a-corrupted-file-by-brute-force/>
* <http://khack40.info/csaw-ctf-2015-sharpturn-forensic-write-up/> (French)
* <http://blog.isis.poly.edu/2015/10/03/csaw-ctf-sharpturn.html>
