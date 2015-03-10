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
#ifndef DATE_H
#define DATE_H
struct eng_date {
    int year;
    int month;
    int date;
    char day[10]; // Name of day, Sunday, Monday,...
    char emonth[10]; // Name of English Month
    int num_day; // Day number, Sunday = 1
};
struct nep_date {
    int year;
    int month;
    int date;
    char day[10]; // Name of day
    char nmonth[10]; // Name of Nepali Month
    int num_day; // Day number, Sunday = 1
};
int is_leap_year(int);
int is_range_eng(struct eng_date);
int is_range_nep(struct nep_date);
int eng_to_nep(struct eng_date, struct nep_date *);
int nep_to_eng(struct nep_date, struct eng_date *);
#endif
