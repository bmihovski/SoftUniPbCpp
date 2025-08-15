#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetMinutes(const int hours, const int minutes) {
  return hours * 60 + minutes;
}
int GetSeconds(const int hours, const int minutes, const int seconds) {
  return GetMinutes(hours, minutes) * 60 + seconds;
}

typedef struct {
  int hours;
  int minutes;
  int seconds;
  int (*GetMinutes)(const int hours, const int minutes);
  int (*GetSeconds)(const int hours, const int minutes, const int seconds);
} Time;

int main() {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
  scanf(" %d %d %d", &hours, &minutes, &seconds);

  Time currentTime = {hours, minutes, seconds};
  currentTime.GetMinutes = GetMinutes;
  currentTime.GetSeconds = GetSeconds;

  printf("%d\n", currentTime.hours);
  printf("%d\n",
         currentTime.GetMinutes(currentTime.hours, currentTime.minutes));
  printf("%d\n", currentTime.GetSeconds(currentTime.hours, currentTime.minutes,
                                        currentTime.seconds));

  return 0;
}
