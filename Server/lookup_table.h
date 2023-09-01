#ifndef _SINE_POINTS_
#define _SINE_POINTS_

uint16_t sine_lookup[200] = {100, 103, 106, 109, 112, 115, 119, 122,
                            125, 128, 131, 134, 136, 139, 142, 145,
                            148, 150, 153, 156, 158, 161, 163, 165,
                            168, 170, 172, 174, 176, 178, 180, 182,
                            184, 185, 187, 188, 190, 191, 192, 193,
                            194, 195, 196, 197, 197, 198, 198, 199,
                            199, 199, 199, 199, 199, 199, 198, 198,
                            197, 197, 196, 195, 194, 193, 192, 191,
                            190, 188, 187, 185, 184, 182, 180, 178,
                            176, 174, 172, 170, 168, 165, 163, 161,
                            158, 156, 153, 150, 148, 145, 142, 139,
                            136, 134, 131, 128, 125, 122, 119, 115,
                            112, 109, 106, 103, 100, 97, 94, 91,
                            88, 85, 81, 78, 75, 72, 69, 66,
                            64, 61, 58, 55, 52, 50, 47, 44,
                            42, 39, 37, 35, 32, 30, 28, 26,
                            24, 22, 20, 18, 16, 15, 13, 12,
                            10, 9, 8, 7, 6, 5, 4, 3,
                            3, 2, 2, 1, 1, 1, 1, 1,
                            1, 1, 2, 2, 3, 3, 4, 5,
                            6, 7, 8, 9, 10, 12, 13, 15,
                            16, 18, 20, 22, 24, 26, 28, 30,
                            32, 35, 37, 39, 42, 44, 47, 50,
                            52, 55, 58, 61, 64, 66, 69, 72,
                            75, 78, 81, 85, 88, 91, 94, 97};

uint16_t square_lookup[200] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
							199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199
	                        ,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199
	                        ,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199
	                        ,199,199,199,199};

uint16_t triangle_lookup[200] = {15,30,45,60,75,90,105,120,135,150,165,180,195,210,225,240,255,270,285,300,315,330,345,
                                360,375,390,405,420,435,450,465,480,495,510,525,540,555,570,585,600,615,630,645,660,675,690,705,720,735,750,765,780,795,
                                810,825,840,855,870,885,900,915,930,945,960,975,990,1005,1020,1035,1050,1065,1080,1095,1110,1125,1140,1155,1170,1185,1200,
                                1215,1230,1245,1260,1275,1290,1305,1320,1335,1350,1365,1380,1395,1410,1425,1440,1455,1470,1485,1500,1485,1470,1455,1440,1425,
                                1410,1395,1380,1365,1350,1335,1320,1305,1290,1275,1260,1245,1230,1215,1200,1185,1170,1155,1140,1125,1110,1095,1080,1065,1050,1035,
                                1020,1005,990,975,960,945,930,915,900,885,870,855,840,825,810,795,780,765,750,735,720,705,690,675,660,645,630,615,600,585,570,555,
                                540,525,510,495,480,465,450,435,420,405,390,375,360,345,330,315,300,285,270,255,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,1,};

uint16_t fabs_sin_lookup[200] = {100, 103, 106, 109, 112, 115, 119, 122,
          125, 128, 131, 134, 136, 139, 142, 145,
          148, 150, 153, 156, 158, 161, 163, 165,
          168, 170, 172, 174, 176, 178, 180, 182,
          184, 185, 187, 188, 190, 191, 192, 193,
          194, 195, 196, 197, 197, 198, 198, 199,
          199, 199, 199, 199, 199, 199, 198, 198,
          197, 197, 196, 195, 194, 193, 192, 191,
          190, 188, 187, 185, 184, 182, 180, 178,
          176, 174, 172, 170, 168, 165, 163, 161,
          158, 156, 153, 150, 148, 145, 142, 139,
          136, 134, 131, 128, 125, 122, 119, 115,
          112, 109, 106, 103,100, 103, 106, 109, 112, 115, 119, 122,
          125, 128, 131, 134, 136, 139, 142, 145,
          148, 150, 153, 156, 158, 161, 163, 165,
          168, 170, 172, 174, 176, 178, 180, 182,
          184, 185, 187, 188, 190, 191, 192, 193,
          194, 195, 196, 197, 197, 198, 198, 199,
          199, 199, 199, 199, 199, 199, 198, 198,
          197, 197, 196, 195, 194, 193, 192, 191,
          190, 188, 187, 185, 184, 182, 180, 178,
          176, 174, 172, 170, 168, 165, 163, 161,
          158, 156, 153, 150, 148, 145, 142, 139,
          136, 134, 131, 128, 125, 122, 119, 115,
          112, 109, 106, 103,};

uint16_t sawtooth_lookup[200] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
								26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,
								55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,
								93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,
								121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,
								147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,
								174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199};      

uint16_t ramp_lookup[200] = {0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96,
0x96, 0x96, 0x96, 0x96, 0x96, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C,
0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4,
0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x1B4, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258,
0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x258, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE,
0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x2EE, 0x384, 0x384, 0x384,
0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384, 0x384,
0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A, 0x41A,
0x41A, 0x41A, 0x41A, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0,
0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x4B0, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546,
0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x546, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC,
0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x5DC, 0x672, 0x672, 0x672, 0x672, 0x672,
0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x672, 0x708, 0x708,
0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708, 0x708,
0x708, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E, 0x79E,
0x79E, 0x79E, 0x79E, 0x79E, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834,
0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x834, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA,
0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x8CA, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960,
0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x960, 0x9F6, 0x9f6, 0x9f6, 0x9f6};

#endif