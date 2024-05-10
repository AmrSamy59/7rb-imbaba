#include "OutputLogger.h"

OutputLogger::OutputLogger(string fname, Game* gamePtr)
{
	gptr = gamePtr;
	earthDf = 0;
	earthDd = 0;
	earthDb = 0;
	alienDf = 0;
	alienDd = 0;
	alienDb = 0;
	saverDf = 0;
	saverDd = 0;
	saverDb = 0;

	File.open(fname);
	File << "Td	ID	Tj	Df	Dd	Db	Unit_Type" << endl;
	File << "------------------------------------------------------" << endl;
}

void OutputLogger::LogUnit(Unit* unit)
{
	int Td = unit->GetDestructionTime();
	int ID = unit->GetID();
	int Tj = unit->GetJoinTime();
	int Ta = unit->GetFirstAttackTime();
	int Df = Ta - Tj;
	int Dd = Td - Ta;
	int Db = Td - Tj;
	Unit::UnitType type = unit->getType();
	string s_type = unit->getTypeString();
	if (type == Unit::AD || type == Unit::AM || type == Unit::AS) {
		alienDf += Df;
		alienDd += Dd;
		alienDb += Db;
	}
	else if (type == Unit::EG || type == Unit::ES || type == Unit::ET || type == Unit::HU)
	{
		earthDf += Df;
		earthDd += Dd;
		earthDb += Db;
	}
	else
	{
		saverDf += Df;
		saverDd += Dd;
		saverDb += Db;
	}
	File << Td << "	" << ID << "	" << Tj << "	"
		<< Df << "	" << Dd << "	" << Db << "	" << s_type << endl;

	File << "------------------------------------------------------" << endl;
}

void OutputLogger::LogEarthArmy(EarthArmy* army)
{
	int total_es = army->GetUnitCount(Unit::ES);
	int total_et = army->GetUnitCount(Unit::ET);
	int total_eg = army->GetUnitCount(Unit::EG);
	int total_hu = army->GetUnitCount(Unit::HU);
	int total_alive = total_es + total_eg + total_et + total_hu;

	int total_es_d = gptr->GetDestructedUnitCount(Unit::ES);
	int total_et_d = gptr->GetDestructedUnitCount(Unit::ET);
	int total_eg_d = gptr->GetDestructedUnitCount(Unit::EG);
	int total_hu_d = gptr->GetDestructedUnitCount(Unit::HU);
	int total_d = total_es_d + total_et_d + total_eg_d + total_hu_d;

	float avg_df = total_d != 0 ? float(earthDf) / total_d : 0;
	float avg_dd = total_d != 0 ? float(earthDd) / total_d : 0;
	float avg_db = total_d != 0 ? float(earthDb) / total_d : 0;

	float df_db_ratio = avg_db != 0 ? avg_df / avg_db : 0;
	float dd_db_ratio = avg_db != 0 ? avg_dd / avg_db : 0;

	int total_es_count = total_es + total_es_d;
	int total_et_count = total_et + total_et_d;
	int total_eg_count = total_eg + total_eg_d;
	int total_hu_count = total_hu + total_hu_d;
	int total_count = total_d + total_alive;


	File << endl << "Earth Army" << endl;
	File << "Total Units: " << total_count << endl;

	File << "ES: " << total_es << " Destructed: " << total_es_d << " ";
	File << "Percentage Destructed: " << (total_es_count != 0 ? (float)total_es_d / total_es_count : 0) * 100 << "%" << endl;
	File << "ET: " << total_et << " Destructed: " << total_et_d << " ";
	File << "Percentage Destructed: " << (total_et_count != 0 ? (float)total_et_d / total_et_count : 0) * 100 << "%" << endl;
	File << "EG: " << total_eg << " Destructed: " << total_eg_d << " ";
	File << "Percentage Destructed: " << (total_eg_count != 0 ? (float)total_eg_d / total_eg_count : 0) * 100 << "%" << endl;
	File << "HU: " << total_hu << " Destructed: " << total_hu_d << " ";
	File << "Percentage Destructed: " << (total_hu_count != 0 ? (float)total_hu_d / total_hu_count : 0) * 100 << "%" << endl;
	File  << endl << "Total Destructed: " << total_d << endl;
	File << "Percentage Destructed: " << (total_count != 0 ? (float)total_d / total_count : 0) * 100 << "%" << endl;


	File << "Average Df: " << avg_df << endl;
	File << "Average Dd: " << avg_dd << endl;
	File << "Average Db: " << avg_db << endl;
	File << "Df/Db Ratio: " << df_db_ratio * 100 << "%" << endl;
	File << "Dd/Db Ratio: " << dd_db_ratio * 100 << "%" << endl;
	File << "------------------------------------------------------" << endl;
}

void OutputLogger::LogAlienArmy(AlienArmy* army)
{
	int total_ad = army->GetUnitCount(Unit::AD);
	int total_am = army->GetUnitCount(Unit::AM);
	int total_as = army->GetUnitCount(Unit::AS);
	int total_alive = total_ad + total_am + total_as;

	int total_ad_d = gptr->GetDestructedUnitCount(Unit::AD);
	int total_am_d = gptr->GetDestructedUnitCount(Unit::AM);
	int total_as_d = gptr->GetDestructedUnitCount(Unit::AS);
	int total_d = total_ad_d + total_am_d + total_as_d;

	float avg_df = total_d != 0 ? float(alienDf) / total_d : 0;
	float avg_dd = total_d != 0 ? float(alienDd) / total_d : 0;
	float avg_db = total_d != 0 ? float(alienDb) / total_d : 0;

	float df_db_ratio = avg_db != 0 ? avg_df / avg_db : 0;
	float dd_db_ratio = avg_db != 0 ? avg_dd / avg_db : 0;

	int total_ad_count = total_ad + total_ad_d;
	int total_am_count = total_am + total_am_d;
	int total_as_count = total_as + total_as_d;
	int total_count = total_d + total_alive;

	File << endl << "Alien Army" << endl;
	File << "Total Units: " << total_count << endl;

	File << "AD: " << total_ad << " Destructed: " << total_ad_d << " ";
	File << "Percentage Destructed: " << (total_ad_count != 0 ? (float)total_ad_d / total_ad_count : 0) * 100 << "%" << endl;
	File << "AM: " << total_am << " Destructed: " << total_am_d << " ";
	File << "Percentage Destructed: " << (total_am_count != 0 ? (float)total_am_d / total_am_count : 0) * 100 << "%" << endl;
	File << "AS: " << total_as << " Destructed: " << total_as_d << " ";
	File << "Percentage Destructed: " << (total_as_count != 0 ? (float)total_as_d / total_as_count : 0) * 100 << "%" << endl;
	File << endl << "Total Destructed: " << total_d << endl;
	File << "Percentage Destructed: " << (total_count != 0 ? (float)total_d / total_count : 0) * 100 << "%" << endl;

	File << "Average Df: " << avg_df << endl;
	File << "Average Dd: " << avg_dd << endl;
	File << "Average Db: " << avg_db << endl;
	File << "Df/Db Ratio: " << df_db_ratio * 100 << "%" << endl;
	File << "Dd/Db Ratio: " << dd_db_ratio * 100 << "%" << endl;
	File << "------------------------------------------------------" << endl;
}

void OutputLogger::LogGameStatus()
{
	int status = gptr->checkGameStatus();
	File << endl << "Battle Results: ";
	if (status == 1)
	{
		File << "Earth Won" << endl;
	}
	else if (status == -1)
	{
		File << "Aliens Won" << endl;
	}
	else
	{
		File << "Tie" << endl;
	}
	File << "------------------------------------------------------" << endl;
}

OutputLogger::~OutputLogger()
{
	File.close();
}