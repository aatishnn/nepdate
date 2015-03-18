/*
This file is part of nepdate.

nepdate is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

nepdate is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with nepdate.  If not, see <http://www.gnu.org/licenses/>.
*/
#include<stdio.h>
#include<string.h>

#include "date.h"

const char nmonth[12][10] = {
    "Baishak",
    "Jestha",
    "Ashad",
    "Shrawan",
    "Bhadra",
    "Ashwin",
    "Kartik",
    "Mangshir",
    "Poush",
    "Magh",
    "Falgun",
    "Chaitra"
};

const char emonth[12][10] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char day_week[7][10] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

/* This array lists number of days in each month of each year. So, this
 * is the only reference needed to convert dates
 */
const int bs[91][13] = {
    {2000, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2001, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2002, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2003, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2004, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2005, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2006, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2007, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2008, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},
    {2009, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2010, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2011, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2012, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},
    {2013, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2014, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2015, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2016, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},
    {2017, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2018, 31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2019, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2020, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},
    {2021, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2022, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},
    {2023, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2024, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},
    {2025, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2026, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2027, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2028, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2029, 31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30},
    {2030, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2031, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2032, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2033, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2034, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2035, 30, 32, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},
    {2036, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2037, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2038, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2039, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},
    {2040, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2041, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2042, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2043, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},
    {2044, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2045, 31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2046, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2047, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},
    {2048, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2049, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},
    {2050, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2051, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},
    {2052, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2053, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},
    {2054, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2055, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2056, 31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30},
    {2057, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2058, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2059, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2060, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2061, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2062, 30, 32, 31, 32, 31, 31, 29, 30, 29, 30, 29, 31},
    {2063, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2064, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2065, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2066, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},
    {2067, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2068, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2069, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2070, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},
    {2071, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2072, 31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},
    {2073, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},
    {2074, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},
    {2075, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2076, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},
    {2077, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},
    {2078, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},
    {2079, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},
    {2080, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},
    {2081, 31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 30, 30},
    {2082, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},
    {2083, 31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},
    {2084, 31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},
    {2085, 31, 32, 31, 32, 30, 31, 30, 30, 29, 30, 30, 30},
    {2086, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},
    {2087, 31, 31, 32, 31, 31, 31, 30, 30, 29, 30, 30, 30},
    {2088, 30, 31, 32, 32, 30, 31, 30, 30, 29, 30, 30, 30},
    {2089, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},
    {2090, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30}
};

int is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	return 1;		/* leap year */
    else
	return 0;		/* not a leap year */
}

/* Checks whether given English date is in the range that can be converted */
int is_range_eng(struct eng_date date)
{
    if (date.year < 1944 || date.year > 2033) {
	fprintf(stderr, "Supported only between 1944-2022");
	return 0;
    }

    if (date.month < 1 || date.month > 12) {
	fprintf(stderr, "Error! value 1-12 only");
	return 0;
    }

    if (date.date < 1 || date.date > 31) {
	fprintf(stderr, "Error! value 1-31 only");
	return 0;
    }

    return 1;
}

/* Checks whether given date is in the range that can be converted */
int is_range_nep(struct nep_date date)
{
    if (date.year < 2000 || date.year > 2090) {
	fprintf(stderr, "Supported only between 2000-2090");
	return 0;
    }

    if (date.month < 1 || date.month > 12) {
	fprintf(stderr, "Error! value 1-12 only");
	return 0;
    }

    if (date.date < 1 || date.date > 32) {
	fprintf(stderr, "Error! value 1-32 only");
	return 0;
    }

    return 1;
}

/* Converts English date to Nepali date 
 * This works by selecting a reference date in English (1994,1,1)
 * and counting the number of days required to reach the English 
 * date to be converted. We also have the Nepali equivalent of the
 * reference English date (2000, 9, 17). From this date, the number
 * of days are added and the date we reach after adding those days
 * is the one after conversion.
 *
 * Returns 0 if not date is not in range
 */
int eng_to_nep(struct eng_date date, struct nep_date *date_return)
{

    /* Number of days in months of normal English year */
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    /* Number of days in months of English Leap years */
    int lmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    /* This is a reference date in English year i.e. 1994-1-1 */
    int def_eyy = 1944;
    /* And this is the Nepali equivalent of the reference year */
    int def_nyy = 2000;
    int def_nmm = 9;
    int def_ndd = 16;		// 17-1

    /* Total Days we have counted */
    int total_eDays = 0;
    int total_nDays = 0;


    int a = 0;
    int day = 7 - 1;
    int m = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    int numDay = 0;

    if (is_range_eng(date) == 0) {
	return 0;
    }

    /* Count total number of days in terms of year */
    for (i = 0; i < (date.year - def_eyy); ++i) {
	if (is_leap_year(def_eyy + i) == 1)
	    for (j = 0; j < 12; ++j)
		total_eDays += lmonth[j];
	else
	    for (j = 0; j < 12; ++j)
		total_eDays += month[j];
    }

    /* Count total number of days in terms of month */
    for (i = 0; i < (date.month - 1); ++i) {
	if (is_leap_year(date.year) == 1)
	    total_eDays += lmonth[i];
	else
	    total_eDays += month[i];
    }

    /* Count total number of days in terms of date */
    total_eDays += date.date;


    i = 0;
    j = def_nmm;
    total_nDays = def_ndd;
    m = def_nmm;
    y = def_nyy;

    /* count nepali date from array */
    while (total_eDays != 0) {
	a = bs[i][j];
	++total_nDays;
	++day;
	if (total_nDays > a) {
	    ++m;
	    total_nDays = 1;
	    ++j;
	}
	if (day > 7)
	    day = 1;
	if (m > 12) {
	    ++y;
	    m = 1;
	}
	if (j > 12) {
	    j = 1;
	    ++i;
	}
	--total_eDays;
    }

    numDay = day;

    date_return->year = y;
    date_return->month = m;
    date_return->date = total_nDays;
    strcpy(date_return->day, day_week[day - 1]);
    strcpy(date_return->nmonth, nmonth[m - 1]);
    date_return->num_day = numDay;
    return 1;

}

/* Converts Nepali date to English date 
 * This works by selecting a reference date in Nepali (2000,1,1)
 * and counting the number of days required to reach the Nepali 
 * date to be converted. We also have the English equivalent of the
 * reference Nepali date (1943, 4, 14). From this date, the number
 * of days are added and the date we reach after adding those days
 * is the one after conversion.
 *
 * Returns 0 if not date is not in range
 */
int nep_to_eng(struct nep_date date, struct eng_date *date_return)
{
    /* This is a reference date in English year i.e. 1993-4-13 */
    int def_eyy = 1943;
    int def_emm = 4;
    int def_edd = 13;		//14-1
    /* This is the Nepali equivalent i.e. 2000-1-1 */
    int def_nyy = 2000;
    //int def_nmm = 1; 
    //int def_ndd = 1;  
    /* Total Days we have counted */            
    int total_eDays = 0;
    int total_nDays = 0;

    int a = 0;
    int day = 3;		//4-1
    int m = 0;
    int y = 0;
    int i = 0;
    int k = 0;
    int numDay = 0;
    int j;

    /* Number of days in months of normal English years */
    int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    /* Number of days in months of English Leap years */
    int lmonth[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (is_range_nep(date) == 0) {
	   return 0;
    }
    /* count total days in-terms of year */
    for (i = 0; i < (date.year - def_nyy); ++i) {
	for (j = 1; j <= 12; ++j) {
	    total_nDays += bs[k][j];
	}
	++k;
    }

    /* count total days in-terms of month  */                 
    for (j = 1; j < date.month; ++j) {
	   total_nDays += bs[k][j];
    }
    /* count total days in-terms of date */
    total_nDays += date.date;

    /* calculation of equivalent english date... */
    total_eDays = def_edd;
    m = def_emm;
    y = def_eyy;
    while (total_nDays != 0) {
	if (is_leap_year(y)) {
	    a = lmonth[m];
	} else {
	    a = month[m];
	}
	++total_eDays;
	++day;
	if (total_eDays > a) {
	    ++m;
	    total_eDays = 1;
	    if (m > 12) {
		++y;
		m = 1;
	    }
	}
	if (day > 7)
	    day = 1;
	--total_nDays;
    }
    numDay = day;

    (*date_return).year = y;
    date_return->month = m;
    date_return->date = total_eDays;
    strcpy(date_return->day, day_week[day - 1]);
    strcpy(date_return->emonth, emonth[m - 1]);
    date_return->num_day = numDay;
    return 1;

}
