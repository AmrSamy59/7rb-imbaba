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
		if(Df > 0)
			alienDf += Df;
		if(Dd > 0)
			alienDd += Dd;
		if(Db > 0)
			alienDb += Db;
	}
	else if (type == Unit::EG || type == Unit::ES || type == Unit::ET || type == Unit::HU)
	{
		if(Df > 0)
			earthDf += Df;
		if(Dd > 0)
			earthDd += Dd;
		if(Db > 0)
			earthDb += Db;
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

	float avg_df = total_d != 0 ? float(earthDf) / total_d : -1;
	float avg_dd = total_d != 0 ? float(earthDd) / total_d : -1;
	float avg_db = total_d != 0 ? float(earthDb) / total_d : -1;

	float df_db_ratio = avg_db >= 0 ? avg_df / avg_db : -1;
	float dd_db_ratio = avg_db >= 0 ? avg_dd / avg_db : -1;

	int total_es_count = total_es + total_es_d;
	int total_et_count = total_et + total_et_d;
	int total_eg_count = total_eg + total_eg_d;
	int total_hu_count = total_hu + total_hu_d;
	int total_count = total_d + total_alive;

	int total_infected = army->GetTotalInfectedCount();
	float infected_percentage = total_es_count != 0 ? (float)total_infected / total_es_count : 0;
	


	File << endl << "Earth Army" << endl << endl;
	File << "Total Units: " << total_count << endl;

	File << "ES	Total: " << total_es_count << " Alive: " << total_es << " Destructed: " << total_es_d << " ";
	File << "Percentage Destructed: " << (total_es_count != 0 ? (float)total_es_d / total_es_count : 0) * 100 << "%" << endl;
	File << "ET	Total: " << total_et_count << " Alive: " << total_et << " Destructed: " << total_et_d << " ";
	File << "Percentage Destructed: " << (total_et_count != 0 ? (float)total_et_d / total_et_count : 0) * 100 << "%" << endl;
	File << "EG	Total: " << total_eg_count << " Alive: " << total_eg << " Destructed: " << total_eg_d << " ";
	File << "Percentage Destructed: " << (total_eg_count != 0 ? (float)total_eg_d / total_eg_count : 0) * 100 << "%" << endl;
	File << "HU	Total: " << total_hu_count << " Alive: " << total_hu << " Destructed: " << total_hu_d << " ";
	File << "Percentage Destructed: " << (total_hu_count != 0 ? (float)total_hu_d / total_hu_count : 0) * 100 << "%" << endl;

	File  << endl << "Total Destructed: " << total_d << endl;
	File << "Percentage Destructed: " << (total_count != 0 ? (float)total_d / total_count : 0) * 100 << "%" << endl;

	File << "Total Infected: " << total_infected << " Percentage Infected: " << infected_percentage * 100 << "%" << endl << endl;

	File << "Average Df: ";
	if (avg_df >= 0)
		File << avg_df << endl;
	else
		File << "None Got Attacked" << endl;
	
	File << "Average Dd: ";
	if (avg_dd >= 0)
		File << avg_dd << endl;
	else
		File << "None Died" << endl;
	File << "Average Db: ";
	if (avg_db >= 0)
		File << avg_db << endl;
	else
		File << "None Died" << endl;
	File << "Df/Db Ratio: ";
	if (df_db_ratio >= 0)
		File << df_db_ratio * 100 << "%" << endl;
	else
		File << "None Died" << endl;
	File << "Dd/Db Ratio: ";
	if (dd_db_ratio >= 0)
		File << dd_db_ratio * 100 << "%" << endl;
	else
		File << "None Died" << endl;
	File << endl << "------------------------------------------------------" << endl;
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

	float avg_df = total_d != 0 ? float(alienDf) / total_d : -1;
	float avg_dd = total_d != 0 ? float(alienDd) / total_d : -1;
	float avg_db = total_d != 0 ? float(alienDb) / total_d : -1;

	float df_db_ratio = avg_db >= 0 ? avg_df / avg_db : -1;
	float dd_db_ratio = avg_db >= 0 ? avg_dd / avg_db : -1;

	int total_ad_count = total_ad + total_ad_d;
	int total_am_count = total_am + total_am_d;
	int total_as_count = total_as + total_as_d;
	int total_count = total_d + total_alive;

	File << endl << "Alien Army" << endl << endl;
	File << "Total Units: " << total_count << endl;

	File << "AS	Total: " << total_as_count << " Alive: " << total_as << " Destructed: " << total_as_d << " ";
	File << "Percentage Destructed: " << (total_as_count != 0 ? (float)total_as_d / total_as_count : 0) * 100 << "%" << endl;
	File << "AM	Total: " << total_am_count << " Alive: " << total_am << " Destructed: " << total_am_d << " ";
	File << "Percentage Destructed: " << (total_am_count != 0 ? (float)total_am_d / total_am_count : 0) * 100 << "%" << endl;
	File << "AD	Total: " << total_ad_count << " Alive: " << total_ad << " Destructed: " << total_ad_d << " ";
	File << "Percentage Destructed: " << (total_ad_count != 0 ? (float)total_ad_d / total_ad_count : 0) * 100 << "%" << endl;
	
	File << endl << "Total Destructed: " << total_d << endl;
	File << "Percentage Destructed: " << (total_count != 0 ? (float)total_d / total_count : 0) * 100 << "%" << endl << endl;

	File << "Average Df: ";
	if (avg_df >= 0)
		File << avg_df << endl;
	else
		File << "None Got Attacked" << endl;

	File << "Average Dd: ";
	if (avg_dd >= 0)
		File << avg_dd << endl;
	else
		File << "None Died" << endl;
	File << "Average Db: ";
	if (avg_db >= 0)
		File << avg_db << endl;
	else
		File << "None Died" << endl;

	File << "Df/Db Ratio: ";
	if (df_db_ratio >= 0)
		File << df_db_ratio * 100 << "%" << endl;
	else
		File << "None Died" << endl;
	File << "Dd/Db Ratio: ";
	if (dd_db_ratio >= 0)
		File << dd_db_ratio * 100 << "%" << endl;
	else
		File << "None Died" << endl;
	File << endl << "------------------------------------------------------" << endl;
}


void OutputLogger::LogGameStatus()
{
	int status = gptr->checkGameStatus();
	File << endl << "Battle Results" << endl;
	File << endl << "Finish Timestep: " << gptr->GetCurrentTimeStep() << endl << endl;
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
	File << endl << "------------------------------------------------------" << endl;
}

OutputLogger::~OutputLogger()
{
	File.close();
}
