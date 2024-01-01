#ifndef CONDITIONS_H
#define CONDITIONS_H

#include "binary_icons/day/day_icons.h"
#include "binary_icons/night/night_icons.h"


struct Condition {
	String dayName;
	String nightName;
	int iconId;
};

Condition* conditions[290];


 void initConditions()
{
	initDayIcons();
	initNightIcons();
	conditions[0] = new Condition();
	conditions[0]->iconId = 113;

	conditions[3] = new Condition();
	conditions[3]->iconId = 116;

	conditions[6] = new Condition();
	conditions[6]->iconId = 119;

	conditions[9] = new Condition();
	conditions[9]->iconId = 122;

	conditions[30] = new Condition();
	conditions[30]->iconId = 143;

	conditions[63] = new Condition();
	conditions[63]->iconId = 176;

	conditions[66] = new Condition();
	conditions[66]->iconId = 179;

	conditions[69] = new Condition();
	conditions[69]->iconId = 182;

	conditions[72] = new Condition();
	conditions[72]->iconId = 185;

	conditions[87] = new Condition();
	conditions[87]->iconId = 200;

	conditions[114] = new Condition();
	conditions[114]->iconId = 227;

	conditions[117] = new Condition();
	conditions[117]->iconId = 230;

	conditions[135] = new Condition();
	conditions[135]->iconId = 248;

	conditions[147] = new Condition();
	conditions[147]->iconId = 260;

	conditions[150] = new Condition();
	conditions[150]->iconId = 263;

	conditions[153] = new Condition();
	conditions[153]->iconId = 266;

	conditions[168] = new Condition();
	conditions[168]->iconId = 281;

	conditions[171] = new Condition();
	conditions[171]->iconId = 284;

	conditions[180] = new Condition();
	conditions[180]->iconId = 293;

	conditions[183] = new Condition();
	conditions[183]->iconId = 296;

	conditions[186] = new Condition();
	conditions[186]->iconId = 299;

	conditions[189] = new Condition();
	conditions[189]->iconId = 302;

	conditions[192] = new Condition();
	conditions[192]->iconId = 305;

	conditions[195] = new Condition();
	conditions[195]->iconId = 308;

	conditions[198] = new Condition();
	conditions[198]->iconId = 311;

	conditions[201] = new Condition();
	conditions[201]->iconId = 314;

	conditions[204] = new Condition();
	conditions[204]->iconId = 317;

	conditions[207] = new Condition();
	conditions[207]->iconId = 320;

	conditions[210] = new Condition();
	conditions[210]->iconId = 323;

	conditions[213] = new Condition();
	conditions[213]->iconId = 326;

	conditions[216] = new Condition();
	conditions[216]->iconId = 329;

	conditions[219] = new Condition();
	conditions[219]->iconId = 332;

	conditions[222] = new Condition();
	conditions[222]->iconId = 335;

	conditions[225] = new Condition();
	conditions[225]->iconId = 338;

	conditions[237] = new Condition();
	conditions[237]->iconId = 350;

	conditions[240] = new Condition();
	conditions[240]->iconId = 353;

	conditions[243] = new Condition();
	conditions[243]->iconId = 356;

	conditions[246] = new Condition();
	conditions[246]->iconId = 359;

	conditions[249] = new Condition();
	conditions[249]->iconId = 362;

	conditions[252] = new Condition();
	conditions[252]->iconId = 365;

	conditions[255] = new Condition();
	conditions[255]->iconId = 368;

	conditions[258] = new Condition();
	conditions[258]->iconId = 371;

	conditions[261] = new Condition();
	conditions[261]->iconId = 374;

	conditions[264] = new Condition();
	conditions[264]->iconId = 377;

	conditions[273] = new Condition();
	conditions[273]->iconId = 386;

	conditions[276] = new Condition();
	conditions[276]->iconId = 389;

	conditions[279] = new Condition();
	conditions[279]->iconId = 392;

	conditions[282] = new Condition();
	conditions[282]->iconId = 395;

}




#endif // CONDITIONS_H
