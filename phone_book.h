typedef struct PhoneBook
{
char name[40];
char email[40];
int phone_num;	
} PhoneBook;

void pbook_alloc( PhoneBook **pBook, int *piEntries );
void look_up(PhoneBook *pBook, int iEntries);
void sort(PhoneBook book[],  int left, int right );

void pbook_remove(PhoneBook **pBook, int *piEntries);
void search(PhoneBook *pBook, int iEntries);
void change(PhoneBook *pBook, int iEntries);