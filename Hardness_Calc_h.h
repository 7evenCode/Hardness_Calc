#ifdef BUILD_DLL
// the dll exports
#define EXPORT __declspec(dllexport)
#else
// the exe imports
#define EXPORT __declspec(dllimport)
#endif
// function to be imported/exported

struct data
{
	unsigned char d_indentor[7];
	unsigned char f[8];
	unsigned char input[6];
	double diameter;
	double HB;
	double hrc;
	double sig_max;
	double sig_min;
	double sig_0_max;
	double sig_0_min;
	struct data *data_p;
};

void print_1(void);
void print_2(void);

void text_hardnes(struct data *);
void text_diameter(struct data *);
void text_data_hardnes(struct data *);
void text_data_diameter(struct data *);
void text_error_d(void (*pf)(void), void (*pf_)(struct data *), struct data *);
void text_error_HB(void (*pf)(void), void (*pf_)(struct data *), struct data *);

void ornamentation(void);
void invert (char []);
void delay(unsigned int);
void free_memory(struct data *data_);

EXPORT double enter(void (*pf)(void), void (*pf_)(struct data *), struct data *);
EXPORT void enter_df(unsigned char[], void (*pf)(void), void (*pf_)(struct data *),
                     struct data *);
EXPORT double hardnes(double d_indentor, double f, double d);
EXPORT double diameter(double d_indentor, double f, double HB);
EXPORT double hrc(double hbw);
EXPORT double sigma_max(double HB);
EXPORT double sigma_min(double HB);
EXPORT double sigma_0_max(double HB);
EXPORT double sigma_0_min(double HB);

EXPORT void print_df(struct data *);
EXPORT void print_d(void);
EXPORT void print_f(void);

EXPORT void str_copy(unsigned char str_1[], unsigned char str_2[]);
EXPORT void save(struct data *);
EXPORT void data_hardnes_save(struct data *, FILE *);
EXPORT unsigned char* utf_8_converter(unsigned char text[]);
EXPORT void free_all_memory(struct data *data_);

enum {RUSSIAN = 0, ENGLISH = 1} Select_Language = ENGLISH;

char *str_heading[] = 
{
	"�ணࠬ�� ���᫥��� ��म��.\n",
    "��� programm computation hardness.\n"
};

char *str_calc_hardness[] = 
{
	"������ ������� 1 - ��� ���᫥��� ��म�� �� �⯥���. \n",
    "Press key 1 - for computation hardness on diameter of mark. \n"
};

char *str_calc_diameter[] = 
{
	"������ ������� 2 - ��� ���᫥��� ����室����� ������� �⯥�⪠ \
�� �������� \n ��म��. \n",
    "Press key 2 - for computation diameter of mark on known hardness in \
Brenell. \n"
};

char *str_info[] = 
{
	"������ ������� 7 - ��� ��ᬮ�� ���ଠ樨 � �ணࠬ��. \n",
    "Press key 7 - for view information about programm. \n"
};

char *str_information[] = 
{
	"�� ���᮫쭠� �ணࠬ�� ��� ����ண� ��।������ ��堭��᪨� \
᢮���.\n�㬠��� ��ࣥ�. emai-7S@protonmail.com 2019 �. \n",
    "This is a programm for fast adjectives mechanical properties. \n \
Chumakov Sergey. emai-7S@protonmail.com 2019 \n"
};

char *str_press_esc[] = 
{
	"������ ������� 'Esc' - ��� ������. \n",
    "Press key 'Esc' - for return. \n"
};

char *str_exit[] = 
{
	"������ ������� 'Esc' - ��� �����襭�� �ணࠬ��. \n",
    "Press key 'Esc' - for termination programm. \n"
};

char *str_diameter_of_mark[] = 
{
	"������� �⯥�⪠ = ",
	"Diameter of mark = "
};

char *str_hardness[] = 
{
	"���म��� = ",
	"Hardness = "
};

char *str_enter_diameter[] = 
{
	"������ ������� �⯥�⪠ � ��, � ������ ������� 'Enter' ��� \
���c����� ��म��. \n",
	"Enter diameter of mark in mm, and press key 'Enter' for \
computation hardness. \n"
};

char *str_enter_hardness[] = 
{
	"������ ��म���, � ������ ������� 'Enter' ��� ���c����� \
ᮮ⢥�����饣� �⯥�⪠. \n",
	"Enter hardness, and press key 'Enter' for computation comformable \
diameter of mark. \n"
};

char *str_enter_item[] = 
{
	"��� ����� ����⥫��� ������ ������ ������� 'F1'. \n",
	"For input test items press key 'F1'. \n"
};

char *str_item[] = 
{
	"����騩 ������� ������� d = %s ��, ᨫ� �ᯠ�⥫쭮� ����㧪� F = %s.\n \
��� ��������� ���祭�� ������� ������ ������� 'd', ��� ��������� ���祭�� \
ᨫ� ������� 'F' \n",
	"Current diameter of indentor d = %s mm, force of test load F = %s. \n \
For change value of diameter press key 'd', for change value of test load \
press key 'F'. \n"
};

char *str_indentor[] = 
{
	"������ ������� ������� � ��, � ������ ������� 'Entet'. \n",
	"Enter indentor diameter in mm, and press key 'Entet'. \n"
};

char *str_force[] = 
{
	"������ ᨫ� ����⥫쭮� ����㧪� � �, � ������ ������� 'Etnter'. \n",
	"Enter test load in N, and press key 'Entet'. \n"
};

char *str_result_hardness[] = 
{
	"���म��� ᮮ⢥����� %0.3f �����栬 �� 誠�� �ਭ���. \n",
	"Hardness meet %0.3f unit on scale of Brenell. \n"
};

char *str_result_hrc[] = 
{
	"��������� ��म��� �� 誠�� �������� ~ %0.3f HRC. \n",
	"Expected hardness on scale of Rockwell ~ %0.3f HRC. \n"
};

char *str_result_diameter_mark[] = 
{
	"������� �⯥�⪠ = %0.3f ��. \n",
	"Diameter of mark = %0.3f mm. \n"
};

char *str_strength_limit[] = 
{
	"������᪨� �।�� ��筮�� = %0.3f ... %0.3f ���. \n",
	"Teoretical limit of strenght = %0.3f ... %0.3f �P�. \n"
};

char *str_fluidity_limit[] = 
{
	"������᪨� �।�� ⥪���� = %0.3f ... %0.3f ���. \n",
	"Teoretical limit of fluidity = %0.3f ... %0.3f �P�. \n"
};

char *str_diameter_indentor[] = 
{
	"������� ������� = %s ��. \n",
	"Diameter of indentor = %s mm. \n"
};

char *str_test_power[] = 
{
	"���� ����⥫쭮� ����㧪� = %s �. \n",
	"Power of test load = %s N. \n"
};

char *str_predicable_hardness[] = 
{
	"���म��� = %s ��. \n",
	"Hardness = %s mm. \n"
};

char *str_predicable_diameter_mark[] = 
{
	"������� �⯥�⪠ = %s ��. \n",
	"Diameter of mark = %s mm. \n"
};

char *str_warning[] = 
{
	"��������, ������� �⯥�⪠ �ॢ�蠥� ������� �ਬ��塞��� �������! \n",
	"Warning, diameter of mark exceed diameter used indentor! \n"
};

char *str_brinell_info[] = 
{
	"��⮤ ����७�� ��म�� �� �ਭ���� ���४⭮ ࠡ�⠥� ��� ���ਠ��� \
��म��� ������ �� �ਢ�蠥� 500 ������! \n",
	"Method metrology hardness of Brinell correct working for materials \
hardness who not exceed 500 unit! \n"
};

char *str_clean_list[] = 
{
	"��� ���⪨ ᯨ᪠ �।����� ����⮢ ������ ������� 'c'. \n",
	"For clean list predicable computations press key 'c'. \n"
};
char *str_return_predicable[] = 
{
	"��� ������ � �।���饥 ���� ������ ������� 'Esc'. \n",
	"For return to the predicable menu press key 'Esc'. \n"
};