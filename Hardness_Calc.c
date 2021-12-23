/*
*This is consol program, which intended for calculate hardness of carbon steel.
*Author Chumakov Sergey (2021.12.23)
*Contacts: telegram: @Technolog7 (my english is not very nice :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include "Hardness_Calc_h.h"

int main(void)
{
	start: 
	
	system("cls");
	printf("%s", str_heading[Select_Language]);
	printf("\n");
	printf("%s", str_calc_hardness[Select_Language]);
	printf("%s", str_calc_diameter[Select_Language]);
	printf("%s", str_info[Select_Language]);
	printf("Press buton L - for select languge.\n");
	printf("%s", str_exit[Select_Language]);
	printf("\n");
	
	unsigned char select = getch();
	
	if(select == '1')
	{
		system("cls");
		
		struct data *hardnes_s_p;
		struct data *hardnes_s_p_t;
		
		unsigned char i = 0;
		
		print_1();
		
		restart_1:;
		
		hardnes_s_p = (struct data *) malloc(sizeof(struct data));
		
		if(0 == i)
		{
			(*hardnes_s_p).data_p = NULL;
			hardnes_s_p_t = hardnes_s_p;
			
			str_copy("10", (*hardnes_s_p).d_indentor);
			str_copy("29420", (*hardnes_s_p).f);
		}
		else
		{
			(*hardnes_s_p).data_p = hardnes_s_p_t;
			
			str_copy((*hardnes_s_p_t).d_indentor, (*hardnes_s_p).d_indentor);
			str_copy((*hardnes_s_p_t).f, (*hardnes_s_p).f);
	
			hardnes_s_p_t = hardnes_s_p;
		}
			
		printf("%s", str_diameter_of_mark[Select_Language]);
		
		double d = enter(print_1, text_data_hardnes, hardnes_s_p);
		
		if(0 == d)
		{
			free(hardnes_s_p);
			goto start;
		}
		
		if(atof((*hardnes_s_p).d_indentor) < d)
		{
			text_error_d(print_1, text_data_hardnes, hardnes_s_p);
			free(hardnes_s_p);
			goto restart_1;
		}
		
	    (*hardnes_s_p).HB = hardnes(atof((*hardnes_s_p).d_indentor),
		                            atof((*hardnes_s_p).f), d);
		
		if(1000 < (*hardnes_s_p).HB)
		{
			text_error_HB(print_1, text_data_hardnes, hardnes_s_p);
			free(hardnes_s_p);
			goto restart_1;
		}
		
		(*hardnes_s_p).hrc = hrc((*hardnes_s_p).HB);
		(*hardnes_s_p).sig_max = sigma_max((*hardnes_s_p).HB);
		(*hardnes_s_p).sig_min = sigma_min((*hardnes_s_p).HB);
		(*hardnes_s_p).sig_0_max = sigma_0_max((*hardnes_s_p).HB);
		(*hardnes_s_p).sig_0_min = sigma_0_min((*hardnes_s_p).HB);
		
		text_hardnes(hardnes_s_p);
		
		++i;
		
		if(8 == i)
		{
			free_memory(hardnes_s_p);
			--i;
		}
		
		goto restart_1;
	}
		
	if(select == '2')
	{
		system("cls");
		
		struct data *diameter_s_p;
		struct data *diameter_s_p_t;
		
		unsigned char i = 0;
		
		print_2();
		
		restart_2:;
		
		diameter_s_p = (struct data *) malloc(sizeof(struct data));
		
		if(0 == i)
		{
			(*diameter_s_p).data_p = NULL;
			diameter_s_p_t = diameter_s_p;
			
			str_copy("10", (*diameter_s_p).d_indentor);
			str_copy("29420", (*diameter_s_p).f);
		}
		else
		{
			(*diameter_s_p).data_p = diameter_s_p_t;
			
			str_copy((*diameter_s_p_t).d_indentor, (*diameter_s_p).d_indentor);
			str_copy((*diameter_s_p_t).f, (*diameter_s_p).f);
	
			diameter_s_p_t = diameter_s_p;
		}

		printf("%s", str_hardness[Select_Language]);
		
		double HB = enter(print_2, text_data_diameter, diameter_s_p);
		
		if(HB == 0)
		{
			free(diameter_s_p);
			goto start;
		}
		
		if(19 > HB)
		{
			text_error_d(print_2, text_data_diameter, diameter_s_p);
			free(diameter_s_p);
			goto restart_2;
		}
		
		if(700 < HB)
		{
			text_error_HB(print_2, text_data_diameter, diameter_s_p);
			free(diameter_s_p);
			goto restart_2;
		}
		
	    (*diameter_s_p).diameter = diameter(atof((*diameter_s_p).d_indentor), 
		                                    atof((*diameter_s_p).f), HB);	
		(*diameter_s_p).hrc = hrc(HB);
		(*diameter_s_p).sig_max = sigma_max(HB);
		(*diameter_s_p).sig_min = sigma_min(HB);
		(*diameter_s_p).sig_0_max = sigma_0_max(HB);
		(*diameter_s_p).sig_0_min = sigma_0_min(HB);
	
		text_diameter(diameter_s_p);
		
		++i;
		
		if(8 == i)
		{
			free_memory(diameter_s_p);
			--i;
		}
		
		goto restart_2;
	}
	
	if(select == '7')
	{
		system("cls");
		printf("%s", str_information[Select_Language]);
		printf("********************************************************\n\n");
		delay(7777);
		ornamentation();
		select = getch();
		if(select == 8 || select == 27) 
		{
			goto start;
		}
	}
	
	if('L' == select || 'l' == select)
	{
		system("cls");
		
		printf("Русский язык нажмите 1 \n");
		printf("Englis languige press 2 \n");
		
		while(1)
		{
			select = getch();
			if('1' == select)
			{
				Select_Language = RUSSIAN;
				goto start;
			}
			if('2' == select)
			{
				Select_Language = ENGLISH;
                goto start;
			}				
		}
	}
	
	if(select == 27)
	{
		return 0;
	}
	
	goto start;
	
	return 0;
}

void print_1(void)
{
	printf("%s", str_enter_diameter[Select_Language]);
	printf("%s", str_enter_item[Select_Language]);
	printf("%s", str_clean_list[Select_Language]);
	printf("%s", str_return_predicable[Select_Language]);
	printf("\n");
	return;
}

void print_2(void)
{
	printf("%s", str_enter_hardness[Select_Language]);
	printf("%s", str_enter_item[Select_Language]);
	printf("%s", str_return_predicable[Select_Language]);
	printf("\n");
	return;
}

void text_hardnes(struct data *data_)
{
	printf("\n");
	printf(str_result_hardness[Select_Language], (*data_).HB);
	printf(str_result_hrc[Select_Language], (*data_).hrc);
	printf(str_strength_limit[Select_Language],(*data_).sig_min, 
	       (*data_).sig_max);
	printf(str_fluidity_limit[Select_Language], (*data_).sig_0_min, 
	       (*data_).sig_0_max);
	printf(str_diameter_indentor[Select_Language], (*data_).d_indentor);
	printf(str_test_power[Select_Language], (*data_).f);
	printf("__________________________ \n");
	return;
}

void text_diameter(struct data *data_)
{
	printf("\n");
	printf(str_result_diameter_mark[Select_Language], (*data_).diameter);
	printf(str_result_hrc[Select_Language], (*data_).hrc);
	printf(str_strength_limit[Select_Language],(*data_).sig_min, 
	       (*data_).sig_max);
	printf(str_fluidity_limit[Select_Language], (*data_).sig_0_min, 
	       (*data_).sig_0_max);
	printf(str_diameter_indentor[Select_Language], (*data_).d_indentor);
	printf(str_test_power[Select_Language], (*data_).f);
	printf("__________________________ \n");
	return;
}

void text_data_hardnes(struct data *data_)
{
	if(NULL == data_)
	{
		return;
	}
	text_data_hardnes((*data_).data_p);
	printf("\n");
	printf(str_predicable_diameter_mark[Select_Language], (*data_).input);
	printf(str_result_hardness[Select_Language], (*data_).HB);
	printf(str_strength_limit[Select_Language],(*data_).sig_min, 
	       (*data_).sig_max);
	printf(str_fluidity_limit[Select_Language], (*data_).sig_0_min, 
	       (*data_).sig_0_max);
	printf(str_diameter_indentor[Select_Language], (*data_).d_indentor);
	printf(str_test_power[Select_Language], (*data_).f);
	printf("__________________________ \n");
	return;
}

void text_data_diameter(struct data *data_)
{
	if(NULL == data_)
	{
		return;
	}
	text_data_diameter((*data_).data_p);
	printf("\n");
    printf(str_predicable_hardness[Select_Language], (*data_).input);
	printf(str_result_diameter_mark[Select_Language], (*data_).diameter);
	printf(str_strength_limit[Select_Language],(*data_).sig_min, 
	       (*data_).sig_max);
	printf(str_fluidity_limit[Select_Language], 
	       (*data_).sig_0_min, (*data_).sig_0_max);
	printf(str_diameter_indentor[Select_Language], (*data_).d_indentor);
	printf(str_test_power[Select_Language], (*data_).f);
	printf("__________________________ \n");
	return;
}

void text_error_d(void (*pf)(void), void (*pf_)(struct data *), 
                  struct data *data_)
{
	system("cls");
	printf(str_warning[Select_Language]);
	printf(str_press_esc[Select_Language]);
	unsigned char c = 0;
	while(27 != (c = getch()))
	{
	}
	system("cls");
	pf();
	pf_((*data_).data_p);
	return;
}

void text_error_HB(void (*pf)(void), void (*pf_)(struct data *), 
                   struct data *data_)
{
	system("cls");
	printf(str_brinell_info[Select_Language]);
	printf(str_press_esc[Select_Language]);
	unsigned char c = 0;
	while(27 != (c = getch()))
	{
	}
	system("cls");
	pf();
	pf_((*data_).data_p);
	return;
}

void ornamentation(void)
{
	char ornament[] = "0000000011111111000000001111111100000000111111110000000011111111\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
0000000011111111000000001111111100000000111111110000000011111111\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
1111111100000000111111110000000011111111000000001111111100000000\n\
1111111100000000111111110000000011111111000000001111111100000000\n";
	char i;
	for(i = 0; 7!=i; ++i)
	{
		system("cls");
		printf("%s", str_information[Select_Language]);
		printf("********************************************************\n\n");
		printf(ornament);
	    delay(777);
	    invert(ornament);
	    /* printf(ornament);
	    delay(900); */
	}
	system("cls");
	printf("%s", str_information[Select_Language]);
	printf("************************************************************\n\n");
	return;
}

void invert(char ornament[])
{
	unsigned short i;
	for(i = 0; ornament[i] != '\0'; ++i)
	{
		if(ornament[i] == '0')
		{
			ornament[i] = '1';
			continue;
		}
		if(ornament[i] == '1')
		{
			ornament[i] = '0';
			continue;
		}
	}
}

void delay(unsigned int ms)
{
	int c = clock() + ms;
	while(clock() < c);
}

void free_memory(struct data *data_)
{
	if(NULL == (*(*data_).data_p).data_p)
	{
		free((*data_).data_p);
		(*data_).data_p = NULL;
		return;
	}
	free_memory((*data_).data_p);
	return;
}