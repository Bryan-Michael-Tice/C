/*

Name: Bryan Michael Tice

Assignment: Lab 02

Course: CSCI 1151

Instructor: J. Chu

Assignment Description: This program is a user input driven tax calculator. 

*/
#include <stdio.h>


int main()

{
	int exemptions;
	float GrossSally,InterestInc,CapGain,CharitableCons,TotInc,AdjInc,TotTax;
	
	printf("Please enter an integer value for number of exemptions\n");
	scanf("%d",&exemptions);
	printf("\n Thank you,\n now enter a value for gross salary\n");
	scanf("%f",&GrossSally);
	printf("Enter income from interest:\n");
	scanf("%f",&InterestInc);
	printf("Enter Capitol gains income\n");
	scanf("%f",&CapGain);
	printf("\nEnter Charitable Contributions");
	scanf("%f",&CharitableCons);

	
	printf("\nNumber of Exemptions: $%-2d",exemptions);
	printf("\nGross Salary: $%-5.2f",GrossSally);
	printf("\nInterest Income: $%-5.2f",InterestInc);
	printf("\nCapitol Gains: $%-5.2f",CapGain);
	printf("\nChartable Contributions: $%-5.2f",CharitableCons);
	
	TotInc=GrossSally+InterestInc+CapGain; /*Calcs the Total income*/
	AdjInc=(TotInc-(exemptions*1500))-CharitableCons;/* Calcs Adjusted Inc*/
	
        if (AdjInc<=10000)
		{
		TotTax=0;
		printf("\nTotal Tax: $%-5.2f", TotTax);	
		}
	else if (AdjInc<=32000)
		{
		TotTax=(AdjInc-10000)*0.15;
		printf("\nTotal Tax: $%-5.2f", TotTax);
		}
	else if (AdjInc<=50000)
		{
		TotTax=(22000*.15)+(AdjInc-32000)*.23;
		printf("\nTotal Tax: $%-5.2f", TotTax);
		}
	else
		{
		TotTax=(22000*.15)+(18000*.23)+(AdjInc-50000)*.28;
		}
	
	printf("\n\nTotal Income:    $%-5.2f",TotInc);
	printf("\nAdjusted Income: $%-5.2f",AdjInc);
	printf("\nTotal Tax:    $%-5.2f",TotTax);

	
return 0;
}