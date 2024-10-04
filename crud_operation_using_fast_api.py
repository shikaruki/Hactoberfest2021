from fastapi import FastAPI
from pydantic import BaseModel, EmailStr
import json

app = FastAPI()

book_ = [
    {"title": "Title one", "author": "Author One", "category": "science"},
    {"title": "Title two", "author": "Author two", "category": "physics"},
    {"title": "Title three", "author": "Author three", "category": "biology"},
    {"title": "Title four", "author": "Author four", "category": "chesmetry"},
    {"title": "Title five", "author": "Author six", "category": "science"},
    {"title": "Title six", "author": "Author six", "category": "ccc"},
]


class Books(BaseModel):
    title: str
    author: str
    category: str


BOOKS_ = [Book(**data) for data in book_]


@app.get("/books")
async def read_All_books_():
    return BOOKS_


@app.get("/books/mybook")
async def read_all_books_():
    return {"book_title": "my favourate book !"}


@app.get("/books/{book_title}")
async def read_book_(book_title: str):
    for book in BOOKS_:
        if book.title.casefold() == book_title.casefold():
            return book
    return {"Unable to find Book with title ": book_title}


@app.get("/books/")
async def read_category_by_query_(category: str):
    books_to_return = []
    for book in BOOKS_:
        if book.title.casefold() == category.casefold():
            books_to_return.append(book)
    return books_to_return


@app.post("/books/create_book")
async def create_book_(new_book: Book):
    BOOKS.append(new_book)
    return "Book created !"


@app.put("/books/update_book")
async def update_book_(updated_book: Book):
    for i in range(len(BOOKS)):
        if BOOKS[i].title.casefold() == updated_book.title.casefold():
            BOOKS[i] = updated_book
            return "Update completed"


@app.delete("/books/delete_book/{book_title}")
async def delete_book_(book_title: str):
    for i in range(len(BOOKS)):
        if BOOKS_[i].title.casefold() == book_title.casefold():
            BOOKS_.pop(i)
            return f"Book with {book_title} deleted successfully !"


