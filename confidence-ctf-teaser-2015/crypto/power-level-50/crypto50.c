#include <stdio.h>
#include <string.h>

unsigned char e0(unsigned char c)
{
	c = ~c;
	c += 133;
	c = -c;
	c ^= 232;
	c = -c;
	c += 231;
	c = ~c;
	c += 50;
	return c;
}

unsigned char e1(unsigned char c)
{
	c -= 0;
	c = -c;
	c += 223;
	c = ~c;
	c -= 251;
	c = -c;
	c -= 86;
	c ^= 196;
	return c;
}

unsigned char e2(unsigned char c)
{
	c = ~c;
	c += 48;
	c = -c;
	c -= 207;
	c += 101;
	c ^= 235;
	c = ~c;
	c -= 6;
	return c;
}

unsigned char e3(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 146;
	c += 96;
	c = -c;
	c += 213;
	c = ~c;
	c ^= 120;
	return c;
}

unsigned char e4(unsigned char c)
{
	c += 182;
	c = -c;
	c += 141;
	c ^= 83;
	c += 137;
	c ^= 175;
	c += 69;
	c = ~c;
	return c;
}

unsigned char e5(unsigned char c)
{
	c ^= 193;
	c += 167;
	c = ~c;
	c -= 67;
	c = ~c;
	c -= 62;
	c = ~c;
	c += 181;
	return c;
}

unsigned char e6(unsigned char c)
{
	c = ~c;
	c += 49;
	c = -c;
	c += 132;
	c -= 51;
	c ^= 105;
	c = ~c;
	c -= 28;
	return c;
}

unsigned char e7(unsigned char c)
{
	c = -c;
	c += 8;
	c ^= 198;
	c += 221;
	c ^= 35;
	c += 217;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e8(unsigned char c)
{
	c -= 170;
	c = ~c;
	c += 17;
	c ^= 119;
	c -= 77;
	c = ~c;
	c = -c;
	c ^= 73;
	return c;
}

unsigned char e9(unsigned char c)
{
	c ^= 111;
	c -= 5;
	c = ~c;
	c = -c;
	c -= 38;
	c += 20;
	c = -c;
	c += 185;
	return c;
}

unsigned char e10(unsigned char c)
{
	c ^= 95;
	c = -c;
	c += 10;
	c = -c;
	c = ~c;
	c -= 68;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e11(unsigned char c)
{
	c -= 176;
	c = ~c;
	c ^= 229;
	c = ~c;
	c ^= 97;
	c = -c;
	c += 116;
	c -= 18;
	return c;
}

unsigned char e12(unsigned char c)
{
	c ^= 224;
	c = -c;
	c += 63;
	c = ~c;
	c = -c;
	c = ~c;
	c += 209;
	c ^= 55;
	return c;
}

unsigned char e13(unsigned char c)
{
	c -= 13;
	c = ~c;
	c ^= 16;
	c -= 47;
	c += 26;
	c ^= 40;
	c = -c;
	c ^= 39;
	return c;
}

unsigned char e14(unsigned char c)
{
	c ^= 125;
	c = ~c;
	c -= 64;
	c += 190;
	c = ~c;
	c ^= 53;
	c += 59;
	c -= 177;
	return c;
}

unsigned char e15(unsigned char c)
{
	c -= 23;
	c ^= 112;
	c += 110;
	c = -c;
	c = ~c;
	c = -c;
	c += 136;
	c = -c;
	return c;
}

unsigned char e16(unsigned char c)
{
	c += 93;
	c ^= 160;
	c += 255;
	c = -c;
	c = ~c;
	c += 100;
	c ^= 130;
	c -= 208;
	return c;
}

unsigned char e17(unsigned char c)
{
	c ^= 206;
	c = -c;
	c += 133;
	c ^= 11;
	c = -c;
	c = ~c;
	c -= 231;
	c = ~c;
	return c;
}

unsigned char e18(unsigned char c)
{
	c ^= 131;
	c = ~c;
	c -= 126;
	c ^= 138;
	c = ~c;
	c = -c;
	c = ~c;
	c += 196;
	return c;
}

unsigned char e19(unsigned char c)
{
	c += 226;
	c ^= 48;
	c += 46;
	c -= 92;
	c += 58;
	c = ~c;
	c += 6;
	c ^= 244;
	return c;
}

unsigned char e20(unsigned char c)
{
	c += 146;
	c -= 96;
	c = -c;
	c -= 191;
	c = -c;
	c += 219;
	c ^= 81;
	c = ~c;
	return c;
}

unsigned char e21(unsigned char c)
{
	c ^= 36;
	c = -c;
	c ^= 83;
	c += 142;
	c ^= 188;
	c = -c;
	c -= 203;
	c += 193;
	return c;
}

unsigned char e22(unsigned char c)
{
	c -= 167;
	c = -c;
	c += 67;
	c -= 249;
	c = ~c;
	c -= 181;
	c += 187;
	c = -c;
	return c;
}

unsigned char e23(unsigned char c)
{
	c -= 22;
	c = ~c;
	c ^= 162;
	c = ~c;
	c = -c;
	c -= 143;
	c = ~c;
	c ^= 250;
	return c;
}

unsigned char e24(unsigned char c)
{
	c += 8;
	c -= 198;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 32;
	c ^= 158;
	return c;
}

unsigned char e25(unsigned char c)
{
	c = -c;
	c ^= 149;
	c += 155;
	c -= 17;
	c ^= 119;
	c += 77;
	c = ~c;
	c -= 80;
	return c;
}

unsigned char e26(unsigned char c)
{
	c += 78;
	c -= 124;
	c = -c;
	c -= 139;
	c ^= 129;
	c += 103;
	c -= 178;
	c += 128;
	return c;
}

unsigned char e27(unsigned char c)
{
	c ^= 254;
	c -= 172;
	c = -c;
	c = ~c;
	c = -c;
	c -= 241;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e28(unsigned char c)
{
	c += 45;
	c = ~c;
	c = -c;
	c ^= 174;
	c = -c;
	c ^= 229;
	c = ~c;
	c -= 200;
	return c;
}

unsigned char e29(unsigned char c)
{
	c -= 134;
	c ^= 116;
	c += 227;
	c -= 153;
	c = -c;
	c += 12;
	c ^= 106;
	c = -c;
	return c;
}

unsigned char e30(unsigned char c)
{
	c ^= 54;
	c += 164;
	c -= 194;
	c = -c;
	c ^= 9;
	c -= 47;
	c += 26;
	c ^= 40;
	return c;
}

unsigned char e31(unsigned char c)
{
	c = ~c;
	c += 125;
	c ^= 195;
	c = -c;
	c ^= 190;
	c = ~c;
	c = -c;
	c ^= 59;
	return c;
}

unsigned char e32(unsigned char c)
{
	c ^= 177;
	c -= 23;
	c = ~c;
	c -= 179;
	c += 233;
	c -= 15;
	c += 165;
	c -= 33;
	return c;
}

unsigned char e33(unsigned char c)
{
	c -= 7;
	c = ~c;
	c -= 163;
	c += 89;
	c = -c;
	c += 204;
	c = ~c;
	c -= 27;
	return c;
}

unsigned char e34(unsigned char c)
{
	c = ~c;
	c ^= 246;
	c = ~c;
	c -= 205;
	c ^= 147;
	c -= 201;
	c = ~c;
	c ^= 133;
	return c;
}

unsigned char e35(unsigned char c)
{
	c += 11;
	c ^= 1;
	c = ~c;
	c = -c;
	c -= 50;
	c = ~c;
	c -= 57;
	c = ~c;
	return c;
}

unsigned char e36(unsigned char c)
{
	c -= 44;
	c += 251;
	c ^= 113;
	c += 215;
	c ^= 173;
	c = ~c;
	c = -c;
	c += 169;
	return c;
}

unsigned char e37(unsigned char c)
{
	c = -c;
	c += 92;
	c = ~c;
	c -= 72;
	c = -c;
	c = ~c;
	c = -c;
	c += 29;
	return c;
}

unsigned char e38(unsigned char c)
{
	c -= 99;
	c += 25;
	c = -c;
	c ^= 213;
	c += 120;
	c -= 182;
	c += 36;
	c -= 66;
	return c;
}

unsigned char e39(unsigned char c)
{
	c = -c;
	c -= 142;
	c = ~c;
	c ^= 69;
	c = -c;
	c -= 168;
	c += 102;
	c = -c;
	return c;
}

unsigned char e40(unsigned char c)
{
	c = -c;
	c ^= 242;
	c += 192;
	c -= 62;
	c = ~c;
	c += 181;
	c = -c;
	c -= 216;
	return c;
}

unsigned char e41(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 132;
	c = -c;
	c -= 51;
	c += 238;
	c = ~c;
	c += 37;
	return c;
}

unsigned char e42(unsigned char c)
{
	c += 171;
	c ^= 161;
	c = -c;
	c = ~c;
	c -= 221;
	c ^= 35;
	c = -c;
	c ^= 158;
	return c;
}

unsigned char e43(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 170;
	c += 17;
	c = -c;
	c -= 228;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e44(unsigned char c)
{
	c = ~c;
	c -= 73;
	c += 111;
	c -= 5;
	c = -c;
	c -= 104;
	c = -c;
	c -= 103;
	return c;
}

unsigned char e45(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c -= 128;
	c ^= 254;
	c -= 172;
	c += 10;
	c = ~c;
	return c;
}

unsigned char e46(unsigned char c)
{
	c += 241;
	c = -c;
	c = ~c;
	c += 176;
	c = ~c;
	c ^= 79;
	c += 186;
	c -= 200;
	return c;
}

unsigned char e47(unsigned char c)
{
	c += 134;
	c -= 116;
	c += 18;
	c -= 224;
	c = ~c;
	c += 12;
	c -= 106;
	c = ~c;
	return c;
}

unsigned char e48(unsigned char c)
{
	c += 54;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 16;
	c = -c;
	c += 60;
	c = ~c;
	return c;
}

unsigned char e49(unsigned char c)
{
	c += 40;
	c ^= 230;
	c += 212;
	c = ~c;
	c += 121;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e50(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c -= 177;
	c = ~c;
	c += 4;
	c -= 179;
	c ^= 233;
	return c;
}

unsigned char e51(unsigned char c)
{
	c = -c;
	c += 165;
	c = ~c;
	c -= 33;
	c ^= 7;
	c -= 93;
	c += 163;
	c = ~c;
	return c;
}

unsigned char e52(unsigned char c)
{
	c ^= 30;
	c += 204;
	c ^= 42;
	c += 246;
	c -= 100;
	c ^= 147;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e53(unsigned char c)
{
	c = -c;
	c ^= 133;
	c = ~c;
	c += 232;
	c = -c;
	c = ~c;
	c += 148;
	c ^= 50;
	return c;
}

unsigned char e54(unsigned char c)
{
	c -= 0;
	c = ~c;
	c ^= 223;
	c = ~c;
	c ^= 138;
	c += 24;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e55(unsigned char c)
{
	c -= 48;
	c ^= 46;
	c -= 92;
	c += 58;
	c -= 72;
	c = -c;
	c -= 244;
	c = -c;
	return c;
}

unsigned char e56(unsigned char c)
{
	c ^= 99;
	c -= 25;
	c = -c;
	c = ~c;
	c = -c;
	c += 81;
	c = ~c;
	c += 141;
	return c;
}

unsigned char e57(unsigned char c)
{
	c ^= 83;
	c -= 137;
	c = ~c;
	c ^= 188;
	c = -c;
	c ^= 203;
	c += 193;
	c = ~c;
	return c;
}

unsigned char e58(unsigned char c)
{
	c -= 84;
	c = ~c;
	c += 67;
	c = ~c;
	c -= 159;
	c += 74;
	c ^= 49;
	c = ~c;
	return c;
}

unsigned char e59(unsigned char c)
{
	c = -c;
	c -= 162;
	c += 240;
	c -= 238;
	c ^= 28;
	c -= 171;
	c += 161;
	c = -c;
	return c;
}

unsigned char e60(unsigned char c)
{
	c = ~c;
	c += 217;
	c -= 127;
	c = -c;
	c += 170;
	c = -c;
	c -= 119;
	c = ~c;
	return c;
}

unsigned char e61(unsigned char c)
{
	c = ~c;
	c ^= 78;
	c -= 124;
	c = -c;
	c += 139;
	c ^= 129;
	c = ~c;
	c -= 189;
	return c;
}

unsigned char e62(unsigned char c)
{
	c = -c;
	c += 185;
	c = -c;
	c -= 172;
	c = -c;
	c ^= 152;
	c += 214;
	c = ~c;
	return c;
}

unsigned char e63(unsigned char c)
{
	c -= 45;
	c = ~c;
	c += 176;
	c = -c;
	c ^= 79;
	c += 186;
	c = -c;
	c += 97;
	return c;
}

unsigned char e64(unsigned char c)
{
	c ^= 71;
	c -= 157;
	c = ~c;
	c ^= 224;
	c -= 94;
	c += 12;
	c ^= 106;
	c += 248;
	return c;
}

unsigned char e65(unsigned char c)
{
	c = ~c;
	c -= 55;
	c += 194;
	c -= 16;
	c += 14;
	c = -c;
	c = ~c;
	c -= 75;
	return c;
}

unsigned char e66(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 39;
	c -= 125;
	c ^= 195;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e67(unsigned char c)
{
	c = ~c;
	c ^= 202;
	c += 177;
	c = ~c;
	c = -c;
	c ^= 34;
	c -= 112;
	c = ~c;
	return c;
}

unsigned char e68(unsigned char c)
{
	c = -c;
	c += 156;
	c ^= 122;
	c = ~c;
	c -= 33;
	c = ~c;
	c ^= 52;
	c -= 163;
	return c;
}

unsigned char e69(unsigned char c)
{
	c = -c;
	c ^= 255;
	c = ~c;
	c ^= 27;
	c -= 145;
	c += 247;
	c ^= 205;
	c += 208;
	return c;
}

unsigned char e70(unsigned char c)
{
	c += 206;
	c = ~c;
	c ^= 133;
	c = -c;
	c = ~c;
	c ^= 1;
	c -= 231;
	c += 61;
	return c;
}

unsigned char e71(unsigned char c)
{
	c -= 131;
	c += 57;
	c -= 223;
	c ^= 245;
	c = -c;
	c += 113;
	c ^= 215;
	c = ~c;
	return c;
}

unsigned char e72(unsigned char c)
{
	c = ~c;
	c -= 48;
	c += 207;
	c ^= 101;
	c = -c;
	c -= 225;
	c += 199;
	c -= 29;
	return c;
}

unsigned char e73(unsigned char c)
{
	c -= 99;
	c = -c;
	c -= 222;
	c ^= 213;
	c = ~c;
	c = -c;
	c ^= 182;
	c -= 36;
	return c;
}

unsigned char e74(unsigned char c)
{
	c += 66;
	c = ~c;
	c ^= 69;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 102;
	c += 84;
	return c;
}

unsigned char e75(unsigned char c)
{
	c -= 242;
	c = -c;
	c -= 249;
	c = ~c;
	c ^= 181;
	c = ~c;
	c = -c;
	c -= 49;
	return c;
}

unsigned char e76(unsigned char c)
{
	c += 151;
	c -= 109;
	c ^= 240;
	c += 238;
	c = ~c;
	c += 37;
	c = -c;
	c -= 8;
	return c;
}

unsigned char e77(unsigned char c)
{
	c -= 198;
	c ^= 180;
	c -= 82;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 76;
	return c;
}

unsigned char e78(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 118;
	c = ~c;
	c += 80;
	c = ~c;
	return c;
}

unsigned char e79(unsigned char c)
{
	c = ~c;
	c ^= 124;
	c = -c;
	c = ~c;
	c = -c;
	c += 129;
	c = ~c;
	c += 20;
	return c;
}

unsigned char e80(unsigned char c)
{
	c = ~c;
	c += 128;
	c = -c;
	c = ~c;
	c -= 172;
	c = ~c;
	c -= 123;
	c = ~c;
	return c;
}

unsigned char e81(unsigned char c)
{
	c = ~c;
	c ^= 87;
	c += 45;
	c = ~c;
	c ^= 176;
	c += 174;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e82(unsigned char c)
{
	c += 186;
	c = -c;
	c += 97;
	c = ~c;
	c ^= 116;
	c = -c;
	c = ~c;
	c -= 153;
	return c;
}

unsigned char e83(unsigned char c)
{
	c = -c;
	c += 12;
	c -= 106;
	c = -c;
	c -= 209;
	c = -c;
	c += 13;
	c = ~c;
	return c;
}

unsigned char e84(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 47;
	c = ~c;
	c ^= 75;
	c = ~c;
	c -= 212;
	c = -c;
	return c;
}

unsigned char e85(unsigned char c)
{
	c = ~c;
	c ^= 64;
	c = -c;
	c += 31;
	c = -c;
	c = ~c;
	c += 59;
	c = -c;
	return c;
}

unsigned char e86(unsigned char c)
{
	c += 150;
	c -= 4;
	c = -c;
	c -= 179;
	c = -c;
	c ^= 15;
	c += 165;
	c ^= 43;
	return c;
}

unsigned char e87(unsigned char c)
{
	c = -c;
	c ^= 70;
	c = -c;
	c ^= 93;
	c += 163;
	c = -c;
	c -= 255;
	c ^= 42;
	return c;
}

unsigned char e88(unsigned char c)
{
	c += 184;
	c -= 246;
	c ^= 100;
	c += 130;
	c ^= 208;
	c -= 206;
	c = -c;
	c ^= 133;
	return c;
}

unsigned char e89(unsigned char c)
{
	c ^= 11;
	c += 1;
	c ^= 231;
	c = ~c;
	c -= 50;
	c = ~c;
	c -= 57;
	c += 223;
	return c;
}

unsigned char e90(unsigned char c)
{
	c = ~c;
	c += 138;
	c = ~c;
	c -= 113;
	c ^= 215;
	c += 173;
	c = ~c;
	c -= 169;
	return c;
}

unsigned char e91(unsigned char c)
{
	c += 207;
	c = -c;
	c = ~c;
	c += 235;
	c = -c;
	c -= 199;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e92(unsigned char c)
{
	c ^= 99;
	c += 25;
	c ^= 191;
	c = ~c;
	c = -c;
	c += 219;
	c = ~c;
	c ^= 182;
	return c;
}

unsigned char e93(unsigned char c)
{
	c = -c;
	c -= 141;
	c ^= 83;
	c = ~c;
	c ^= 142;
	c = -c;
	c -= 203;
	c = ~c;
	return c;
}

unsigned char e94(unsigned char c)
{
	c += 102;
	c ^= 84;
	c = -c;
	c += 67;
	c ^= 249;
	c = ~c;
	c += 74;
	c = ~c;
	return c;
}

unsigned char e95(unsigned char c)
{
	c ^= 49;
	c += 151;
	c -= 51;
	c += 105;
	c ^= 143;
	c -= 8;
	c += 198;
	c -= 180;
	return c;
}

unsigned char e96(unsigned char c)
{
	c ^= 82;
	c = -c;
	c -= 158;
	c = -c;
	c += 170;
	c = ~c;
	c ^= 17;
	c = ~c;
	return c;
}

unsigned char e97(unsigned char c)
{
	c += 228;
	c = ~c;
	c ^= 80;
	c = -c;
	c -= 111;
	c = ~c;
	c = -c;
	c -= 139;
	return c;
}

unsigned char e98(unsigned char c)
{
	c += 129;
	c = -c;
	c ^= 20;
	c = -c;
	c -= 128;
	c = -c;
	c ^= 95;
	c = -c;
	return c;
}

unsigned char e99(unsigned char c)
{
	c = ~c;
	c += 152;
	c -= 214;
	c = -c;
	c ^= 45;
	c = ~c;
	c = -c;
	c ^= 41;
	return c;
}

unsigned char e100(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 200;
	c += 134;
	c = -c;
	c ^= 157;
	c = ~c;
	return c;
}

unsigned char e101(unsigned char c)
{
	c -= 224;
	c = ~c;
	c += 12;
	c -= 91;
	c += 209;
	c = ~c;
	c ^= 164;
	c = -c;
	return c;
}

unsigned char e102(unsigned char c)
{
	c -= 211;
	c += 9;
	c -= 60;
	c = ~c;
	c += 75;
	c = ~c;
	c ^= 230;
	c = ~c;
	return c;
}

unsigned char e103(unsigned char c)
{
	c ^= 125;
	c = ~c;
	c += 121;
	c = -c;
	c = ~c;
	c += 53;
	c ^= 59;
	c = ~c;
	return c;
}

unsigned char e104(unsigned char c)
{
	c = ~c;
	c ^= 23;
	c += 237;
	c -= 179;
	c += 110;
	c ^= 165;
	c += 43;
	c = -c;
	return c;
}

unsigned char e105(unsigned char c)
{
	c -= 70;
	c += 93;
	c = -c;
	c = ~c;
	c -= 30;
	c += 204;
	c -= 42;
	c = -c;
	return c;
}

unsigned char e106(unsigned char c)
{
	c = -c;
	c -= 246;
	c = ~c;
	c ^= 130;
	c += 239;
	c = -c;
	c = ~c;
	c += 11;
	return c;
}

unsigned char e107(unsigned char c)
{
	c += 1;
	c = ~c;
	c += 148;
	c = -c;
	c -= 131;
	c ^= 57;
	c -= 44;
	c += 251;
	return c;
}

unsigned char e108(unsigned char c)
{
	c += 113;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 226;
	c += 48;
	c = ~c;
	c ^= 92;
	return c;
}

unsigned char e109(unsigned char c)
{
	c = ~c;
	c ^= 72;
	c = ~c;
	c ^= 199;
	c = -c;
	c -= 99;
	c = ~c;
	c -= 191;
	return c;
}

unsigned char e110(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 219;
	c = -c;
	c += 182;
	c = ~c;
	c = -c;
	c ^= 83;
	return c;
}

unsigned char e111(unsigned char c)
{
	c += 137;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 154;
	c -= 193;
	c = -c;
	c -= 253;
	return c;
}

unsigned char e112(unsigned char c)
{
	c = -c;
	c -= 192;
	c += 62;
	c = ~c;
	c ^= 181;
	c -= 49;
	c ^= 151;
	c -= 51;
	return c;
}

unsigned char e113(unsigned char c)
{
	c ^= 105;
	c += 143;
	c ^= 37;
	c += 171;
	c = ~c;
	c ^= 198;
	c = ~c;
	c += 82;
	return c;
}

unsigned char e114(unsigned char c)
{
	c = ~c;
	c += 217;
	c -= 127;
	c += 149;
	c ^= 155;
	c -= 17;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e115(unsigned char c)
{
	c ^= 2;
	c = -c;
	c += 78;
	c ^= 124;
	c = -c;
	c ^= 104;
	c -= 38;
	c += 189;
	return c;
}

unsigned char e116(unsigned char c)
{
	c = ~c;
	c ^= 128;
	c -= 254;
	c = ~c;
	c += 123;
	c -= 241;
	c = -c;
	c ^= 68;
	return c;
}

unsigned char e117(unsigned char c)
{
	c = ~c;
	c -= 176;
	c ^= 174;
	c += 220;
	c = ~c;
	c -= 107;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e118(unsigned char c)
{
	c += 71;
	c = ~c;
	c = -c;
	c ^= 224;
	c = ~c;
	c ^= 63;
	c -= 106;
	c ^= 248;
	return c;
}

unsigned char e119(unsigned char c)
{
	c = -c;
	c += 55;
	c -= 13;
	c ^= 16;
	c -= 14;
	c += 60;
	c = ~c;
	c -= 40;
	return c;
}

unsigned char e120(unsigned char c)
{
	c = -c;
	c += 39;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 190;
	c = ~c;
	c -= 53;
	return c;
}

unsigned char e121(unsigned char c)
{
	c = -c;
	c ^= 177;
	c = -c;
	c = ~c;
	c -= 179;
	c = ~c;
	c -= 110;
	c ^= 165;
	return c;
}

unsigned char e122(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 70;
	c = ~c;
	c ^= 210;
	c += 160;
	c -= 30;
	c += 204;
	return c;
}

unsigned char e123(unsigned char c)
{
	c ^= 42;
	c = ~c;
	c = -c;
	c -= 100;
	c = -c;
	c ^= 147;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e124(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c -= 11;
	c = ~c;
	c = -c;
	c ^= 148;
	c += 50;
	return c;
}

unsigned char e125(unsigned char c)
{
	c += 0;
	c -= 223;
	c += 245;
	c ^= 251;
	c = -c;
	c -= 215;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e126(unsigned char c)
{
	c = ~c;
	c ^= 48;
	c = -c;
	c -= 207;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 72;
	return c;
}

unsigned char e127(unsigned char c)
{
	c += 6;
	c = ~c;
	c += 29;
	c ^= 99;
	c = -c;
	c += 222;
	c -= 140;
	c ^= 234;
	return c;
}

unsigned char e128(unsigned char c)
{
	c += 120;
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 141;
	c = -c;
	c ^= 154;
	c += 168;
	return c;
}

unsigned char e129(unsigned char c)
{
	c -= 102;
	c = ~c;
	c = -c;
	c = ~c;
	c += 67;
	c -= 249;
	c += 159;
	c = ~c;
	return c;
}

unsigned char e130(unsigned char c)
{
	c = ~c;
	c -= 187;
	c += 49;
	c ^= 151;
	c -= 109;
	c = -c;
	c -= 240;
	c = ~c;
	return c;
}

unsigned char e131(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 37;
	c -= 171;
	c = ~c;
	c -= 198;
	c ^= 180;
	c -= 82;
	return c;
}

unsigned char e132(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 158;
	c = ~c;
	c = -c;
	c -= 56;
	c = ~c;
	c += 119;
	return c;
}

unsigned char e133(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 19;
	c = -c;
	c = ~c;
	c += 5;
	c = ~c;
	c += 38;
	return c;
}

unsigned char e134(unsigned char c)
{
	c = ~c;
	c += 178;
	c = ~c;
	c -= 254;
	c ^= 117;
	c = -c;
	c = ~c;
	c += 241;
	return c;
}

unsigned char e135(unsigned char c)
{
	c -= 87;
	c = ~c;
	c += 98;
	c -= 176;
	c = ~c;
	c -= 79;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e136(unsigned char c)
{
	c = -c;
	c += 200;
	c = ~c;
	c -= 71;
	c = ~c;
	c -= 18;
	c = ~c;
	c -= 153;
	return c;
}

unsigned char e137(unsigned char c)
{
	c -= 63;
	c = ~c;
	c += 106;
	c -= 248;
	c ^= 54;
	c = ~c;
	c -= 211;
	c = -c;
	return c;
}

unsigned char e138(unsigned char c)
{
	c ^= 14;
	c -= 60;
	c = ~c;
	c = -c;
	c -= 40;
	c = ~c;
	c -= 39;
	c = ~c;
	return c;
}

unsigned char e139(unsigned char c)
{
	c -= 114;
	c += 64;
	c -= 190;
	c += 108;
	c -= 59;
	c = -c;
	c = ~c;
	c -= 237;
	return c;
}

unsigned char e140(unsigned char c)
{
	c = -c;
	c ^= 112;
	c = ~c;
	c += 156;
	c -= 43;
	c ^= 33;
	c = -c;
	c ^= 52;
	return c;
}

unsigned char e141(unsigned char c)
{
	c += 210;
	c = ~c;
	c ^= 89;
	c -= 255;
	c = -c;
	c -= 42;
	c ^= 184;
	c -= 247;
	return c;
}

unsigned char e142(unsigned char c)
{
	c = -c;
	c -= 130;
	c = -c;
	c = ~c;
	c += 252;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e143(unsigned char c)
{
	c ^= 166;
	c = -c;
	c ^= 61;
	c -= 131;
	c ^= 126;
	c -= 44;
	c = -c;
	c += 24;
	return c;
}

unsigned char e144(unsigned char c)
{
	c ^= 86;
	c = -c;
	c += 173;
	c = ~c;
	c ^= 48;
	c += 46;
	c ^= 92;
	c = ~c;
	return c;
}

unsigned char e145(unsigned char c)
{
	c ^= 235;
	c = -c;
	c += 244;
	c -= 99;
	c += 25;
	c ^= 191;
	c -= 213;
	c = -c;
	return c;
}

unsigned char e146(unsigned char c)
{
	c ^= 81;
	c -= 183;
	c = -c;
	c = ~c;
	c ^= 83;
	c = -c;
	c += 142;
	c = ~c;
	return c;
}

unsigned char e147(unsigned char c)
{
	c = -c;
	c ^= 154;
	c += 168;
	c = ~c;
	c += 84;
	c = -c;
	c += 192;
	c ^= 62;
	return c;
}

unsigned char e148(unsigned char c)
{
	c += 236;
	c = -c;
	c = ~c;
	c += 216;
	c = -c;
	c ^= 132;
	c -= 162;
	c = ~c;
	return c;
}

unsigned char e149(unsigned char c)
{
	c -= 105;
	c = ~c;
	c ^= 37;
	c = -c;
	c ^= 8;
	c += 198;
	c = -c;
	c ^= 35;
	return c;
}

unsigned char e150(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c -= 76;
	c = -c;
	c = ~c;
	c += 56;
	c -= 118;
	return c;
}

unsigned char e151(unsigned char c)
{
	c = -c;
	c += 77;
	c -= 19;
	c = ~c;
	c ^= 78;
	c += 5;
	c = ~c;
	c += 104;
	return c;
}

unsigned char e152(unsigned char c)
{
	c = -c;
	c ^= 103;
	c -= 189;
	c = ~c;
	c -= 128;
	c = ~c;
	c ^= 95;
	c = ~c;
	return c;
}

unsigned char e153(unsigned char c)
{
	c -= 10;
	c ^= 152;
	c -= 87;
	c ^= 45;
	c = ~c;
	c -= 41;
	c = -c;
	c += 220;
	return c;
}

unsigned char e154(unsigned char c)
{
	c = ~c;
	c += 107;
	c = ~c;
	c += 134;
	c ^= 116;
	c = -c;
	c += 94;
	c ^= 12;
	return c;
}

unsigned char e155(unsigned char c)
{
	c = -c;
	c ^= 91;
	c = -c;
	c += 54;
	c -= 164;
	c += 194;
	c = -c;
	c -= 9;
	return c;
}

unsigned char e156(unsigned char c)
{
	c -= 47;
	c += 197;
	c ^= 75;
	c -= 65;
	c ^= 39;
	c -= 125;
	c = ~c;
	c ^= 121;
	return c;
}

unsigned char e157(unsigned char c)
{
	c -= 31;
	c = ~c;
	c ^= 88;
	c = -c;
	c -= 4;
	c ^= 34;
	c = -c;
	c ^= 233;
	return c;
}

unsigned char e158(unsigned char c)
{
	c -= 15;
	c = -c;
	c += 122;
	c ^= 136;
	c -= 70;
	c = -c;
	c = ~c;
	c += 163;
	return c;
}

unsigned char e159(unsigned char c)
{
	c = ~c;
	c += 255;
	c = -c;
	c -= 184;
	c += 246;
	c ^= 100;
	c = ~c;
	c ^= 147;
	return c;
}

unsigned char e160(unsigned char c)
{
	c = ~c;
	c += 206;
	c = -c;
	c -= 218;
	c = -c;
	c = ~c;
	c = -c;
	c -= 231;
	return c;
}

unsigned char e161(unsigned char c)
{
	c += 61;
	c = -c;
	c ^= 126;
	c -= 44;
	c += 138;
	c = -c;
	c ^= 113;
	c = ~c;
	return c;
}

unsigned char e162(unsigned char c)
{
	c ^= 196;
	c = ~c;
	c = -c;
	c ^= 169;
	c = -c;
	c = ~c;
	c -= 101;
	c += 235;
	return c;
}

unsigned char e163(unsigned char c)
{
	c ^= 225;
	c = -c;
	c -= 29;
	c += 99;
	c = ~c;
	c += 222;
	c -= 140;
	c ^= 234;
	return c;
}

unsigned char e164(unsigned char c)
{
	c = ~c;
	c -= 81;
	c = -c;
	c = ~c;
	c += 66;
	c = -c;
	c -= 137;
	c += 175;
	return c;
}

unsigned char e165(unsigned char c)
{
	c -= 69;
	c = ~c;
	c = -c;
	c += 253;
	c -= 192;
	c ^= 62;
	c += 236;
	c = ~c;
	return c;
}

unsigned char e166(unsigned char c)
{
	c += 187;
	c = ~c;
	c ^= 22;
	c += 132;
	c = ~c;
	c = -c;
	c += 240;
	c -= 143;
	return c;
}

unsigned char e167(unsigned char c)
{
	c = -c;
	c += 250;
	c ^= 8;
	c = ~c;
	c -= 180;
	c += 82;
	c -= 32;
	c = ~c;
	return c;
}

unsigned char e168(unsigned char c)
{
	c = ~c;
	c -= 76;
	c = ~c;
	c += 155;
	c = -c;
	c ^= 119;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e169(unsigned char c)
{
	c -= 19;
	c += 73;
	c = ~c;
	c += 5;
	c -= 139;
	c = ~c;
	c -= 38;
	c = -c;
	return c;
}

unsigned char e170(unsigned char c)
{
	c = -c;
	c ^= 128;
	c = ~c;
	c -= 95;
	c = -c;
	c ^= 10;
	c -= 152;
	c += 214;
	return c;
}

unsigned char e171(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 176;
	c = -c;
	c -= 220;
	c = ~c;
	c -= 97;
	c += 71;
	return c;
}

unsigned char e172(unsigned char c)
{
	c = -c;
	c += 18;
	c ^= 224;
	c = -c;
	c ^= 12;
	c = ~c;
	c -= 91;
	c = ~c;
	return c;
}

unsigned char e173(unsigned char c)
{
	c = ~c;
	c ^= 55;
	c = -c;
	c ^= 194;
	c -= 16;
	c = -c;
	c -= 47;
	c += 197;
	return c;
}

unsigned char e174(unsigned char c)
{
	c += 75;
	c = -c;
	c = ~c;
	c += 212;
	c ^= 195;
	c = ~c;
	c += 31;
	c ^= 53;
	return c;
}

unsigned char e175(unsigned char c)
{
	c ^= 59;
	c -= 177;
	c = -c;
	c ^= 237;
	c = -c;
	c -= 112;
	c = -c;
	c -= 15;
	return c;
}

unsigned char e176(unsigned char c)
{
	c = -c;
	c += 122;
	c ^= 136;
	c += 70;
	c = ~c;
	c ^= 93;
	c = -c;
	c += 160;
	return c;
}

unsigned char e177(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 204;
	c -= 42;
	c += 184;
	c = ~c;
	c += 100;
	c ^= 147;
	return c;
}

unsigned char e178(unsigned char c)
{
	c += 201;
	c = -c;
	c += 252;
	c -= 218;
	c ^= 232;
	c = ~c;
	c ^= 231;
	c = ~c;
	return c;
}

unsigned char e179(unsigned char c)
{
	c ^= 50;
	c += 0;
	c = -c;
	c = ~c;
	c -= 245;
	c += 251;
	c -= 113;
	c = ~c;
	return c;
}

unsigned char e180(unsigned char c)
{
	c = ~c;
	c -= 173;
	c = ~c;
	c -= 48;
	c ^= 46;
	c -= 101;
	c = ~c;
	c ^= 225;
	return c;
}

unsigned char e181(unsigned char c)
{
	c = ~c;
	c -= 244;
	c = -c;
	c -= 99;
	c = -c;
	c ^= 222;
	c -= 140;
	c ^= 219;
	return c;
}

unsigned char e182(unsigned char c)
{
	c += 81;
	c = ~c;
	c ^= 36;
	c = -c;
	c ^= 83;
	c = ~c;
	c ^= 142;
	c = ~c;
	return c;
}

unsigned char e183(unsigned char c)
{
	c -= 69;
	c = -c;
	c = ~c;
	c = -c;
	c -= 102;
	c = ~c;
	c = -c;
	c ^= 192;
	return c;
}

unsigned char e184(unsigned char c)
{
	c = -c;
	c ^= 159;
	c = -c;
	c ^= 74;
	c = ~c;
	c ^= 49;
	c -= 151;
	c = -c;
	return c;
}

unsigned char e185(unsigned char c)
{
	c += 162;
	c ^= 240;
	c -= 238;
	c = ~c;
	c = -c;
	c += 250;
	c -= 161;
	c = -c;
	return c;
}

unsigned char e186(unsigned char c)
{
	c += 180;
	c = ~c;
	c ^= 35;
	c = ~c;
	c += 158;
	c -= 76;
	c ^= 170;
	c = ~c;
	return c;
}

unsigned char e187(unsigned char c)
{
	c = -c;
	c ^= 118;
	c = ~c;
	c -= 77;
	c += 80;
	c = -c;
	c += 111;
	c ^= 90;
	return c;
}

unsigned char e188(unsigned char c)
{
	c = ~c;
	c -= 129;
	c ^= 189;
	c = ~c;
	c += 95;
	c = ~c;
	c -= 10;
	c += 152;
	return c;
}

unsigned char e189(unsigned char c)
{
	c = ~c;
	c += 87;
	c = ~c;
	c -= 98;
	c ^= 176;
	c -= 174;
	c += 220;
	c -= 186;
	return c;
}

unsigned char e190(unsigned char c)
{
	c = ~c;
	c -= 97;
	c = ~c;
	c ^= 157;
	c = -c;
	c = ~c;
	c ^= 94;
	c = -c;
	return c;
}

unsigned char e191(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 209;
	c = -c;
	c += 164;
	c = -c;
	c -= 211;
	c = ~c;
	return c;
}

unsigned char e192(unsigned char c)
{
	c += 14;
	c ^= 60;
	c -= 26;
	c ^= 40;
	c = ~c;
	c = -c;
	c ^= 212;
	c = ~c;
	return c;
}

unsigned char e193(unsigned char c)
{
	c = ~c;
	c += 64;
	c ^= 31;
	c = ~c;
	c = -c;
	c += 88;
	c -= 23;
	c = -c;
	return c;
}

unsigned char e194(unsigned char c)
{
	c -= 112;
	c = ~c;
	c = -c;
	c -= 156;
	c += 122;
	c = -c;
	c ^= 7;
	c += 93;
	return c;
}

unsigned char e195(unsigned char c)
{
	c += 163;
	c ^= 89;
	c = ~c;
	c ^= 204;
	c += 42;
	c = -c;
	c -= 145;
	c = ~c;
	return c;
}

unsigned char e196(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 130;
	c += 208;
	c ^= 206;
	c -= 252;
	c ^= 232;
	c = ~c;
	return c;
}

unsigned char e197(unsigned char c)
{
	c ^= 148;
	c = ~c;
	c += 131;
	c -= 57;
	c ^= 223;
	c = ~c;
	c ^= 251;
	c += 113;
	return c;
}

unsigned char e198(unsigned char c)
{
	c += 215;
	c ^= 226;
	c = ~c;
	c -= 169;
	c ^= 207;
	c -= 101;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e199(unsigned char c)
{
	c += 225;
	c = -c;
	c = ~c;
	c ^= 29;
	c += 99;
	c ^= 222;
	c -= 140;
	c += 234;
	return c;
}

unsigned char e200(unsigned char c)
{
	c -= 120;
	c ^= 182;
	c += 36;
	c -= 66;
	c = ~c;
	c += 137;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e201(unsigned char c)
{
	c -= 69;
	c += 203;
	c = -c;
	c += 102;
	c = ~c;
	c -= 253;
	c += 67;
	c = -c;
	return c;
}

unsigned char e202(unsigned char c)
{
	c = -c;
	c += 236;
	c = ~c;
	c = -c;
	c ^= 216;
	c += 22;
	c -= 132;
	c ^= 162;
	return c;
}

unsigned char e203(unsigned char c)
{
	c ^= 240;
	c = -c;
	c += 250;
	c -= 161;
	c += 135;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e204(unsigned char c)
{
	c += 32;
	c = -c;
	c -= 76;
	c = -c;
	c ^= 56;
	c = -c;
	c -= 228;
	c = -c;
	return c;
}

unsigned char e205(unsigned char c)
{
	c -= 19;
	c ^= 73;
	c = ~c;
	c ^= 5;
	c += 139;
	c -= 129;
	c ^= 103;
	c += 189;
	return c;
}

unsigned char e206(unsigned char c)
{
	c = -c;
	c -= 128;
	c += 254;
	c = ~c;
	c = -c;
	c += 10;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e207(unsigned char c)
{
	c -= 214;
	c += 68;
	c = ~c;
	c ^= 176;
	c += 174;
	c -= 220;
	c = -c;
	c -= 200;
	return c;
}

unsigned char e208(unsigned char c)
{
	c += 134;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 94;
	c += 85;
	c ^= 248;
	c -= 54;
	return c;
}

unsigned char e209(unsigned char c)
{
	c = ~c;
	c += 13;
	c -= 211;
	c += 9;
	c ^= 47;
	c -= 26;
	c ^= 40;
	c += 39;
	return c;
}

unsigned char e210(unsigned char c)
{
	c += 125;
	c ^= 195;
	c += 190;
	c = -c;
	c += 202;
	c = -c;
	c = ~c;
	c += 4;
	return c;
}

unsigned char e211(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 15;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e212(unsigned char c)
{
	c += 136;
	c -= 70;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c += 30;
	c ^= 204;
	return c;
}

unsigned char e213(unsigned char c)
{
	c = -c;
	c += 27;
	c -= 246;
	c = -c;
	c ^= 147;
	c = -c;
	c = ~c;
	c ^= 239;
	return c;
}

unsigned char e214(unsigned char c)
{
	c -= 133;
	c = -c;
	c += 232;
	c = -c;
	c -= 148;
	c = -c;
	c -= 126;
	c = ~c;
	return c;
}

unsigned char e215(unsigned char c)
{
	c = ~c;
	c ^= 138;
	c -= 24;
	c += 215;
	c ^= 173;
	c = ~c;
	c = -c;
	c += 207;
	return c;
}

unsigned char e216(unsigned char c)
{
	c = ~c;
	c -= 58;
	c += 225;
	c ^= 244;
	c = ~c;
	c -= 99;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e217(unsigned char c)
{
	c = ~c;
	c -= 234;
	c += 120;
	c = ~c;
	c ^= 83;
	c = -c;
	c -= 175;
	c += 154;
	return c;
}

unsigned char e218(unsigned char c)
{
	c -= 168;
	c = -c;
	c ^= 84;
	c = -c;
	c += 249;
	c = ~c;
	c += 236;
	c ^= 74;
	return c;
}

unsigned char e219(unsigned char c)
{
	c -= 216;
	c = ~c;
	c = -c;
	c += 109;
	c = -c;
	c = ~c;
	c ^= 143;
	c = -c;
	return c;
}

unsigned char e220(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 135;
	c ^= 82;
	c -= 32;
	c ^= 158;
	return c;
}

unsigned char e221(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 170;
	c -= 56;
	c += 118;
	c = -c;
	c ^= 77;
	c -= 19;
	return c;
}

unsigned char e222(unsigned char c)
{
	c = -c;
	c -= 78;
	c = -c;
	c ^= 5;
	c = ~c;
	c -= 104;
	c = ~c;
	c ^= 20;
	return c;
}

unsigned char e223(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 128;
	c += 254;
	c = ~c;
	c += 117;
	c -= 123;
	c ^= 241;
	return c;
}

unsigned char e224(unsigned char c)
{
	c ^= 87;
	c = -c;
	c += 98;
	c = -c;
	c -= 174;
	c += 220;
	c -= 186;
	c = -c;
	return c;
}

unsigned char e225(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 116;
	c = -c;
	c += 224;
	c = -c;
	c ^= 12;
	c -= 248;
	return c;
}

unsigned char e226(unsigned char c)
{
	c = -c;
	c -= 55;
	c = -c;
	c = ~c;
	c -= 211;
	c ^= 9;
	c -= 26;
	c += 40;
	return c;
}

unsigned char e227(unsigned char c)
{
	c = -c;
	c -= 39;
	c = ~c;
	c ^= 114;
	c = -c;
	c = ~c;
	c += 190;
	c = ~c;
	return c;
}

unsigned char e228(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 150;
	c = ~c;
	c ^= 237;
	c = -c;
	c += 112;
	c ^= 15;
	return c;
}

unsigned char e229(unsigned char c)
{
	c -= 165;
	c ^= 43;
	c += 33;
	c = -c;
	c -= 52;
	c += 163;
	c -= 89;
	c ^= 204;
	return c;
}

unsigned char e230(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 184;
	c = -c;
	c ^= 247;
	c += 205;
	c ^= 147;
	c -= 201;
	return c;
}

unsigned char e231(unsigned char c)
{
	c += 239;
	c = ~c;
	c -= 218;
	c += 232;
	c = ~c;
	c += 231;
	c ^= 61;
	c += 131;
	return c;
}

unsigned char e232(unsigned char c)
{
	c += 57;
	c = ~c;
	c ^= 245;
	c -= 251;
	c += 113;
	c ^= 215;
	c -= 173;
	c = ~c;
	return c;
}

unsigned char e233(unsigned char c)
{
	c += 48;
	c = ~c;
	c -= 58;
	c = ~c;
	c += 6;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e234(unsigned char c)
{
	c += 99;
	c = -c;
	c += 191;
	c ^= 213;
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 183;
	return c;
}

unsigned char e235(unsigned char c)
{
	c += 141;
	c ^= 83;
	c = -c;
	c += 142;
	c = -c;
	c = ~c;
	c += 154;
	c = -c;
	return c;
}

unsigned char e236(unsigned char c)
{
	c ^= 193;
	c += 167;
	c ^= 253;
	c += 67;
	c -= 249;
	c ^= 159;
	c -= 74;
	c += 216;
	return c;
}

unsigned char e237(unsigned char c)
{
	c -= 22;
	c ^= 132;
	c -= 162;
	c = -c;
	c += 143;
	c -= 37;
	c ^= 171;
	c = -c;
	return c;
}

unsigned char e238(unsigned char c)
{
	c -= 198;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 35;
	c = ~c;
	c ^= 158;
	c = ~c;
	return c;
}

unsigned char e239(unsigned char c)
{
	c += 149;
	c -= 17;
	c ^= 228;
	c = ~c;
	c -= 19;
	c ^= 78;
	c = ~c;
	c ^= 5;
	return c;
}

unsigned char e240(unsigned char c)
{
	c -= 139;
	c = -c;
	c += 38;
	c = -c;
	c -= 189;
	c = -c;
	c = ~c;
	c ^= 254;
	return c;
}

unsigned char e241(unsigned char c)
{
	c = ~c;
	c -= 117;
	c = ~c;
	c ^= 152;
	c = -c;
	c ^= 87;
	c -= 45;
	c = ~c;
	return c;
}

unsigned char e242(unsigned char c)
{
	c -= 176;
	c ^= 174;
	c -= 220;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 116;
	return c;
}

unsigned char e243(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 12;
	c = ~c;
	c -= 91;
	c ^= 54;
	c = -c;
	return c;
}

unsigned char e244(unsigned char c)
{
	c -= 13;
	c ^= 16;
	c = ~c;
	c += 47;
	c ^= 197;
	c += 75;
	c ^= 65;
	c += 212;
	return c;
}

unsigned char e245(unsigned char c)
{
	c = ~c;
	c ^= 195;
	c -= 121;
	c = -c;
	c += 108;
	c = ~c;
	c ^= 59;
	c -= 150;
	return c;
}

unsigned char e246(unsigned char c)
{
	c -= 4;
	c ^= 34;
	c -= 110;
	c ^= 156;
	c = ~c;
	c += 43;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e247(unsigned char c)
{
	c += 7;
	c = -c;
	c ^= 210;
	c -= 160;
	c ^= 30;
	c -= 21;
	c = ~c;
	c ^= 246;
	return c;
}

unsigned char e248(unsigned char c)
{
	c += 100;
	c = ~c;
	c ^= 147;
	c = ~c;
	c += 206;
	c ^= 252;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e249(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 166;
	c += 61;
	c -= 131;
	c = ~c;
	c -= 126;
	c = ~c;
	return c;
}

unsigned char e250(unsigned char c)
{
	c = ~c;
	c ^= 138;
	c = -c;
	c ^= 86;
	c += 196;
	c = ~c;
	c -= 115;
	c ^= 169;
	return c;
}

unsigned char e251(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c -= 58;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 199;
	return c;
}

unsigned char e252(unsigned char c)
{
	c -= 29;
	c += 96;
	c -= 222;
	c = ~c;
	c = -c;
	c ^= 219;
	c = ~c;
	c -= 182;
	return c;
}

unsigned char e253(unsigned char c)
{
	c ^= 36;
	c -= 137;
	c = -c;
	c += 188;
	c = -c;
	c ^= 193;
	c -= 167;
	c += 253;
	return c;
}

unsigned char e254(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 159;
	c = ~c;
	c += 74;
	c = -c;
	return c;
}

unsigned char e255(unsigned char c)
{
	c += 49;
	c ^= 151;
	c -= 109;
	c = -c;
	c -= 240;
	c += 238;
	c -= 37;
	c = ~c;
	return c;
}

unsigned char e256(unsigned char c)
{
	c -= 8;
	c += 198;
	c ^= 221;
	c += 32;
	c ^= 158;
	c = ~c;
	c = -c;
	c += 170;
	return c;
}

unsigned char e257(unsigned char c)
{
	c = -c;
	c ^= 17;
	c = ~c;
	c += 228;
	c -= 19;
	c = ~c;
	c = -c;
	c += 90;
	return c;
}

unsigned char e258(unsigned char c)
{
	c = -c;
	c += 103;
	c = -c;
	c = ~c;
	c = -c;
	c -= 185;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e259(unsigned char c)
{
	c ^= 117;
	c += 123;
	c ^= 214;
	c = -c;
	c += 45;
	c -= 243;
	c = ~c;
	c -= 79;
	return c;
}

unsigned char e260(unsigned char c)
{
	c = ~c;
	c -= 186;
	c = -c;
	c ^= 97;
	c += 71;
	c = -c;
	c -= 18;
	c = -c;
	return c;
}

unsigned char e261(unsigned char c)
{
	c = -c;
	c -= 94;
	c ^= 12;
	c = ~c;
	c = -c;
	c += 209;
	c = ~c;
	c ^= 164;
	return c;
}

unsigned char e262(unsigned char c)
{
	c ^= 194;
	c = -c;
	c -= 9;
	c = ~c;
	c ^= 60;
	c = -c;
	c -= 75;
	c += 65;
	return c;
}

unsigned char e263(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 114;
	c ^= 121;
	c = ~c;
	c += 108;
	c = -c;
	c -= 88;
	return c;
}

unsigned char e264(unsigned char c)
{
	c = -c;
	c ^= 23;
	c = ~c;
	c = -c;
	c ^= 112;
	c = ~c;
	c -= 165;
	c = ~c;
	return c;
}

unsigned char e265(unsigned char c)
{
	c -= 136;
	c ^= 52;
	c += 210;
	c ^= 160;
	c = -c;
	c ^= 255;
	c = ~c;
	c += 184;
	return c;
}

unsigned char e266(unsigned char c)
{
	c += 246;
	c = ~c;
	c -= 205;
	c ^= 147;
	c = ~c;
	c -= 206;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e267(unsigned char c)
{
	c -= 11;
	c = -c;
	c -= 166;
	c = -c;
	c = ~c;
	c += 131;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e268(unsigned char c)
{
	c -= 223;
	c = -c;
	c -= 138;
	c = ~c;
	c += 86;
	c = ~c;
	c ^= 173;
	c -= 115;
	return c;
}

unsigned char e269(unsigned char c)
{
	c = -c;
	c ^= 46;
	c = ~c;
	c -= 58;
	c = -c;
	c = ~c;
	c += 244;
	c = ~c;
	return c;
}

unsigned char e270(unsigned char c)
{
	c += 99;
	c = ~c;
	c -= 222;
	c = ~c;
	c = -c;
	c += 234;
	c ^= 120;
	c = -c;
	return c;
}

unsigned char e271(unsigned char c)
{
	c = -c;
	c += 36;
	c = -c;
	c ^= 83;
	c -= 137;
	c ^= 175;
	c = ~c;
	c += 154;
	return c;
}

unsigned char e272(unsigned char c)
{
	c ^= 168;
	c = -c;
	c ^= 167;
	c = ~c;
	c = -c;
	c += 67;
	c = ~c;
	c += 159;
	return c;
}

unsigned char e273(unsigned char c)
{
	c ^= 181;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 22;
	c -= 132;
	c += 162;
	c = ~c;
	return c;
}

unsigned char e274(unsigned char c)
{
	c = ~c;
	c -= 238;
	c = ~c;
	c -= 171;
	c ^= 161;
	c = -c;
	c ^= 180;
	c = -c;
	return c;
}

unsigned char e275(unsigned char c)
{
	c -= 35;
	c ^= 217;
	c += 127;
	c -= 170;
	c = ~c;
	c -= 17;
	c += 119;
	c ^= 77;
	return c;
}

unsigned char e276(unsigned char c)
{
	c -= 19;
	c += 73;
	c ^= 111;
	c = -c;
	c += 90;
	c ^= 104;
	c -= 38;
	c += 20;
	return c;
}

unsigned char e277(unsigned char c)
{
	c -= 178;
	c ^= 128;
	c = -c;
	c = ~c;
	c -= 117;
	c ^= 123;
	c -= 241;
	c ^= 68;
	return c;
}

unsigned char e278(unsigned char c)
{
	c -= 98;
	c = ~c;
	c += 41;
	c -= 79;
	c += 229;
	c ^= 107;
	c = -c;
	c -= 71;
	return c;
}

unsigned char e279(unsigned char c)
{
	c ^= 157;
	c = ~c;
	c += 224;
	c -= 94;
	c ^= 12;
	c -= 106;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e280(unsigned char c)
{
	c += 54;
	c ^= 13;
	c -= 211;
	c = ~c;
	c += 14;
	c = ~c;
	c = -c;
	c -= 40;
	return c;
}

unsigned char e281(unsigned char c)
{
	c -= 230;
	c ^= 125;
	c = ~c;
	c = -c;
	c ^= 31;
	c -= 53;
	c += 88;
	c ^= 150;
	return c;
}

unsigned char e282(unsigned char c)
{
	c += 4;
	c -= 34;
	c = -c;
	c = ~c;
	c ^= 156;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e283(unsigned char c)
{
	c += 70;
	c = -c;
	c += 93;
	c = -c;
	c += 160;
	c = -c;
	c -= 255;
	c = ~c;
	return c;
}

unsigned char e284(unsigned char c)
{
	c ^= 42;
	c = -c;
	c = ~c;
	c = -c;
	c -= 100;
	c ^= 130;
	c = ~c;
	c += 201;
	return c;
}

unsigned char e285(unsigned char c)
{
	c -= 239;
	c = ~c;
	c = -c;
	c -= 232;
	c = ~c;
	c += 231;
	c -= 61;
	c += 0;
	return c;
}

unsigned char e286(unsigned char c)
{
	c = ~c;
	c += 223;
	c ^= 138;
	c += 86;
	c -= 196;
	c ^= 226;
	c = -c;
	c -= 169;
	return c;
}

unsigned char e287(unsigned char c)
{
	c = -c;
	c += 101;
	c ^= 235;
	c -= 225;
	c = -c;
	c ^= 244;
	c -= 146;
	c = -c;
	return c;
}

unsigned char e288(unsigned char c)
{
	c = -c;
	c -= 222;
	c = ~c;
	c += 213;
	c -= 219;
	c = -c;
	c -= 183;
	c += 141;
	return c;
}

unsigned char e289(unsigned char c)
{
	c ^= 83;
	c = ~c;
	c ^= 175;
	c = ~c;
	c += 154;
	c ^= 168;
	c -= 102;
	c ^= 84;
	return c;
}

unsigned char e290(unsigned char c)
{
	c ^= 242;
	c += 192;
	c = ~c;
	c = -c;
	c ^= 236;
	c += 74;
	c ^= 216;
	c = -c;
	return c;
}

unsigned char e291(unsigned char c)
{
	c = -c;
	c ^= 109;
	c = -c;
	c += 240;
	c ^= 238;
	c += 28;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e292(unsigned char c)
{
	c = -c;
	c ^= 161;
	c += 135;
	c ^= 35;
	c = ~c;
	c = -c;
	c ^= 127;
	c -= 149;
	return c;
}

unsigned char e293(unsigned char c)
{
	c -= 155;
	c += 17;
	c -= 228;
	c = -c;
	c -= 19;
	c ^= 73;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e294(unsigned char c)
{
	c = ~c;
	c ^= 104;
	c += 38;
	c ^= 20;
	c = -c;
	c = ~c;
	c += 185;
	c ^= 95;
	return c;
}

unsigned char e295(unsigned char c)
{
	c ^= 117;
	c -= 123;
	c += 241;
	c -= 87;
	c = ~c;
	c -= 243;
	c ^= 41;
	c = -c;
	return c;
}

unsigned char e296(unsigned char c)
{
	c ^= 220;
	c = -c;
	c += 107;
	c ^= 97;
	c = -c;
	c ^= 157;
	c -= 224;
	c = ~c;
	return c;
}

unsigned char e297(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 106;
	c = ~c;
	c += 55;
	c -= 13;
	c += 9;
	return c;
}

unsigned char e298(unsigned char c)
{
	c -= 47;
	c = -c;
	c ^= 75;
	c += 65;
	c ^= 39;
	c += 125;
	c -= 195;
	c = -c;
	return c;
}

unsigned char e299(unsigned char c)
{
	c = -c;
	c ^= 108;
	c = ~c;
	c = -c;
	c -= 177;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e300(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 112;
	c = -c;
	c -= 15;
	c = ~c;
	c -= 122;
	c = -c;
	return c;
}

unsigned char e301(unsigned char c)
{
	c -= 33;
	c = ~c;
	c = -c;
	c += 163;
	c ^= 89;
	c += 255;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e302(unsigned char c)
{
	c ^= 27;
	c -= 246;
	c = -c;
	c ^= 205;
	c = ~c;
	c ^= 201;
	c -= 239;
	c += 133;
	return c;
}

unsigned char e303(unsigned char c)
{
	c ^= 11;
	c -= 231;
	c = -c;
	c ^= 50;
	c -= 0;
	c += 126;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e304(unsigned char c)
{
	c -= 138;
	c = ~c;
	c -= 215;
	c = ~c;
	c = -c;
	c -= 115;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e305(unsigned char c)
{
	c = -c;
	c += 92;
	c = -c;
	c = ~c;
	c ^= 72;
	c = -c;
	c += 199;
	c = -c;
	return c;
}

unsigned char e306(unsigned char c)
{
	c += 99;
	c ^= 25;
	c -= 191;
	c = -c;
	c = ~c;
	c += 120;
	c ^= 182;
	c -= 36;
	return c;
}

unsigned char e307(unsigned char c)
{
	c = ~c;
	c ^= 83;
	c += 137;
	c -= 188;
	c = ~c;
	c -= 203;
	c += 193;
	c = -c;
	return c;
}

unsigned char e308(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 67;
	c = -c;
	c += 62;
	c ^= 236;
	c = -c;
	c += 187;
	return c;
}

unsigned char e309(unsigned char c)
{
	c ^= 49;
	c = -c;
	c ^= 132;
	c = -c;
	c ^= 240;
	c = ~c;
	c -= 143;
	c = ~c;
	return c;
}

unsigned char e310(unsigned char c)
{
	c -= 250;
	c = -c;
	c += 161;
	c = ~c;
	c -= 35;
	c = ~c;
	c ^= 149;
	c += 155;
	return c;
}

unsigned char e311(unsigned char c)
{
	c = -c;
	c ^= 118;
	c = ~c;
	c -= 2;
	c += 80;
	c = -c;
	c += 111;
	c = -c;
	return c;
}

unsigned char e312(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 104;
	c = -c;
	c = ~c;
	c -= 20;
	c += 178;
	c = -c;
	return c;
}

unsigned char e313(unsigned char c)
{
	c -= 185;
	c = ~c;
	c = -c;
	c -= 214;
	c += 45;
	c -= 243;
	c ^= 41;
	c -= 220;
	return c;
}

unsigned char e314(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 200;
	c = ~c;
	c -= 116;
	c = ~c;
	c ^= 224;
	c = ~c;
	return c;
}

unsigned char e315(unsigned char c)
{
	c ^= 63;
	c -= 106;
	c ^= 209;
	c = -c;
	c = ~c;
	c -= 211;
	c ^= 9;
	c = -c;
	return c;
}

unsigned char e316(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 75;
	c = ~c;
	c ^= 230;
	c = ~c;
	c -= 114;
	c ^= 121;
	return c;
}

unsigned char e317(unsigned char c)
{
	c = ~c;
	c ^= 108;
	c = ~c;
	c += 59;
	c = ~c;
	c -= 23;
	c = ~c;
	c ^= 34;
	return c;
}

unsigned char e318(unsigned char c)
{
	c = ~c;
	c += 110;
	c = -c;
	c = ~c;
	c -= 122;
	c ^= 136;
	c -= 70;
	c += 52;
	return c;
}

unsigned char e319(unsigned char c)
{
	c += 210;
	c ^= 160;
	c -= 30;
	c = -c;
	c += 21;
	c -= 27;
	c = ~c;
	c ^= 100;
	return c;
}

unsigned char e320(unsigned char c)
{
	c -= 130;
	c += 208;
	c ^= 206;
	c += 133;
	c = ~c;
	c = -c;
	c ^= 1;
	c = ~c;
	return c;
}

unsigned char e321(unsigned char c)
{
	c -= 131;
	c = -c;
	c += 126;
	c = ~c;
	c += 24;
	c -= 86;
	c += 196;
	c -= 226;
	return c;
}

unsigned char e322(unsigned char c)
{
	c = ~c;
	c ^= 207;
	c += 101;
	c -= 235;
	c = ~c;
	c -= 199;
	c = ~c;
	c += 146;
	return c;
}

unsigned char e323(unsigned char c)
{
	c -= 96;
	c = ~c;
	c += 191;
	c = -c;
	c += 219;
	c = -c;
	c += 182;
	c = -c;
	return c;
}

unsigned char e324(unsigned char c)
{
	c -= 141;
	c ^= 83;
	c += 142;
	c = ~c;
	c ^= 203;
	c = ~c;
	c = -c;
	c += 167;
	return c;
}

unsigned char e325(unsigned char c)
{
	c ^= 253;
	c = -c;
	c += 249;
	c ^= 236;
	c += 74;
	c = ~c;
	c -= 151;
	c = ~c;
	return c;
}

unsigned char e326(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 240;
	c = -c;
	c += 28;
	c -= 250;
	c ^= 8;
	c = -c;
	return c;
}

unsigned char e327(unsigned char c)
{
	c = -c;
	c ^= 180;
	c = -c;
	c ^= 35;
	c -= 158;
	c = ~c;
	c -= 149;
	c ^= 155;
	return c;
}

unsigned char e328(unsigned char c)
{
	c = ~c;
	c += 118;
	c ^= 77;
	c -= 19;
	c += 78;
	c = -c;
	c -= 5;
	c ^= 139;
	return c;
}

unsigned char e329(unsigned char c)
{
	c += 129;
	c = -c;
	c = ~c;
	c -= 189;
	c = ~c;
	c += 128;
	c -= 254;
	c += 172;
	return c;
}

unsigned char e330(unsigned char c)
{
	c ^= 10;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 45;
	c -= 243;
	c = -c;
	return c;
}

unsigned char e331(unsigned char c)
{
	c ^= 174;
	c += 229;
	c -= 107;
	c += 97;
	c = -c;
	c += 116;
	c = -c;
	c ^= 227;
	return c;
}

unsigned char e332(unsigned char c)
{
	c ^= 153;
	c -= 63;
	c = ~c;
	c += 106;
	c -= 209;
	c = -c;
	c ^= 164;
	c += 194;
	return c;
}

unsigned char e333(unsigned char c)
{
	c += 16;
	c -= 14;
	c = -c;
	c -= 197;
	c = -c;
	c = ~c;
	c -= 230;
	c = -c;
	return c;
}

unsigned char e334(unsigned char c)
{
	c -= 125;
	c ^= 64;
	c -= 190;
	c ^= 108;
	c = -c;
	c ^= 88;
	c = ~c;
	c -= 23;
	return c;
}

unsigned char e335(unsigned char c)
{
	c += 237;
	c = -c;
	c = ~c;
	c += 233;
	c = -c;
	c = ~c;
	c -= 122;
	c ^= 136;
	return c;
}

unsigned char e336(unsigned char c)
{
	c += 70;
	c ^= 52;
	c = ~c;
	c -= 89;
	c = ~c;
	c = -c;
	c -= 42;
	c += 145;
	return c;
}

unsigned char e337(unsigned char c)
{
	c = ~c;
	c += 100;
	c ^= 208;
	c = ~c;
	c ^= 239;
	c += 133;
	c -= 11;
	c += 1;
	return c;
}

unsigned char e338(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 61;
	c = ~c;
	c ^= 57;
	c += 223;
	c -= 245;
	c ^= 251;
	return c;
}

unsigned char e339(unsigned char c)
{
	c -= 113;
	c += 215;
	c = -c;
	c = ~c;
	c -= 115;
	c += 169;
	c ^= 101;
	c = -c;
	return c;
}

unsigned char e340(unsigned char c)
{
	c += 72;
	c ^= 199;
	c -= 29;
	c += 99;
	c -= 25;
	c ^= 191;
	c -= 213;
	c = -c;
	return c;
}

unsigned char e341(unsigned char c)
{
	c = ~c;
	c ^= 36;
	c += 83;
	c = -c;
	c = ~c;
	c -= 188;
	c = ~c;
	c += 203;
	return c;
}

unsigned char e342(unsigned char c)
{
	c = ~c;
	c -= 102;
	c += 84;
	c ^= 242;
	c += 192;
	c ^= 62;
	c = -c;
	c ^= 49;
	return c;
}

unsigned char e343(unsigned char c)
{
	c -= 151;
	c ^= 109;
	c = -c;
	c -= 105;
	c ^= 143;
	c = ~c;
	c -= 250;
	c ^= 8;
	return c;
}

unsigned char e344(unsigned char c)
{
	c -= 198;
	c = -c;
	c ^= 82;
	c += 217;
	c = -c;
	c = ~c;
	c ^= 149;
	c = -c;
	return c;
}

unsigned char e345(unsigned char c)
{
	c = -c;
	c ^= 17;
	c = -c;
	c = ~c;
	c = -c;
	c += 2;
	c ^= 80;
	c -= 78;
	return c;
}

unsigned char e346(unsigned char c)
{
	c += 124;
	c = ~c;
	c += 139;
	c ^= 20;
	c = -c;
	c ^= 3;
	c += 185;
	c ^= 95;
	return c;
}

unsigned char e347(unsigned char c)
{
	c = ~c;
	c ^= 123;
	c = -c;
	c += 87;
	c -= 45;
	c = -c;
	c -= 41;
	c += 79;
	return c;
}

unsigned char e348(unsigned char c)
{
	c ^= 229;
	c = ~c;
	c += 97;
	c ^= 116;
	c += 18;
	c -= 224;
	c += 94;
	c = -c;
	return c;
}

unsigned char e349(unsigned char c)
{
	c = -c;
	c -= 106;
	c = -c;
	c ^= 209;
	c = -c;
	c += 164;
	c = -c;
	c -= 211;
	return c;
}

unsigned char e350(unsigned char c)
{
	c = -c;
	c ^= 14;
	c = ~c;
	c -= 197;
	c = -c;
	c ^= 40;
	c = ~c;
	c += 39;
	return c;
}

unsigned char e351(unsigned char c)
{
	c = -c;
	c ^= 114;
	c = ~c;
	c -= 121;
	c ^= 108;
	c -= 202;
	c = ~c;
	c -= 150;
	return c;
}

unsigned char e352(unsigned char c)
{
	c ^= 4;
	c -= 34;
	c += 112;
	c ^= 110;
	c = -c;
	c += 165;
	c = -c;
	c += 136;
	return c;
}

unsigned char e353(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 52;
	c = -c;
	c -= 160;
	c = ~c;
	c += 255;
	c ^= 42;
	return c;
}

unsigned char e354(unsigned char c)
{
	c += 184;
	c ^= 246;
	c = ~c;
	c += 205;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 239;
	return c;
}

unsigned char e355(unsigned char c)
{
	c ^= 133;
	c = -c;
	c ^= 232;
	c = -c;
	c = ~c;
	c ^= 50;
	c -= 0;
	c ^= 126;
	return c;
}

unsigned char e356(unsigned char c)
{
	c += 44;
	c = -c;
	c = ~c;
	c += 113;
	c -= 196;
	c += 226;
	c ^= 169;
	c += 207;
	return c;
}

unsigned char e357(unsigned char c)
{
	c ^= 101;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 99;
	c ^= 25;
	c -= 191;
	return c;
}

unsigned char e358(unsigned char c)
{
	c ^= 213;
	c -= 219;
	c = -c;
	c -= 182;
	c += 36;
	c = -c;
	c += 83;
	c -= 137;
	return c;
}

unsigned char e359(unsigned char c)
{
	c -= 175;
	c ^= 69;
	c = ~c;
	c += 102;
	c = -c;
	c = ~c;
	c += 242;
	c -= 192;
	return c;
}

unsigned char e360(unsigned char c)
{
	c ^= 62;
	c += 181;
	c -= 187;
	c = -c;
	c = ~c;
	c -= 132;
	c ^= 162;
	c -= 240;
	return c;
}

unsigned char e361(unsigned char c)
{
	c = -c;
	c ^= 143;
	c += 37;
	c ^= 171;
	c = ~c;
	c += 198;
	c -= 180;
	c = ~c;
	return c;
}

unsigned char e362(unsigned char c)
{
	c ^= 35;
	c -= 217;
	c = ~c;
	c -= 155;
	c = ~c;
	c ^= 2;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e363(unsigned char c)
{
	c ^= 78;
	c -= 124;
	c = ~c;
	c += 129;
	c -= 103;
	c ^= 189;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e364(unsigned char c)
{
	c -= 185;
	c += 172;
	c ^= 10;
	c += 152;
	c ^= 214;
	c += 68;
	c -= 98;
	c = ~c;
	return c;
}

unsigned char e365(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 220;
	c += 107;
	c = ~c;
	c += 134;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e366(unsigned char c)
{
	c ^= 227;
	c -= 153;
	c = -c;
	c += 85;
	c ^= 91;
	c -= 209;
	c = ~c;
	c -= 194;
	return c;
}

unsigned char e367(unsigned char c)
{
	c ^= 16;
	c = ~c;
	c += 47;
	c -= 197;
	c ^= 75;
	c -= 65;
	c += 212;
	c = ~c;
	return c;
}

unsigned char e368(unsigned char c)
{
	c -= 195;
	c ^= 121;
	c += 31;
	c = -c;
	c += 202;
	c ^= 177;
	c = ~c;
	c += 4;
	return c;
}

unsigned char e369(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 112;
	c = ~c;
	c += 15;
	c -= 122;
	c += 136;
	c -= 70;
	return c;
}

unsigned char e370(unsigned char c)
{
	c = ~c;
	c += 93;
	c = ~c;
	c ^= 160;
	c = ~c;
	c = -c;
	c -= 21;
	c ^= 27;
	return c;
}

unsigned char e371(unsigned char c)
{
	c = ~c;
	c += 246;
	c = -c;
	c += 147;
	c = ~c;
	c ^= 133;
	c += 11;
	c -= 166;
	return c;
}

unsigned char e372(unsigned char c)
{
	c += 148;
	c ^= 0;
	c = ~c;
	c += 44;
	c = -c;
	c -= 251;
	c = -c;
	c += 86;
	return c;
}

unsigned char e373(unsigned char c)
{
	c = -c;
	c += 173;
	c -= 115;
	c = -c;
	c -= 46;
	c += 92;
	c ^= 58;
	c = ~c;
	return c;
}

unsigned char e374(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 199;
	c ^= 29;
	c += 99;
	c = ~c;
	c ^= 222;
	c += 140;
	return c;
}

unsigned char e375(unsigned char c)
{
	c -= 234;
	c = ~c;
	c -= 182;
	c = -c;
	c -= 66;
	c ^= 144;
	c -= 142;
	c ^= 69;
	return c;
}

unsigned char e376(unsigned char c)
{
	c -= 203;
	c = -c;
	c += 167;
	c -= 253;
	c = ~c;
	c = -c;
	c ^= 249;
	c -= 181;
	return c;
}

unsigned char e377(unsigned char c)
{
	c += 187;
	c ^= 22;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c += 105;
	c -= 28;
	return c;
}

unsigned char e378(unsigned char c)
{
	c -= 250;
	c += 8;
	c = -c;
	c ^= 135;
	c += 221;
	c -= 35;
	c ^= 217;
	c += 76;
	return c;
}

unsigned char e379(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 56;
	c = -c;
	c -= 119;
	c += 77;
	c -= 19;
	c += 73;
	return c;
}

unsigned char e380(unsigned char c)
{
	c = -c;
	c += 124;
	c -= 90;
	c = ~c;
	c -= 38;
	c += 189;
	c ^= 3;
	c = -c;
	return c;
}

unsigned char e381(unsigned char c)
{
	c = ~c;
	c += 95;
	c -= 10;
	c = -c;
	c ^= 241;
	c = ~c;
	c ^= 45;
	c -= 243;
	return c;
}

unsigned char e382(unsigned char c)
{
	c += 41;
	c = ~c;
	c ^= 229;
	c = ~c;
	c -= 200;
	c = -c;
	c = ~c;
	c ^= 157;
	return c;
}

unsigned char e383(unsigned char c)
{
	c = ~c;
	c ^= 153;
	c = ~c;
	c = -c;
	c ^= 248;
	c += 54;
	c -= 164;
	c = ~c;
	return c;
}

unsigned char e384(unsigned char c)
{
	c -= 211;
	c = ~c;
	c = -c;
	c += 47;
	c -= 197;
	c = ~c;
	c += 40;
	c -= 230;
	return c;
}

unsigned char e385(unsigned char c)
{
	c ^= 212;
	c -= 114;
	c ^= 64;
	c = ~c;
	c = -c;
	c ^= 108;
	c -= 202;
	c = -c;
	return c;
}

unsigned char e386(unsigned char c)
{
	c = ~c;
	c ^= 150;
	c = ~c;
	c += 237;
	c = -c;
	c -= 233;
	c += 15;
	c = -c;
	return c;
}

unsigned char e387(unsigned char c)
{
	c += 43;
	c ^= 33;
	c += 7;
	c = ~c;
	c += 210;
	c = ~c;
	c -= 89;
	c = ~c;
	return c;
}

unsigned char e388(unsigned char c)
{
	c = -c;
	c ^= 21;
	c -= 27;
	c = -c;
	c = ~c;
	c ^= 247;
	c -= 205;
	c += 147;
	return c;
}

unsigned char e389(unsigned char c)
{
	c ^= 201;
	c = ~c;
	c ^= 252;
	c = ~c;
	c += 232;
	c = ~c;
	c -= 231;
	c = -c;
	return c;
}

unsigned char e390(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 57;
	c += 44;
	c = ~c;
	c -= 24;
	c += 86;
	return c;
}

unsigned char e391(unsigned char c)
{
	c ^= 196;
	c = -c;
	c -= 115;
	c ^= 46;
	c -= 92;
	c ^= 58;
	c -= 72;
	c += 6;
	return c;
}

unsigned char e392(unsigned char c)
{
	c = ~c;
	c += 29;
	c = -c;
	c ^= 96;
	c = -c;
	c += 140;
	c ^= 234;
	c += 120;
	return c;
}

unsigned char e393(unsigned char c)
{
	c = -c;
	c ^= 183;
	c = ~c;
	c += 83;
	c ^= 142;
	c -= 154;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e394(unsigned char c)
{
	c = -c;
	c += 192;
	c = -c;
	c -= 159;
	c ^= 181;
	c -= 216;
	c ^= 22;
	c -= 162;
	return c;
}

unsigned char e395(unsigned char c)
{
	c = ~c;
	c ^= 105;
	c = ~c;
	c ^= 28;
	c = -c;
	c = ~c;
	c -= 198;
	c ^= 180;
	return c;
}

unsigned char e396(unsigned char c)
{
	c ^= 82;
	c += 217;
	c = -c;
	c += 76;
	c = ~c;
	c ^= 155;
	c -= 17;
	c = ~c;
	return c;
}

unsigned char e397(unsigned char c)
{
	c ^= 228;
	c -= 2;
	c = ~c;
	c ^= 73;
	c = -c;
	c -= 124;
	c ^= 139;
	c = ~c;
	return c;
}

unsigned char e398(unsigned char c)
{
	c += 38;
	c = ~c;
	c -= 178;
	c += 185;
	c = -c;
	c += 172;
	c ^= 10;
	c = ~c;
	return c;
}

unsigned char e399(unsigned char c)
{
	c -= 241;
	c = -c;
	c -= 68;
	c ^= 98;
	c += 176;
	c -= 174;
	c = -c;
	c ^= 186;
	return c;
}

unsigned char e400(unsigned char c)
{
	c -= 200;
	c = ~c;
	c += 71;
	c ^= 18;
	c -= 224;
	c ^= 94;
	c = -c;
	c += 85;
	return c;
}

unsigned char e401(unsigned char c)
{
	c -= 91;
	c = -c;
	c = ~c;
	c = -c;
	c += 194;
	c -= 16;
	c += 14;
	c = -c;
	return c;
}

unsigned char e402(unsigned char c)
{
	c = ~c;
	c ^= 26;
	c += 40;
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 114;
	c = ~c;
	return c;
}

unsigned char e403(unsigned char c)
{
	c -= 121;
	c ^= 108;
	c += 202;
	c = ~c;
	c ^= 177;
	c = -c;
	c ^= 237;
	c = -c;
	return c;
}

unsigned char e404(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 110;
	c = -c;
	c -= 43;
	c ^= 33;
	c -= 7;
	c = ~c;
	return c;
}

unsigned char e405(unsigned char c)
{
	c = -c;
	c ^= 89;
	c = -c;
	c -= 21;
	c = ~c;
	c ^= 184;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e406(unsigned char c)
{
	c += 100;
	c = ~c;
	c += 147;
	c = -c;
	c ^= 206;
	c = ~c;
	c ^= 133;
	c -= 11;
	return c;
}

unsigned char e407(unsigned char c)
{
	c = ~c;
	c ^= 166;
	c -= 148;
	c = -c;
	c += 131;
	c = ~c;
	c = -c;
	c -= 223;
	return c;
}

unsigned char e408(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 251;
	c ^= 113;
	c = -c;
	c += 196;
	c = ~c;
	c -= 115;
	return c;
}

unsigned char e409(unsigned char c)
{
	c = ~c;
	c -= 207;
	c = -c;
	c ^= 58;
	c -= 72;
	c = -c;
	c = ~c;
	c ^= 244;
	return c;
}

unsigned char e410(unsigned char c)
{
	c -= 146;
	c = ~c;
	c ^= 25;
	c = ~c;
	c += 140;
	c -= 234;
	c = -c;
	c -= 81;
	return c;
}

unsigned char e411(unsigned char c)
{
	c = -c;
	c ^= 36;
	c += 66;
	c -= 144;
	c = ~c;
	c ^= 175;
	c -= 154;
	c = -c;
	return c;
}

unsigned char e412(unsigned char c)
{
	c = -c;
	c += 102;
	c ^= 84;
	c = ~c;
	c -= 192;
	c = -c;
	c = ~c;
	c ^= 236;
	return c;
}

unsigned char e413(unsigned char c)
{
	c ^= 74;
	c += 216;
	c ^= 151;
	c = -c;
	c = ~c;
	c = -c;
	c += 240;
	c ^= 238;
	return c;
}

unsigned char e414(unsigned char c)
{
	c = ~c;
	c += 37;
	c -= 171;
	c += 198;
	c = -c;
	c -= 221;
	c = ~c;
	c -= 217;
	return c;
}

unsigned char e415(unsigned char c)
{
	c = ~c;
	c += 76;
	c ^= 170;
	c += 56;
	c ^= 118;
	c += 228;
	c = ~c;
	c -= 19;
	return c;
}

unsigned char e416(unsigned char c)
{
	c = -c;
	c += 78;
	c = ~c;
	c -= 90;
	c = -c;
	c = ~c;
	c = -c;
	c -= 103;
	return c;
}

unsigned char e417(unsigned char c)
{
	c -= 189;
	c ^= 3;
	c -= 185;
	c = ~c;
	c += 172;
	c -= 10;
	c ^= 152;
	c -= 214;
	return c;
}

unsigned char e418(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c -= 243;
	c = -c;
	c ^= 174;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e419(unsigned char c)
{
	c ^= 186;
	c = -c;
	c -= 97;
	c ^= 116;
	c += 18;
	c ^= 224;
	c = -c;
	c -= 85;
	return c;
}

unsigned char e420(unsigned char c)
{
	c += 91;
	c = ~c;
	c -= 54;
	c ^= 164;
	c -= 211;
	c ^= 9;
	c -= 47;
	c = ~c;
	return c;
}

unsigned char e421(unsigned char c)
{
	c ^= 26;
	c = ~c;
	c = -c;
	c ^= 230;
	c = ~c;
	c -= 125;
	c ^= 195;
	c = -c;
	return c;
}

unsigned char e422(unsigned char c)
{
	c += 190;
	c ^= 108;
	c = -c;
	c -= 59;
	c = ~c;
	c ^= 23;
	c -= 237;
	c = -c;
	return c;
}

unsigned char e423(unsigned char c)
{
	c -= 112;
	c = -c;
	c ^= 165;
	c = -c;
	c -= 136;
	c ^= 7;
	c = -c;
	c += 160;
	return c;
}

unsigned char e424(unsigned char c)
{
	c += 30;
	c = -c;
	c ^= 21;
	c += 27;
	c ^= 145;
	c = -c;
	c = ~c;
	c ^= 205;
	return c;
}

unsigned char e425(unsigned char c)
{
	c += 147;
	c -= 201;
	c = -c;
	c += 218;
	c = ~c;
	c -= 1;
	c = ~c;
	c += 61;
	return c;
}

unsigned char e426(unsigned char c)
{
	c = -c;
	c ^= 0;
	c -= 126;
	c += 44;
	c = ~c;
	c = -c;
	c -= 113;
	c = ~c;
	return c;
}

unsigned char e427(unsigned char c)
{
	c = ~c;
	c += 226;
	c -= 48;
	c = -c;
	c -= 92;
	c ^= 58;
	c = -c;
	c ^= 225;
	return c;
}

unsigned char e428(unsigned char c)
{
	c = -c;
	c -= 29;
	c = -c;
	c -= 96;
	c = -c;
	c ^= 191;
	c = -c;
	c += 234;
	return c;
}

unsigned char e429(unsigned char c)
{
	c -= 120;
	c += 182;
	c = -c;
	c ^= 66;
	c = ~c;
	c = -c;
	c += 175;
	c = -c;
	return c;
}

unsigned char e430(unsigned char c)
{
	c -= 154;
	c = -c;
	c = ~c;
	c = -c;
	c += 253;
	c = -c;
	c ^= 192;
	c -= 62;
	return c;
}

unsigned char e431(unsigned char c)
{
	c = -c;
	c ^= 181;
	c -= 187;
	c ^= 49;
	c -= 132;
	c += 162;
	c ^= 240;
	c = ~c;
	return c;
}

unsigned char e432(unsigned char c)
{
	c -= 143;
	c ^= 37;
	c -= 8;
	c = -c;
	c += 135;
	c = -c;
	c = ~c;
	c ^= 35;
	return c;
}

unsigned char e433(unsigned char c)
{
	c = -c;
	c ^= 158;
	c += 76;
	c -= 170;
	c ^= 56;
	c += 118;
	c -= 228;
	c += 2;
	return c;
}

unsigned char e434(unsigned char c)
{
	c += 80;
	c -= 78;
	c = ~c;
	c -= 90;
	c = -c;
	c -= 129;
	c ^= 103;
	c -= 189;
	return c;
}

unsigned char e435(unsigned char c)
{
	c = ~c;
	c += 128;
	c -= 117;
	c = -c;
	c -= 152;
	c ^= 68;
	c -= 98;
	c ^= 176;
	return c;
}

unsigned char e436(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 186;
	c = -c;
	c -= 97;
	c ^= 71;
	c -= 157;
	c ^= 227;
	return c;
}

unsigned char e437(unsigned char c)
{
	c ^= 153;
	c = ~c;
	c = -c;
	c ^= 85;
	c = -c;
	c ^= 209;
	c += 55;
	c = -c;
	return c;
}

unsigned char e438(unsigned char c)
{
	c -= 211;
	c = -c;
	c ^= 14;
	c = -c;
	c = ~c;
	c += 26;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e439(unsigned char c)
{
	c -= 230;
	c += 212;
	c -= 114;
	c ^= 64;
	c = -c;
	c -= 53;
	c = ~c;
	c -= 88;
	return c;
}

unsigned char e440(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 4;
	c -= 34;
	c = ~c;
	c ^= 233;
	c -= 15;
	c ^= 165;
	return c;
}

unsigned char e441(unsigned char c)
{
	c ^= 43;
	c += 33;
	c = ~c;
	c ^= 93;
	c = ~c;
	c -= 89;
	c += 255;
	c = ~c;
	return c;
}

unsigned char e442(unsigned char c)
{
	c = -c;
	c ^= 27;
	c -= 145;
	c ^= 130;
	c += 208;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e443(unsigned char c)
{
	c += 218;
	c = ~c;
	c -= 1;
	c = -c;
	c ^= 148;
	c = ~c;
	c += 131;
	c ^= 57;
	return c;
}

unsigned char e444(unsigned char c)
{
	c ^= 223;
	c += 245;
	c -= 251;
	c ^= 113;
	c -= 215;
	c ^= 173;
	c -= 115;
	c ^= 169;
	return c;
}

unsigned char e445(unsigned char c)
{
	c ^= 207;
	c = -c;
	c ^= 58;
	c = -c;
	c += 225;
	c = ~c;
	c = -c;
	c += 146;
	return c;
}

unsigned char e446(unsigned char c)
{
	c ^= 96;
	c = -c;
	c += 140;
	c -= 234;
	c += 120;
	c = ~c;
	c -= 183;
	c = -c;
	return c;
}

unsigned char e447(unsigned char c)
{
	c += 83;
	c = -c;
	c += 142;
	c = ~c;
	c = -c;
	c -= 154;
	c ^= 168;
	c -= 102;
	return c;
}

unsigned char e448(unsigned char c)
{
	c -= 84;
	c = ~c;
	c += 192;
	c -= 62;
	c = -c;
	c = ~c;
	c ^= 74;
	c = ~c;
	return c;
}

unsigned char e449(unsigned char c)
{
	c = ~c;
	c -= 22;
	c = -c;
	c += 109;
	c = -c;
	c -= 105;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e450(unsigned char c)
{
	c ^= 37;
	c += 171;
	c -= 161;
	c += 180;
	c = -c;
	c -= 35;
	c += 217;
	c -= 127;
	return c;
}

unsigned char e451(unsigned char c)
{
	c -= 149;
	c = ~c;
	c -= 56;
	c = ~c;
	c += 119;
	c ^= 77;
	c -= 19;
	c = ~c;
	return c;
}

unsigned char e452(unsigned char c)
{
	c ^= 78;
	c += 5;
	c = -c;
	c ^= 104;
	c += 38;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e453(unsigned char c)
{
	c ^= 3;
	c += 185;
	c = -c;
	c += 172;
	c -= 10;
	c += 152;
	c = -c;
	c -= 87;
	return c;
}

unsigned char e454(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 243;
	c = ~c;
	c ^= 174;
	c = ~c;
	c = -c;
	c += 186;
	return c;
}

unsigned char e455(unsigned char c)
{
	c ^= 200;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c += 153;
	c ^= 63;
	c = ~c;
	return c;
}

unsigned char e456(unsigned char c)
{
	c ^= 106;
	c = ~c;
	c -= 209;
	c ^= 55;
	c = -c;
	c -= 194;
	c += 16;
	c = ~c;
	return c;
}

unsigned char e457(unsigned char c)
{
	c = -c;
	c += 60;
	c = ~c;
	c -= 40;
	c = ~c;
	c -= 39;
	c ^= 125;
	c += 195;
	return c;
}

unsigned char e458(unsigned char c)
{
	c -= 121;
	c = ~c;
	c = -c;
	c += 53;
	c = -c;
	c -= 150;
	c = ~c;
	c ^= 237;
	return c;
}

unsigned char e459(unsigned char c)
{
	c = -c;
	c += 112;
	c -= 110;
	c ^= 165;
	c = ~c;
	c = -c;
	c += 33;
	c = -c;
	return c;
}

unsigned char e460(unsigned char c)
{
	c ^= 52;
	c = ~c;
	c = -c;
	c ^= 30;
	c -= 204;
	c = ~c;
	c = -c;
	c += 145;
	return c;
}

unsigned char e461(unsigned char c)
{
	c -= 247;
	c = ~c;
	c = -c;
	c += 147;
	c = ~c;
	c += 206;
	c = -c;
	c += 218;
	return c;
}

unsigned char e462(unsigned char c)
{
	c -= 232;
	c ^= 166;
	c = -c;
	c = ~c;
	c -= 50;
	c = -c;
	c = ~c;
	c -= 223;
	return c;
}

unsigned char e463(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 24;
	c = ~c;
	c ^= 196;
	c = -c;
	c -= 115;
	c = -c;
	return c;
}

unsigned char e464(unsigned char c)
{
	c -= 46;
	c = -c;
	c += 58;
	c ^= 72;
	c = -c;
	c -= 199;
	c ^= 29;
	c = -c;
	return c;
}

unsigned char e465(unsigned char c)
{
	c = ~c;
	c ^= 25;
	c = ~c;
	c += 140;
	c = -c;
	c += 81;
	c -= 183;
	c += 141;
	return c;
}

unsigned char e466(unsigned char c)
{
	c += 83;
	c -= 137;
	c = ~c;
	c ^= 188;
	c -= 154;
	c ^= 168;
	c += 102;
	c -= 253;
	return c;
}

unsigned char e467(unsigned char c)
{
	c = -c;
	c -= 192;
	c = ~c;
	c += 159;
	c = -c;
	c -= 74;
	c ^= 216;
	c = -c;
	return c;
}

unsigned char e468(unsigned char c)
{
	c -= 151;
	c = -c;
	c = ~c;
	c += 238;
	c ^= 28;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e469(unsigned char c)
{
	c = -c;
	c += 198;
	c ^= 180;
	c += 35;
	c -= 217;
	c += 127;
	c ^= 149;
	c += 155;
	return c;
}

unsigned char e470(unsigned char c)
{
	c ^= 17;
	c -= 77;
	c = -c;
	c += 73;
	c = ~c;
	c -= 124;
	c ^= 139;
	c -= 129;
	return c;
}

unsigned char e471(unsigned char c)
{
	c = -c;
	c += 20;
	c = -c;
	c = ~c;
	c ^= 128;
	c = ~c;
	c ^= 172;
	c += 10;
	return c;
}

unsigned char e472(unsigned char c)
{
	c = -c;
	c ^= 241;
	c = ~c;
	c -= 68;
	c += 98;
	c -= 176;
	c = ~c;
	c += 79;
	return c;
}

unsigned char e473(unsigned char c)
{
	c -= 229;
	c = -c;
	c ^= 200;
	c += 134;
	c ^= 116;
	c += 18;
	c ^= 224;
	c -= 94;
	return c;
}

unsigned char e474(unsigned char c)
{
	c -= 12;
	c = ~c;
	c -= 91;
	c ^= 209;
	c = -c;
	c -= 13;
	c += 16;
	c = -c;
	return c;
}

unsigned char e475(unsigned char c)
{
	c ^= 47;
	c += 197;
	c -= 75;
	c ^= 65;
	c -= 212;
	c += 114;
	c = -c;
	c ^= 190;
	return c;
}

unsigned char e476(unsigned char c)
{
	c = -c;
	c -= 53;
	c ^= 59;
	c = ~c;
	c = -c;
	c -= 23;
	c = -c;
	c += 34;
	return c;
}

unsigned char e477(unsigned char c)
{
	c += 112;
	c ^= 110;
	c += 156;
	c ^= 122;
	c = -c;
	c += 33;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e478(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 160;
	c = -c;
	c -= 255;
	c += 21;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e479(unsigned char c)
{
	c += 246;
	c ^= 100;
	c -= 130;
	c = -c;
	c += 201;
	c ^= 239;
	c = -c;
	c += 218;
	return c;
}

unsigned char e480(unsigned char c)
{
	c -= 232;
	c = ~c;
	c -= 148;
	c ^= 50;
	c += 0;
	c = ~c;
	c += 223;
	c ^= 138;
	return c;
}

unsigned char e481(unsigned char c)
{
	c -= 24;
	c += 86;
	c = ~c;
	c -= 226;
	c += 48;
	c ^= 46;
	c -= 101;
	c = -c;
	return c;
}

unsigned char e482(unsigned char c)
{
	c ^= 72;
	c = ~c;
	c ^= 199;
	c += 29;
	c = -c;
	c += 25;
	c ^= 191;
	c += 213;
	return c;
}

unsigned char e483(unsigned char c)
{
	c ^= 219;
	c = -c;
	c -= 182;
	c = -c;
	c ^= 141;
	c += 83;
	c = ~c;
	c ^= 142;
	return c;
}

unsigned char e484(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 203;
	c ^= 193;
	c -= 167;
	c = -c;
	c += 242;
	c ^= 192;
	return c;
}

unsigned char e485(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 181;
	c = -c;
	c -= 216;
	c = -c;
	c -= 151;
	c = -c;
	return c;
}

unsigned char e486(unsigned char c)
{
	c -= 240;
	c ^= 143;
	c = -c;
	c ^= 250;
	c = -c;
	c = ~c;
	c -= 180;
	c = ~c;
	return c;
}

unsigned char e487(unsigned char c)
{
	c -= 35;
	c = -c;
	c += 76;
	c = -c;
	c -= 17;
	c = -c;
	c += 228;
	c -= 2;
	return c;
}

unsigned char e488(unsigned char c)
{
	c = -c;
	c ^= 73;
	c -= 111;
	c += 5;
	c = -c;
	c -= 38;
	c ^= 20;
	c = ~c;
	return c;
}

unsigned char e489(unsigned char c)
{
	c = -c;
	c ^= 95;
	c = -c;
	c ^= 123;
	c -= 241;
	c += 87;
	c ^= 98;
	c -= 176;
	return c;
}

unsigned char e490(unsigned char c)
{
	c = -c;
	c += 79;
	c -= 229;
	c ^= 107;
	c = -c;
	c += 71;
	c = ~c;
	c ^= 153;
	return c;
}

unsigned char e491(unsigned char c)
{
	c += 63;
	c = ~c;
	c ^= 106;
	c -= 248;
	c += 54;
	c ^= 164;
	c += 194;
	c ^= 16;
	return c;
}

unsigned char e492(unsigned char c)
{
	c += 14;
	c = -c;
	c ^= 65;
	c += 39;
	c = ~c;
	c += 195;
	c = -c;
	c -= 31;
	return c;
}

unsigned char e493(unsigned char c)
{
	c ^= 53;
	c = -c;
	c = ~c;
	c ^= 177;
	c -= 23;
	c = ~c;
	c ^= 34;
	c -= 233;
	return c;
}

unsigned char e494(unsigned char c)
{
	c ^= 15;
	c = -c;
	c ^= 122;
	c = ~c;
	c += 70;
	c = ~c;
	c -= 93;
	c = -c;
	return c;
}

unsigned char e495(unsigned char c)
{
	c -= 160;
	c = -c;
	c += 255;
	c = -c;
	c = ~c;
	c += 27;
	c = ~c;
	c -= 205;
	return c;
}

unsigned char e496(unsigned char c)
{
	c += 147;
	c ^= 201;
	c += 239;
	c -= 133;
	c ^= 11;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e497(unsigned char c)
{
	c += 148;
	c = -c;
	c = ~c;
	c ^= 57;
	c = -c;
	c ^= 44;
	c -= 138;
	c += 24;
	return c;
}

unsigned char e498(unsigned char c)
{
	c += 86;
	c = ~c;
	c ^= 173;
	c -= 115;
	c = ~c;
	c -= 92;
	c += 58;
	c = ~c;
	return c;
}

unsigned char e499(unsigned char c)
{
	c += 6;
	c -= 244;
	c ^= 146;
	c -= 25;
	c += 140;
	c -= 219;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e500(unsigned char c)
{
	c += 183;
	c -= 141;
	c += 83;
	c = ~c;
	c -= 175;
	c = -c;
	c = ~c;
	c += 168;
	return c;
}

unsigned char e501(unsigned char c)
{
	c = ~c;
	c ^= 167;
	c -= 242;
	c = ~c;
	c += 62;
	c = -c;
	c -= 74;
	c += 216;
	return c;
}

unsigned char e502(unsigned char c)
{
	c ^= 22;
	c = ~c;
	c += 109;
	c = -c;
	c = ~c;
	c ^= 105;
	c += 143;
	c = -c;
	return c;
}

unsigned char e503(unsigned char c)
{
	c ^= 250;
	c = -c;
	c -= 198;
	c = ~c;
	c -= 221;
	c += 35;
	c = -c;
	c -= 127;
	return c;
}

unsigned char e504(unsigned char c)
{
	c ^= 149;
	c -= 155;
	c ^= 17;
	c = -c;
	c = ~c;
	c ^= 77;
	c -= 19;
	c = -c;
	return c;
}

unsigned char e505(unsigned char c)
{
	c += 78;
	c -= 124;
	c = -c;
	c -= 139;
	c = -c;
	c += 38;
	c -= 20;
	c = ~c;
	return c;
}

unsigned char e506(unsigned char c)
{
	c -= 3;
	c += 185;
	c -= 95;
	c = ~c;
	c += 10;
	c ^= 152;
	c = ~c;
	c += 87;
	return c;
}

unsigned char e507(unsigned char c)
{
	c ^= 45;
	c -= 243;
	c ^= 41;
	c = ~c;
	c = -c;
	c -= 229;
	c += 107;
	c = -c;
	return c;
}

unsigned char e508(unsigned char c)
{
	c = ~c;
	c -= 71;
	c = ~c;
	c = -c;
	c ^= 227;
	c += 153;
	c ^= 63;
	c = -c;
	return c;
}

unsigned char e509(unsigned char c)
{
	c -= 106;
	c += 248;
	c = ~c;
	c = -c;
	c += 164;
	c ^= 194;
	c = -c;
	c ^= 9;
	return c;
}

unsigned char e510(unsigned char c)
{
	c += 47;
	c = -c;
	c ^= 65;
	c -= 39;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e511(unsigned char c)
{
	c = ~c;
	c ^= 88;
	c += 150;
	c ^= 4;
	c = -c;
	c = ~c;
	c = -c;
	c += 15;
	return c;
}

unsigned char e512(unsigned char c)
{
	c = -c;
	c ^= 122;
	c = ~c;
	c = -c;
	c ^= 7;
	c = -c;
	c += 210;
	c = -c;
	return c;
}

unsigned char e513(unsigned char c)
{
	c = -c;
	c -= 30;
	c += 21;
	c ^= 27;
	c = -c;
	c = ~c;
	c += 247;
	c = ~c;
	return c;
}

unsigned char e514(unsigned char c)
{
	c += 130;
	c -= 208;
	c = ~c;
	c += 239;
	c -= 133;
	c += 11;
	c = -c;
	c ^= 166;
	return c;
}

unsigned char e515(unsigned char c)
{
	c ^= 148;
	c -= 50;
	c = -c;
	c += 57;
	c = ~c;
	c ^= 44;
	c -= 251;
	c = ~c;
	return c;
}

unsigned char e516(unsigned char c)
{
	c = ~c;
	c += 215;
	c = -c;
	c += 226;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e517(unsigned char c)
{
	c ^= 92;
	c += 58;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 29;
	c += 99;
	c ^= 25;
	return c;
}

unsigned char e518(unsigned char c)
{
	c += 191;
	c ^= 213;
	c = ~c;
	c -= 120;
	c ^= 182;
	c = ~c;
	c = -c;
	c += 83;
	return c;
}

unsigned char e519(unsigned char c)
{
	c ^= 137;
	c = -c;
	c = ~c;
	c -= 69;
	c = -c;
	c = ~c;
	c += 193;
	c = ~c;
	return c;
}

unsigned char e520(unsigned char c)
{
	c = ~c;
	c += 253;
	c = ~c;
	c -= 192;
	c += 62;
	c = -c;
	c += 181;
	c = ~c;
	return c;
}

unsigned char e521(unsigned char c)
{
	c = -c;
	c += 22;
	c -= 132;
	c += 162;
	c = -c;
	c = ~c;
	c += 143;
	c = -c;
	return c;
}

unsigned char e522(unsigned char c)
{
	c ^= 250;
	c += 198;
	c ^= 180;
	c -= 35;
	c = ~c;
	c -= 158;
	c ^= 76;
	c += 170;
	return c;
}

unsigned char e523(unsigned char c)
{
	c ^= 56;
	c -= 119;
	c = -c;
	c ^= 2;
	c = ~c;
	c = -c;
	c ^= 124;
	c = -c;
	return c;
}

unsigned char e524(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c ^= 103;
	c -= 189;
	c ^= 3;
	c = ~c;
	c -= 254;
	return c;
}

unsigned char e525(unsigned char c)
{
	c ^= 172;
	c = -c;
	c -= 123;
	c ^= 87;
	c -= 45;
	c += 176;
	c -= 174;
	c += 220;
	return c;
}

unsigned char e526(unsigned char c)
{
	c += 186;
	c = ~c;
	c ^= 97;
	c += 116;
	c ^= 18;
	c += 224;
	c = ~c;
	c -= 63;
	return c;
}

unsigned char e527(unsigned char c)
{
	c += 85;
	c = -c;
	c -= 54;
	c = ~c;
	c -= 13;
	c ^= 9;
	c = ~c;
	c ^= 60;
	return c;
}

unsigned char e528(unsigned char c)
{
	c = ~c;
	c ^= 40;
	c = -c;
	c ^= 114;
	c = -c;
	c -= 190;
	c = -c;
	c ^= 202;
	return c;
}

unsigned char e529(unsigned char c)
{
	c -= 88;
	c = ~c;
	c += 23;
	c = -c;
	c -= 34;
	c = -c;
	c += 233;
	c = ~c;
	return c;
}

unsigned char e530(unsigned char c)
{
	c -= 156;
	c ^= 122;
	c += 136;
	c -= 70;
	c ^= 52;
	c -= 210;
	c += 160;
	c -= 30;
	return c;
}

unsigned char e531(unsigned char c)
{
	c -= 204;
	c = ~c;
	c = -c;
	c += 184;
	c -= 246;
	c = -c;
	c ^= 205;
	c += 147;
	return c;
}

unsigned char e532(unsigned char c)
{
	c -= 201;
	c = ~c;
	c = -c;
	c -= 133;
	c = ~c;
	c ^= 232;
	c -= 166;
	c = -c;
	return c;
}

unsigned char e533(unsigned char c)
{
	c += 61;
	c = -c;
	c += 0;
	c ^= 223;
	c -= 245;
	c = ~c;
	c ^= 113;
	c = -c;
	return c;
}

unsigned char e534(unsigned char c)
{
	c = ~c;
	c ^= 226;
	c -= 48;
	c += 46;
	c = ~c;
	c += 58;
	c = ~c;
	c += 199;
	return c;
}

unsigned char e535(unsigned char c)
{
	c = -c;
	c -= 146;
	c = -c;
	c += 25;
	c = -c;
	c ^= 140;
	c = ~c;
	c += 219;
	return c;
}

unsigned char e536(unsigned char c)
{
	c -= 81;
	c ^= 183;
	c -= 66;
	c = -c;
	c += 142;
	c = -c;
	c -= 69;
	c ^= 203;
	return c;
}

unsigned char e537(unsigned char c)
{
	c += 193;
	c = -c;
	c += 84;
	c = -c;
	c ^= 192;
	c += 62;
	c = -c;
	c -= 181;
	return c;
}

unsigned char e538(unsigned char c)
{
	c += 187;
	c = ~c;
	c += 151;
	c -= 109;
	c = -c;
	c += 240;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e539(unsigned char c)
{
	c = -c;
	c ^= 250;
	c += 8;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 221;
	c += 35;
	return c;
}

unsigned char e540(unsigned char c)
{
	c = -c;
	c -= 158;
	c ^= 76;
	c = -c;
	c += 155;
	c -= 119;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e541(unsigned char c)
{
	c -= 19;
	c += 78;
	c = ~c;
	c ^= 5;
	c -= 104;
	c = ~c;
	c ^= 20;
	c -= 3;
	return c;
}

unsigned char e542(unsigned char c)
{
	c = -c;
	c -= 254;
	c ^= 172;
	c = ~c;
	c += 123;
	c -= 214;
	c = ~c;
	c -= 243;
	return c;
}

unsigned char e543(unsigned char c)
{
	c -= 41;
	c = -c;
	c = ~c;
	c += 186;
	c = ~c;
	c ^= 97;
	c = ~c;
	c ^= 116;
	return c;
}

unsigned char e544(unsigned char c)
{
	c += 18;
	c = ~c;
	c = -c;
	c += 94;
	c -= 12;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e545(unsigned char c)
{
	c -= 164;
	c = -c;
	c = ~c;
	c -= 60;
	c = ~c;
	c -= 75;
	c += 65;
	c = ~c;
	return c;
}

unsigned char e546(unsigned char c)
{
	c -= 212;
	c += 114;
	c -= 190;
	c = -c;
	c = ~c;
	c -= 202;
	c += 88;
	c = ~c;
	return c;
}

unsigned char e547(unsigned char c)
{
	c += 23;
	c -= 237;
	c = -c;
	c -= 112;
	c = ~c;
	c ^= 156;
	c -= 43;
	c += 70;
	return c;
}

unsigned char e548(unsigned char c)
{
	c -= 52;
	c = -c;
	c = ~c;
	c -= 160;
	c ^= 255;
	c -= 27;
	c ^= 145;
	c = -c;
	return c;
}

unsigned char e549(unsigned char c)
{
	c = -c;
	c += 147;
	c = ~c;
	c -= 239;
	c = ~c;
	c = -c;
	c ^= 232;
	c = ~c;
	return c;
}

unsigned char e550(unsigned char c)
{
	c ^= 231;
	c = ~c;
	c ^= 50;
	c -= 0;
	c ^= 126;
	c += 138;
	c ^= 24;
	c = -c;
	return c;
}

unsigned char e551(unsigned char c)
{
	c = -c;
	c ^= 196;
	c = -c;
	c -= 115;
	c ^= 169;
	c = -c;
	c ^= 92;
	c = ~c;
	return c;
}

unsigned char e552(unsigned char c)
{
	c ^= 235;
	c -= 225;
	c = -c;
	c ^= 29;
	c += 99;
	c -= 25;
	c = ~c;
	c ^= 140;
	return c;
}

unsigned char e553(unsigned char c)
{
	c = -c;
	c ^= 219;
	c += 81;
	c ^= 183;
	c = -c;
	c = ~c;
	c += 83;
	c -= 137;
	return c;
}

unsigned char e554(unsigned char c)
{
	c ^= 175;
	c = ~c;
	c = -c;
	c += 203;
	c = ~c;
	c += 167;
	c -= 253;
	c = ~c;
	return c;
}

unsigned char e555(unsigned char c)
{
	c = ~c;
	c += 249;
	c = ~c;
	c = -c;
	c ^= 181;
	c = -c;
	c ^= 216;
	c -= 22;
	return c;
}

unsigned char e556(unsigned char c)
{
	c += 132;
	c = -c;
	c ^= 240;
	c += 238;
	c = ~c;
	c -= 37;
	c = -c;
	c += 8;
	return c;
}

unsigned char e557(unsigned char c)
{
	c -= 198;
	c += 221;
	c -= 35;
	c += 217;
	c = ~c;
	c ^= 76;
	c += 170;
	c = -c;
	return c;
}

unsigned char e558(unsigned char c)
{
	c = ~c;
	c ^= 228;
	c -= 2;
	c += 80;
	c -= 78;
	c ^= 124;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e559(unsigned char c)
{
	c -= 104;
	c += 38;
	c = -c;
	c ^= 189;
	c = -c;
	c += 185;
	c -= 95;
	c ^= 10;
	return c;
}

unsigned char e560(unsigned char c)
{
	c = -c;
	c -= 68;
	c += 98;
	c ^= 176;
	c = ~c;
	c = -c;
	c += 220;
	c = ~c;
	return c;
}

unsigned char e561(unsigned char c)
{
	c ^= 107;
	c += 97;
	c = -c;
	c ^= 157;
	c -= 227;
	c += 153;
	c = -c;
	c -= 12;
	return c;
}

unsigned char e562(unsigned char c)
{
	c += 106;
	c ^= 248;
	c = ~c;
	c ^= 164;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 9;
	return c;
}

unsigned char e563(unsigned char c)
{
	c -= 47;
	c ^= 197;
	c = -c;
	c += 40;
	c = ~c;
	c = -c;
	c += 212;
	c -= 114;
	return c;
}

unsigned char e564(unsigned char c)
{
	c -= 64;
	c = ~c;
	c += 31;
	c = -c;
	c ^= 202;
	c = -c;
	c += 177;
	c ^= 23;
	return c;
}

unsigned char e565(unsigned char c)
{
	c += 237;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 110;
	c -= 156;
	c ^= 122;
	c = ~c;
	return c;
}

unsigned char e566(unsigned char c)
{
	c -= 33;
	c ^= 7;
	c = ~c;
	c += 210;
	c ^= 160;
	c = ~c;
	c = -c;
	c -= 204;
	return c;
}

unsigned char e567(unsigned char c)
{
	c -= 42;
	c = ~c;
	c -= 145;
	c = -c;
	c += 100;
	c -= 130;
	c ^= 208;
	c = -c;
	return c;
}

unsigned char e568(unsigned char c)
{
	c -= 239;
	c = ~c;
	c ^= 11;
	c = ~c;
	c += 148;
	c = ~c;
	c = -c;
	c += 57;
	return c;
}

unsigned char e569(unsigned char c)
{
	c = ~c;
	c ^= 44;
	c -= 138;
	c ^= 113;
	c = -c;
	c += 196;
	c -= 226;
	c = ~c;
	return c;
}

unsigned char e570(unsigned char c)
{
	c = -c;
	c += 46;
	c = ~c;
	c += 235;
	c -= 225;
	c = -c;
	c -= 244;
	c += 146;
	return c;
}

unsigned char e571(unsigned char c)
{
	c -= 96;
	c += 222;
	c ^= 140;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 182;
	return c;
}

unsigned char e572(unsigned char c)
{
	c ^= 36;
	c += 66;
	c = ~c;
	c ^= 142;
	c = -c;
	c = ~c;
	c ^= 154;
	c -= 168;
	return c;
}

unsigned char e573(unsigned char c)
{
	c += 102;
	c -= 84;
	c ^= 67;
	c -= 249;
	c ^= 159;
	c -= 181;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e574(unsigned char c)
{
	c = -c;
	c ^= 151;
	c -= 162;
	c = -c;
	c += 105;
	c -= 143;
	c += 250;
	c = ~c;
	return c;
}

unsigned char e575(unsigned char c)
{
	c += 161;
	c = ~c;
	c = -c;
	c += 35;
	c = ~c;
	c ^= 127;
	c = -c;
	c -= 155;
	return c;
}

unsigned char e576(unsigned char c)
{
	c = ~c;
	c -= 118;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 80;
	c += 111;
	return c;
}

unsigned char e577(unsigned char c)
{
	c ^= 5;
	c -= 139;
	c += 129;
	c -= 20;
	c ^= 128;
	c = ~c;
	c += 95;
	c = ~c;
	return c;
}

unsigned char e578(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 214;
	c = -c;
	c ^= 98;
	c = -c;
	c += 41;
	c ^= 79;
	return c;
}

unsigned char e579(unsigned char c)
{
	c = ~c;
	c -= 200;
	c ^= 134;
	c = ~c;
	c += 157;
	c ^= 227;
	c -= 153;
	c = ~c;
	return c;
}

unsigned char e580(unsigned char c)
{
	c -= 12;
	c = -c;
	c ^= 91;
	c -= 209;
	c += 55;
	c = -c;
	c += 194;
	c = ~c;
	return c;
}

unsigned char e581(unsigned char c)
{
	c += 14;
	c -= 60;
	c = ~c;
	c += 75;
	c = ~c;
	c ^= 230;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e582(unsigned char c)
{
	c -= 195;
	c = -c;
	c = ~c;
	c = -c;
	c -= 108;
	c = ~c;
	c -= 88;
	c = -c;
	return c;
}

unsigned char e583(unsigned char c)
{
	c ^= 23;
	c = -c;
	c ^= 34;
	c += 112;
	c = ~c;
	c = -c;
	c ^= 156;
	c += 122;
	return c;
}

unsigned char e584(unsigned char c)
{
	c = ~c;
	c -= 33;
	c = ~c;
	c += 52;
	c = ~c;
	c += 160;
	c = ~c;
	c -= 204;
	return c;
}

unsigned char e585(unsigned char c)
{
	c ^= 42;
	c += 145;
	c = -c;
	c = ~c;
	c += 205;
	c ^= 208;
	c += 206;
	c = ~c;
	return c;
}

unsigned char e586(unsigned char c)
{
	c = ~c;
	c += 11;
	c -= 166;
	c ^= 148;
	c -= 50;
	c += 0;
	c = -c;
	c ^= 223;
	return c;
}

unsigned char e587(unsigned char c)
{
	c = -c;
	c += 138;
	c -= 113;
	c = ~c;
	c -= 115;
	c ^= 207;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e588(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 199;
	c = ~c;
	c -= 146;
	c = -c;
	c += 25;
	c = -c;
	return c;
}

unsigned char e589(unsigned char c)
{
	c ^= 140;
	c = ~c;
	c ^= 120;
	c -= 182;
	c += 36;
	c ^= 66;
	c += 144;
	c -= 142;
	return c;
}

unsigned char e590(unsigned char c)
{
	c += 188;
	c ^= 154;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 253;
	c = ~c;
	return c;
}

unsigned char e591(unsigned char c)
{
	c ^= 192;
	c = -c;
	c -= 159;
	c ^= 181;
	c = ~c;
	c ^= 49;
	c = -c;
	c -= 132;
	return c;
}

unsigned char e592(unsigned char c)
{
	c = ~c;
	c ^= 51;
	c += 238;
	c -= 37;
	c += 171;
	c = -c;
	c -= 135;
	c ^= 82;
	return c;
}

unsigned char e593(unsigned char c)
{
	c ^= 32;
	c += 158;
	c ^= 76;
	c = ~c;
	c ^= 17;
	c += 119;
	c -= 77;
	c = -c;
	return c;
}

unsigned char e594(unsigned char c)
{
	c = -c;
	c ^= 73;
	c = ~c;
	c = -c;
	c ^= 90;
	c = -c;
	c += 129;
	c = ~c;
	return c;
}

unsigned char e595(unsigned char c)
{
	c += 20;
	c = -c;
	c ^= 3;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 172;
	c -= 123;
	return c;
}

unsigned char e596(unsigned char c)
{
	c ^= 241;
	c -= 87;
	c = ~c;
	c = -c;
	c -= 243;
	c ^= 41;
	c += 220;
	c = ~c;
	return c;
}

unsigned char e597(unsigned char c)
{
	c -= 107;
	c += 97;
	c = ~c;
	c += 116;
	c -= 227;
	c = -c;
	c ^= 94;
	c = ~c;
	return c;
}

unsigned char e598(unsigned char c)
{
	c ^= 85;
	c = -c;
	c += 248;
	c = ~c;
	c ^= 194;
	c += 9;
	c = -c;
	c ^= 60;
	return c;
}

unsigned char e599(unsigned char c)
{
	c = ~c;
	c -= 230;
	c += 114;
	c ^= 121;
	c = ~c;
	c -= 108;
	c += 202;
	c = ~c;
	return c;
}

unsigned char e600(unsigned char c)
{
	c ^= 150;
	c += 4;
	c = -c;
	c ^= 179;
	c = ~c;
	c = -c;
	c -= 156;
	c += 122;
	return c;
}

unsigned char e601(unsigned char c)
{
	c -= 136;
	c += 70;
	c = -c;
	c ^= 163;
	c = ~c;
	c += 30;
	c = ~c;
	c -= 42;
	return c;
}

unsigned char e602(unsigned char c)
{
	c -= 184;
	c += 246;
	c -= 100;
	c += 130;
	c = -c;
	c -= 206;
	c = ~c;
	c += 1;
	return c;
}

unsigned char e603(unsigned char c)
{
	c += 231;
	c ^= 61;
	c = -c;
	c -= 0;
	c = -c;
	c -= 223;
	c += 245;
	c = ~c;
	return c;
}

unsigned char e604(unsigned char c)
{
	c = -c;
	c += 113;
	c -= 215;
	c += 173;
	c -= 115;
	c = ~c;
	c ^= 46;
	c = ~c;
	return c;
}

unsigned char e605(unsigned char c)
{
	c += 101;
	c -= 235;
	c = -c;
	c ^= 6;
	c -= 29;
	c = -c;
	c += 96;
	c ^= 222;
	return c;
}

unsigned char e606(unsigned char c)
{
	c ^= 140;
	c -= 234;
	c = -c;
	c -= 183;
	c = -c;
	c += 83;
	c ^= 142;
	c = -c;
	return c;
}

unsigned char e607(unsigned char c)
{
	c = ~c;
	c ^= 154;
	c = -c;
	c = ~c;
	c += 167;
	c ^= 67;
	c += 249;
	c -= 236;
	return c;
}

unsigned char e608(unsigned char c)
{
	c = -c;
	c += 187;
	c -= 49;
	c = -c;
	c = ~c;
	c += 162;
	c -= 240;
	c ^= 143;
	return c;
}

unsigned char e609(unsigned char c)
{
	c = ~c;
	c += 250;
	c -= 8;
	c ^= 135;
	c = -c;
	c = ~c;
	c += 35;
	c ^= 217;
	return c;
}

unsigned char e610(unsigned char c)
{
	c = ~c;
	c ^= 76;
	c = -c;
	c += 155;
	c -= 17;
	c ^= 119;
	c += 77;
	c = -c;
	return c;
}

unsigned char e611(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c ^= 90;
	c += 129;
	c = -c;
	c ^= 20;
	c -= 3;
	return c;
}

unsigned char e612(unsigned char c)
{
	c ^= 185;
	c = ~c;
	c ^= 172;
	c -= 10;
	c = ~c;
	c += 45;
	c -= 243;
	c = -c;
	return c;
}

unsigned char e613(unsigned char c)
{
	c -= 174;
	c += 229;
	c = -c;
	c = ~c;
	c = -c;
	c -= 157;
	c ^= 227;
	c += 153;
	return c;
}

unsigned char e614(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c -= 91;
	c = ~c;
	c ^= 55;
	c += 13;
	c = -c;
	return c;
}

unsigned char e615(unsigned char c)
{
	c ^= 16;
	c += 14;
	c = ~c;
	c = -c;
	c -= 26;
	c = ~c;
	c -= 65;
	c ^= 39;
	return c;
}

unsigned char e616(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 195;
	c = ~c;
	c += 190;
	c -= 108;
	c ^= 59;
	c += 150;
	return c;
}

unsigned char e617(unsigned char c)
{
	c = ~c;
	c += 237;
	c ^= 179;
	c = ~c;
	c += 110;
	c ^= 156;
	c += 122;
	c -= 136;
	return c;
}

unsigned char e618(unsigned char c)
{
	c = -c;
	c += 7;
	c ^= 93;
	c = ~c;
	c ^= 160;
	c += 30;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e619(unsigned char c)
{
	c += 42;
	c = ~c;
	c = -c;
	c -= 205;
	c += 147;
	c = -c;
	c ^= 206;
	c += 252;
	return c;
}

unsigned char e620(unsigned char c)
{
	c -= 218;
	c = ~c;
	c += 1;
	c -= 231;
	c += 61;
	c = ~c;
	c ^= 0;
	c = -c;
	return c;
}

unsigned char e621(unsigned char c)
{
	c += 223;
	c = -c;
	c += 138;
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 196;
	c -= 115;
	return c;
}

unsigned char e622(unsigned char c)
{
	c += 169;
	c = -c;
	c += 101;
	c ^= 235;
	c = -c;
	c ^= 199;
	c = -c;
	c ^= 146;
	return c;
}

unsigned char e623(unsigned char c)
{
	c -= 96;
	c = -c;
	c ^= 191;
	c = -c;
	c ^= 234;
	c += 120;
	c ^= 182;
	c -= 36;
	return c;
}

unsigned char e624(unsigned char c)
{
	c -= 66;
	c = -c;
	c ^= 137;
	c -= 175;
	c += 69;
	c ^= 168;
	c += 102;
	c = -c;
	return c;
}

unsigned char e625(unsigned char c)
{
	c += 253;
	c = ~c;
	c = -c;
	c -= 249;
	c ^= 159;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e626(unsigned char c)
{
	c -= 216;
	c += 22;
	c ^= 132;
	c = ~c;
	c = -c;
	c ^= 238;
	c += 28;
	c = -c;
	return c;
}

unsigned char e627(unsigned char c)
{
	c -= 8;
	c += 198;
	c = ~c;
	c ^= 221;
	c -= 35;
	c = ~c;
	c += 158;
	c ^= 76;
	return c;
}

unsigned char e628(unsigned char c)
{
	c = ~c;
	c ^= 155;
	c = -c;
	c -= 80;
	c += 78;
	c = -c;
	c ^= 90;
	c = ~c;
	return c;
}

unsigned char e629(unsigned char c)
{
	c = -c;
	c += 103;
	c = -c;
	c = ~c;
	c ^= 3;
	c = ~c;
	c += 254;
	c = -c;
	return c;
}

unsigned char e630(unsigned char c)
{
	c = ~c;
	c ^= 10;
	c += 152;
	c = ~c;
	c -= 68;
	c = ~c;
	c -= 243;
	c ^= 174;
	return c;
}

unsigned char e631(unsigned char c)
{
	c ^= 220;
	c = ~c;
	c ^= 107;
	c = ~c;
	c ^= 134;
	c -= 116;
	c = -c;
	c -= 227;
	return c;
}

unsigned char e632(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 85;
	c = ~c;
	c += 209;
	c = -c;
	c -= 194;
	return c;
}

unsigned char e633(unsigned char c)
{
	c = -c;
	c -= 14;
	c ^= 60;
	c -= 26;
	c ^= 230;
	c += 212;
	c = -c;
	c += 195;
	return c;
}

unsigned char e634(unsigned char c)
{
	c = -c;
	c += 190;
	c -= 108;
	c += 202;
	c = ~c;
	c += 150;
	c -= 4;
	c = ~c;
	return c;
}

unsigned char e635(unsigned char c)
{
	c ^= 179;
	c += 233;
	c = ~c;
	c += 122;
	c = -c;
	c ^= 33;
	c -= 7;
	c += 93;
	return c;
}

unsigned char e636(unsigned char c)
{
	c ^= 163;
	c += 255;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 246;
	c += 100;
	return c;
}

unsigned char e637(unsigned char c)
{
	c = -c;
	c += 147;
	c -= 201;
	c += 239;
	c -= 218;
	c = ~c;
	c -= 166;
	c ^= 148;
	return c;
}

unsigned char e638(unsigned char c)
{
	c -= 50;
	c = ~c;
	c -= 57;
	c = -c;
	c += 245;
	c ^= 251;
	c = ~c;
	c -= 86;
	return c;
}

unsigned char e639(unsigned char c)
{
	c += 196;
	c = -c;
	c -= 115;
	c ^= 169;
	c = ~c;
	c += 101;
	c ^= 72;
	c = ~c;
	return c;
}

unsigned char e640(unsigned char c)
{
	c = ~c;
	c ^= 29;
	c = -c;
	c ^= 96;
	c = -c;
	c -= 191;
	c += 213;
	c = -c;
	return c;
}

unsigned char e641(unsigned char c)
{
	c = -c;
	c ^= 81;
	c = ~c;
	c ^= 36;
	c = ~c;
	c += 83;
	c = -c;
	c -= 188;
	return c;
}

unsigned char e642(unsigned char c)
{
	c ^= 154;
	c -= 193;
	c ^= 167;
	c = ~c;
	c = -c;
	c ^= 67;
	c = -c;
	c -= 62;
	return c;
}

unsigned char e643(unsigned char c)
{
	c -= 236;
	c ^= 74;
	c += 216;
	c = ~c;
	c -= 151;
	c = -c;
	c -= 162;
	c += 240;
	return c;
}

unsigned char e644(unsigned char c)
{
	c = ~c;
	c += 143;
	c = ~c;
	c += 250;
	c = -c;
	c = ~c;
	c = -c;
	c += 180;
	return c;
}

unsigned char e645(unsigned char c)
{
	c ^= 82;
	c = -c;
	c ^= 158;
	c -= 149;
	c += 56;
	c = -c;
	c += 228;
	c -= 2;
	return c;
}

unsigned char e646(unsigned char c)
{
	c = ~c;
	c -= 78;
	c = ~c;
	c -= 5;
	c += 104;
	c = ~c;
	c -= 103;
	c ^= 189;
	return c;
}

unsigned char e647(unsigned char c)
{
	c -= 3;
	c = -c;
	c ^= 254;
	c = -c;
	c -= 10;
	c = -c;
	c -= 241;
	c += 87;
	return c;
}

unsigned char e648(unsigned char c)
{
	c -= 45;
	c += 176;
	c = ~c;
	c -= 220;
	c = ~c;
	c ^= 200;
	c = -c;
	c -= 71;
	return c;
}

unsigned char e649(unsigned char c)
{
	c ^= 157;
	c -= 224;
	c = -c;
	c ^= 63;
	c = ~c;
	c = -c;
	c += 91;
	c = -c;
	return c;
}

unsigned char e650(unsigned char c)
{
	c = -c;
	c ^= 164;
	c = ~c;
	c = -c;
	c -= 16;
	c ^= 14;
	c = ~c;
	c -= 197;
	return c;
}

unsigned char e651(unsigned char c)
{
	c += 75;
	c -= 65;
	c = -c;
	c ^= 125;
	c -= 195;
	c ^= 121;
	c = ~c;
	c -= 108;
	return c;
}

unsigned char e652(unsigned char c)
{
	c = -c;
	c -= 59;
	c ^= 177;
	c = ~c;
	c = -c;
	c -= 237;
	c ^= 179;
	c += 15;
	return c;
}

unsigned char e653(unsigned char c)
{
	c = ~c;
	c += 122;
	c = -c;
	c ^= 33;
	c = ~c;
	c -= 210;
	c = ~c;
	c ^= 30;
	return c;
}

unsigned char e654(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 42;
	c = ~c;
	c = -c;
	c += 247;
	c ^= 205;
	c += 147;
	return c;
}

unsigned char e655(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c ^= 252;
	c -= 218;
	c = ~c;
	c = -c;
	c -= 61;
	return c;
}

unsigned char e656(unsigned char c)
{
	c = ~c;
	c -= 0;
	c = -c;
	c -= 245;
	c = -c;
	c -= 24;
	c = -c;
	c += 215;
	return c;
}

unsigned char e657(unsigned char c)
{
	c = ~c;
	c -= 226;
	c = -c;
	c += 46;
	c = -c;
	c ^= 101;
	c = ~c;
	c += 72;
	return c;
}

unsigned char e658(unsigned char c)
{
	c ^= 6;
	c += 244;
	c -= 146;
	c += 96;
	c = -c;
	c += 191;
	c -= 213;
	c = ~c;
	return c;
}

unsigned char e659(unsigned char c)
{
	c -= 81;
	c += 183;
	c = -c;
	c += 66;
	c -= 144;
	c += 142;
	c = -c;
	c += 168;
	return c;
}

unsigned char e660(unsigned char c)
{
	c = ~c;
	c += 84;
	c = ~c;
	c += 249;
	c -= 236;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e661(unsigned char c)
{
	c -= 22;
	c = ~c;
	c -= 109;
	c ^= 51;
	c = ~c;
	c = -c;
	c = ~c;
	c += 28;
	return c;
}

unsigned char e662(unsigned char c)
{
	c = ~c;
	c += 171;
	c -= 161;
	c += 135;
	c = ~c;
	c += 82;
	c = ~c;
	c ^= 217;
	return c;
}

unsigned char e663(unsigned char c)
{
	c += 127;
	c ^= 149;
	c = ~c;
	c = -c;
	c += 17;
	c -= 119;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e664(unsigned char c)
{
	c += 80;
	c ^= 78;
	c = -c;
	c -= 5;
	c = -c;
	c += 104;
	c ^= 103;
	c += 189;
	return c;
}

unsigned char e665(unsigned char c)
{
	c ^= 3;
	c = ~c;
	c = -c;
	c = ~c;
	c += 10;
	c = ~c;
	c += 241;
	c ^= 68;
	return c;
}

unsigned char e666(unsigned char c)
{
	c ^= 98;
	c = ~c;
	c = -c;
	c -= 79;
	c ^= 229;
	c -= 107;
	c = ~c;
	c ^= 71;
	return c;
}

unsigned char e667(unsigned char c)
{
	c += 157;
	c -= 227;
	c += 153;
	c -= 63;
	c = -c;
	c = ~c;
	c = -c;
	c -= 248;
	return c;
}

unsigned char e668(unsigned char c)
{
	c ^= 54;
	c += 164;
	c ^= 194;
	c = ~c;
	c ^= 60;
	c -= 26;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e669(unsigned char c)
{
	c += 39;
	c -= 64;
	c ^= 190;
	c -= 108;
	c += 202;
	c -= 88;
	c = ~c;
	c += 4;
	return c;
}

unsigned char e670(unsigned char c)
{
	c = -c;
	c ^= 179;
	c = -c;
	c = ~c;
	c ^= 136;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e671(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 163;
	c = -c;
	c -= 255;
	c += 21;
	c = -c;
	c ^= 184;
	return c;
}

unsigned char e672(unsigned char c)
{
	c ^= 246;
	c -= 100;
	c += 130;
	c = ~c;
	c -= 252;
	c = -c;
	c = ~c;
	c ^= 166;
	return c;
}

unsigned char e673(unsigned char c)
{
	c -= 148;
	c += 50;
	c ^= 0;
	c = ~c;
	c += 223;
	c ^= 245;
	c = ~c;
	c += 24;
	return c;
}

unsigned char e674(unsigned char c)
{
	c ^= 86;
	c -= 196;
	c = ~c;
	c -= 115;
	c = -c;
	c -= 46;
	c += 92;
	c -= 58;
	return c;
}

unsigned char e675(unsigned char c)
{
	c += 72;
	c = -c;
	c += 199;
	c ^= 146;
	c -= 96;
	c ^= 191;
	c -= 234;
	c ^= 120;
	return c;
}

unsigned char e676(unsigned char c)
{
	c = ~c;
	c += 183;
	c -= 141;
	c += 83;
	c = ~c;
	c -= 142;
	c += 69;
	c ^= 203;
	return c;
}

unsigned char e677(unsigned char c)
{
	c = -c;
	c += 102;
	c ^= 84;
	c = ~c;
	c ^= 67;
	c -= 249;
	c = -c;
	c -= 236;
	return c;
}

unsigned char e678(unsigned char c)
{
	c ^= 74;
	c = ~c;
	c ^= 49;
	c += 151;
	c ^= 51;
	c += 105;
	c = ~c;
	c -= 28;
	return c;
}

unsigned char e679(unsigned char c)
{
	c = ~c;
	c -= 171;
	c += 198;
	c -= 180;
	c += 35;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e680(unsigned char c)
{
	c ^= 170;
	c = ~c;
	c = -c;
	c -= 118;
	c ^= 77;
	c = -c;
	c += 80;
	c = ~c;
	return c;
}

unsigned char e681(unsigned char c)
{
	c ^= 111;
	c -= 5;
	c += 139;
	c -= 129;
	c = ~c;
	c = -c;
	c = ~c;
	c += 178;
	return c;
}

unsigned char e682(unsigned char c)
{
	c += 128;
	c ^= 254;
	c = -c;
	c -= 10;
	c ^= 152;
	c += 68;
	c = -c;
	c -= 243;
	return c;
}

unsigned char e683(unsigned char c)
{
	c += 41;
	c = -c;
	c -= 220;
	c = -c;
	c += 200;
	c ^= 134;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e684(unsigned char c)
{
	c -= 18;
	c += 224;
	c -= 94;
	c = ~c;
	c += 85;
	c -= 91;
	c ^= 209;
	c -= 55;
	return c;
}

unsigned char e685(unsigned char c)
{
	c ^= 13;
	c = -c;
	c = ~c;
	c += 9;
	c -= 47;
	c = -c;
	c ^= 230;
	c = ~c;
	return c;
}

unsigned char e686(unsigned char c)
{
	c = ~c;
	c -= 114;
	c ^= 64;
	c = -c;
	c -= 31;
	c = -c;
	c ^= 59;
	c += 177;
	return c;
}

unsigned char e687(unsigned char c)
{
	c += 23;
	c ^= 237;
	c = ~c;
	c -= 233;
	c = -c;
	c += 165;
	c -= 43;
	c += 33;
	return c;
}

unsigned char e688(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 93;
	c = ~c;
	c ^= 89;
	c += 255;
	c -= 21;
	c += 246;
	return c;
}

unsigned char e689(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 130;
	c -= 206;
	c ^= 252;
	c -= 218;
	c = -c;
	c -= 1;
	return c;
}

unsigned char e690(unsigned char c)
{
	c ^= 231;
	c = ~c;
	c -= 57;
	c = -c;
	c -= 245;
	c += 251;
	c ^= 113;
	c = -c;
	return c;
}

unsigned char e691(unsigned char c)
{
	c = -c;
	c += 226;
	c = ~c;
	c -= 169;
	c = -c;
	c ^= 101;
	c = ~c;
	c += 225;
	return c;
}

unsigned char e692(unsigned char c)
{
	c -= 199;
	c = ~c;
	c += 146;
	c ^= 96;
	c -= 222;
	c = -c;
	c -= 213;
	c ^= 219;
	return c;
}

unsigned char e693(unsigned char c)
{
	c = -c;
	c -= 182;
	c += 141;
	c ^= 142;
	c += 188;
	c = ~c;
	c = -c;
	c += 167;
	return c;
}

unsigned char e694(unsigned char c)
{
	c ^= 253;
	c = ~c;
	c += 192;
	c = ~c;
	c -= 236;
	c ^= 187;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e695(unsigned char c)
{
	c += 151;
	c ^= 109;
	c = -c;
	c ^= 105;
	c -= 143;
	c += 37;
	c = -c;
	c ^= 8;
	return c;
}

unsigned char e696(unsigned char c)
{
	c = -c;
	c ^= 135;
	c = -c;
	c ^= 32;
	c = -c;
	c = ~c;
	c = -c;
	c -= 170;
	return c;
}

unsigned char e697(unsigned char c)
{
	c ^= 56;
	c -= 118;
	c ^= 228;
	c = -c;
	c ^= 80;
	c = -c;
	c += 111;
	c -= 5;
	return c;
}

unsigned char e698(unsigned char c)
{
	c = ~c;
	c -= 129;
	c = -c;
	c -= 20;
	c ^= 3;
	c -= 185;
	c = -c;
	c += 117;
	return c;
}

unsigned char e699(unsigned char c)
{
	c += 123;
	c = ~c;
	c += 214;
	c = ~c;
	c -= 45;
	c = -c;
	c ^= 41;
	c = -c;
	return c;
}

unsigned char e700(unsigned char c)
{
	c ^= 220;
	c -= 186;
	c = ~c;
	c -= 97;
	c = -c;
	c -= 116;
	c = -c;
	c -= 227;
	return c;
}

unsigned char e701(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e702(unsigned char c)
{
	c += 54;
	c = -c;
	c -= 13;
	c = -c;
	c += 16;
	c -= 47;
	c = -c;
	c ^= 75;
	return c;
}

unsigned char e703(unsigned char c)
{
	c = -c;
	c -= 230;
	c ^= 212;
	c = -c;
	c += 195;
	c ^= 121;
	c += 31;
	c = ~c;
	return c;
}

unsigned char e704(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 150;
	c -= 4;
	c = ~c;
	c ^= 179;
	c = ~c;
	c -= 15;
	return c;
}

unsigned char e705(unsigned char c)
{
	c += 165;
	c ^= 43;
	c += 33;
	c = -c;
	c = ~c;
	c ^= 163;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e706(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 21;
	c = ~c;
	c += 184;
	c ^= 247;
	c = -c;
	c += 147;
	return c;
}

unsigned char e707(unsigned char c)
{
	c = -c;
	c ^= 206;
	c = ~c;
	c ^= 133;
	c -= 1;
	c = ~c;
	c ^= 148;
	c -= 50;
	return c;
}

unsigned char e708(unsigned char c)
{
	c = -c;
	c += 126;
	c = -c;
	c ^= 245;
	c = ~c;
	c -= 113;
	c = -c;
	c += 196;
	return c;
}

unsigned char e709(unsigned char c)
{
	c ^= 226;
	c += 48;
	c = ~c;
	c ^= 207;
	c -= 58;
	c = ~c;
	c += 225;
	c ^= 199;
	return c;
}

unsigned char e710(unsigned char c)
{
	c -= 29;
	c = -c;
	c = ~c;
	c += 191;
	c ^= 213;
	c = -c;
	c += 120;
	c = -c;
	return c;
}

unsigned char e711(unsigned char c)
{
	c = -c;
	c ^= 141;
	c += 83;
	c ^= 137;
	c += 175;
	c ^= 69;
	c -= 203;
	c = -c;
	return c;
}

unsigned char e712(unsigned char c)
{
	c = ~c;
	c -= 167;
	c += 253;
	c ^= 67;
	c += 249;
	c ^= 159;
	c += 74;
	c -= 216;
	return c;
}

unsigned char e713(unsigned char c)
{
	c ^= 22;
	c += 132;
	c = -c;
	c ^= 51;
	c = -c;
	c ^= 238;
	c -= 28;
	c = ~c;
	return c;
}

unsigned char e714(unsigned char c)
{
	c ^= 171;
	c = -c;
	c = ~c;
	c ^= 180;
	c += 82;
	c = ~c;
	c ^= 217;
	c += 127;
	return c;
}

unsigned char e715(unsigned char c)
{
	c = ~c;
	c += 170;
	c -= 56;
	c = -c;
	c = ~c;
	c += 228;
	c = -c;
	c += 78;
	return c;
}

unsigned char e716(unsigned char c)
{
	c += 124;
	c -= 139;
	c += 38;
	c = ~c;
	c = -c;
	c -= 3;
	c ^= 185;
	c += 95;
	return c;
}

unsigned char e717(unsigned char c)
{
	c -= 117;
	c = -c;
	c += 152;
	c = ~c;
	c = -c;
	c += 45;
	c = -c;
	c -= 176;
	return c;
}

unsigned char e718(unsigned char c)
{
	c += 174;
	c = ~c;
	c ^= 229;
	c = ~c;
	c = -c;
	c = ~c;
	c += 71;
	c = -c;
	return c;
}

unsigned char e719(unsigned char c)
{
	c += 18;
	c ^= 224;
	c = ~c;
	c -= 63;
	c += 85;
	c = ~c;
	c ^= 209;
	c = ~c;
	return c;
}

unsigned char e720(unsigned char c)
{
	c ^= 164;
	c = ~c;
	c = -c;
	c ^= 16;
	c -= 14;
	c = ~c;
	c = -c;
	c += 75;
	return c;
}

unsigned char e721(unsigned char c)
{
	c ^= 65;
	c += 39;
	c = -c;
	c += 114;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 31;
	return c;
}

unsigned char e722(unsigned char c)
{
	c = -c;
	c -= 59;
	c = ~c;
	c += 150;
	c = -c;
	c = ~c;
	c += 34;
	c ^= 112;
	return c;
}

unsigned char e723(unsigned char c)
{
	c = -c;
	c += 165;
	c = -c;
	c = ~c;
	c ^= 52;
	c = -c;
	c = ~c;
	c ^= 160;
	return c;
}

unsigned char e724(unsigned char c)
{
	c -= 30;
	c = ~c;
	c -= 21;
	c ^= 27;
	c = -c;
	c = ~c;
	c = -c;
	c += 100;
	return c;
}

unsigned char e725(unsigned char c)
{
	c -= 130;
	c = -c;
	c -= 201;
	c = -c;
	c ^= 252;
	c = -c;
	c += 11;
	c = -c;
	return c;
}

unsigned char e726(unsigned char c)
{
	c ^= 166;
	c = -c;
	c = ~c;
	c ^= 50;
	c += 57;
	c ^= 223;
	c = ~c;
	c -= 138;
	return c;
}

unsigned char e727(unsigned char c)
{
	c ^= 24;
	c = ~c;
	c = -c;
	c = ~c;
	c += 173;
	c = -c;
	c ^= 48;
	c = -c;
	return c;
}

unsigned char e728(unsigned char c)
{
	c ^= 207;
	c = -c;
	c = ~c;
	c -= 72;
	c = -c;
	c = ~c;
	c += 244;
	c = -c;
	return c;
}

unsigned char e729(unsigned char c)
{
	c = ~c;
	c -= 96;
	c = ~c;
	c = -c;
	c = ~c;
	c += 234;
	c = -c;
	c ^= 182;
	return c;
}

unsigned char e730(unsigned char c)
{
	c ^= 36;
	c = ~c;
	c += 83;
	c = -c;
	c = ~c;
	c ^= 188;
	c += 154;
	c -= 168;
	return c;
}

unsigned char e731(unsigned char c)
{
	c += 102;
	c = ~c;
	c += 242;
	c = -c;
	c = ~c;
	c += 62;
	c -= 236;
	c = ~c;
	return c;
}

unsigned char e732(unsigned char c)
{
	c += 216;
	c ^= 151;
	c = ~c;
	c -= 162;
	c = ~c;
	c -= 105;
	c = -c;
	c ^= 28;
	return c;
}

unsigned char e733(unsigned char c)
{
	c = ~c;
	c += 8;
	c -= 135;
	c += 221;
	c = -c;
	c = ~c;
	c -= 158;
	c = -c;
	return c;
}

unsigned char e734(unsigned char c)
{
	c = -c;
	c -= 170;
	c += 56;
	c ^= 118;
	c = ~c;
	c ^= 77;
	c = -c;
	c -= 80;
	return c;
}

unsigned char e735(unsigned char c)
{
	c -= 78;
	c = ~c;
	c += 90;
	c -= 104;
	c = -c;
	c -= 103;
	c ^= 189;
	c += 3;
	return c;
}

unsigned char e736(unsigned char c)
{
	c = ~c;
	c -= 254;
	c = -c;
	c += 117;
	c -= 123;
	c = ~c;
	c -= 87;
	c ^= 45;
	return c;
}

unsigned char e737(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 41;
	c += 79;
	c = -c;
	c -= 107;
	c = -c;
	c ^= 134;
	return c;
}

unsigned char e738(unsigned char c)
{
	c ^= 116;
	c = ~c;
	c -= 227;
	c = ~c;
	c += 63;
	c -= 85;
	c ^= 91;
	c -= 209;
	return c;
}

unsigned char e739(unsigned char c)
{
	c += 55;
	c ^= 13;
	c = -c;
	c ^= 14;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e740(unsigned char c)
{
	c += 40;
	c ^= 230;
	c -= 212;
	c = ~c;
	c += 195;
	c -= 121;
	c = ~c;
	c += 53;
	return c;
}

unsigned char e741(unsigned char c)
{
	c = ~c;
	c ^= 88;
	c += 150;
	c ^= 4;
	c += 110;
	c = ~c;
	c ^= 165;
	c = ~c;
	return c;
}

unsigned char e742(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 52;
	c ^= 210;
	c = ~c;
	c ^= 89;
	c += 204;
	c ^= 42;
	return c;
}

unsigned char e743(unsigned char c)
{
	c = ~c;
	c += 145;
	c -= 247;
	c = ~c;
	c += 147;
	c = ~c;
	c = -c;
	c ^= 239;
	return c;
}

unsigned char e744(unsigned char c)
{
	c = -c;
	c -= 11;
	c = -c;
	c -= 166;
	c = ~c;
	c -= 61;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e745(unsigned char c)
{
	c = ~c;
	c += 126;
	c = -c;
	c ^= 138;
	c -= 24;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e746(unsigned char c)
{
	c = -c;
	c ^= 169;
	c += 207;
	c = -c;
	c -= 72;
	c = ~c;
	c = -c;
	c ^= 29;
	return c;
}

unsigned char e747(unsigned char c)
{
	c = -c;
	c ^= 96;
	c += 222;
	c = -c;
	c += 219;
	c = ~c;
	c += 182;
	c = ~c;
	return c;
}

unsigned char e748(unsigned char c)
{
	c += 66;
	c = -c;
	c -= 137;
	c = -c;
	c = ~c;
	c += 203;
	c ^= 193;
	c = ~c;
	return c;
}

unsigned char e749(unsigned char c)
{
	c = -c;
	c -= 253;
	c ^= 67;
	c = -c;
	c ^= 62;
	c = ~c;
	c ^= 181;
	c += 187;
	return c;
}

unsigned char e750(unsigned char c)
{
	c += 49;
	c = -c;
	c -= 132;
	c = ~c;
	c ^= 51;
	c = ~c;
	c = -c;
	c ^= 143;
	return c;
}

unsigned char e751(unsigned char c)
{
	c ^= 37;
	c -= 171;
	c = -c;
	c ^= 135;
	c = ~c;
	c -= 82;
	c += 32;
	c -= 158;
	return c;
}

unsigned char e752(unsigned char c)
{
	c = -c;
	c += 149;
	c = -c;
	c ^= 17;
	c += 119;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e753(unsigned char c)
{
	c -= 80;
	c ^= 78;
	c += 124;
	c = ~c;
	c += 139;
	c = -c;
	c = ~c;
	c ^= 103;
	return c;
}

unsigned char e754(unsigned char c)
{
	c += 189;
	c -= 3;
	c = -c;
	c -= 117;
	c = ~c;
	c ^= 241;
	c -= 87;
	c = -c;
	return c;
}

unsigned char e755(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 174;
	c = ~c;
	c = -c;
	c -= 200;
	c = -c;
	c ^= 71;
	return c;
}

unsigned char e756(unsigned char c)
{
	c += 157;
	c -= 224;
	c += 94;
	c ^= 85;
	c -= 91;
	c += 209;
	c ^= 55;
	c = -c;
	return c;
}

unsigned char e757(unsigned char c)
{
	c ^= 194;
	c = -c;
	c -= 9;
	c ^= 47;
	c = ~c;
	c = -c;
	c += 40;
	c -= 230;
	return c;
}

unsigned char e758(unsigned char c)
{
	c += 212;
	c = -c;
	c = ~c;
	c ^= 121;
	c += 31;
	c -= 53;
	c ^= 59;
	c = ~c;
	return c;
}

unsigned char e759(unsigned char c)
{
	c = ~c;
	c = -c;
	c += 4;
	c = -c;
	c ^= 179;
	c = -c;
	c -= 110;
	c = -c;
	return c;
}

unsigned char e760(unsigned char c)
{
	c ^= 165;
	c = -c;
	c = ~c;
	c += 70;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 255;
	return c;
}

unsigned char e761(unsigned char c)
{
	c = ~c;
	c -= 27;
	c = -c;
	c -= 247;
	c += 205;
	c = ~c;
	c += 201;
	c ^= 252;
	return c;
}

unsigned char e762(unsigned char c)
{
	c = -c;
	c += 232;
	c -= 231;
	c = -c;
	c -= 50;
	c = -c;
	c ^= 126;
	c = -c;
	return c;
}

unsigned char e763(unsigned char c)
{
	c += 245;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 173;
	c = -c;
	c -= 46;
	return c;
}

unsigned char e764(unsigned char c)
{
	c -= 92;
	c = -c;
	c ^= 235;
	c = ~c;
	c ^= 6;
	c -= 244;
	c = ~c;
	c += 222;
	return c;
}

unsigned char e765(unsigned char c)
{
	c = -c;
	c += 213;
	c ^= 219;
	c = ~c;
	c -= 183;
	c ^= 141;
	c += 83;
	c = ~c;
	return c;
}

unsigned char e766(unsigned char c)
{
	c -= 142;
	c ^= 188;
	c = ~c;
	c = -c;
	c += 193;
	c = -c;
	c -= 84;
	c = -c;
	return c;
}

unsigned char e767(unsigned char c)
{
	c = ~c;
	c -= 192;
	c ^= 62;
	c = ~c;
	c = -c;
	c ^= 187;
	c = -c;
	c -= 22;
	return c;
}

unsigned char e768(unsigned char c)
{
	c = -c;
	c += 162;
	c ^= 28;
	c -= 250;
	c = ~c;
	c ^= 161;
	c = ~c;
	c += 180;
	return c;
}

unsigned char e769(unsigned char c)
{
	c ^= 82;
	c = ~c;
	c ^= 217;
	c = -c;
	c -= 149;
	c ^= 155;
	c -= 17;
	c ^= 119;
	return c;
}

unsigned char e770(unsigned char c)
{
	c = ~c;
	c += 2;
	c = ~c;
	c += 73;
	c -= 111;
	c = ~c;
	c = -c;
	c += 38;
	return c;
}

unsigned char e771(unsigned char c)
{
	c -= 20;
	c += 3;
	c ^= 185;
	c += 95;
	c ^= 117;
	c += 123;
	c -= 241;
	c = ~c;
	return c;
}

unsigned char e772(unsigned char c)
{
	c = ~c;
	c -= 98;
	c += 176;
	c = ~c;
	c = -c;
	c += 107;
	c ^= 97;
	c += 71;
	return c;
}

unsigned char e773(unsigned char c)
{
	c = ~c;
	c ^= 18;
	c += 94;
	c -= 85;
	c = ~c;
	c += 248;
	c = -c;
	c ^= 55;
	return c;
}

unsigned char e774(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 16;
	c = -c;
	c += 47;
	c = -c;
	c ^= 75;
	c += 65;
	return c;
}

unsigned char e775(unsigned char c)
{
	c = ~c;
	c ^= 212;
	c += 195;
	c = ~c;
	c = -c;
	c = ~c;
	c += 53;
	c = -c;
	return c;
}

unsigned char e776(unsigned char c)
{
	c += 88;
	c -= 150;
	c = ~c;
	c -= 237;
	c ^= 179;
	c -= 233;
	c += 15;
	c ^= 165;
	return c;
}

unsigned char e777(unsigned char c)
{
	c ^= 43;
	c = ~c;
	c = -c;
	c -= 7;
	c ^= 163;
	c -= 89;
	c = ~c;
	c += 204;
	return c;
}

unsigned char e778(unsigned char c)
{
	c ^= 42;
	c -= 184;
	c ^= 246;
	c = -c;
	c ^= 130;
	c += 208;
	c = -c;
	c += 239;
	return c;
}

unsigned char e779(unsigned char c)
{
	c = -c;
	c ^= 11;
	c = -c;
	c ^= 61;
	c = -c;
	c += 0;
	c ^= 126;
	c -= 44;
	return c;
}

unsigned char e780(unsigned char c)
{
	c += 138;
	c = -c;
	c ^= 113;
	c = ~c;
	c ^= 196;
	c = -c;
	c -= 48;
	c ^= 46;
	return c;
}

unsigned char e781(unsigned char c)
{
	c += 92;
	c = -c;
	c += 235;
	c = ~c;
	c = -c;
	c = ~c;
	c += 244;
	c -= 146;
	return c;
}

unsigned char e782(unsigned char c)
{
	c = -c;
	c += 222;
	c = -c;
	c ^= 234;
	c -= 120;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e783(unsigned char c)
{
	c -= 144;
	c ^= 142;
	c -= 188;
	c = ~c;
	c -= 203;
	c += 193;
	c ^= 167;
	c += 242;
	return c;
}

unsigned char e784(unsigned char c)
{
	c ^= 192;
	c -= 159;
	c = -c;
	c += 74;
	c ^= 216;
	c -= 22;
	c ^= 132;
	c -= 238;
	return c;
}

unsigned char e785(unsigned char c)
{
	c -= 28;
	c ^= 171;
	c += 198;
	c ^= 180;
	c += 82;
	c = -c;
	c += 217;
	c -= 127;
	return c;
}

unsigned char e786(unsigned char c)
{
	c ^= 149;
	c = -c;
	c ^= 56;
	c -= 118;
	c ^= 228;
	c = -c;
	c += 80;
	c ^= 78;
	return c;
}

unsigned char e787(unsigned char c)
{
	c += 124;
	c = ~c;
	c -= 139;
	c ^= 129;
	c -= 103;
	c ^= 178;
	c += 128;
	c = ~c;
	return c;
}

unsigned char e788(unsigned char c)
{
	c = -c;
	c -= 172;
	c ^= 10;
	c -= 152;
	c ^= 214;
	c -= 68;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e789(unsigned char c)
{
	c ^= 176;
	c = -c;
	c -= 79;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 97;
	c -= 71;
	return c;
}

unsigned char e790(unsigned char c)
{
	c -= 157;
	c += 227;
	c = ~c;
	c ^= 94;
	c += 12;
	c = -c;
	c = ~c;
	c ^= 54;
	return c;
}

unsigned char e791(unsigned char c)
{
	c = -c;
	c ^= 13;
	c = -c;
	c = ~c;
	c += 9;
	c = ~c;
	c += 60;
	c ^= 26;
	return c;
}

unsigned char e792(unsigned char c)
{
	c = ~c;
	c += 65;
	c = -c;
	c -= 212;
	c = ~c;
	c = -c;
	c += 64;
	c = ~c;
	return c;
}

unsigned char e793(unsigned char c)
{
	c = ~c;
	c -= 53;
	c = -c;
	c -= 177;
	c += 237;
	c ^= 179;
	c -= 233;
	c += 15;
	return c;
}

unsigned char e794(unsigned char c)
{
	c ^= 165;
	c += 43;
	c -= 33;
	c ^= 7;
	c = -c;
	c ^= 210;
	c = ~c;
	c ^= 89;
	return c;
}

unsigned char e795(unsigned char c)
{
	c ^= 255;
	c = ~c;
	c -= 42;
	c += 184;
	c ^= 246;
	c += 100;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e796(unsigned char c)
{
	c += 208;
	c = ~c;
	c = -c;
	c ^= 218;
	c = ~c;
	c ^= 1;
	c = ~c;
	c -= 148;
	return c;
}

unsigned char e797(unsigned char c)
{
	c += 50;
	c = ~c;
	c = -c;
	c -= 223;
	c += 245;
	c = -c;
	c = ~c;
	c -= 113;
	return c;
}

unsigned char e798(unsigned char c)
{
	c += 215;
	c ^= 173;
	c = -c;
	c = ~c;
	c -= 207;
	c = -c;
	c -= 235;
	c = ~c;
	return c;
}

unsigned char e799(unsigned char c)
{
	c = -c;
	c ^= 244;
	c = ~c;
	c ^= 96;
	c = ~c;
	c = -c;
	c += 213;
	c -= 219;
	return c;
}

unsigned char e800(unsigned char c)
{
	c += 81;
	c ^= 36;
	c -= 66;
	c = ~c;
	c += 137;
	c ^= 175;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e801(unsigned char c)
{
	c = -c;
	c ^= 168;
	c = -c;
	c = ~c;
	c ^= 84;
	c = ~c;
	c -= 67;
	c = -c;
	return c;
}

unsigned char e802(unsigned char c)
{
	c = -c;
	c += 159;
	c = -c;
	c = ~c;
	c -= 216;
	c = -c;
	c = ~c;
	c ^= 109;
	return c;
}

unsigned char e803(unsigned char c)
{
	c ^= 51;
	c = ~c;
	c ^= 28;
	c -= 250;
	c ^= 161;
	c += 135;
	c ^= 221;
	c = -c;
	return c;
}

unsigned char e804(unsigned char c)
{
	c += 32;
	c = -c;
	c -= 149;
	c = -c;
	c -= 118;
	c += 228;
	c = -c;
	c ^= 80;
	return c;
}

unsigned char e805(unsigned char c)
{
	c = ~c;
	c ^= 111;
	c += 5;
	c ^= 139;
	c = ~c;
	c ^= 103;
	c = -c;
	c += 178;
	return c;
}

unsigned char e806(unsigned char c)
{
	c -= 128;
	c = ~c;
	c -= 172;
	c = ~c;
	c -= 123;
	c = -c;
	c += 214;
	c = -c;
	return c;
}

unsigned char e807(unsigned char c)
{
	c = -c;
	c += 98;
	c = -c;
	c += 174;
	c = -c;
	c -= 229;
	c ^= 200;
	c = -c;
	return c;
}

unsigned char e808(unsigned char c)
{
	c ^= 71;
	c = -c;
	c -= 18;
	c = -c;
	c -= 153;
	c += 12;
	c = -c;
	c ^= 91;
	return c;
}

unsigned char e809(unsigned char c)
{
	c ^= 209;
	c = -c;
	c ^= 164;
	c = ~c;
	c = -c;
	c += 16;
	c -= 14;
	c = -c;
	return c;
}

unsigned char e810(unsigned char c)
{
	c += 197;
	c -= 75;
	c += 65;
	c = ~c;
	c = -c;
	c -= 114;
	c = ~c;
	c ^= 121;
	return c;
}

unsigned char e811(unsigned char c)
{
	c ^= 31;
	c -= 202;
	c = ~c;
	c += 177;
	c = ~c;
	c ^= 4;
	c += 34;
	c = ~c;
	return c;
}

unsigned char e812(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c += 156;
	c -= 122;
	c = -c;
	c -= 33;
	c = ~c;
	return c;
}

unsigned char e813(unsigned char c)
{
	c -= 52;
	c += 210;
	c = -c;
	c += 89;
	c -= 255;
	c = -c;
	c ^= 42;
	c = -c;
	return c;
}

unsigned char e814(unsigned char c)
{
	c -= 145;
	c += 247;
	c -= 130;
	c ^= 208;
	c -= 206;
	c = ~c;
	c -= 133;
	c ^= 1;
	return c;
}

unsigned char e815(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c += 223;
	c -= 245;
	c ^= 24;
	c += 86;
	c = ~c;
	return c;
}

unsigned char e816(unsigned char c)
{
	c -= 173;
	c = -c;
	c += 48;
	c = -c;
	c ^= 92;
	c = -c;
	c ^= 72;
	c += 199;
	return c;
}

unsigned char e817(unsigned char c)
{
	c = -c;
	c += 146;
	c = ~c;
	c ^= 222;
	c -= 140;
	c ^= 234;
	c = -c;
	c += 183;
	return c;
}

unsigned char e818(unsigned char c)
{
	c += 141;
	c = ~c;
	c += 144;
	c = -c;
	c ^= 175;
	c -= 69;
	c += 203;
	c = ~c;
	return c;
}

unsigned char e819(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c ^= 67;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e820(unsigned char c)
{
	c = ~c;
	c += 187;
	c = ~c;
	c ^= 22;
	c -= 132;
	c ^= 51;
	c = -c;
	c -= 238;
	return c;
}

unsigned char e821(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 250;
	c = -c;
	c += 161;
	c -= 135;
	c += 221;
	c -= 32;
	return c;
}

unsigned char e822(unsigned char c)
{
	c += 158;
	c -= 76;
	c = ~c;
	c += 155;
	c = ~c;
	c = -c;
	c -= 119;
	c = ~c;
	return c;
}

unsigned char e823(unsigned char c)
{
	c = -c;
	c ^= 80;
	c = -c;
	c ^= 111;
	c += 5;
	c ^= 129;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e824(unsigned char c)
{
	c ^= 189;
	c -= 3;
	c ^= 185;
	c -= 172;
	c ^= 10;
	c = -c;
	c = ~c;
	c ^= 87;
	return c;
}

unsigned char e825(unsigned char c)
{
	c = ~c;
	c ^= 98;
	c = -c;
	c -= 41;
	c = -c;
	c = ~c;
	c -= 229;
	c ^= 107;
	return c;
}

unsigned char e826(unsigned char c)
{
	c += 97;
	c = ~c;
	c -= 116;
	c ^= 18;
	c = -c;
	c = ~c;
	c += 12;
	c -= 91;
	return c;
}

unsigned char e827(unsigned char c)
{
	c = ~c;
	c -= 55;
	c = ~c;
	c += 194;
	c = -c;
	c ^= 14;
	c += 60;
	c ^= 26;
	return c;
}

unsigned char e828(unsigned char c)
{
	c -= 40;
	c += 230;
	c ^= 125;
	c = -c;
	c += 121;
	c -= 31;
	c = ~c;
	c += 202;
	return c;
}

unsigned char e829(unsigned char c)
{
	c ^= 88;
	c += 23;
	c -= 237;
	c ^= 179;
	c += 233;
	c -= 15;
	c = -c;
	c -= 122;
	return c;
}

unsigned char e830(unsigned char c)
{
	c = -c;
	c -= 33;
	c = -c;
	c += 52;
	c = ~c;
	c -= 163;
	c += 30;
	c -= 42;
	return c;
}

unsigned char e831(unsigned char c)
{
	c = ~c;
	c += 145;
	c ^= 247;
	c = ~c;
	c = -c;
	c -= 201;
	c = -c;
	c -= 133;
	return c;
}

unsigned char e832(unsigned char c)
{
	c = -c;
	c -= 232;
	c ^= 166;
	c -= 61;
	c = ~c;
	c += 0;
	c -= 126;
	c ^= 245;
	return c;
}

unsigned char e833(unsigned char c)
{
	c += 251;
	c -= 113;
	c ^= 215;
	c = ~c;
	c = -c;
	c += 48;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e834(unsigned char c)
{
	c -= 92;
	c ^= 58;
	c += 72;
	c = -c;
	c -= 199;
	c ^= 29;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e835(unsigned char c)
{
	c -= 25;
	c ^= 213;
	c = ~c;
	c += 81;
	c ^= 183;
	c = -c;
	c ^= 66;
	c = -c;
	return c;
}

unsigned char e836(unsigned char c)
{
	c = ~c;
	c += 175;
	c -= 69;
	c = ~c;
	c += 168;
	c -= 84;
	c ^= 242;
	c = ~c;
	return c;
}

unsigned char e837(unsigned char c)
{
	c -= 62;
	c = ~c;
	c += 181;
	c ^= 187;
	c += 22;
	c = -c;
	c = ~c;
	c ^= 51;
	return c;
}

unsigned char e838(unsigned char c)
{
	c -= 105;
	c ^= 28;
	c = -c;
	c ^= 8;
	c += 198;
	c = ~c;
	c += 82;
	c = -c;
	return c;
}

unsigned char e839(unsigned char c)
{
	c += 217;
	c -= 127;
	c = ~c;
	c ^= 170;
	c = -c;
	c ^= 17;
	c -= 119;
	c += 77;
	return c;
}

unsigned char e840(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 78;
	c -= 124;
	c = ~c;
	c += 104;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e841(unsigned char c)
{
	c += 189;
	c = ~c;
	c += 185;
	c -= 95;
	c = -c;
	c -= 10;
	c = ~c;
	c ^= 241;
	return c;
}

unsigned char e842(unsigned char c)
{
	c ^= 87;
	c += 45;
	c = -c;
	c -= 176;
	c ^= 174;
	c = -c;
	c -= 229;
	c += 107;
	return c;
}

unsigned char e843(unsigned char c)
{
	c += 97;
	c = -c;
	c = ~c;
	c += 157;
	c -= 227;
	c = ~c;
	c = -c;
	c ^= 63;
	return c;
}

unsigned char e844(unsigned char c)
{
	c += 85;
	c = ~c;
	c -= 248;
	c = ~c;
	c -= 164;
	c ^= 194;
	c -= 9;
	c = -c;
	return c;
}

unsigned char e845(unsigned char c)
{
	c -= 60;
	c ^= 26;
	c = -c;
	c = ~c;
	c ^= 230;
	c = -c;
	c += 125;
	c -= 121;
	return c;
}

unsigned char e846(unsigned char c)
{
	c = ~c;
	c ^= 53;
	c = -c;
	c -= 88;
	c += 150;
	c = ~c;
	c = -c;
	c ^= 179;
	return c;
}

unsigned char e847(unsigned char c)
{
	c ^= 233;
	c -= 15;
	c = -c;
	c ^= 43;
	c = -c;
	c = ~c;
	c += 7;
	c = ~c;
	return c;
}

unsigned char e848(unsigned char c)
{
	c = -c;
	c ^= 163;
	c = -c;
	c += 204;
	c = ~c;
	c ^= 184;
	c -= 246;
	c = -c;
	return c;
}

unsigned char e849(unsigned char c)
{
	c -= 205;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c += 252;
	c ^= 218;
	c = -c;
	return c;
}

unsigned char e850(unsigned char c)
{
	c += 1;
	c -= 231;
	c = -c;
	c ^= 50;
	c -= 0;
	c = ~c;
	c -= 44;
	c = ~c;
	return c;
}

unsigned char e851(unsigned char c)
{
	c ^= 251;
	c += 113;
	c = -c;
	c ^= 196;
	c += 226;
	c ^= 48;
	c = -c;
	c ^= 207;
	return c;
}

unsigned char e852(unsigned char c)
{
	c = ~c;
	c ^= 58;
	c += 72;
	c = ~c;
	c ^= 199;
	c += 29;
	c ^= 99;
	c = -c;
	return c;
}

unsigned char e853(unsigned char c)
{
	c += 191;
	c -= 213;
	c = -c;
	c ^= 120;
	c += 182;
	c -= 36;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e854(unsigned char c)
{
	c ^= 144;
	c = -c;
	c = ~c;
	c -= 69;
	c = ~c;
	c = -c;
	c -= 167;
	c = -c;
	return c;
}

unsigned char e855(unsigned char c)
{
	c = ~c;
	c ^= 67;
	c = -c;
	c -= 62;
	c = ~c;
	c -= 181;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e856(unsigned char c)
{
	c -= 49;
	c += 151;
	c ^= 51;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c += 171;
	return c;
}

unsigned char e857(unsigned char c)
{
	c += 161;
	c = ~c;
	c = -c;
	c -= 221;
	c += 35;
	c -= 217;
	c += 127;
	c = -c;
	return c;
}

unsigned char e858(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c += 118;
	c ^= 228;
	c = -c;
	c -= 80;
	c = ~c;
	return c;
}

unsigned char e859(unsigned char c)
{
	c ^= 124;
	c -= 90;
	c = ~c;
	c += 129;
	c = ~c;
	c += 178;
	c -= 128;
	c ^= 254;
	return c;
}

unsigned char e860(unsigned char c)
{
	c -= 172;
	c ^= 10;
	c = ~c;
	c -= 214;
	c = -c;
	c -= 98;
	c = ~c;
	c ^= 79;
	return c;
}

unsigned char e861(unsigned char c)
{
	c = ~c;
	c ^= 186;
	c += 200;
	c = -c;
	c += 71;
	c = ~c;
	c += 227;
	c -= 153;
	return c;
}

unsigned char e862(unsigned char c)
{
	c -= 63;
	c = -c;
	c = ~c;
	c += 91;
	c -= 209;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e863(unsigned char c)
{
	c ^= 14;
	c += 60;
	c ^= 26;
	c = -c;
	c = ~c;
	c -= 230;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e864(unsigned char c)
{
	c -= 64;
	c ^= 190;
	c = ~c;
	c += 202;
	c = -c;
	c = ~c;
	c ^= 23;
	c -= 34;
	return c;
}

unsigned char e865(unsigned char c)
{
	c = -c;
	c ^= 110;
	c -= 156;
	c = -c;
	c += 43;
	c = -c;
	c += 70;
	c = -c;
	return c;
}

unsigned char e866(unsigned char c)
{
	c -= 93;
	c = -c;
	c += 89;
	c = ~c;
	c += 204;
	c = -c;
	c += 27;
	c = -c;
	return c;
}

unsigned char e867(unsigned char c)
{
	c = -c;
	c ^= 100;
	c = ~c;
	c -= 208;
	c = -c;
	c ^= 239;
	c -= 133;
	c = ~c;
	return c;
}

unsigned char e868(unsigned char c)
{
	c = -c;
	c += 1;
	c ^= 231;
	c += 50;
	c = -c;
	c -= 126;
	c ^= 245;
	c = -c;
	return c;
}

unsigned char e869(unsigned char c)
{
	c = -c;
	c += 196;
	c ^= 226;
	c = -c;
	c += 46;
	c -= 92;
	c ^= 58;
	c = ~c;
	return c;
}

unsigned char e870(unsigned char c)
{
	c = -c;
	c ^= 6;
	c = ~c;
	c += 146;
	c = ~c;
	c -= 222;
	c ^= 213;
	c -= 219;
	return c;
}

unsigned char e871(unsigned char c)
{
	c = ~c;
	c += 182;
	c = -c;
	c += 141;
	c = ~c;
	c = -c;
	c = ~c;
	c += 142;
	return c;
}

unsigned char e872(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 154;
	c = ~c;
	c -= 193;
	c ^= 167;
	c -= 242;
	c = -c;
	return c;
}

unsigned char e873(unsigned char c)
{
	c ^= 249;
	c = -c;
	c = ~c;
	c ^= 181;
	c -= 187;
	c += 49;
	c ^= 151;
	c = -c;
	return c;
}

unsigned char e874(unsigned char c)
{
	c ^= 162;
	c = ~c;
	c += 105;
	c = -c;
	c -= 37;
	c = ~c;
	c += 8;
	c = ~c;
	return c;
}

unsigned char e875(unsigned char c)
{
	c = -c;
	c -= 180;
	c = -c;
	c -= 32;
	c ^= 158;
	c -= 76;
	c ^= 170;
	c = ~c;
	return c;
}

unsigned char e876(unsigned char c)
{
	c += 119;
	c -= 77;
	c = -c;
	c = ~c;
	c += 73;
	c = ~c;
	c -= 124;
	c ^= 139;
	return c;
}

unsigned char e877(unsigned char c)
{
	c += 129;
	c -= 103;
	c = ~c;
	c += 3;
	c = -c;
	c ^= 254;
	c -= 172;
	c ^= 241;
	return c;
}

unsigned char e878(unsigned char c)
{
	c = -c;
	c -= 45;
	c = -c;
	c += 176;
	c = -c;
	c += 79;
	c = ~c;
	c ^= 186;
	return c;
}

unsigned char e879(unsigned char c)
{
	c = ~c;
	c -= 71;
	c = -c;
	c -= 227;
	c ^= 153;
	c += 63;
	c = -c;
	c ^= 91;
	return c;
}

unsigned char e880(unsigned char c)
{
	c += 209;
	c ^= 164;
	c -= 194;
	c = ~c;
	c ^= 47;
	c += 26;
	c ^= 40;
	c += 230;
	return c;
}

unsigned char e881(unsigned char c)
{
	c = ~c;
	c -= 125;
	c += 195;
	c ^= 190;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e882(unsigned char c)
{
	c = ~c;
	c -= 150;
	c = -c;
	c = ~c;
	c ^= 179;
	c -= 233;
	c ^= 15;
	c -= 165;
	return c;
}

unsigned char e883(unsigned char c)
{
	c -= 43;
	c = -c;
	c ^= 7;
	c = -c;
	c = ~c;
	c ^= 163;
	c -= 89;
	c += 255;
	return c;
}

unsigned char e884(unsigned char c)
{
	c -= 21;
	c ^= 27;
	c = -c;
	c ^= 246;
	c += 100;
	c = -c;
	c = ~c;
	c ^= 201;
	return c;
}

unsigned char e885(unsigned char c)
{
	c ^= 239;
	c = ~c;
	c += 218;
	c ^= 232;
	c = ~c;
	c += 148;
	c -= 50;
	c += 0;
	return c;
}

unsigned char e886(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 44;
	c = ~c;
	c -= 251;
	c = ~c;
	c = -c;
	c -= 215;
	return c;
}

unsigned char e887(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 48;
	c += 207;
	c = ~c;
	c ^= 58;
	c = ~c;
	c ^= 225;
	return c;
}

unsigned char e888(unsigned char c)
{
	c = -c;
	c -= 244;
	c = ~c;
	c ^= 99;
	c -= 25;
	c = ~c;
	c += 234;
	c ^= 81;
	return c;
}

unsigned char e889(unsigned char c)
{
	c = -c;
	c ^= 36;
	c = ~c;
	c -= 144;
	c = ~c;
	c -= 154;
	c += 102;
	c -= 84;
	return c;
}

unsigned char e890(unsigned char c)
{
	c = -c;
	c ^= 67;
	c = ~c;
	c += 236;
	c -= 74;
	c = -c;
	c -= 22;
	c = ~c;
	return c;
}

unsigned char e891(unsigned char c)
{
	c -= 109;
	c ^= 51;
	c += 238;
	c = ~c;
	c -= 37;
	c += 8;
	c = ~c;
	c ^= 221;
	return c;
}

unsigned char e892(unsigned char c)
{
	c = ~c;
	c ^= 32;
	c = -c;
	c = ~c;
	c -= 76;
	c += 155;
	c -= 17;
	c += 119;
	return c;
}

unsigned char e893(unsigned char c)
{
	c = ~c;
	c -= 2;
	c = ~c;
	c ^= 73;
	c -= 111;
	c ^= 5;
	c += 139;
	c = ~c;
	return c;
}

unsigned char e894(unsigned char c)
{
	c = -c;
	c ^= 103;
	c = -c;
	c -= 3;
	c += 185;
	c -= 95;
	c += 117;
	c = ~c;
	return c;
}

unsigned char e895(unsigned char c)
{
	c += 152;
	c ^= 214;
	c += 45;
	c = -c;
	c += 176;
	c = ~c;
	c += 220;
	c ^= 186;
	return c;
}

unsigned char e896(unsigned char c)
{
	c = ~c;
	c ^= 134;
	c -= 116;
	c ^= 18;
	c -= 224;
	c = -c;
	c ^= 12;
	c = ~c;
	return c;
}

unsigned char e897(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c ^= 54;
	c += 164;
	c = ~c;
	c = -c;
	c -= 16;
	return c;
}

unsigned char e898(unsigned char c)
{
	c = -c;
	c += 47;
	c ^= 197;
	c = -c;
	c ^= 40;
	c = -c;
	c ^= 114;
	c += 64;
	return c;
}

unsigned char e899(unsigned char c)
{
	c = -c;
	c += 31;
	c = ~c;
	c ^= 177;
	c = -c;
	c ^= 4;
	c += 34;
	c -= 112;
	return c;
}

unsigned char e900(unsigned char c)
{
	c = -c;
	c ^= 15;
	c -= 165;
	c = -c;
	c += 136;
	c = ~c;
	c += 52;
	c -= 210;
	return c;
}

unsigned char e901(unsigned char c)
{
	c -= 160;
	c = -c;
	c ^= 204;
	c = -c;
	c -= 27;
	c = ~c;
	c ^= 246;
	c -= 100;
	return c;
}

unsigned char e902(unsigned char c)
{
	c -= 130;
	c += 208;
	c -= 206;
	c = -c;
	c = ~c;
	c += 218;
	c ^= 232;
	c -= 166;
	return c;
}

unsigned char e903(unsigned char c)
{
	c ^= 148;
	c = -c;
	c = ~c;
	c -= 0;
	c = ~c;
	c -= 44;
	c ^= 138;
	c -= 215;
	return c;
}

unsigned char e904(unsigned char c)
{
	c ^= 173;
	c = -c;
	c -= 48;
	c ^= 46;
	c = ~c;
	c ^= 58;
	c -= 72;
	c = ~c;
	return c;
}

unsigned char e905(unsigned char c)
{
	c += 199;
	c = -c;
	c = ~c;
	c += 96;
	c -= 222;
	c = -c;
	c -= 234;
	c = -c;
	return c;
}

unsigned char e906(unsigned char c)
{
	c -= 81;
	c = ~c;
	c -= 141;
	c = ~c;
	c ^= 137;
	c = -c;
	c = ~c;
	c -= 154;
	return c;
}

unsigned char e907(unsigned char c)
{
	c -= 168;
	c = -c;
	c = ~c;
	c += 242;
	c = ~c;
	c -= 249;
	c ^= 159;
	c += 216;
	return c;
}

unsigned char e908(unsigned char c)
{
	c = -c;
	c -= 132;
	c ^= 51;
	c = -c;
	c -= 238;
	c = -c;
	c -= 37;
	c = -c;
	return c;
}

unsigned char e909(unsigned char c)
{
	c = ~c;
	c = -c;
	c -= 135;
	c += 221;
	c = -c;
	c += 32;
	c = -c;
	c ^= 127;
	return c;
}

unsigned char e910(unsigned char c)
{
	c += 149;
	c ^= 155;
	c += 17;
	c ^= 119;
	c = ~c;
	c = -c;
	c += 80;
	c = -c;
	return c;
}

unsigned char e911(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c -= 90;
	c = ~c;
	c ^= 189;
	c += 3;
	c -= 185;
	return c;
}

unsigned char e912(unsigned char c)
{
	c += 95;
	c -= 117;
	c += 123;
	c = ~c;
	c += 68;
	c ^= 98;
	c = -c;
	c -= 174;
	return c;
}

unsigned char e913(unsigned char c)
{
	c = -c;
	c = ~c;
	c += 186;
	c -= 200;
	c = -c;
	c = ~c;
	c += 116;
	c = ~c;
	return c;
}

unsigned char e914(unsigned char c)
{
	c -= 227;
	c = ~c;
	c ^= 12;
	c = ~c;
	c ^= 248;
	c += 54;
	c = ~c;
	c ^= 13;
	return c;
}

unsigned char e915(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 9;
	c += 47;
	c = -c;
	c += 26;
	c = -c;
	c -= 230;
	return c;
}

unsigned char e916(unsigned char c)
{
	c = -c;
	c ^= 125;
	c = ~c;
	c -= 64;
	c = -c;
	c += 108;
	c = -c;
	c ^= 88;
	return c;
}

unsigned char e917(unsigned char c)
{
	c ^= 150;
	c += 4;
	c ^= 34;
	c = ~c;
	c += 233;
	c ^= 156;
	c = -c;
	c ^= 43;
	return c;
}

unsigned char e918(unsigned char c)
{
	c ^= 33;
	c = -c;
	c ^= 52;
	c += 89;
	c = ~c;
	c ^= 204;
	c = ~c;
	c ^= 145;
	return c;
}

unsigned char e919(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c += 208;
	c ^= 206;
	c += 252;
	c = ~c;
	c += 166;
	return c;
}

unsigned char e920(unsigned char c)
{
	c = -c;
	c -= 61;
	c ^= 131;
	c -= 57;
	c ^= 223;
	c += 245;
	c ^= 251;
	c = ~c;
	return c;
}

unsigned char e921(unsigned char c)
{
	c += 86;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c += 169;
	c -= 207;
	c += 101;
	return c;
}

unsigned char e922(unsigned char c)
{
	c = ~c;
	c -= 72;
	c ^= 6;
	c += 244;
	c ^= 146;
	c -= 96;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e923(unsigned char c)
{
	c -= 140;
	c += 234;
	c = ~c;
	c += 81;
	c = ~c;
	c -= 36;
	c ^= 66;
	c = ~c;
	return c;
}

unsigned char e924(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 203;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e925(unsigned char c)
{
	c += 167;
	c -= 253;
	c ^= 67;
	c += 62;
	c = ~c;
	c -= 74;
	c = -c;
	c ^= 22;
	return c;
}

unsigned char e926(unsigned char c)
{
	c = -c;
	c ^= 109;
	c = -c;
	c -= 105;
	c += 143;
	c -= 37;
	c += 171;
	c -= 161;
	return c;
}

unsigned char e927(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 82;
	c = -c;
	c -= 158;
	c = -c;
	c ^= 119;
	c = -c;
	return c;
}

unsigned char e928(unsigned char c)
{
	c += 2;
	c ^= 80;
	c += 78;
	c ^= 124;
	c = -c;
	c -= 129;
	c = -c;
	c ^= 20;
	return c;
}

unsigned char e929(unsigned char c)
{
	c += 178;
	c = -c;
	c = ~c;
	c ^= 117;
	c = ~c;
	c = -c;
	c += 214;
	c = ~c;
	return c;
}

unsigned char e930(unsigned char c)
{
	c -= 45;
	c = -c;
	c -= 41;
	c += 220;
	c = ~c;
	c -= 200;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e931(unsigned char c)
{
	c ^= 116;
	c -= 18;
	c += 224;
	c = ~c;
	c += 63;
	c -= 85;
	c += 91;
	c ^= 209;
	return c;
}

unsigned char e932(unsigned char c)
{
	c ^= 55;
	c -= 13;
	c = -c;
	c += 16;
	c -= 14;
	c ^= 60;
	c += 26;
	c = -c;
	return c;
}

unsigned char e933(unsigned char c)
{
	c += 230;
	c -= 212;
	c = -c;
	c ^= 64;
	c -= 190;
	c += 108;
	c = ~c;
	c -= 59;
	return c;
}

unsigned char e934(unsigned char c)
{
	c += 177;
	c -= 23;
	c = -c;
	c ^= 179;
	c -= 110;
	c = ~c;
	c ^= 122;
	c = ~c;
	return c;
}

unsigned char e935(unsigned char c)
{
	c ^= 33;
	c -= 52;
	c += 210;
	c -= 89;
	c ^= 255;
	c = -c;
	c += 27;
	c -= 145;
	return c;
}

unsigned char e936(unsigned char c)
{
	c = ~c;
	c ^= 100;
	c += 130;
	c ^= 208;
	c = ~c;
	c -= 252;
	c += 218;
	c -= 1;
	return c;
}

unsigned char e937(unsigned char c)
{
	c = ~c;
	c = -c;
	c = ~c;
	c += 0;
	c -= 223;
	c = -c;
	c ^= 138;
	c += 24;
	return c;
}

unsigned char e938(unsigned char c)
{
	c = ~c;
	c ^= 196;
	c += 226;
	c ^= 169;
	c -= 207;
	c += 101;
	c -= 235;
	c += 225;
	return c;
}

unsigned char e939(unsigned char c)
{
	c ^= 199;
	c += 29;
	c = ~c;
	c = -c;
	c -= 25;
	c = ~c;
	c -= 140;
	c = -c;
	return c;
}

unsigned char e940(unsigned char c)
{
	c -= 219;
	c ^= 182;
	c = -c;
	c ^= 141;
	c = ~c;
	c += 144;
	c = -c;
	c ^= 175;
	return c;
}

unsigned char e941(unsigned char c)
{
	c += 69;
	c ^= 203;
	c = -c;
	c += 102;
	c = -c;
	c -= 67;
	c = ~c;
	c += 62;
	return c;
}

unsigned char e942(unsigned char c)
{
	c += 236;
	c -= 187;
	c = ~c;
	c += 22;
	c -= 109;
	c ^= 51;
	c = ~c;
	c = -c;
	return c;
}

unsigned char e943(unsigned char c)
{
	c = ~c;
	c ^= 250;
	c -= 8;
	c += 198;
	c -= 180;
	c = -c;
	c ^= 32;
	c -= 158;
	return c;
}

unsigned char e944(unsigned char c)
{
	c -= 76;
	c += 170;
	c = ~c;
	c ^= 118;
	c = ~c;
	c ^= 2;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e945(unsigned char c)
{
	c -= 78;
	c = ~c;
	c = -c;
	c ^= 139;
	c -= 129;
	c += 103;
	c = ~c;
	c -= 178;
	return c;
}

unsigned char e946(unsigned char c)
{
	c = ~c;
	c += 185;
	c = ~c;
	c = -c;
	c ^= 152;
	c = ~c;
	c += 87;
	c = ~c;
	return c;
}

unsigned char e947(unsigned char c)
{
	c -= 98;
	c = ~c;
	c -= 174;
	c += 229;
	c = -c;
	c -= 97;
	c += 71;
	c = ~c;
	return c;
}

unsigned char e948(unsigned char c)
{
	c ^= 18;
	c -= 224;
	c += 94;
	c ^= 12;
	c += 248;
	c -= 54;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e949(unsigned char c)
{
	c = -c;
	c ^= 16;
	c -= 47;
	c = -c;
	c += 26;
	c = ~c;
	c = -c;
	c ^= 230;
	return c;
}

unsigned char e950(unsigned char c)
{
	c += 212;
	c ^= 114;
	c += 64;
	c -= 190;
	c += 108;
	c ^= 202;
	c += 88;
	c = ~c;
	return c;
}

unsigned char e951(unsigned char c)
{
	c = -c;
	c -= 237;
	c ^= 179;
	c = -c;
	c += 110;
	c ^= 156;
	c -= 43;
	c += 33;
	return c;
}

unsigned char e952(unsigned char c)
{
	c = ~c;
	c -= 93;
	c ^= 163;
	c = -c;
	c -= 30;
	c ^= 204;
	c = ~c;
	c ^= 27;
	return c;
}

unsigned char e953(unsigned char c)
{
	c += 145;
	c = -c;
	c ^= 130;
	c = -c;
	c = ~c;
	c = -c;
	c -= 239;
	c += 133;
	return c;
}

unsigned char e954(unsigned char c)
{
	c -= 11;
	c = -c;
	c += 148;
	c = -c;
	c ^= 131;
	c = ~c;
	c ^= 126;
	c = ~c;
	return c;
}

unsigned char e955(unsigned char c)
{
	c += 245;
	c -= 251;
	c += 215;
	c ^= 226;
	c += 48;
	c = -c;
	c ^= 92;
	c += 58;
	return c;
}

unsigned char e956(unsigned char c)
{
	c = -c;
	c += 225;
	c = ~c;
	c -= 244;
	c ^= 99;
	c += 222;
	c -= 140;
	c += 234;
	return c;
}

unsigned char e957(unsigned char c)
{
	c -= 120;
	c += 182;
	c ^= 36;
	c -= 66;
	c ^= 144;
	c += 142;
	c = -c;
	c += 203;
	return c;
}

unsigned char e958(unsigned char c)
{
	c = -c;
	c ^= 167;
	c = ~c;
	c -= 249;
	c ^= 159;
	c = ~c;
	c -= 74;
	c ^= 216;
	return c;
}

unsigned char e959(unsigned char c)
{
	c = ~c;
	c = -c;
	c ^= 51;
	c += 105;
	c -= 143;
	c = ~c;
	c ^= 250;
	c -= 8;
	return c;
}

unsigned char e960(unsigned char c)
{
	c = -c;
	c -= 135;
	c = -c;
	c += 82;
	c = ~c;
	c ^= 127;
	c -= 149;
	c = ~c;
	return c;
}

unsigned char e961(unsigned char c)
{
	c ^= 56;
	c += 118;
	c = ~c;
	c += 77;
	c = -c;
	c += 73;
	c = -c;
	c += 139;
	return c;
}

unsigned char e962(unsigned char c)
{
	c -= 129;
	c = -c;
	c = ~c;
	c -= 254;
	c = ~c;
	c ^= 117;
	c = ~c;
	c -= 152;
	return c;
}

unsigned char e963(unsigned char c)
{
	c -= 214;
	c = -c;
	c ^= 45;
	c = -c;
	c -= 176;
	c ^= 174;
	c += 220;
	c ^= 107;
	return c;
}

unsigned char e964(unsigned char c)
{
	c = -c;
	c -= 71;
	c += 18;
	c ^= 224;
	c += 94;
	c ^= 12;
	c -= 106;
	c = -c;
	return c;
}

unsigned char e965(unsigned char c)
{
	c ^= 209;
	c -= 55;
	c ^= 13;
	c = -c;
	c ^= 16;
	c = ~c;
	c -= 47;
	c = ~c;
	return c;
}

unsigned char e966(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 65;
	c -= 39;
	c += 114;
	c -= 64;
	c = -c;
	c += 108;
	return c;
}

unsigned char e967(unsigned char c)
{
	c = ~c;
	c += 59;
	c = ~c;
	c ^= 4;
	c += 34;
	c ^= 112;
	c -= 110;
	c = ~c;
	return c;
}

unsigned char e968(unsigned char c)
{
	c ^= 122;
	c -= 136;
	c += 70;
	c = -c;
	c -= 163;
	c += 89;
	c ^= 204;
	c = -c;
	return c;
}

unsigned char e969(unsigned char c)
{
	c += 184;
	c = -c;
	c += 247;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 208;
	c += 206;
	return c;
}

unsigned char e970(unsigned char c)
{
	c -= 252;
	c = ~c;
	c = -c;
	c = ~c;
	c -= 1;
	c += 231;
	c ^= 50;
	c -= 57;
	return c;
}

unsigned char e971(unsigned char c)
{
	c ^= 223;
	c -= 245;
	c = ~c;
	c += 113;
	c ^= 215;
	c = -c;
	c ^= 48;
	c -= 46;
	return c;
}

unsigned char e972(unsigned char c)
{
	c = ~c;
	c += 101;
	c ^= 72;
	c -= 199;
	c = -c;
	c = ~c;
	c -= 96;
	c += 222;
	return c;
}

unsigned char e973(unsigned char c)
{
	c = ~c;
	c -= 213;
	c += 219;
	c = -c;
	c += 182;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e974(unsigned char c)
{
	c -= 142;
	c = -c;
	c += 69;
	c = ~c;
	c ^= 168;
	c = ~c;
	c += 253;
	c -= 67;
	return c;
}

unsigned char e975(unsigned char c)
{
	c ^= 249;
	c -= 159;
	c = -c;
	c += 74;
	c -= 216;
	c = ~c;
	c += 151;
	c ^= 109;
	return c;
}

unsigned char e976(unsigned char c)
{
	c ^= 51;
	c += 105;
	c -= 143;
	c = ~c;
	c ^= 250;
	c = -c;
	c = ~c;
	c ^= 135;
	return c;
}

unsigned char e977(unsigned char c)
{
	c ^= 221;
	c = -c;
	c -= 32;
	c = ~c;
	c -= 127;
	c ^= 149;
	c -= 56;
	c = ~c;
	return c;
}

unsigned char e978(unsigned char c)
{
	c -= 119;
	c = -c;
	c -= 2;
	c ^= 73;
	c += 111;
	c -= 5;
	c ^= 104;
	c += 20;
	return c;
}

unsigned char e979(unsigned char c)
{
	c += 178;
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c += 123;
	c = ~c;
	return c;
}

unsigned char e980(unsigned char c)
{
	c = -c;
	c ^= 87;
	c = -c;
	c += 98;
	c = ~c;
	c ^= 41;
	c -= 220;
	c += 186;
	return c;
}

unsigned char e981(unsigned char c)
{
	c ^= 200;
	c = ~c;
	c = -c;
	c += 116;
	c -= 18;
	c += 224;
	c ^= 63;
	c = -c;
	return c;
}

unsigned char e982(unsigned char c)
{
	c += 106;
	c = ~c;
	c -= 209;
	c = ~c;
	c = -c;
	c += 194;
	c = -c;
	c += 9;
	return c;
}

unsigned char e983(unsigned char c)
{
	c = -c;
	c = ~c;
	c -= 197;
	c ^= 75;
	c += 230;
	c -= 212;
	c = ~c;
	c ^= 64;
	return c;
}

unsigned char e984(unsigned char c)
{
	c = ~c;
	c += 108;
	c ^= 202;
	c = ~c;
	c = -c;
	c -= 150;
	c += 4;
	c ^= 34;
	return c;
}

unsigned char e985(unsigned char c)
{
	c = -c;
	c -= 233;
	c = -c;
	c ^= 156;
	c = -c;
	c = ~c;
	c = -c;
	c += 7;
	return c;
}

unsigned char e986(unsigned char c)
{
	c ^= 93;
	c = ~c;
	c ^= 255;
	c += 21;
	c = ~c;
	c = -c;
	c += 145;
	c ^= 247;
	return c;
}

unsigned char e987(unsigned char c)
{
	c += 205;
	c = ~c;
	c -= 208;
	c = -c;
	c += 252;
	c = ~c;
	c += 11;
	c = -c;
	return c;
}

unsigned char e988(unsigned char c)
{
	c ^= 166;
	c -= 148;
	c = ~c;
	c ^= 131;
	c -= 223;
	c ^= 245;
	c += 251;
	c = -c;
	return c;
}

unsigned char e989(unsigned char c)
{
	c = -c;
	c ^= 215;
	c -= 173;
	c = -c;
	c = ~c;
	c ^= 46;
	c = -c;
	c ^= 101;
	return c;
}

unsigned char e990(unsigned char c)
{
	c = ~c;
	c ^= 72;
	c -= 6;
	c ^= 244;
	c += 146;
	c ^= 96;
	c = ~c;
	c ^= 213;
	return c;
}

unsigned char e991(unsigned char c)
{
	c = -c;
	c = ~c;
	c ^= 183;
	c += 66;
	c = -c;
	c += 137;
	c = ~c;
	c += 188;
	return c;
}

unsigned char e992(unsigned char c)
{
	c = -c;
	c += 168;
	c ^= 102;
	c = ~c;
	c -= 242;
	c += 192;
	c = -c;
	c += 159;
	return c;
}

unsigned char e993(unsigned char c)
{
	c += 181;
	c = -c;
	c += 216;
	c -= 22;
	c = -c;
	c = ~c;
	c ^= 51;
	c -= 238;
	return c;
}

unsigned char e994(unsigned char c)
{
	c += 28;
	c ^= 250;
	c = -c;
	c += 198;
	c -= 180;
	c = -c;
	c = ~c;
	c ^= 32;
	return c;
}

unsigned char e995(unsigned char c)
{
	c = ~c;
	c += 127;
	c = ~c;
	c = -c;
	c += 56;
	c = ~c;
	c = -c;
	c -= 77;
	return c;
}

unsigned char e996(unsigned char c)
{
	c = -c;
	c = ~c;
	c = -c;
	c = ~c;
	c = -c;
	c -= 5;
	c = -c;
	c += 104;
	return c;
}

unsigned char e997(unsigned char c)
{
	c = -c;
	c += 103;
	c ^= 189;
	c = -c;
	c -= 128;
	c = ~c;
	c = -c;
	c = ~c;
	return c;
}

unsigned char e998(unsigned char c)
{
	c ^= 123;
	c = -c;
	c = ~c;
	c ^= 98;
	c += 176;
	c = -c;
	c += 79;
	c ^= 229;
	return c;
}

unsigned char e999(unsigned char c)
{
	c = ~c;
	c ^= 200;
	c += 71;
	c ^= 157;
	c += 227;
	c ^= 94;
	c += 85;
	c ^= 248;
	return c;
}

unsigned char (*e[1000])(unsigned char) = {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,e62,e63,e64,e65,e66,e67,e68,e69,e70,e71,e72,e73,e74,e75,e76,e77,e78,e79,e80,e81,e82,e83,e84,e85,e86,e87,e88,e89,e90,e91,e92,e93,e94,e95,e96,e97,e98,e99,e100,e101,e102,e103,e104,e105,e106,e107,e108,e109,e110,e111,e112,e113,e114,e115,e116,e117,e118,e119,e120,e121,e122,e123,e124,e125,e126,e127,e128,e129,e130,e131,e132,e133,e134,e135,e136,e137,e138,e139,e140,e141,e142,e143,e144,e145,e146,e147,e148,e149,e150,e151,e152,e153,e154,e155,e156,e157,e158,e159,e160,e161,e162,e163,e164,e165,e166,e167,e168,e169,e170,e171,e172,e173,e174,e175,e176,e177,e178,e179,e180,e181,e182,e183,e184,e185,e186,e187,e188,e189,e190,e191,e192,e193,e194,e195,e196,e197,e198,e199,e200,e201,e202,e203,e204,e205,e206,e207,e208,e209,e210,e211,e212,e213,e214,e215,e216,e217,e218,e219,e220,e221,e222,e223,e224,e225,e226,e227,e228,e229,e230,e231,e232,e233,e234,e235,e236,e237,e238,e239,e240,e241,e242,e243,e244,e245,e246,e247,e248,e249,e250,e251,e252,e253,e254,e255,e256,e257,e258,e259,e260,e261,e262,e263,e264,e265,e266,e267,e268,e269,e270,e271,e272,e273,e274,e275,e276,e277,e278,e279,e280,e281,e282,e283,e284,e285,e286,e287,e288,e289,e290,e291,e292,e293,e294,e295,e296,e297,e298,e299,e300,e301,e302,e303,e304,e305,e306,e307,e308,e309,e310,e311,e312,e313,e314,e315,e316,e317,e318,e319,e320,e321,e322,e323,e324,e325,e326,e327,e328,e329,e330,e331,e332,e333,e334,e335,e336,e337,e338,e339,e340,e341,e342,e343,e344,e345,e346,e347,e348,e349,e350,e351,e352,e353,e354,e355,e356,e357,e358,e359,e360,e361,e362,e363,e364,e365,e366,e367,e368,e369,e370,e371,e372,e373,e374,e375,e376,e377,e378,e379,e380,e381,e382,e383,e384,e385,e386,e387,e388,e389,e390,e391,e392,e393,e394,e395,e396,e397,e398,e399,e400,e401,e402,e403,e404,e405,e406,e407,e408,e409,e410,e411,e412,e413,e414,e415,e416,e417,e418,e419,e420,e421,e422,e423,e424,e425,e426,e427,e428,e429,e430,e431,e432,e433,e434,e435,e436,e437,e438,e439,e440,e441,e442,e443,e444,e445,e446,e447,e448,e449,e450,e451,e452,e453,e454,e455,e456,e457,e458,e459,e460,e461,e462,e463,e464,e465,e466,e467,e468,e469,e470,e471,e472,e473,e474,e475,e476,e477,e478,e479,e480,e481,e482,e483,e484,e485,e486,e487,e488,e489,e490,e491,e492,e493,e494,e495,e496,e497,e498,e499,e500,e501,e502,e503,e504,e505,e506,e507,e508,e509,e510,e511,e512,e513,e514,e515,e516,e517,e518,e519,e520,e521,e522,e523,e524,e525,e526,e527,e528,e529,e530,e531,e532,e533,e534,e535,e536,e537,e538,e539,e540,e541,e542,e543,e544,e545,e546,e547,e548,e549,e550,e551,e552,e553,e554,e555,e556,e557,e558,e559,e560,e561,e562,e563,e564,e565,e566,e567,e568,e569,e570,e571,e572,e573,e574,e575,e576,e577,e578,e579,e580,e581,e582,e583,e584,e585,e586,e587,e588,e589,e590,e591,e592,e593,e594,e595,e596,e597,e598,e599,e600,e601,e602,e603,e604,e605,e606,e607,e608,e609,e610,e611,e612,e613,e614,e615,e616,e617,e618,e619,e620,e621,e622,e623,e624,e625,e626,e627,e628,e629,e630,e631,e632,e633,e634,e635,e636,e637,e638,e639,e640,e641,e642,e643,e644,e645,e646,e647,e648,e649,e650,e651,e652,e653,e654,e655,e656,e657,e658,e659,e660,e661,e662,e663,e664,e665,e666,e667,e668,e669,e670,e671,e672,e673,e674,e675,e676,e677,e678,e679,e680,e681,e682,e683,e684,e685,e686,e687,e688,e689,e690,e691,e692,e693,e694,e695,e696,e697,e698,e699,e700,e701,e702,e703,e704,e705,e706,e707,e708,e709,e710,e711,e712,e713,e714,e715,e716,e717,e718,e719,e720,e721,e722,e723,e724,e725,e726,e727,e728,e729,e730,e731,e732,e733,e734,e735,e736,e737,e738,e739,e740,e741,e742,e743,e744,e745,e746,e747,e748,e749,e750,e751,e752,e753,e754,e755,e756,e757,e758,e759,e760,e761,e762,e763,e764,e765,e766,e767,e768,e769,e770,e771,e772,e773,e774,e775,e776,e777,e778,e779,e780,e781,e782,e783,e784,e785,e786,e787,e788,e789,e790,e791,e792,e793,e794,e795,e796,e797,e798,e799,e800,e801,e802,e803,e804,e805,e806,e807,e808,e809,e810,e811,e812,e813,e814,e815,e816,e817,e818,e819,e820,e821,e822,e823,e824,e825,e826,e827,e828,e829,e830,e831,e832,e833,e834,e835,e836,e837,e838,e839,e840,e841,e842,e843,e844,e845,e846,e847,e848,e849,e850,e851,e852,e853,e854,e855,e856,e857,e858,e859,e860,e861,e862,e863,e864,e865,e866,e867,e868,e869,e870,e871,e872,e873,e874,e875,e876,e877,e878,e879,e880,e881,e882,e883,e884,e885,e886,e887,e888,e889,e890,e891,e892,e893,e894,e895,e896,e897,e898,e899,e900,e901,e902,e903,e904,e905,e906,e907,e908,e909,e910,e911,e912,e913,e914,e915,e916,e917,e918,e919,e920,e921,e922,e923,e924,e925,e926,e927,e928,e929,e930,e931,e932,e933,e934,e935,e936,e937,e938,e939,e940,e941,e942,e943,e944,e945,e946,e947,e948,e949,e950,e951,e952,e953,e954,e955,e956,e957,e958,e959,e960,e961,e962,e963,e964,e965,e966,e967,e968,e969,e970,e971,e972,e973,e974,e975,e976,e977,e978,e979,e980,e981,e982,e983,e984,e985,e986,e987,e988,e989,e990,e991,e992,e993,e994,e995,e996,e997,e998,e999};

unsigned int a,b,c,d,v;

unsigned int f(unsigned int x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

int main(int ac, unsigned char**av)
{
	unsigned char *plaintext;
	int i, len;
	plaintext = av[1];
	a = (unsigned int)plaintext[0];
	b = (unsigned int)plaintext[1];
	c = (unsigned int)plaintext[2];
	d = (unsigned int)plaintext[3];
	len = strlen(plaintext);
	for(i=0;i<len;i++)
	{
		v = f(plaintext[i]);
		v = e[v%1000](plaintext[i]) ^ (v%251);
		printf("%u ",v);
	}
	return 0;
}
