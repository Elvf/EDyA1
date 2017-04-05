#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTACTS 50

typedef struct {
  char name[100];
  char phone[100];
  unsigned int age;
} contact;

typedef struct {
  contact list[50];
  unsigned int size;
} contactList;

void updateAge (contact *a) {
	printf("Set a new age for the contact: ");
	scanf("%ud", &(a->age));
}

contact createContact (void) {
	contact newContact;
  
  printf("Name: ");
  scanf("%s", newContact.name);
  
  printf("Phone: ");
  scanf("%s", newContact.phone);
  
  printf("Age: ");
  scanf("%ud", &newContact.age);
  
  return newContact;
}

void printContacts (contactList phoneBook) {
  int i = 0;
  
  for (; i < phoneBook.size; i++) {
    printf("[CONTACT %d]\n", i);
    printf("Name: %s", phoneBook.list[i].name);
    printf(" | Phone: %s", phoneBook.list[i].phone);
    printf(" | Age: %u", phoneBook.list[i].age);
    printf("\n");
  }
  
  printf("\n");
}

int main (void) {
  contactList phoneBook;
  int selector, contactSelector;
  
  /* We initialize the phone book for the execution */
  phoneBook.size = 0;
  
  while (1 == 1) {
    printf("CONTACTS MENU\nType the number of the option you want to perform.\n");
    printf(" [1] Add a new contact\n [2] Update a contact's age\n [3] View all contacts\n [4] Exit\n\n");
    printf("Type the number here: ");
    
    /* Scan for user input */
    scanf("%d", &selector);
    
    /* Use a switch/case for options */
    switch (selector) {
      case 1: /* Add a new contact */
        if (phoneBook.size < MAX_CONTACTS) {
          phoneBook.list[phoneBook.size] = createContact();
          phoneBook.size++;
          printf("Contact has been successfully created.\n\n");
        } else {
          printf("The current phone book is full!\n\n");
        }
        break;
        
      case 2: /* Update Age */
        printf("There are %u available contacts. Select a contact (starting from 0) to update the age: ", phoneBook.size);
        scanf("%d", &contactSelector);
        
        if (contactSelector > phoneBook.size) {
          printf("ERROR: The number can't be greater to the amount of contacts.\n\n");
        } else {
          updateAge(&phoneBook.list[contactSelector]);
          printf("Age was updated successfully!\n\n");
        }
        break;
      
      case 3: /* View contacts */
        printContacts(phoneBook);
        break;
      
      case 4: /* Exit */
        return 0;
        break;
        
      default:
        printf("Sorry, the option you selected is invalid.\n\n");
    }
  }
  
  return 0;
}
