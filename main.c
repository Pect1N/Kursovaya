#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu()
{
	int action;
	int exit;

	system("cls");

	exit = 0;

	printf("For add enter 1 \n");
	printf("For reduct enter 2 \n");
	printf("For delete enter 3 \n");
	printf("For show all enter 4 \n");
	printf("For short enter 5 \n");
	printf("For exit enter 6 \n");

	scanf("%d", &action);
	getchar();

	switch (action)
	{
	case 1:
	{
		add();
		break;
	}
	case 2:
	{
		reduct();
		break;
	}
	case 3:
	{
		delete();
		break;
	}
	case 4:
	{
		show();
		break;
	}
	case 5:
	{
		shorty();
		break;
	}
	case 6:
	{
		exit = 1;
		break;
	}
	default:
		printf("Error in entering \n");
		system("pause");
		break;
	}

	return exit;
}

int add()
{
	FILE *fpin;
	char c;
	int k, flag = 0;
	char num[5];
	int i = 0, yes = 1;

	system("cls");

	flag = 0;
	k = 0;
	c = 0;

	fopen_s(&fpin, "number_of_busses.txt", "a");
	if (fpin == NULL)
	{
		printf("Error number_of_busses.txt. Create new? \n press enter to continue \n");
		getchar();
		return 1;
	}

	while (yes == 1)
	{
		i = 0;
		printf("Enter number of bus (no more 3 dijits) \n");
		fgets(num, 5, stdin);
		while (num[i] != '\n')
		{
			if (num[i] <= '0' || num[i] > '9')
			{
				printf("again \n");
				yes = 1;
				break;
			}
			i++;
			yes = 0;
		}
	}
	fprintf(fpin, num, "%s");

	fclose(fpin);

	fopen_s(&fpin, "roads.txt", "a");
	if (fpin == NULL)
	{
		printf("Error roads.txt. Create new? \n press enter to continue \n");
		getchar();
		return 1;
	}

	yes = 1;

	while (yes == 1)
	{
		i = 0;
		printf("Enter roads of bus (no more 3 stops) \n");
		fgets(num, 5, stdin);
		while (num[i] != '\n')
		{
			if (num[i] <= '0' || num[i] > '9' || num[i] == num[i + 1] || num[i] == num[i + 2])
			{
				printf("again \n");
				yes = 1;
				break;
			}
			i++;
			yes = 0;
		}
	}
	fprintf(fpin, num, "%s");


	fclose(fpin);

	return 0;
}

int reduct()
{
	int action;

	printf("what you want reduct? \n For numbers enter 1 \n For roads enter 2 \n");
	scanf("%d", &action);
	getchar();

	switch (action)
	{
	case 1:
	{
		redN();
		break;
	}
	case 2:
	{
		redR();
		break;
	}
	default:
		printf("Error in entering \n");
		system("pause");
		break;
	}


	return 0;
}

int redN()
{
	FILE *fpin;
	FILE *fpout;
	int nothing, shag, i, c, number_of_line, k, flag;

	shag = k = nothing = flag = 0;

	fopen_s(&fpin, "number_of_busses.txt", "r");
	if (fpin == NULL)
	{
		printf("Error number_of_busses.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	printf("busses in baza: \n");
	while (!feof(fpin))
	{
		fscanf(fpin, "%d", &i);
		if (i == '\0')
		{
			nothing = 1;
		}
		if (i == 0)
		{
			break;
		}
		if (i != '\n')
		{
			shag++;
			printf("%d %d\n", shag, i);
			i = 0;
		}
	}

	fseek(fpin, 0, SEEK_SET);

	if (nothing == 1 && shag == 0)
	{
		printf("Nothing in basa \n");
		fclose(fpin);
		system("pause");
		return 0;
	}
	fopen_s(&fpout, "number_of_busses2.txt", "w");
	if (fpin == NULL)
	{
		printf("Error number_of_busses2.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	while (flag == 0)
	{
		printf("Enter position of bus \n");
		scanf("%d", &c);
		if (c < 0 || c > shag)
			printf("ahain \n");
		else
		{
			flag = 1;
		}
	}
	printf("enter new number \n");
	scanf("%d", &k);

	number_of_line = 0;

	while (shag != 0)
	{
		fscanf(fpin, "%d", &i);
		number_of_line++;
		if (number_of_line == c)
		{
			fprintf(fpout, "%d\n", k);
		}
		if (number_of_line != c)
		{
			fprintf(fpout, "%d\n", i);
			i = 0;
		}
		shag--;
	}

	fclose(fpin);
	fclose(fpout);

	remove("number_of_busses.txt");
	rename("number_of_busses2.txt", "number_of_busses.txt");


	return 0;
}

int redR()
{
	FILE *fpin;
	FILE *fpout;
	int nothing, shag, i, c, number_of_line, k;

	shag = k = nothing = 0;

	fopen_s(&fpin, "roads.txt", "r");
	if (fpin == NULL)
	{
		printf("Error roadss.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	printf("roads in baza: \n");
	while (!feof(fpin))
	{
		fscanf(fpin, "%d", &i);
		if (i == '\0')
		{
			nothing = 1;
		}
		if (i == 0)
		{
			break;
		}
		if (i != '\n')
		{
			shag++;
			printf("%d %d\n", shag, i);
			i = 0;
		}
	}

	fseek(fpin, 0, SEEK_SET);

	if (nothing == 1 && shag == 0)
	{
		printf("Nothing in basa \n");
		fclose(fpin);
		system("pause");
		return 0;
	}
	fopen_s(&fpout, "roads2.txt", "w");
	if (fpin == NULL)
	{
		printf("Error roads2.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	printf("Enter position of road \n");
	scanf("%d", &c);
	printf("enter new road \n");
	scanf("%d", &k);

	number_of_line = 0;

	while (shag != 0)
	{
		fscanf(fpin, "%d", &i);
		number_of_line++;
		if (number_of_line == c)
		{
			fprintf(fpout, "%d\n", k);
		}
		if (number_of_line != c)
		{
			fprintf(fpout, "%d\n", i);
			i = 0;
		}
		shag--;
	}

	fclose(fpin);
	fclose(fpout);

	remove("roads.txt");
	rename("roads2.txt", "roads.txt");


	return 0;
}

int delete()
{
	FILE *fpin;
	FILE *fpout;
	int c, i, number_of_line, point_line, nothing, shag, yes = 1;
	system("cls");

	c = i = nothing = shag = 0;
	number_of_line = 1;


	fopen_s(&fpin, "number_of_busses.txt", "r");
	if (fpin == NULL)
	{
		printf("Error number_of_busses.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	printf("busses in baza: \n");
	while (!feof(fpin))
	{
		fscanf(fpin, "%d", &i);
		if (i == '\0')
		{
			nothing = 1;
		}
		if (i == 0)
		{
			break;
		}
		if (i != '\n')
		{
			shag++;
			printf("%d %d\n", shag, i);
			i = 0;
		}
	}

	fseek(fpin, 0, SEEK_SET);

	if (shag == 0)
	{
		printf("Nothing in basa \n");
		fclose(fpin);
		system("pause");
		return 0;
	}

	fopen_s(&fpout, "number_of_busses2.txt", "w");
	if (fpin == NULL)
	{
		printf("Error number_of_busses2.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	printf("Enter position of bus \n");
	scanf("%d", &c);

	number_of_line = 1;

	while (number_of_line <= shag)
	{
		fscanf(fpin, "%d", &i);
		if (number_of_line != c)
		{
			fprintf(fpout, "%d\n", i);
		}
		number_of_line++;
	}

	fclose(fpin);
	fclose(fpout);

	remove("number_of_busses.txt");
	rename("number_of_busses2.txt", "number_of_busses.txt");

	fopen_s(&fpin, "roads.txt", "r");
	if (fpin == NULL)
	{
		printf("Error roads.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}
	fopen_s(&fpout, "roads2.txt", "w");
	if (fpin == NULL)
	{
		printf("Error roads2.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	point_line = 1;

	while (point_line <= shag)
	{
		fscanf(fpin, "%d", &i);
		if (point_line != c)
		{
			fprintf(fpout, "%d\n", i);
		}
		point_line++;
	}

	fclose(fpin);
	fclose(fpout);

	remove("roads.txt");
	rename("roads2.txt", "roads.txt");

	return 0;
}

int show()
{
	FILE *fpin1;
	FILE *fpin2;
	int j, i;
	char bus[4], num[4];

	system("cls");

	fopen_s(&fpin1, "roads.txt", "r");
	if (fpin1 == NULL)
	{
		printf("Error roadss.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	fopen_s(&fpin2, "number_of_busses.txt", "r");
	if (fpin2 == NULL)
	{
		printf("Error number_of_busses.txt. Add new? \n press enter to continue \n");
		getchar(); 
		return 1;
	}

	for (i = 1; i <= 9; i++)
	{
		printf("Busses stops on %d stop: \n", i);
		while (!feof(fpin1))
		{
			fgets(bus, 4, fpin2);
			fgets(num, 4, fpin1);
			for (j = 0; j < 3; j++)
			{
				if (num[j] == (48 + i))
				{
					printf("  %s \n", bus);
				}
			}
		}
		fseek(fpin1, 0, SEEK_SET);
		fseek(fpin2, 0, SEEK_SET);
	}

	fclose(fpin1);
	fclose(fpin2);

	system("pause \n");

	return 0;
}

int shorty()
{
	FILE *fpin1;
	FILE *fpin2;
	FILE *fpin3;
	FILE *fpin4;
	char num1[4], num2[4], bus1[4], bus2[4];
	int a, b, i, j, k, l, flag = 0, count = 0;

	system("cls");

	fopen_s(&fpin1, "roads.txt", "r");
	if (fpin1 == NULL)
	{
		printf("Error roadss.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}
	fopen_s(&fpin3, "roads.txt", "r");
	if (fpin3 == NULL)
	{
		printf("Error roadss.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}
	fopen_s(&fpin2, "number_of_busses.txt", "r");
	if (fpin2 == NULL)
	{
		printf("Error number_of_busses.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}
	fopen_s(&fpin4, "number_of_busses.txt", "r");
	if (fpin4 == NULL)
	{
		printf("Error number_of_busses.txt. Add something! \n press enter to continue \n");
		getchar(); 
		return 1;
	}



	printf("Enter the starter stop (A): \n");
	scanf("%d", &a);
	printf("Enter the starter stop (B): \n");
	scanf("%d", &b);

	while (!feof(fpin1))
	{
		fgets(num1, 4, fpin1);
		fgets(bus1, 4, fpin2);
		for (i = 0; i < 3; i++)
		{
			if (num1[i] == (a + 48) || num1[i] == (b + 48))
				count++;
		}
		if (count == 2)
		{
			flag = 1;
			printf("short marsh: %s \n", bus1);
		}
		count = 0;
	}
	if (flag != 1)
	{
		fseek(fpin1, 0, SEEK_SET);
		fseek(fpin2, 0, SEEK_SET);
		while (!feof(fpin1))
		{
			fgets(num1, 4, fpin1);
			fgets(bus1, 4, fpin2);
			for (i = 0; i < 3; i++)
			{
				if (num1[i] == (a + 48))
				{
					while (!feof(fpin3))
					{
						fgets(num2, 4, fpin3);
						fgets(bus2, 4, fpin4);
						for (j = 0; j < 3; j++)
						{
							if (num2[j] == (b + 48))
							{
								for (k = 0; k < 3; k++)
								{
									for (l = 0; l < 3; l++)
									{
										if (num1[k] == num2[l])
											printf("short way fron %s to %s \n", bus1, bus2);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	fclose(fpin1);
	fclose(fpin2);
	fclose(fpin3);
	fclose(fpin4);

	system("pause \n");

	return 0;
}

int main()
{
	int exit;

	exit = 0;
	exit = menu();

	while (exit != 1)
	{
		exit = menu();
	}

	system("pause \n");

	return 0;
}