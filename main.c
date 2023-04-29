
#include "phone_book.c"

int main(void)
{
	PhoneBook *phoneBook;

	int entries;
	char op;
	entries = 0;
	phoneBook = (PhoneBook *)malloc(sizeof(PhoneBook));
	if (phoneBook == NULL)
	{
		printf("\nErro de alocacao de memoria.");
		exit(1);
	}

	do
	{
		fflush(stdin);
		printf("\nq - Load");
		printf("\nw - Save");
		printf("\na - Add");
		printf("\nc - Change");
		printf("\nl - Look up");
		printf("\nr - Remove");
		printf("\ns - Search");
		printf("\ne - Exit\n");
		scanf(" %c", &op);

		switch (op)
		{
		case 'q':
			break;
			FILE *fr = fopen("calendar.cal", "rb+");
			if (!fr)
			{
				fprintf(stderr, "Could not find your calendar\n");
				break;
			}
			fread(&phoneBook[0], sizeof(PhoneBook), 1, fr);
			printf("\nYour calendar has been loaded!");
			break;
		case 'w':
			fflush(stdin);
			FILE *f = fopen("calendar.cal", "wb+");
			if (!f)
			{
				fprintf(stderr, "Could not save your calendar\n");
				break;
			}
			fwrite(&phoneBook[0], sizeof(PhoneBook), 1, f);
			printf("\nCalendar saved to calendar.bin!");
			break;
		case 'a':
			fflush(stdin);

			pbook_alloc(&phoneBook, &entries);
			printf("!!!!! Add !!!!!");

			printf("\n\tType the entry name:");
			scanf("%s", &phoneBook[entries].name);
			fflush(stdin);

			printf("\n\tType the email:");
			scanf("%s", &phoneBook[entries].email);
			fflush(stdin);

			printf("\n\tType the phone number:");
			scanf("%d", &phoneBook[entries].phone_num);
			fflush(stdin);

			entries++;
			break;
		case 'c':
			change(phoneBook, entries);
			break;
		case 'l':
			sort(phoneBook, 0, entries - 1);
			look_up(phoneBook, entries);
			break;
		case 'r':
			sort(phoneBook, 0, entries - 1);
			pbook_remove(&phoneBook, &entries);
			break;
		case 's':
			sort(phoneBook, 0, entries - 1);
			search(phoneBook, entries);
			break;
		case 'e':
			return 0;
		default:
			break;
		}

	} while (op != 'e');
}