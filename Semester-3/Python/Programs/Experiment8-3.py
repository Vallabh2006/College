class Book:

    book_data = [
        [101, "Harry Potter", "J.K. Rowling"],
        [102, "The Hobbit", "J.R.R. Tolkien"],
        [103, "1984", "George Orwell"],
        [104, "The Alchemist", "Paulo Coelho"],
        [105, "The Great Gatsby", "F. Scott Fitzgerald"],
        [106, "To Kill a Mockingbird", "Harper Lee"],
        [107, "Pride and Prejudice", "Jane Austen"],
        [108, "The Catcher in the Rye", "J.D. Salinger"],
        [109, "The Lord of the Rings", "J.R.R. Tolkien"],
        [110, "Animal Farm", "George Orwell"]
    ]

    def display(self, book):
        print("\nBook Details:")
        print("Book ID:", book[0])
        print("Title:", book[1])
        print("Author:", book[2])

    def searchBook(self, id):
        for book in self.book_data:
            if book[0] == id:
                self.display(book)
                return

        print("\nBook not found.")


books = Book()

num = int(input("\nEnter Book ID (101-110): "))

books.searchBook(num)

print()