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
#include "date.h"
int main(void)
{
    struct eng_date date_ei;
    struct eng_date *date_e;
    struct nep_date date_o;
    date_e = &date_ei;
    date_o.year = 2061;
    date_o.month = 1;
    date_o.date = 14;
    if (nep_to_eng(date_o, date_e)) {
	printf
	    ("Nepali Date: 2061 Baisakh 1 is Eng Eq. to %d %d %d %s Day Number:%d %s\n",
	     date_e->year, date_e->month, date_e->date, date_e->emonth,
	     date_e->num_day, date_e->day);
    }
    return 0;
}
