# Book-List
A simple book list maker
# The Purpose
This program creates a simple book list using the C language.
# How to use
There are 3 options in the menu:
- Show Books
- Add Book
- Save and Quit
- The book is added to the list with the "Add Book" option.
- The "Show Books" option shows the books in your list that are saved in your "booksDatabase.txt" file.
- The "Save and Quit" option saves the books you added to the "booksDatabase.txt" file and closes the program.
# Listed book information are:
- Book title
- Author name
- Book category
- Release date
- Price
# Generated Functions
- menu();
- addBook(struct Books *book);
- printBooks(struct Books *book);
- save(struct Books *book);
- printFromFile(struct Books *book);
