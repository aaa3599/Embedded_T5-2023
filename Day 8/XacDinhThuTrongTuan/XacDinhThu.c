// Cho 1 ngày bất kì ==> Thứ mấy

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Kiem tra ngay hop le
bool check_date(int day, int month)
{
  if ((month == 2) && (day > 0) && (day < 30))
  {
    return true;
  }
  if ((
          (month == 1) ||
          (month == 3) ||
          (month == 5) ||
          (month == 7) ||
          (month == 8) ||
          (month == 10) ||
          (month == 12)) &&
      ((day > 0) && (day < 32)))
  {
    return true;
  }
  if ((
          (month == 4) ||
          (month == 6) ||
          (month == 9) ||
          (month == 11)) &&
      ((day > 0) && (day < 31)))
  {
    return true;
  }
  return false;
}

// Kiem tra thang hop le
bool check_month(int month)
{
  if ((month > 0) && (month < 13))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Kiem tra nam hop le
bool check_year(int year)
{

  if ((year > 999) && (year < 10000))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Kiem tra nam nhuan
bool check_leap_year(int year)
{
  if (((year % 4) == 0) && ((year % 100) != 0))
  {
    return true;
  }
  else if ((year % 400) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Tính số ngày trong 1 năm bất kì
int numberDayInYear(int year)
{
  if (check_leap_year(year))
    return 366;
  return (365);
}

// Tính số ngày trước năm đang xét từ 1/1/1 đến 31/12/(year-1)
int numberDayBeforeYear(int year)
{
  int numNumberDayBefore = 0;
  for (int i = 1; i < year; i += 1)
    numNumberDayBefore += numberDayInYear(i);
  return numNumberDayBefore;
}

// Tính số ngày trong 1 tháng của 1 năm bất kì
int numberDayInMonth(int year, int month)
{
  switch (month)
  {
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2:
  {
    if (check_leap_year(year))
      return 29;
    return 28;
  }
  default:
    return 31;
  }
}

// Tính số ngày trước tháng đang xét kể từ đầu năm
int numberDayBeforeMonth(int year, int month)
{
  int numberDay = 0;
  for (int i = 1; i < month; i += 1)
    numberDay += numberDayInMonth(year, i);
  return numberDay;
}

// Tính tổng số ngày kể từ 1/1/1 đến hiện tại
int numNumberDay(int year, int month, int day)
{
  return numberDayBeforeYear(year) + numberDayBeforeMonth(year, month) + day;
}

// Tim chính xác thứ theo ngày tháng nam dã biêt
const char *get_day(int day, int month, int year)
{
  int i = numNumberDay(year, month, day) % 7;
  const char *weekday[] = {"Chu nhat",
                           "Thu 2",
                           "Thu 3",
                           "Thu 4",
                           "Thu 5",
                           "Thu 6",
                           "Thu 7"};
  return weekday[i];
}

int main()
{
  // Khai bao bien
  int year, month, date;

  printf("\n[+] CHUONG TRINH TINH THU KHI BIET NGAY THANG NAM.");

  // Take Inputs
  printf("\n[+] Vui long nhap nam [YYYY] : ");
  scanf("%d", &year);

  // verify year
  if (check_year(year))
  {
    printf("[-] Xac nhan!");
  }
  else
  {
    printf("\n\t [-] Nhap sai!\n");
    exit(0);
  }

  printf("\n[+] Vui long nhap thang [MM] : ");
  scanf("%d", &month);

  // verify month
  if (check_month(month))
  {
    printf("[-] Xac nhan!");
  }
  else
  {
    printf("[-] Nhap sai!");
    exit(0);
  }

  printf("\n[+] Vui long nhap ngay [DD] : ");
  scanf("%d", &date);

  // verify date
  if (check_date(date, month))
  {
    printf("[-] Xac nhan!\n\n");
  }
  else
  {
    printf("[-] Nhap sai!");
    exit(0);
  }

  // Trả về kết quả
  printf("[+] Ngay : %d, Thang : %d, Nam : %d ", date, month, year);
  if (check_leap_year(year))
  {
    printf("[Nam nhuan]");
  }
  else
  {
    printf("[Khong phai nam nhuan]");
  }
  printf("\n[-] Thu trong tuan: %s\n\n", get_day(date, month, year));

  return 0;
}