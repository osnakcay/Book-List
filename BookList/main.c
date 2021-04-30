#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Books
{
    char bookName[50];
    char authorName[50];
    char category[50];
    int publishingYear;
    int price;
};

void menu(){
    system("cls"); //This function clears the console. Use "clear" for Linux.
    printf("Welcome to the bookstore!\n----------------------------------\n\n");
    printf("1- Show Books\n2- Add Book\n9- Save and Quit\n");
    printf("\nPlease enter the code of the action you want to do: ");
}

void addBook(struct Books *book){
    int counter;
    for(counter = 0; counter < 50; counter++){
        if(book[counter].publishingYear == -1){
            break;}
    }
    printf("Book Name: ");
    scanf("%s",book[counter].bookName);
    printf("Author Name: ");
    scanf("%s",book[counter].authorName);
    printf("Category: ");
    scanf("%s",book[counter].category);
    printf("Publishing Year: ");
    scanf("%d",&(book[counter].publishingYear));
    printf("Price: ");
    scanf("%d",&(book[counter].price));

    book[counter+1].publishingYear = -1;
    printf("Book successfully added!");

}

void printBooks(struct Books *book){
    int counter;
    for(counter = 0; counter < 50; counter++){
        if(book[counter].publishingYear == -1){
            break;}
        printf("%d- %25s %15s %15s %4d %d$\n",counter+1, book[counter].bookName, book[counter].authorName, book[counter].category, book[counter].publishingYear, book[counter].price);
    }
}

void save(struct Books *book){
    FILE *target_file = fopen("booksDatabase.txt","w+");

    int counter;
    for(counter = 0; counter < 50; counter++){
        if(book[counter].publishingYear == -1){
            break;}
        fprintf(target_file,"%s %s %s %d %d$\n",book[counter].bookName, book[counter].authorName, book[counter].category, book[counter].publishingYear, book[counter].price);
    }

    fclose(target_file);
}

void printFromFile(struct Books *book){
    FILE *target_file = fopen("booksDatabase.txt","r+");
    if(target_file == NULL){
        return;
    }
    int counter;
    for(counter = 0; counter < 50; counter++){
        fscanf(target_file,"%s %s %s %d %d\n",book[counter].bookName, book[counter].authorName, book[counter].category, &(book[counter].publishingYear), &(book[counter].price));
        if(feof(target_file)){
            break;
        }
    }
    book[counter+1].publishingYear = -1;

    fclose(target_file);
}

int main()
{
    int choice, flag = 0;
    struct Books book[50];
    book[0].publishingYear = -1;
    printFromFile(book);

    while(flag == 0){
        menu();
        scanf("%d",&choice);

        switch(choice){
    case 1:
        printBooks(book);
        break;
    case 2:
        addBook(book);
        break;
    case 9:
        flag = 1;
        save(book);
        printf("Press a enter to quit...\n");
        break;
    default:
        printf("Please make the right choice...\n");
        }
        getch(); //This function prevents the program from ending immediately. It asks us to press a key before ending the program.
    }


    return 0;
}
