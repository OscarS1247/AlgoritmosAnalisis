#include <conio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
#include <chrono>
using namespace std;

vector<int> selectionSort(vector<int> _datos) {
	for (int i = 0; i < _datos.size(); i++)
	{
		for (int j = i; j < _datos.size(); j++)
		{
			if (_datos[i] > _datos[j])
			{
				int aux = _datos[j];
				_datos[j] = _datos[i];
				_datos[i] = aux;
			}
		}
	}

	return _datos;
}

void imprimirDatos(vector<int> _datos) {
	cout << "\n* * * L i s t a  d e  D a t o s * * *\n";

	for (int i = 0; i < _datos.size(); i++) {
		cout << "[ " << _datos[i] << " ] ";
	}
	cout << "\n\n";
}


int main() {
	vector<int> numeros{ 1116, 2704, 1444, 2498, 3770, 1796, 3239, 3844, 3347, 2554, 3198, 243, 4133, 1342, 2256, 1718, 1686, 3322, 3324, 1503, 592, 190, 4685, 3749, 1195, 1894, 3304, 2395, 4912, 4410, 4225, 1452, 1146, 3957, 2890, 2473, 1561, 4357, 2346, 3779, 197, 1072, 1642, 98, 2276, 3583, 4201, 95, 1972, 4119, 604, 3300, 3062, 975, 4679, 1249, 2828, 1375, 4166, 1070, 3084, 4879, 2358, 2602, 2393, 709, 2554, 1341, 3540, 1829, 3157, 753, 3247, 954, 690, 934, 2114, 2427, 1295, 2691, 2049, 1946, 2830, 912, 3677, 1134, 4021, 992, 1196, 3024, 3720, 1589, 4294, 4017, 2053, 672, 428, 4992, 612, 4192, 2012, 2637, 167, 716, 1490, 2855, 2008, 481, 4258, 4206, 1230, 4313, 1269, 2016, 2500, 1546, 4179, 3560, 446, 4062, 3252, 1822, 100, 525, 3023, 3156, 2426, 4060, 2229, 3777, 1741, 1645, 4537, 2826, 4932, 1962, 4303, 4627, 4287, 4887, 2321, 2420, 4687, 3595, 4940, 3737, 4683, 1639, 4496, 3574, 3616, 549, 399, 38, 520, 71, 3397, 2342, 3058, 3164, 1267, 568, 3915, 1972, 3672, 4113, 3800, 4406, 1762, 4813, 3186, 2687, 4817, 4710, 3889, 406, 3214, 766, 1724, 1794, 1216, 4759, 1967, 4633, 2259, 956, 2036, 4032, 3668, 2860, 3139, 567, 1289, 2189, 3680, 662, 3727, 4732, 106, 3184, 402, 2921, 1763, 1136, 1976, 3559, 4241, 2906, 53, 1889, 1703, 3242, 1818, 384, 2015, 1843, 2407, 706, 4742, 3422, 4294, 580, 2134, 1876, 3987, 1324, 2705, 1016, 3003, 2485, 543, 1104, 4003, 1302, 397, 3695, 1515, 2630, 1348, 4262, 2063, 4394, 2479, 3924, 4555, 4420, 1813, 2067, 1055, 4953, 2133, 4696, 4715, 1665, 2691, 3392, 2551, 2156, 3924, 1862, 2535, 2537, 4646, 4239, 4751, 30, 4144, 1050, 501, 3053, 3151, 3481, 107, 4319, 4438, 4242, 3378, 2956, 3808, 3276, 2698, 365, 401, 977, 3050, 3950, 3482, 2439, 478, 2211, 3967, 3385, 3894, 3361, 465, 4866, 3538, 3451, 3261, 2052, 121, 1982, 1408, 2339, 4240, 4669, 4075, 3088, 2245, 521, 1272, 1416, 3244, 1534, 3738, 2981, 2088, 632, 4322, 19, 4067, 1472, 1802, 3358, 4429, 1456, 1192, 4626, 4306, 2770, 2616, 2806, 145, 3216, 3266, 723, 2871, 177, 2601, 1258, 2612, 2388, 3570, 2480, 51, 893, 4920, 2961, 1933, 472, 3272, 1401, 3095, 851, 3914, 3344, 190, 1055, 3382, 405, 4765, 4158, 745, 3912, 872, 1094, 495, 4610, 3915, 840, 4805, 903, 2494, 3806, 4618, 1110, 2104, 4804, 4579, 1258, 1183, 3121, 4990, 1352, 74, 547, 4390, 4270, 3623, 1887, 3342, 4722, 2336, 927, 996, 1521, 708, 1839, 1089, 1382, 659, 3307, 4168, 4812, 2769, 2426, 3757, 4449, 2719, 934, 2181, 902, 1012, 332, 2272, 1736, 1025, 2937, 769, 510, 2544, 2763, 938, 2494, 1086, 2448, 986, 852, 2909, 4883, 4648, 2598, 613, 757, 2026, 3797, 1360, 1964, 3425, 3679, 2571, 2782, 1354, 1505, 1868, 1161, 583, 3046, 2012, 4026, 719, 1168, 2954, 4217, 4301, 4538, 4867, 2933, 2510, 3640, 683, 2198, 158, 3895, 4237, 1727, 3811, 2763, 2845, 3922, 2044, 2650, 43, 2642, 3020, 4624, 4440, 3655, 367, 3752, 2180, 4808, 4513, 605, 1682, 400, 1979, 2930, 725, 4199, 2326, 361, 3152, 711, 1198, 3308, 4240, 1118, 4572, 2768, 1492, 2482, 1885, 3686, 2081, 1181, 3827, 1949, 490, 216, 3323, 2326, 1734, 2721, 3708, 2722, 4592, 1051, 2864, 127, 1240, 349, 2154, 1879, 942, 3411, 2533, 530, 4756, 2035, 4688, 3700, 2238, 2083, 1757, 227, 334, 3425, 2711, 145, 1742, 1955, 3087, 3157, 2435, 860, 1175, 4243, 2166, 1312, 160, 4781, 831, 954, 2187, 2065, 3695, 714, 418, 2203, 910, 2324, 2766, 3508, 1372, 2215, 3298, 2529, 1649, 983, 1922, 4213, 4604, 193, 3733, 2345, 2011, 2337, 759, 4545, 666, 4162, 2395, 3196, 623, 1449, 473, 3256, 3949, 4113, 4141, 4959, 4345, 4202, 1869, 2882, 2808, 1569, 4395, 1310, 4953, 3318, 2837, 2125, 134, 4941, 2452, 2295, 3251, 520, 1901, 3785, 4671, 1477, 2016, 569, 386, 661, 800, 3155, 3766, 168, 4415, 1113, 754, 1888, 1822, 2961, 2847, 700, 2762, 4756, 4734, 280, 4088, 3431, 3165, 1107, 2315, 4578, 2552, 3225, 3930, 4983, 2080, 3558, 4390, 2522, 3831, 1807, 4084, 4871, 3482, 1531, 3924, 1499, 4000, 4745, 1910, 387, 968, 3282, 3961, 2901, 4313, 3845, 3894, 3042, 2169, 1884, 4580, 2481, 1723, 4918, 4264, 2827, 3584, 4319, 589, 2831, 1031, 1751, 4358, 2863, 351, 3565, 3212, 2897, 1653, 604, 4504, 80, 2618, 2489, 2684, 223, 645, 3675, 2465, 4361, 4111, 3427, 3083, 382, 1956, 3778, 302, 2686, 1948, 2595, 336, 1156, 2515, 3871, 200, 801, 543, 1079, 3242, 1304, 445, 158, 201, 1410, 4345, 535, 3711, 3718, 3697, 1503, 1033, 2345, 2837, 4408, 4751, 3374, 1551, 4384, 3619, 4870, 4138, 2591, 1045, 4801, 980, 4203, 528, 2615, 500, 1288, 1745, 3173, 1543, 289, 376, 2746, 4654, 3181, 2786, 4742, 4614, 4211, 320, 2945, 4613, 2531, 3169, 2755, 3650, 4872, 2484, 4089, 1670, 2651, 1367, 4181, 1136, 780, 4910, 627, 3887, 1058, 1040, 1327, 420, 3603, 2605, 467, 4471, 650, 2088, 4905, 173, 1857, 2766, 990, 2027, 505, 3589, 4474, 2260, 4006, 3502, 3336, 1355, 3407, 2573, 2046, 488, 3891, 204, 3507, 625, 3634, 4887, 841, 3241, 4316, 2770, 964, 2848, 3796, 1172, 737, 473, 251, 3534, 3966, 4818, 1675, 3457, 3701, 2711, 4865, 1243, 1936, 2451, 2587, 3828, 2044, 3696, 2826, 3132, 1608, 4437, 2316, 3675, 1886, 142, 4267, 1420, 3726, 3233, 2502, 4492, 4700, 3228, 3281, 925, 3829, 4431, 2112, 1142, 2250, 1399, 4640, 3113, 4338, 1227, 2558, 2153, 3751, 1016, 3618, 1307, 4273, 859, 428, 3449, 3791, 3478, 4738, 4724, 4753, 4321, 1593, 1195, 2573, 2744, 3586, 2697, 1290, 1127, 2998, 4188, 3672, 577, 3485, 393, 430, 2881, 4827, 4350, 2721, 3982, 1125, 265, 369, 1481, 4010, 249, 4303, 4277, 809, 3122, 4950, 1010, 180, 2598, 1522, 448, 1160, 2858, 2388, 3125, 1890, 3489, 3370, 2823, 4138, 2310, 672, 3458, 1905, 2036, 4788, 691, 1339, 2611, 3388, 278, 3219, 2646, 1691, 917, 1672, 5000, 2009, 1357, 3074, 2761, 3542, 2595, 4912, 776, 244, 1541, 3583, 4960, 1704, 437, 1353, 682, 4257, 2999, 26, 4196, 353, 537, 2941, 3844, 4706, 430, 3909, 3006, 2753, 2587, 4302, 2869, 84, 2884, 1316, 155, 1338, 3559, 3362, 1303, 3294, 4247, 590, 1485, 409, 2639, 828, 609, 4710, 913, 1764, 1100, 2581, 3827, 632, 1812, 1272, 404, 169, 4414, 13, 3303, 1739, 4175, 2414, 3740, 4177, 4156, 1507, 3487, 2180, 1079, 1270, 815, 694, 1475, 1730, 46, 2442, 26, 4987, 3218, 3185, 101, 104, 4310, 2800, 803, 372, 4463, 712, 955, 15, 886, 2768, 541, 4232, 2013, 4445, 804, 3524, 1959, 4096, 1782, 3308, 3616, 2322, 1632, 3991, 3431, 3220, 2482, 3960, 4404, 441, 2239, 2822, 4837, 2252, 1864, 598, 2414, 1511, 1118, 398, 706, 2067, 4590, 4967, 1882, 723, 105, 1121, 1341, 3966, 952, 4929, 2981, 1699, 4852, 1875, 3950, 2593, 4223, 589, 2957, 3363, 2944, 2264, 1691, 4526, 1919, 956, 2884, 4314, 4482, 1555, 3352, 3695, 1098, 3643, 307, 1339, 875, 3967, 3006, 2392, 131, 914, 379, 3009, 4502, 331, 1662, 1906, 1890, 129, 176, 3588, 3841, 2491, 2334, 150, 4133, 134, 1434, 605, 4477, 3621, 897, 3417, 1799, 2485, 3732, 802, 2348, 1233, 2382, 4876, 33, 3682, 2750, 516, 527, 1521, 4556, 2503, 612, 1691, 3338, 4662, 3039, 2307, 2146, 2723, 146, 4486, 3090, 3685, 3360, 1942, 370, 4754, 120, 4365, 1903, 3458, 4800, 3060, 478, 387, 1177, 950, 2961, 559, 4525, 2653, 741, 3302, 1628, 3086, 1231, 3470, 2050, 3723, 4134, 1755, 2861, 1702, 1033, 3121, 369, 2783, 3103, 2029, 1325, 1812, 3349, 4003, 853, 601, 2397, 1291, 3894, 266, 3069, 3844, 3617, 4902, 3487, 4830, 4698, 1189, 387, 3509, 752, 1302, 169, 3468, 4673, 2044, 1651, 2885, 3107, 2766, 291, 1868, 1362, 1444, 1393, 3258, 3656, 3816, 627, 1114, 1512, 4739, 2177, 2599, 795, 2579, 3710, 1907, 2926, 2162, 3456, 3641, 2448, 3563, 4324, 2438, 667, 85, 1544, 2625, 2405, 3379, 3335, 1851, 1321, 3698, 1819, 2744, 3405, 2125, 4995, 3707, 651, 4215, 4322, 2802, 60, 3519, 2983, 3783, 3980, 3010, 3241, 2968, 192, 966, 443, 4777, 3907, 4024, 1694, 2759, 4247, 1192, 4949, 4641, 3918, 1307, 4326, 50, 3468, 2114, 4560, 4371, 1675, 3689, 296, 4751, 3521, 2921, 4808, 3366, 3158, 3561, 4833, 4242, 4508, 2031, 1133, 1959, 878, 1322, 4165, 2477, 710, 3744, 3036, 947, 1200, 4319, 4662, 1549, 4807, 3310, 57, 4426, 3336, 435, 3190, 618, 3589, 2602, 881, 679, 3097, 4949, 2379, 1723, 85, 3340, 3371, 1083, 4402, 2062, 3311, 1975, 3141, 2990, 754, 3404, 4533, 789, 2257, 2991, 1899, 3610, 3156, 895, 1989, 2233, 394, 3568, 1902, 4486, 3907, 4073, 2435, 4121, 527, 4237, 1548, 1623, 1103, 2230, 571, 2605, 2355, 988, 3368, 3483, 3957, 398, 1349, 1792, 3187, 2378, 3217, 3777, 2448, 4950, 743, 3817, 4943, 3394, 4440, 3083, 1247, 2166, 48, 4174, 1519, 1959, 4627, 76, 4992, 4185, 305, 3408, 4299, 4119, 3597, 981, 3699, 1074, 404, 2587, 2153, 3245, 2153, 4365, 1836, 1315, 3175, 4755, 4316, 1803, 2965, 1898, 4619, 3400, 4402, 3192, 755, 1776, 3152, 519, 4558, 4931, 3722, 1407, 438, 1648, 3835, 749, 4518, 3688, 4427, 305, 4245, 382, 117, 4339, 1037, 1068, 334, 1470, 2887, 797, 1638, 2084, 986, 1454, 2754, 2509, 2017, 3533, 381, 53, 1176, 4819, 4055, 2325, 3854, 4128, 3202, 1167, 4056, 2424, 2110, 491, 3035, 1674, 1063, 1424, 2833, 4863, 2632, 2103, 4672, 4575, 2085, 4433, 1718, 3527, 4750, 2298, 4336, 540, 2525, 4396, 1245, 3486, 2112, 4587, 1110, 2316, 3244, 2264, 1581, 1511, 2020, 4744, 3267, 2725, 4507, 4206, 1035, 4553, 53, 1218, 1816, 198, 2962, 2046, 759, 350, 4517, 1944, 2061, 1385, 301, 2410, 656, 4840, 3643, 509, 488, 287, 3820, 2196, 949, 4614, 351, 2092, 1956, 3193, 3343, 1341, 113, 4970, 3357, 4046, 4761, 3395, 3481, 311, 4087, 1444, 1530, 3614, 4, 1204, 1423, 2744, 3763, 3217, 808, 3651, 2185, 2428, 3644, 4477, 4697, 1128, 445, 328, 1233, 1275, 2920, 4552, 2997, 4779, 1512, 3945, 3013, 2400, 1937, 2945, 4186, 4199, 3491, 4987, 2962, 4704, 2086, 2123, 387, 388, 4715, 1050, 2791, 2229, 776, 1066, 3373, 686, 3451, 1949, 3670, 4474, 4070, 849, 4951, 247, 1384, 3048, 3976, 1002, 4035, 2072, 708, 4196, 2184, 1532, 2468, 4024, 1860, 2879, 2974, 399, 1878, 1182, 4560, 1343, 555, 2993, 1244, 3143, 1411, 3590, 4344, 3622, 202, 937, 218, 2769, 4479, 3762, 1064, 777, 2755, 2983, 3138, 3818, 632, 2174, 3314, 1743, 3170, 4856, 1522, 2181, 1777, 3100, 1744, 3846, 1673, 3518, 3731, 1359, 377, 2983, 2074, 4259, 3018, 3537, 88, 2435, 3017, 1371, 2412, 4545, 664, 4404, 523, 2968, 2164, 1109, 2940, 3765, 1075, 2699, 1885, 1256, 2717, 4955, 485, 420, 3835, 3707, 2031, 2284, 2862, 4519, 3200, 3796, 4356, 4399, 1786, 4718, 4334, 1000, 927, 1856, 555, 1920, 2141, 188, 1414, 4836, 4539, 2242, 3287, 1243, 1808, 4986, 4866, 961, 4465, 4646, 4532, 2703, 380, 4816, 1014, 1839, 318, 2727, 3913, 3286, 1099, 4440, 1126, 209, 2466, 3991, 2970, 198, 4175, 1328, 4904, 4084, 1262, 2259, 3314, 4502, 1506, 2113, 3192, 1708, 3978, 4895, 4115, 638, 758, 814, 1328, 3906, 2590, 4208, 302, 3388, 222, 3080, 2638, 300, 3872, 903, 2401, 2166, 2862, 4484, 2721, 2195, 985, 4840, 2975, 2127, 4619, 3217, 3456, 4594, 536, 2638, 3265, 3964, 1839, 556, 3213, 3431, 4284, 1356, 556, 2761, 4122, 3187, 4139, 2892, 2014, 2009, 1304, 2124, 1597, 2595, 4410, 2092, 2486, 3993, 2636, 4426, 1847, 200, 2052, 4886, 1006, 1038, 1522, 2074, 3244, 3541, 3779, 1572, 2573, 128, 3726, 1320, 3372, 3237, 811, 491, 2717, 77, 3522, 3931, 2247, 75, 2532, 3312, 3589, 2990, 3375, 3199, 2069, 2634, 42, 2762, 4554, 4065, 2305, 3708, 3580, 1549, 2708, 1837, 1793, 2140, 4013, 3570, 2075, 4758, 2870, 4490, 741, 1373, 3605, 2216, 4050, 2983, 1343, 187, 2515, 999, 4527, 1826, 4724, 2484, 12, 53, 3774, 623, 992, 4552, 162, 1954, 1686, 4641, 1546, 3489, 4439, 4918, 571, 3422, 769, 1997, 1569, 516, 2738, 1802, 3602, 3617, 4473, 3920, 3289, 1074, 960, 4901, 1750, 3221, 2952, 3882, 3737, 2798, 2253, 4668, 3007, 4728, 1951, 4351, 1843, 2776, 239, 451, 699, 2146, 2066, 4819, 3028, 4495, 83, 4101, 3925, 1881, 1257, 2690, 2835, 3254, 2888, 1496, 3976, 1338, 3744, 4021, 1104, 4289, 3493, 2868, 331, 302, 4967, 4018, 4136, 4194, 4769, 2130, 1611, 1461, 1240, 2880, 2008, 4669, 3284, 938, 1196, 3976, 4843, 3814, 3813, 1793, 127, 3923, 2734, 4241, 1825, 1788, 3541, 4891, 287, 2256, 267, 1120, 3899, 2184, 4512, 2954, 3254, 2671, 3097, 2847, 3333, 397, 1919, 4964, 4333, 1238, 665, 1114, 188, 4818, 3336, 3262, 4276, 2985, 4698, 3866, 3932, 49, 2164, 1883, 4751, 2457, 4745, 464, 1384, 2184, 4930, 3661, 2910, 4768, 681, 2212, 4228, 1713, 2850, 2623, 74, 2617, 4025, 4175, 3397, 2950, 4380, 190, 711, 2711, 3174, 2591, 1151, 3082, 2723, 2277, 3930, 2729, 326, 3500, 1349, 2457, 3915, 948, 2000, 2083, 4486, 2121, 895, 2369, 969, 331, 4749, 2940, 2637, 3148, 3250, 489, 1359, 4198, 3677, 1890, 4003, 1677, 2838, 2871, 3560, 169, 4336, 3548, 1724, 1620, 4237, 3057, 4139, 904, 2033, 2254, 1254, 4591, 4460, 3410, 947, 2412, 595, 1739, 3960, 3115, 1071, 2994, 699, 1183, 1159, 1559, 1892, 2882, 4794, 4922, 4451, 4834, 3193, 2153, 4247, 4022, 4043, 500, 2762, 653, 4066, 1043, 2850, 860, 4103, 3669, 3806, 2647, 4304, 614, 4442, 2033, 3013, 1975, 4603, 2974, 2388, 4248, 309, 2576, 55, 2839, 1840, 2231, 2680, 1378, 1347, 1324, 3788, 2359, 2696, 1090, 4362, 2904, 1694, 1518, 713, 921, 4240, 234, 2348, 4101, 4102, 2773, 4825, 1766, 4927, 1184, 267, 1816, 3353, 2646, 4920, 3605, 4043, 2256, 1893, 2809, 1313, 3294, 2234, 2585, 4784, 3361, 2539, 4671, 2946, 805, 4719, 4221, 2026, 1109, 1890, 723, 136, 2147, 2853, 3927, 3477, 1237, 1066, 1426, 4666, 3326, 1686, 1701, 404, 1222, 4266, 1186, 257, 717, 2026, 71, 772, 3234, 107, 882, 1768, 3048, 2540, 4192, 4420, 2212, 1525, 78, 1802, 2427, 1573, 2001, 1705, 1500, 2165, 4745, 3341, 1242, 3417, 1284, 1558, 4665, 286, 791, 4430, 1902, 2868, 3760, 1641, 4103, 4170, 2747, 3271, 900, 4686, 2812, 1159, 3547, 2041, 4886, 4115, 1655, 2439, 1335, 3578, 2542, 3740, 4833, 4005, 2860, 2853, 4554, 1230, 2790, 1959, 4889, 4753, 2803, 627, 3180, 2009, 4815, 4916, 3430, 2211, 3004, 1080, 961, 2705, 143, 4151, 3849, 1445, 4079, 981, 4518, 1342, 2994, 338, 1362, 4474, 4157, 516, 3031, 823, 796, 4493, 2695, 809, 2872, 4192, 3619, 1630, 1764, 3240, 2913, 3473, 1913, 435, 3194, 1845, 2365, 3843, 4618, 2205, 4124, 1897, 75, 2658, 3170, 3596, 3186, 2148, 4206, 4858, 428, 1351, 3952, 895, 1647, 314, 4540, 3689, 2989, 3876, 327, 3599, 3207, 1920, 84, 2426, 938, 2472, 4122, 830, 1281, 3948, 1507, 2489, 3322, 22, 1024, 2961, 4540, 3158, 2693, 3691, 4445, 2742, 4744, 842, 1414, 3430, 132, 3738, 2166, 2188, 3138, 2342, 1875, 1697, 1589, 2574, 3095, 4672, 4076, 1296, 3433, 1977, 2019, 1180, 4598, 153, 3648, 2976, 1759, 4707, 1216, 3379, 2595, 578, 4637, 2191, 3657, 1670, 2398, 3951, 2235, 161, 3357, 4105, 2412, 1729, 403, 1591, 1152, 2394, 1622, 7, 2008, 2148, 2220, 445, 2948, 3538, 4380, 4405, 4416, 3826, 2254, 3532, 3961, 51, 1380, 3240, 4658, 1277, 685, 1733, 754, 1255, 4522, 2863, 1110, 2289, 3463, 2998, 634, 3529, 1896, 1100, 3588, 4422, 1091, 3609, 1269, 60, 2565, 116, 683, 4383, 1347, 3706, 1777, 4608, 3097, 4861, 1990, 3902, 672, 1086, 3408, 3001, 1462, 2337, 2235, 3011, 1257, 954, 3836, 4717, 456, 913, 4197, 2647, 2219, 1739, 1392, 2607, 2771, 1833, 2008, 4611, 4854, 4240, 2513, 4478, 310, 4082, 19, 3465, 3048, 3322, 3308, 4800, 3700, 391, 2206, 4009, 1533, 4246, 3539, 2683, 1406, 2059, 1759, 1236, 207, 2333, 1738, 1316, 4307, 4715, 627, 1177, 4726, 4749, 425, 1921, 1349, 771, 1911, 1313, 1444, 1665, 35, 1065, 4673, 4235, 1598, 1290, 4963, 108, 2519, 4625, 4595, 1426, 736, 1296, 1965, 3581, 2541, 3077, 4752, 3449, 234, 4793, 814, 3004, 418, 2994, 1681, 3227, 1478, 4735, 3394, 1706, 2811, 4552, 1481, 4865, 712, 2712, 4411, 1904, 4970, 801, 211, 1227, 4919, 2643, 89, 55, 3469, 992, 4315, 4893, 4925, 4214, 3303, 1647, 4491, 3771, 115, 3934, 2867, 3908, 2814, 3153, 3879, 3647, 74, 970, 651, 2239, 2874, 3309, 2115, 2647, 4812, 3477, 294, 2452, 2958, 2719, 639, 3013, 1020, 1241, 1749, 3047, 3810, 2337, 2484, 659, 3182, 261, 4451, 4329, 3625, 3060, 235, 4290, 4247, 3362, 3724, 130, 2143, 3877, 715, 3648, 2726, 2566, 2555, 1508, 133, 4410, 3179, 1721, 3077, 3953, 1611, 3224, 113, 3474, 2683, 4896, 603, 3041, 4112, 1821, 146, 1150, 4234, 3715, 3649, 364, 3228, 158, 382, 3339, 1833, 1554, 4281, 1239, 1509, 4868, 1898, 202, 4354, 4604, 1527, 1052, 333, 1687, 148, 2195, 3261, 1896, 1776, 2166, 2047, 1230, 3964, 4826, 2100, 3280, 196, 2765, 1664, 4487, 4794, 372, 642, 3963, 1966, 1908, 649, 3475, 3533, 65, 2192, 3151, 2852, 134, 2947, 3070, 219, 3521, 2026, 928, 1934, 3553, 1440, 400, 740, 3599, 4315, 592, 3612, 3763, 2168, 1330, 3047, 3265, 2080, 2492, 3136, 4641, 4529, 1779, 293, 4503, 1113, 4198, 3581, 2213, 2528, 109, 3820, 2215, 3663, 1346, 788, 1517, 735, 4346, 1980, 3471, 4923, 2442, 1466, 1167, 1394, 2999, 2119, 1222, 147, 3194, 725, 3092, 3209, 4024, 4792, 2173, 1547, 2310, 1815, 1489, 1092, 2844, 4769, 3350, 3420, 3802, 4934, 139, 3897, 2808, 1666, 3198, 3218, 191, 2465, 2518, 2609, 1836, 2271, 1309, 579, 4591, 633, 539, 460, 825, 949, 1135, 1411, 897, 3053, 1272, 1473, 4423, 2991, 4458, 2050, 4202, 338, 2237, 3868, 479, 3811, 4026, 4814, 2897, 1800, 4134, 1099, 1442, 4168, 1561, 3672, 1101, 4584, 1250, 2528, 3688, 4528, 1892, 3342, 1495, 748, 1353, 4460, 1371, 2266, 284, 4734, 2779, 4654, 4426, 4118, 1985, 2550, 2547, 4912, 1319, 1289, 357, 1194, 3666, 2200, 4103, 2599, 684, 4348, 3825, 4001, 1156, 1483, 950, 3682, 944, 1074, 2555, 67, 4707, 3398, 2342, 3100, 544, 4151, 111, 1602, 764, 1956, 970, 4003, 2038, 1671, 2639, 2098, 3260, 4240, 493, 3879, 4550, 2453, 389, 3257, 2078, 2905, 2144, 460, 1670, 3773, 3532, 2773, 1111, 4791, 2773, 2623, 988, 2279, 3775, 4778, 2223, 1253, 3166, 209, 1344, 1853, 3139, 2528, 2401, 1702, 572, 2863, 756, 990, 3692, 1963, 788, 69, 4811, 2740, 1839, 895, 200, 2216, 1366, 2696, 1513, 2865, 1580, 4977, 650, 4029, 3111, 1053, 2079, 4215, 4185, 4302, 996, 4758, 3775, 2388, 3538, 1012, 4174, 56, 2477, 4579, 881, 4087, 237, 492, 12, 2446, 970, 1827, 3921, 3939, 3897, 3236, 3357, 1800, 1747, 3956, 4814, 3475, 4024, 1614, 4790, 4914, 4360, 4049, 479, 3661, 332, 2497, 1308, 4827, 1264, 3673, 2740, 3903, 3917, 1426, 3917, 1339, 3529, 689, 1349, 4100, 1746, 2373, 2650, 3373, 3394, 426, 4138, 3900, 1571, 789, 1147, 4454, 2432, 3346, 3701, 2616, 881, 1419, 2553, 4956, 3959, 1971, 389, 1311, 2592, 1513, 1626, 309, 2036, 285, 1216, 1031, 1, 3511, 1605, 1845, 3912, 1995, 2998, 4924, 4020, 2720, 1612, 1931, 3547, 1003, 4061, 3952, 436, 3089, 4594, 4328, 666, 3944, 1515, 4712, 1005, 4004, 2777, 3005, 3760, 306, 2169, 4984, 1949, 4699, 458, 1912, 2864, 4463, 2246, 3211, 3712, 748, 1926, 1625, 1782, 3202, 2324, 202, 4309, 3164, 4078, 2810, 2169, 4416, 429, 79, 2955, 1687, 908, 870, 702, 1340, 2718, 3612, 4006, 2031, 2417, 745, 4598, 3730, 1996, 268, 3206, 1785, 1237, 2773, 3845, 2981, 2302, 1922, 986, 3047, 3599, 3042, 4268, 1881, 3229, 3453, 2784, 361, 2975, 1042, 4651, 584, 2909, 2915, 2731, 2140, 1137, 4174, 3031, 355, 4231, 4006, 2103, 417, 1035, 3539, 592, 2288, 10, 3349, 269, 3146, 649, 4640, 2419, 3828, 2608, 2310, 4673, 4040, 1747, 4129, 3908, 4740, 103, 3936, 3076, 2980, 1063, 639, 4809, 4606, 3326, 4812, 3343, 1443, 4091, 1210, 3538, 3682, 708, 2800, 3318, 2840, 326, 2325, 2786, 1137, 4122, 4863, 1113, 163, 227, 2397, 1690, 4625, 2476, 227, 2850, 2950, 637, 4489, 1922, 2562, 2032, 1882, 745, 2464, 4106, 818, 2727, 4470, 1844, 1784, 4301, 343, 3949, 14, 1329, 350, 3830, 4866, 622, 1638, 2980, 4068, 21, 453, 1036, 470, 1837, 2819, 2477, 2682, 241, 4559, 644, 3260, 1293, 1267, 1745, 1992, 3065, 414, 4689, 1338, 4405, 740, 4606, 4865, 1222, 3456, 999, 882, 3471, 3124, 188, 2377, 882, 3737, 3265, 805, 4118, 13, 564, 1821, 443, 3928, 988, 4588, 2214, 3090, 4298, 1799, 1801, 3267, 1020, 2173, 3278, 3985, 3289, 3841, 4733, 1525, 4544, 3950, 4921, 233, 3655, 4652, 2301, 1721, 4501, 3719, 2165, 1654, 3844, 2130, 3603, 3123, 1913, 4877, 4200, 2848, 1059, 1566, 2579, 4425, 860, 4106, 4114, 2171, 4005, 4561, 4051, 2346, 2422, 4939, 1974, 2314, 799, 4352, 877, 1960, 2728, 328, 308, 1309, 4781, 3411, 3502, 58, 2649, 1928, 3538, 1580, 2060, 1601, 508, 3236, 490, 1002, 4952, 1832, 3331, 4066, 1471, 4597, 401, 1820, 1312, 537, 3632, 3121, 3644, 1117, 1985, 1424, 2477, 4031, 4517, 4771, 284, 1494, 1774, 3579, 757, 348, 4144, 1504, 3337, 4718, 2695, 3713, 3103, 355, 271, 1602, 1520, 3432, 3618, 555, 1267, 1000, 2979, 3930, 1191, 462, 1073, 2214, 3357, 2163, 4853, 3702, 2640, 823, 465, 2554, 4068, 865, 3930, 4615, 212, 3869, 3855, 3445, 3143, 4362, 4083, 2361, 4958, 560, 4825, 1709, 4953, 1466, 4245, 1960, 4457, 1335, 3634, 256, 2814, 3055, 2521, 723, 2493, 4098, 1608, 710, 3073, 2948, 4149, 1757, 4713, 2432, 4063, 523, 4792, 4610, 4688, 3407, 911, 4156, 2154, 368, 2224, 4527, 1610, 2332, 2355, 2944, 776, 2007, 2523, 2775, 2388, 1972, 4667, 826, 3749, 4176, 2509, 3523, 4139, 224, 2969, 2196, 1580, 1209, 2035, 4909, 3099, 3888, 1164, 2683, 3320, 331, 2480, 3115, 4883, 3522, 3341, 4036, 1507, 3340, 1796, 4061, 1041, 3192, 4386, 2354, 266, 3396, 3202, 1043, 4537, 4455, 4674, 753, 2985, 4699, 4039, 3134, 1263, 926, 3148, 1351, 773, 3234, 4619, 4355, 3901, 1257, 3520, 4934, 4843, 1709, 3996, 859, 1725, 4317, 2300, 2325, 1121, 1475, 3117, 4689, 1718, 1941, 3170, 2987, 1857, 3469, 960, 1597, 319, 3447, 833, 4177, 4905, 3145, 1138, 591, 950, 3336, 95, 4616, 2511, 235, 2720, 3336, 3464, 4583, 4303, 4115, 2230, 4701, 1934, 963, 3816, 4462, 1336, 163, 2804, 82, 1225, 1373, 1626, 4947, 2293, 1132, 1630, 414, 3858, 3050, 3388, 806, 87, 791, 4321, 2281, 976, 1850, 1419, 3123, 2398, 1996, 4682, 202, 1420, 1550, 1654, 842, 844, 2748, 2886, 3428, 4738, 2668, 1844, 1380, 3424, 2925, 425, 1708, 1832, 4186, 528, 3785, 4435, 2195, 3631, 3753, 2443, 1435, 643, 302, 974, 381, 3347, 2047, 3965, 1238, 2706, 360, 1793, 715, 1996, 3567, 4157, 4361, 4746, 3582, 1816, 1728, 2454, 3708, 1750, 157, 4463, 1786, 3064, 4553, 3394, 2526, 3387, 1308, 4765, 3853, 3981, 4731, 3632, 3579, 2534, 3124, 1261, 1351, 1623, 4692, 1547, 2453, 2169, 1679, 1761, 2111, 2661, 860, 764, 1081, 711, 4599, 2858, 2414, 138, 3703, 4428, 4821, 2078, 3515, 164, 3945, 3593, 2631, 4586, 2046, 289, 4886, 2065, 2705, 4967, 4406, 4320, 1619, 4299, 2059, 1591, 4204, 4817, 578, 132, 839, 4488, 4292, 2723, 1099, 2415, 4831, 2479, 3130, 3990, 1134, 2382, 4043, 3099, 2899, 3479, 845, 2375, 3808, 3935, 1583, 1348, 2718, 4943, 1572, 1743, 4544, 53, 4960, 4603, 2742, 430, 320, 4232, 4005, 461, 4395, 3169, 4755, 2372, 2561, 3883, 3359, 843, 262, 917, 2144, 62, 3436, 2007, 3692, 2155, 717, 3775, 3462, 1771, 3487, 2863, 1091, 809, 3283, 1852, 1680, 3093, 173, 2340, 3248, 3894, 4625, 2339, 483, 1561, 4676, 468, 4112, 1419, 538, 4297, 3171, 3225, 2895, 4339, 3070, 715, 708, 3205, 1497, 857, 3261, 1810, 359, 4157, 3233, 1940, 4588, 4243, 377, 351, 2065, 4209, 3064, 2427, 2493, 1784, 4398, 2370, 3639, 1936, 159, 1664, 3258, 1144, 2175, 4476, 1364, 1419, 1461, 4956, 2770, 1661, 2666, 2910, 535, 1996, 1497, 717, 4005, 3533, 3179, 715, 512, 952, 3287, 4296, 2898, 2220, 3406, 645, 3580, 560, 2563, 3435, 253, 3580, 4733, 4515, 2246, 4232, 651, 1040, 3795, 917, 1217, 4433, 4950, 3863, 1979, 377, 84, 2351, 2497, 1786, 2276, 3895, 2514, 2262, 4541, 3276, 3007, 3651, 4695, 2309, 665, 4154, 808, 592, 3733, 4168, 4481, 1665, 3469, 38, 1032, 2601, 3857, 1933, 3897, 2201, 2579, 2289, 268, 808, 1906, 3018, 2067, 4386, 806, 4356, 269, 4451, 4089, 2488, 190, 1173, 1952, 4182, 1636, 2086, 4465, 3722, 2979, 3841, 3676, 1887, 1396, 2948, 2271, 3517, 3853, 2330, 2764, 379, 4774, 4482, 749, 2198, 417, 104, 1441, 2047, 4667, 4843, 3539, 2398, 4890, 405, 3992, 23, 4806, 2543, 655, 3992, 2729, 2947, 2661, 3718, 4602, 2813, 2413, 2426, 3472, 1882, 2312, 1046, 1210, 953, 484, 344, 576, 1815, 1855, 4254, 3594, 4690, 1570, 4, 1961, 4398, 3162, 4469, 452, 4073, 962, 2481, 3758, 4038, 3000, 4334, 3195, 4171, 505, 4347, 2570, 2012, 4249, 29, 3507, 3741, 4331, 2867, 4601, 349, 124, 4675, 417, 4223, 1936, 301, 1336, 2893, 3154, 169, 4795, 2572, 3420, 3889, 2652, 3044, 3124, 1989, 1388, 1466, 3888, 353, 4082, 3193, 3078, 2169, 4987, 183, 3020, 3624, 3086, 2978, 1282, 3049, 1840, 79, 1893, 186, 539, 3620, 4724, 2716, 4787, 4235, 691, 1764, 2643, 1779, 3417, 3623, 3730, 4910, 1513, 1861, 152, 325, 2184, 1717, 2098, 3267, 330, 1819, 1539, 479, 146, 4808, 4285, 4469, 2279, 4981, 604, 2581, 2622, 2389, 538, 3199, 1989, 1807, 1756, 4117, 2280, 2796, 4841, 4185, 568, 1026, 1578, 3924, 4786, 2144, 502, 2091, 2132, 1674, 740, 3555, 1385, 2158, 2585, 1541, 630, 1977, 285, 358, 3279, 4122, 3928, 1149, 4402, 533, 1263, 1401, 693, 1600, 814, 2349, 1406, 1148, 495, 1920, 2060, 3091, 2519, 4626, 3617, 2549, 2748, 2534, 2403, 1970, 2922, 108, 1200, 2110, 3237, 4298, 3871, 2759, 914, 4691, 2363, 2774, 3567, 1896, 3467, 1495, 3599, 4656, 1451, 4515, 774, 1103, 3143, 2862, 3824, 1379, 1802, 3096, 2000, 3825, 1028, 346, 3179, 2373, 1353, 1946, 4691, 1987, 2788, 439, 1284, 1361, 1147, 884, 2914, 1131, 2586, 187, 452, 1332, 3883, 2780, 3530, 2847, 411, 2314, 3012, 4659, 4758, 2802, 859, 1491, 3867, 153, 2578, 4021, 1834, 2338, 4741, 1793, 4816, 895, 4453, 3723, 3914, 2321, 4669, 2501, 661, 873, 3962, 3983, 617, 1542, 908, 62, 2987, 4583, 2488, 2643, 1248, 4720, 3581, 121, 701, 152, 3617, 718, 579, 1438, 245, 2758, 731, 4220, 3729, 1787, 594, 117, 3042, 3786, 1420, 1144, 3282, 3633, 3551, 543, 1848, 4743, 3172, 719, 1423, 4541, 4551, 2939, 385, 1759, 1285, 2884, 2234, 2302, 774, 954, 191, 3540, 2292, 3759, 3044, 2224, 1687, 1054, 2738, 1911, 4515, 2458, 1560, 2677, 557, 1941, 477, 583, 3771, 4914, 359, 2700, 566, 4259, 2203, 738, 2722, 1274, 4063, 2438, 2278, 273, 2459, 474, 608, 213, 1479, 4758, 3248, 1878, 2401, 2460, 4314, 2703, 3505, 241, 1198, 2646, 64, 1592, 4587, 564, 4039, 462, 3352, 3059, 257, 1323, 1470, 1256, 1788, 1500, 744, 1638, 4022, 3355, 3774, 2772, 3345, 2244, 308, 612, 3002, 2313, 2974, 3303, 1024, 1637, 56, 3232, 2509, 2921, 4420, 3693, 394, 3145, 3392, 1471, 2794, 2639, 805, 2452, 3783, 40, 3471, 491, 2970, 2454, 4197, 4575, 3416, 1039, 2610, 2862, 3997, 2020, 1086, 653, 4925, 4398, 818, 1717, 1859, 4858, 717, 745, 4298, 370, 3864, 4154, 2627, 756, 1717, 4677, 2487, 1763, 4190, 2100, 44, 4103, 1246, 1380, 4084, 1898, 1985, 1985, 3707, 3823, 4473, 3268, 4282, 2475, 1966, 4087, 1440, 4720, 4566, 4420, 3856, 1091, 781, 2319, 3858, 2261, 2076, 2403, 3755, 2075, 3897, 1496, 4375, 4971, 4166, 536, 2091, 4806, 751, 492, 1140, 2642, 3700, 931, 2398, 40, 3897, 4821, 3433, 1909, 3324, 3097, 2891, 956, 531, 3401, 4041, 4163, 3307, 970, 658, 3415, 1186, 2334, 352, 2069, 3283, 1304, 2561, 2756, 38, 193, 3185, 52, 4203, 3149, 3910, 3059, 3478, 3197, 276, 3385, 104, 3088, 444, 847, 4852, 3237, 1687, 3072, 685, 3994, 1196, 4506, 2568, 3455, 1115, 2320, 1934, 891, 3275, 2868, 1854, 3044, 3215, 1780, 4269, 3770, 3254, 3013, 268, 3165, 2591, 569, 810, 1177, 2308, 2891, 924, 4598, 2797, 1518, 649, 285, 1643, 2390, 3543, 99, 1032, 3544, 448, 1674, 2046, 4308, 1971, 3988, 3406, 3839, 4627, 4485, 3240, 4808, 2538, 1678, 233, 2120, 3544, 4191, 427, 1225, 1767, 1285, 2425, 4006, 3818, 1311, 3311, 4417, 2267, 538, 1580, 2983, 324, 1251, 4407, 224, 3459, 2288, 1457, 532, 3923, 194, 2717, 131, 4713, 4152, 2031, 2584, 3395, 2535, 1065, 537, 3402, 4011, 4302, 1960, 1918, 4502, 644, 2948, 2824, 568, 3928, 4087, 2677, 2385, 4852, 2846, 204, 338, 2182, 1761, 328, 3005, 592, 3874, 4187, 3343, 2272, 2984, 1053, 526, 3441, 2935, 921, 2052, 2621, 785, 2542, 3538, 1574, 2559, 1232, 3064, 3636, 2159, 1042, 3753, 1551, 1832, 827, 3384, 4878, 2636, 4305, 4419, 1080, 1715, 680, 3530, 554, 921, 2208, 16, 3668, 3615, 4438, 3476, 130, 4202, 1514, 1871, 135, 1220, 4374, 1091, 3974, 4869, 3919, 462, 4924, 1744, 277, 2013, 242, 2161, 866, 2478, 2350, 175, 948, 1927, 3553, 4785, 4033, 4080, 4570, 3732, 1002, 2915, 28, 4226, 3916, 1837, 2760, 3873, 1076, 1141, 4354, 339, 3954, 3088, 3396, 1450, 2947, 1689, 3890, 4818, 3021, 4203, 339, 3117, 4366, 4684, 3273, 1243, 3555, 1823, 4439, 2606, 470, 1132, 856, 1686, 120, 4428, 4290, 525, 4578, 3388, 3100, 2016, 4830, 2568, 3427, 2363, 3033, 2735, 4516, 2546, 1452, 2428, 1957, 3521, 1043, 2635, 4380, 459, 960, 4070, 3460, 1933, 1639, 3147, 4978, 3481, 4011, 2212, 647, 4018, 366, 3949, 1323, 4730, 4736, 1866, 213, 2165, 2237, 3535, 4349, 3889, 4891, 2343, 3080, 4088, 2916, 3460, 1362, 1325, 2563, 269, 480, 1470, 3042, 4112, 4600, 2656, 3989, 2371, 4774, 3859, 1872, 4631, 1760, 1165, 922, 368, 3952, 1995, 134, 825, 874, 3540, 2072, 413, 98, 3284, 2782, 1734, 845, 4150, 2698, 1343, 4011, 2692, 2313, 2997, 4836, 1461, 4850, 1527, 2050, 4666, 4207, 3447, 716, 2266, 2834, 3781, 446, 2662, 1289, 306, 3346, 2759, 1383, 4545, 2470, 2682, 4988, 3719, 4621, 1726, 4387, 2789, 1800, 1726, 4260, 1917, 4101, 3292, 4931, 3954, 558, 4863, 338, 3713, 65, 3206, 4570, 1481, 1878, 1243, 4424, 2837, 3740, 112, 3496, 1400, 1115, 584, 3360, 3596, 1720, 4851, 3402, 701, 2097, 1129, 3866, 555, 3088, 71, 578, 110, 3728, 2384, 2005, 1880, 3837, 393, 2261, 1655, 3880, 1539, 1809, 2248, 4033, 2315, 1287, 3466, 1455, 4458, 1320, 2061, 4282, 4204, 3619, 3385, 2045, 1289, 3573, 1390, 2838, 2855, 862, 3146, 2539, 3980, 1439, 2454, 340, 981, 1596, 2865, 4782, 3222, 685, 2410, 839, 4660, 1870, 3705, 3075, 1164, 2360, 4050, 1400, 4257, 1590, 2018, 3696, 743, 1761, 3770, 1556, 2715, 2480, 2670, 1712, 302, 4243, 3939, 1740, 70, 3875, 2492, 4495, 1169, 2737, 2574, 4291, 1596, 2758, 4043, 3055, 208, 35, 2629, 4781, 507, 715, 2615, 3351, 661, 2197, 4312, 4652, 2658, 2326, 4626, 1218, 4562, 3050, 2458, 15, 2878, 183, 1132, 3932, 2955, 4657, 2326, 2848, 1909, 1249, 4277, 120, 2776, 418, 3698, 3385, 2859, 3668, 2343, 1526, 3938, 1865, 2543, 556,
		4355, 2952, 4192, 3529};

	cout << "Datos sin ordenar: " << endl;
	imprimirDatos(numeros);

	cout << "Datos Ordenados con SelectionSort: " << endl;

	auto start = std::chrono::high_resolution_clock::now();

	numeros = selectionSort(numeros);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos" << std::endl;

	imprimirDatos(numeros);

	return 1;
}