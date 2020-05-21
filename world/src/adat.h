#ifndef __adat_h__
#define __adat_h__

#include "vector2.h"
#include <map>
#include <list>
#include <set>
#include "item.h"
#include "error.h"
#include "vector.h"
#include "model/dropdata2.h"

enum tweather {wnothing=0, rain, snow};
//extern float dambigfloat;

extern const bool forcedchangeonblink;

#define bpposter 2026
#define rmposter 2027
#define arrows 2028

extern const float md;
extern float dropmult;

extern double moneymultiplier;

extern vector3d<> arenapos;
extern float arenarange;


class tquest;
struct mobdata2
{
	int id;
	int level;
	int hp;
	int size;
	int str;
	int sta;
	int dex;
	int intl;
	int element;
	int atkmin;
	int atkmax;
	int def;
	int hit;
	int flee;
	int exp,fxp;
	int flying;
	bool giant;
	bool valid;
	int attackdelay;
	float speed;
	float resistele[5];
	int mdrop;
	int cash;
	std::string name;
	std::map<int, std::pair<int, int> > quest_killmobs;
	typedef rune::model::DropData2 tdrop;
	std::list<tdrop> drops;
	struct questdata
	{
		int dropid;
		int number;
		long long dropchance;
		tquest *q;
		questdata(int a, int b, long long c, tquest *d):dropid(a),number(b), dropchance(c),q(d){}
	};
	std::list<questdata> quests;
	mobdata2()
	{
		valid=false;
		mdrop=0;
	}
};

struct tskilldata
{
	int id,level;
int min;
int max;
//int val5;
//int val6;
//int val7;
//int val8;
int prob;
//int val10;
//int val11;
int stat1;
int stat2;
int sval1;
int sval2;
//int val16;
//int val17;
//int val18;
//int val19;
//int val20;
//int val21;
//int val22;
//int val23;
int mpreq;
int fpreq;
//int val26;
int val27;
int range;
//int val29;
//int val30;
int duration;
//int val32;
//int val33;
int pxp;
int astime;
int element;
int elementval;
int element2;
int elementval2;
int skilltype;
int dot;
int cooldown;
int rstat1,rstat2;
int rval1, rval2;
int rtarget1, rtarget2;
int playerjob;
int handed;
int weapontype;
bool magic;
bool targetless_aoe;
tskilldata()
{
	targetless_aoe=false;
}
};

struct tguildexp
{
	int mdrop;
	int money;
	tguildexp(int a, int b):mdrop(a),money(b){}
};

struct setbonusdata
{
	int stat;
	int val;
	int nparts;
};

struct setdata
{
	int id;
	std::array<setbonusdata, 7> bonuses;
};

void datainit();

extern const std::array<int, 45> skillmaxlevel[32];
extern const std::array<int, 45> skills[32];
//extern btree<int, itemdata> itemlist;
extern std::vector2<itemdata> itemlist;

extern const std::array<int, 10> ultimatestats;
extern const std::array<int, 11> uphitbonus;
extern const std::array<int, 11> upblockbonus;
extern const std::array<int, 11> uphpbonus;
extern const std::array<int, 11> upmagicbonus;
extern const std::array<int, 11> upallstatbonus;
extern const std::array<int, 5> ultimatebonus[9][5];

extern const std::array<unsigned int, 49> itemstats;
extern const std::array<int, 21> ringbonus;
extern const std::array<int, 21> defbonus;
extern const std::array<int, 21> atkbonus;
extern const std::array<int, 21> hpbonus;
extern const std::array<int, 21> mpbonus;
extern const std::array<int, 21> fpbonus;

extern const std::array<int, 6> elementl;
extern const std::array<int, 6> delementl;
extern const std::array<int, 6> stlk;
extern const std::array<int, 6> dstlk;
extern const std::array<int, 6> stlknl;
extern const std::array<int, 6> dstlknl;

extern const std::array<int, 57> bufflist;
extern const std::array<int, 32> job1;
extern const std::array<int, 32> job2;
extern const std::array<int, 20> skillexp2;
extern const std::array<int, 20> skillacc;
extern const std::array<int, 7> petstats;
extern const std::array<int, 9> petbonus[7];
extern const std::array<int, 11> enctable;
extern const std::array<long double, 16> hpj;
extern const std::array<long double, 16> mpj;
extern const std::array<long double, 16> fpj;
extern const std::array<long double, 16> stadef;
extern const std::array<long double, 16> leveldef;
extern const std::array<long double, 16> defbase;
extern const std::array<int, 3> petids[8];
extern const std::array<vector3d<>, 3> towns;
extern const std::array<vector3d<>, 5> lodelights;
extern const std::array<vector3d<>, 4> gwtele;
extern const std::array<tguildexp, 50> guildexp;
extern std::vector2<int> skillsupliment;

extern const std::array<int, 10> upgradeChances;
extern const std::array<int, 10> upgradeChancesUlt;
extern const std::array<int, 20> upgradeChancesJewel;
extern const std::array<int, 2> ultimateweap[50];
extern std::vector2<std::vector2<tskilldata> > skilllist;
extern std::vector2<tskilldata > cskilllist;
extern std::vector2<mobdata2> monsterlist;
extern const std::array<unsigned long long, 150> explist;
extern const std::array<int, 150> pxplist;
//extern std::vector2<int> skilltype;
extern std::vector2<int> nguildmembers;

#define ST_ATTACK 1
#define ST_AOE 2
#define ST_HEAL 4
#define ST_BUFF 8
#define ST_SELF 16
#define ST_OTHERS 32


extern long double skillExpMultiplier;
extern int itemstaytime;
extern int itemlocktime;

extern long double expMultiplier;
extern int partypointsperlevel;
extern int partyexpszorzo;
extern unsigned long long explose;

#define w_unbound 0
#define wb_weapon 1
#define wb_shield 2
#define w_sword 4
#define w_axe 8
#define w_stick 16
#define w_knuckle 32
#define w_staff 64
#define w_wand 128
#define w_yoyo 256
#define w_bow 512
#define w_weapon 1024
#define w_shield 2048


//class tparty;
//extern btree<tparty*, tparty*> parties;
//extern pmutex partiesmutex;;
#endif
