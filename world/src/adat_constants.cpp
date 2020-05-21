#include <array>
#include "adat.h"
#include "buff.h"

vector3d<> arenapos(8491.26f, /*91.59f*/0, 3473);
float arenarange=25*25;

float dropmult=10.0f;
double moneymultiplier=100.0;
long double expMultiplier=50;
long double skillExpMultiplier=100;
int partypointsperlevel=10;
int partyexpszorzo=10;
unsigned long long explose=1.0;
const bool forcedchangeonblink=true;

int itemstaytime=1000*60;
int itemlocktime=1000*30;

const float md=1.0f;

const std::array<int, 21> ringbonus = {1,2,3,4,5,6,7,8,9,10,11,13,15,17,19,21,24,27,31,35,40};
const std::array<int, 21> defbonus = {44,49,54,59,64,70,76,82,89,96,104,113,123,135,150,168,189,213,240,270,310};
const std::array<int, 21> atkbonus = {10,15,20,25,30,35,41,48,56,66,77,90,105,125,150,170,200,235,275,320,375};
const std::array<int, 21> hpbonus = {82,118,154,190,226,262,298,334,370,418,466,514,562,610,658,706,766,826,886,946,1018};
const std::array<int, 21> mpbonus = {57,65,73,81,89,97,105,113,121,129,137,146,155,164,173,182,191,200,209,218,227};
const std::array<int, 21> fpbonus = {57,65,73,81,89,97,105,113,121,129,137,146,155,164,173,182,191,200,209,218,227};

const std::array<int, 6> elementl = {0,1,2,3,5,4};
const std::array<int, 6> delementl = {0,2,3,4,5,1};
const std::array<int, 6> selementl = {0,5,1,2,3,4};
const std::array<int, 6> stlk = {0, DST_MASTRY_FIRE, DST_MASTRY_WATER, DST_MASTRY_ELECTRICITY, DST_MASTRY_EARTH, DST_MASTRY_WIND};
const std::array<int, 6> dstlk = {0, DST_RESIST_FIRE, DST_RESIST_WATER, DST_RESIST_ELECTRICITY, DST_RESIST_EARTH, DST_RESIST_WIND};

const std::array<int, 6> stlknl = {0, DST_MASTRY_FIRE, DST_MASTRY_WATER, DST_MASTRY_ELECTRICITY, DST_MASTRY_WIND, DST_MASTRY_EARTH};
const std::array<int, 6> dstlknl = {0, DST_RESIST_FIRE, DST_RESIST_WATER, DST_RESIST_ELECTRICITY, DST_RESIST_WIND, DST_RESIST_EARTH};

const std::array<int, 57> bufflist = {7,8,9,10,20,46,48,49,50,52,53,108,109,111, 113, 114,115,116, 128,129,130,143,145,146,147,148,150,156,161,165,169, 172,175,178,181,191,192,193, 195,199,207,208,209,210, 221, 309, 310, 311,312,313,314,315,237,239,240,241,242};

const std::array<long double, 16> defbase = {20,26,24,22,22,22,30,26,27,26,22,29,24,24,24,24};

const std::array<int, 11> enctable = {0, 2, 4, 6, 8, 10, 13, 16, 19, 21, 24};

const std::array<unsigned long long, 150> explist = {
        14,
        20,
        36,
        90,
        152,
        250,
        352,
        480,
        591,
        743,
        973,
        1290,
        1632,
        1928,
        2340,
        3480,
        4125,
        4995,
        5880,
        7840,
        6875,
        8243,
        10380,
        13052,
        16450,
        20700,
        26143,
        31950,
        38640,
        57035,
        65000,
        69125,
        72000,
        87239,
        105863,
        128694,
        182307,
        221450,
        269042,
        390368,
        438550,
        458137,
        468943,
        560177,
        669320,
        799963,
        1115396,
        1331100,
        1590273,
        2306878,
        2594255,
        2711490,
        2777349,
        3318059,
        3963400,
        4735913,
        6600425,
        7886110,
        9421875,
        13547310,
        15099446,
        15644776,
        15885934,
        18817757,
        22280630,
        26392968,
        36465972,
        43184958,
        51141217,
        73556918,
        81991117,
        84966758,
        86252845,
        102171368,
        120995493,
        143307208,
        198000645,
        234477760,
        277716683,
        381795797,
        406848219,
        403044458,
        391191019,
        442876559,
        501408635,
        567694433,
        749813704,
        849001357,
        961154774,
        1309582668,
        1382799035,
        1357505030,
        1305632790,
        1464862605,
        1628695740,
        1810772333,
        2348583653,
        2611145432,
        2903009208,
        3919352097,
        4063358600,
        3916810682,
        4314535354,
        4752892146,
        5235785988,
        5767741845,
        6353744416,
        6999284849,
        7710412189,
        8493790068,
        9356759139,
        10307405867,
        11354638303,
        12508269555,
        13779109742,
        15179067292,
        16721260528,
        18420140598,
        20291626883,
        22353256174,
        24624347002,
        27126180657,
        29882200612,
        32918232194,
        36262724585,
        39947017402,
        44005634371,
        48476606823,
        53401830076,
        58827456011,
        64804325542,
        71388445017,
        78641511031,
        86631488552,
        95433247789,
        105129265764,
        115810399166,
        127576735721,
        140538532070,
        154817246928,
        170546679216,
        187874221825,
        206962242762,
        227989606627,
        251153350660,
        276670531087,
        304780257046,
        335745931162,
        369857717768,
        369857717768
};

const std::array<long double, 16> fpj = {
        0.3000000119209289600,  // 0.3
        0.6999999880790710400,  // 0.7
        0.5000000000000000000,  // 0.5
        0.6000000238418579100,  // 0.6
        0.3000000119209289600,  // 0.3
        0.5000000000000000000,  // 0.5
        0.8999999761581420900,  // 0.9
        0.8000000119209289600,  // 0.8
        0.6999999880790710400,  // 0.7
        0.6000000238418579100,  // 0.6
        0.4000000059604644800,  // 0.4
        0.6999999880790710400,  // 0.7
        0.4000000059604644800,  // 0.4
        0.4000000059604644800,  // 0.4
        0.5000000000000000000,  // 0.5
        0.5000000000000000000}; // 0.5

const std::array<vector3d<>, 4> gwtele = {
        vector3d<>(1265.94f, 83.0f, 1254.35f),
        vector3d<>(1263.26f, 83.0f, 1305.46f),
        vector3d<>(1310.11f, 83.0f, 1303.18f),
        vector3d<>(1314.63f, 83.0f, 1253.43f)
};

const std::array<tguildexp, 50> guildexp = {
        tguildexp(0,0),
        tguildexp(24,5200),
        tguildexp(205,14625),
        tguildexp(485,34666),
        tguildexp(1353,58035),
        tguildexp(2338,100285),
        tguildexp(4547,139343),
        tguildexp(6788,208000),
        tguildexp(11045,263250),
        tguildexp(15151,361110),
        tguildexp(22183,432575),
        tguildexp(28800,561600),
        tguildexp(39340,649113),
        tguildexp(49135,810727),
        tguildexp(63920,914063),
        tguildexp(71608,1024000),
        tguildexp(84365,1064483),
        tguildexp(91041,1148727),
        tguildexp(109698,1238429),
        tguildexp(115152,1300000),
        tguildexp(134545,1443000),
        tguildexp(156813,1601730),
        tguildexp(182351,1777920),
        tguildexp(211610,1973491),
        tguildexp(245099,2190574),
        tguildexp(283396,2431537),
        tguildexp(327152,2699005),
        tguildexp(377106,2995896),
        tguildexp(434090,3325443),
        tguildexp(499049,3691241),
        tguildexp(573046,4097276),
        tguildexp(657283,4547976),
        tguildexp(753119,5048252),
        tguildexp(862086,5603559),
        tguildexp(985913,6219950),
        tguildexp(1126550,6904144),
        tguildexp(1286198,7663599),
        tguildexp(1467338,8506594),
        tguildexp(1672765,9442319),
        tguildexp(1905631,10480973),
        tguildexp(2169488,11633879),
        tguildexp(2468335,12913606),
        tguildexp(2806677,14334102),
        tguildexp(3189588,15910852),
        tguildexp(3622778,17661045),
        tguildexp(4112677,19603760),
        tguildexp(4666517,21760172),
        tguildexp(5292439,24153791),
        tguildexp(5999599,26810707),
        tguildexp(7075777,29759885),
};

const std::array<long double, 16> hpj = {
        0.8999999761581420900,  // 0.9
        1.5000000000000000000,  // 1.5
        1.3999999761581421000,  // 1.4
        1.3999999761581421000,  // 1.4
        1.3999999761581421000,  // 1.4
        1.6000000238418579000,  // 1.6
        2.0000000000000000000,  // 2.0
        1.6000000238418579000,  // 1.6
        1.6000000238418579000,  // 1.6
        1.6000000238418579000,  // 1.6
        1.6000000238418579000,  // 1.6
        1.7999999523162842000,  // 1.8
        1.5000000000000000000,  // 1.5
        1.5000000000000000000,  // 1.5
        0.6999999880790710400,  // 0.7
        0.6999999880790710400}; // 0.7

#define st(str,sta,dex,intl) (str+sta*0x100+dex*0x10000+intl*0x1000000)

const std::array<unsigned int, 49> itemstats = {
        st(0,0,0,0), st(1,0,0,0), st(0,0,1,0), st(0,0,0,1), st(0,1,0,0), st(1,1,0,0), st(1,0,1,0),
        st(0,1,1,0), st(0,1,0,1), st(2,0,0,0), st(0,0,2,0), st(0,0,0,2), st(0,2,0,0), st(2,1,0,0),
        st(1,2,0,0), st(2,0,1,0), st(1,0,2,0), st(0,1,2,0), st(0,2,1,0), st(0,1,0,2), st(0,2,0,1),
        st(3,0,0,0), st(0,0,3,0), st(0,0,0,3), st(0,3,0,0), st(2,2,0,0), st(1,3,0,0), st(3,2,0,0),
        st(2,0,2,0), st(3,0,1,0), st(1,0,3,0), st(0,2,2,0), st(0,1,3,0), st(0,3,1,0), st(0,2,0,2),
        st(0,1,0,3), st(0,3,0,1), st(4,0,0,0), st(0,0,4,0), st(0,0,0,4), st(0,4,0,0), st(3,2,0,0),
        st(2,3,0,0), st(3,0,2,0), st(2,0,3,0), st(0,2,3,0), st(0,3,2,0), st(0,2,0,3), st(0,3,0,2)
};

#undef st

const std::array<long double, 16> leveldef = {
        0.714444444444,
        0.714444444444,
        0.714444444444,
        0.713137254902,
        0.713137254902,
        0.713137254902,
        0.714640522876,
        0.714444444444,
        0.714444444444,
        0.714444444444,
        0.713137254902,
        0.714444444444,
        0.714640522876,
        0.714640522876,
        0.714640522876,
        0.714640522876};

const std::array<vector3d<>, 5> lodelights = {
        vector3d<>(6968.384766f, 100.0f, 3328.863037f),	//flaris town
        vector3d<>(7342, 159, 3870),	//flaris
        vector3d<>(8441, 87, 2678),	//sm
        vector3d<>(5514, 75, 3891),	//d1
        vector3d<>(3218, 11, 3410)	//d3
};

const std::array<int, 32> job1 = {0,1,2,3,4,5,1,1,2,2,3,3,4,4,5,5,1,1,2,2,3,3,4,4,1,1,2,2,3,3,4,4};
const std::array<int, 32> job2 = {0,0,0,0,0,0,6,7,8,9,10,11,12,13,14,15,6,7,8,9,10,11,12,13,6,7,8,9,10,11,12,13};

const std::array<long double, 16> mpj = {
        0.3000000119209289600,  // 0.3
        0.5000000000000000000,  // 0.5
        0.5000000000000000000,  // 0.5
        1.2999999523162842000,  // 1.3
        1.7000000476837158000,  // 1.7
        0.5000000000000000000,  // 0.5
        0.6000000238418579100,  // 0.6
        0.6000000238418579100,  // 0.6
        0.5000000000000000000,  // 0.5
        0.5000000000000000000,  // 0.5
        1.7999999523162842000,  // 1.8
        1.0000000000000000000,  // 1.0
        2.0000000000000000000,  // 2.0
        2.0000000000000000000,  // 2.0
        1.0000000000000000000,  // 1.0
        0.5000000000000000000}; // 0.5

const std::array<int, 3> petids[8] = {
        {731,731,731},
        {732,733,884},
        {734,735,885},
        {736,737,886},
        {742,743,889},
        {738,739,887},
        {744,745,890},
        {740,741,888}
};

const std::array<int, 9> petbonus[7] = {
        {1,2,4,7,11,16,22,29,37},	//str
        {1,2,4,7,11,16,22,29,37},	//sta
        {1,2,4,7,11,16,22,29,37},	//dex
        {1,2,4,7,11,16,22,29,37},	//int
        {5,10,20,35,55,80,110,145,185},	//atk
        {4,8,16,28,44,64,88,116,148},	//def
        {91,182,364,637,1001,1456,2002,2639,3367}		//maxhp
};

const std::array<int, 7> petstats = {1,4,2,3,83,26,35};

const std::array<int, 150> pxplist = {
        1,
        1,
        2,
        2,
        3,
        4,
        4,
        5,
        5,
        6,
        6,
        7,
        8,
        9,
        10,
        12,
        13,
        15,
        17,
        19,
        22,
        25,
        29,
        33,
        38,
        43,
        50,
        57,
        64,
        73,
        83,
        95,
        108,
        123,
        140,
        159,
        181,
        206,
        235,
        263,
        294,
        329,
        368,
        412,
        462,
        517,
        579,
        648,
        726,
        812,
        910,
        1018,
        1140,
        1277,
        1430,
        1602,
        1794,
        2009,
        2250,
        2497,
        2772,
        3076,
        3415,
        3790,
        4207,
        4670,
        5183,
        5753,
        6386,
        7088,
        7868,
        8733,
        9694,
        10760,
        11943,
        13256,
        14714,
        16333,
        18129,
        20123,
        22336,
        24793,
        27520,
        30548,
        33908,
        37637,
        41777,
        46372,
        51473,
        56620,
        62282,
        68510,
        75361,
        82897,
        90358,
        98490,
        107354,
        117015,
        127546,
        139025,
        150147,
        162159,
        175132,
        189142,
        204273,
        220615,
        238264,
        257326,
        277912,
        300145,
        324156,
        350089,
        378096,
        408343,
        441011,
        476292,
        514395,
        555547,
        599990,
        647990,
        699829,
        755815,
        816280,
        881583,
        952109,
        1028278,
        1110541,
        1199384,
        1295334,
        1398961,
        1510878,
        1631748,
        1762288,
        1903271,
        2055533,
        2219976,
        2397574,
        2589380,
        2796530,
        3020252,
        3261873,
        3522822,
        3804648,
        4109020,
        4437742,
        4792761,
        5176182,
        5590276,
        6037498,
        6520498
};

const std::array<int, 20> skillacc = {0, 40, 140, 278, 472, 738, 1084, 1514, 2370, 3386, 5450, 7722, 10932, 14402, 19092, 24102, 30678, 37668, 47270, 59270};

const std::array<int, 20> skillexp2 = {0, 40, 100, 138, 194, 266, 346, 430, 856, 1016, 2064, 2272, 3210, 3470, 4690, 5010, 6576, 6990, 9602, 12000};

const std::array<int, 45> skillmaxlevel[32] = {
	{10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*vagrant*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*merc*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*acrobat*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*assist*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*mage*/
	{10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*puppeteer*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*knigth*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*blade*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*jester*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*ranger*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10, 1, 3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*rm*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*bp*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*psy*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,-1,-1,-1},	/*ele*/
	{10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*gatekeeper*/
	{10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*doppler*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,10,10,10,10,10,10,10,10, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*knigth master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,10,10,10,10,10,10,10,10, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*blade master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*jester master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*ranger master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10, 1, 3, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*rm master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*bp master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*psy master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10, 5,-1,-1},	/*ele master*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,10,10,10,10,10,10,10,10, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*knigth hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,-1,-1,10,10,10,10,10,10,10,10, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*blade hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*jester hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*ranger hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10, 1, 3, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*rm hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*bp hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10, 5, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*psy hero*/
	{10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,-1,-1,-1,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10, 5, 5,-1},	/*ele hero*/
};

const std::array<int, 45> skills[32] = {
	{1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*vagrant*/
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*merc*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*acrobat*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*assist*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,122,123,124,125,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*mage*/
	{1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*puppeteer*/
 	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,128,129,130,131,132,133,134,135,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*knigth*/
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,136,137,138,139,140,141,142,143,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*blade*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,207,208,209,210,211,212,213,214,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*jester*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,215,216,217,218,219,220,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*ranger*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,150,151,148,147,146,144,145,149,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*rm*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,156,152,154,157,158,153,155,159,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*bp*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,-1,-1,-1,160,161,162,163,164,165,166,167,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*psy*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,-1,-1,-1,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,-1,-1,-1},	/*ele*/
	{1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*gatekeeper*/
	{1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*doppler*/
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,128,129,130,131,132,133,134,135,310,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*knigth master*/
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,136,137,138,139,140,141,142,143,309,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*blade master*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,207,208,209,210,211,212,213,214,311,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*jester master*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,215,216,217,218,219,220,221,222,312,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*ranger master*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,150,151,148,147,146,144,145,149,316,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*rm master*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,156,152,154,157,158,153,155,159,315,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*bp master*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,-1,-1,-1,160,161,162,163,164,165,166,167,314,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*psy master*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,-1,-1,-1,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,313,-1,-1},	/*ele master*/
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,128,129,130,131,132,133,134,135,310,238,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*knigth hero*/
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,108,109,111,112,-1,-1,-1,-1,-1,136,137,138,139,140,141,142,143,309,237,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*blade hero*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,207,208,209,210,211,212,213,214,311,239,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*jester hero*/
	{1,2,3,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,-1,-1,-1,215,216,217,218,219,220,221,222,312,240,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*ranger hero*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,150,151,148,147,146,144,145,149,316,244,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*rm hero*/
	{1,2,3,44,52,46,114,49,104,45,20,51,53,113,105,115,48,116,117,50,-1,-1,-1,156,152,154,157,158,153,155,159,315,243,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*bp hero*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,-1,-1,-1,160,161,162,163,164,165,166,167,314,242,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},	/*psy hero*/
	{1,2,3,30,31,32,33,34,35,36,37,64,65,69,70,107,118,119,120,121,-1,-1,-1,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,313,241,-1},	/*ele hero*/
};

const std::array<long double, 16> stadef = {
        1.188235294118,
        1.541176470588,
        1.576470588235,
        1.388235294118,
        1.388235294118,
        1.388235294118,
        1.976470588235,
        1.682352941176,
        1.776470588235,
        1.682352941176,
        1.388235294118,
        1.882352941176,
        1.482352941176,
        1.482352941176,
        1.482352941176,
        1.482352941176
};

const std::array<vector3d<>, 3> towns = {
        vector3d<>(6968.384766f, 100.0f, 3328.863037f),	//flaris
        vector3d<>(8470.578125f, 100.0f, 3635.788086f),	//sm
        vector3d<>(3808.401123f,  59.0f, 4455.150879f)
};

const std::array<int, 10> ultimatestats = {35,83,26,-1,-1,1,4,2,3};

const std::array<int, 11> uphitbonus = {0,0,0,5,10,10,20,20,30,30,45};
const std::array<int, 11> upblockbonus = {0,0,0,3,3,3,6,6,10,10,15};
const std::array<int, 11> uphpbonus = {0,0,0,0,0,5,5,5,10,10,20};
const std::array<int, 11> upmagicbonus = {0,0,0,3,4,5,6,7,8,9,10};
const std::array<int, 11> upallstatbonus = {0,0,0,0,0,1,1,1,2,2,3};

const std::array<int, 5> ultimatebonus[9][5] = {
        {
        {228,455,683,910,1365},
        {455,910,1365,1820,2730},
        {683,1365,2048,2730,4095},
        {910,1820,2730,3640,5460},
        {1138,2275,3413,4550,6825}
        },{
        {13,25,38,50,75},
        {25,50,75,100,150},
        {38,75,113,150,225},
        {50,100,150,200,300},
        {63,125,188,250,375}
        },{
        {10,20,30,40,60},
        {20,40,60,80,120},
        {30,60,90,120,180},
        {40,80,120,160,240},
        {50,100,150,200,300}
        },{
        {1,2,3,4,6},
        {2,3,5,6,9},
        {2,4,6,8,12},
        {3,5,8,10,15},
        {3,6,9,12,18}
        },{
        {2,4,6,8,12},
        {3,6,9,12,18},
        {4,8,12,16,24},
        {5,10,15,20,30},
        {6,12,18,24,36}
        },{
        {3,5,8,10,15},
        {5,10,15,20,30},
        {8,15,23,30,45},
        {10,20,30,40,60},
        {13,25,38,50,75}
        },{
        {3,5,8,10,15},
        {5,10,15,20,30},
        {8,15,23,30,45},
        {10,20,30,40,60},
        {13,25,38,50,75}
        },{
        {3,5,8,10,15},
        {5,10,15,20,30},
        {8,15,23,30,45},
        {10,20,30,40,60},
        {13,25,38,50,75}
        },{
        {3,5,8,10,15},
        {5,10,15,20,30},
        {8,15,23,30,45},
        {10,20,30,40,60},
        {13,25,38,50,75}
    }
};

const std::array<int, 2> ultimateweap[50] = {
        {22026,	22368},
        {22027,	22369},
        {22028,	22370},
        {22029,	22371},
        {22030,	22373},
        {22031,	22374},
        {22032,	22375},
        {22033,	22376},
        {22034,	20378},
        {22035,	22379},
        {22036,	22380},
        {22037,	22381},
        {22038,	22383},
        {22039,	22384},
        {22040,	22385},
        {22041,	22386},
        {22042,	22388},
        {22043,	22389},
        {22044,	22390},
        {22045,	22391},
        {22046,	22393},
        {22047,	22394},
        {22048,	22395},
        {22049,	22396},
        {22050,	22398},
        {22051,	22399},
        {22052,	22400},
        {22053,	22401},
        {22054,	22403},
        {22055,	22404},
        {22056,	22405},
        {22057,	22406},
        {22058,	22408},
        {22059,	22409},
        {22060,	22410},
        {22061,	22411},
        {22062,	22413},
        {22063,	22414},
        {22064,	22415},
        {22065,	22416},
        {22354,	22372},
        {22355,	22377},
        {22356,	22382},
        {22357,	22387},
        {22358,	22392},
        {22359,	22397},
        {22360,	22412},
        {22361,	22417},
        {22362,	22407},
        {22363,	22402}
};

const std::array<int, 10> upgradeChances = {95, 90, 80, 70, 60,50,40,30,20,10};
const std::array<int, 10> upgradeChancesUlt = {95, 90, 80, 70, 60,50,40,30,20,10};
const std::array<int, 20> upgradeChancesJewel = {95, 95, 90, 85, 80,75,70,65,60,55,50,45,40,35,30,25,20,15,10,10};