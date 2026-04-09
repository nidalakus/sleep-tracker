#include <stdio.h>

float calculateAverageSleep(int sleepHours[], int days) {
	int total = 0;
	int i;
	for (i=0; i<days; i++) {
		total += sleepHours[i];
		
	}
	return (float)total / days;
}


int findLeastSleepDay(int sleepHours[], int days) {
	int min = sleepHours[0];
	int index = 0;
	int i;
	for (i=0; i<days; i++) {
		if (sleepHours[i] < min) {
			min = sleepHours[i];
			index = i;
		}
	}
	return index;
}


int countIrregularDays(int sleepHours[], int days) {
	float avg = calculateAverageSleep(sleepHours, days);
	int count = 0;
	int i;
	for (i=0; i<days; i++) {
		if (sleepHours[i] < avg - 2 || sleepHours[i] > avg + 2) {
			count++;
		}
	}
	return count; 
}


int main () {
	
	int sleepHours[7];
	char daysOfWeek[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", 
	"Saturday", "Sunday"};
	int i;
	
	printf("\nEnter sleep hours for each day \n");
	for (i=0; i<7; i++) {
		printf("%s: ", daysOfWeek[i]);
		scanf("%d", &sleepHours[i]);
		
	}
	printf("\n\n");
	
	float average = calculateAverageSleep(sleepHours, 7);
	int leastDay = findLeastSleepDay(sleepHours, 7);
	int irregularCount = countIrregularDays(sleepHours, 7);
	
	printf("Average sleep hour: %.2f \n", average);
	printf("Least sleep day is: %s (%d hour) \n", daysOfWeek[leastDay], sleepHours[leastDay]);
	printf("Number of Irregular Sleep day: %d \n",irregularCount);
	
	
	printf("\n\n");
	
	if (average < 6) 
		printf("Warning: You may be sleep-deprived. Try to sleep more! \n");
		
	else if (irregularCount > 3) 
		printf("Your sleep pattarn is inconsistent. You should build a new routine! \n");
		
	else 
		printf("Great job! Your sleep habits seem healthy. \n");
		
	
	return 0;
	
}




