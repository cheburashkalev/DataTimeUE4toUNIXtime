// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnixTimeBPLibrary.h"
#include "UnixTime.h"
#include <iomanip>
#include <iostream>
#include <cstdint>

UUnixTimeBPLibrary::UUnixTimeBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


int UUnixTimeBPLibrary::UnixToUE4(FDateTime Param)
{
	struct tm  timeinfo;
	unsigned int unixtime;
	timeinfo.tm_year = Param.GetYear() - 1900;
	timeinfo.tm_mon = Param.GetMonth() - 1;
	timeinfo.tm_mday = Param.GetDay();
	timeinfo.tm_hour = Param.GetHour();
	timeinfo.tm_min = Param.GetMinute();
	timeinfo.tm_sec = Param.GetSecond();
	unixtime = mktime(&timeinfo);
	return unixtime;
}


