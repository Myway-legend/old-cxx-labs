#include "bookUserInterface.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include "tools.hpp"

namespace samoilenko
{
  void add(Book& book, const std::string& number, const std::string& name, std::ostream& out)
  {
    if (isNumberValid(number) && isNameValid(name))
    {
      book.push_back({ number, removeSlashes(name).substr(1, name.length() - 2) });
    }
    else
    {
      out << INVALID_COMMAND;
    }
  }

  void store(Book& book, const std::string& bookmark, const std::string& newBookmark, std::ostream& out)
  {
    if (book.isBookmarkExists(bookmark) && !book.isBookmarkExists(newBookmark))
    {
      book.storeNote(bookmark, newBookmark);
    }
    else
    {
      out << INVALID_BOOKMARK;
    }
  }

  void insertBefore(Book& book, const std::string& bookmark, const std::string& number, const std::string& name, std::ostream& out)
  {
    bool bookmarkExist = book.isBookmarkExists(bookmark);
    bool numberValid = isNumberValid(number);
    bool nameValid = isNameValid(name);
    if (bookmarkExist && numberValid && nameValid && !book.isEmpty())
    {
      book.insertNoteBefore(bookmark, { number, name.substr(1, name.length() - 2) });
    }
    else if (book.isEmpty())
    {
      add(book, number, name, out);
    }
    else if (!bookmarkExist)
    {
      out << INVALID_BOOKMARK;
    }
    else
    {
      out << INVALID_COMMAND;
    }
  }

  void insertAfter(Book& book, const std::string& bookmark, const std::string& number, const std::string& name, std::ostream& out)
  {
    bool bookmarkExist = book.isBookmarkExists(bookmark);
    bool numberValid = isNumberValid(number);
    bool nameValid = isNameValid(name);
    if (bookmarkExist && numberValid && nameValid && !book.isEmpty())
    {
      book.insertNoteAfter(bookmark, { number, name.substr(1, name.length() - 2) });
    }
    else if (book.isEmpty())
    {
      add(book, number, name, out);
    }
    else if (!bookmarkExist)
    {
      out << INVALID_BOOKMARK;
    }
    else
    {
      out << INVALID_COMMAND;
    }
  }

  void deleteNote(Book& book, const std::string& bookmark, std::ostream& out)
  {
    if (book.isBookmarkExists(bookmark))
    {
      book.deleteNote(bookmark);
    }
    else
    {
      out << INVALID_BOOKMARK;
    }
  }

  void show(Book& book, const std::string& bookmark, std::ostream& out)
  {
    if (!book.isBookmarkExists(bookmark))
    {
      out << INVALID_BOOKMARK;
    }
    else if (book.isBookmarkExists(bookmark) && !book.isEmpty())
    {
      auto temp = book.getBookmark(bookmark);
      if (temp != book.getEnd())
      {
        out << temp->second->number << ' ' << temp->second->name << '\n';
      }
    }
    else if (book.isEmpty())
    {
      out << EMPTY;
    }
  }

  void move(Book& book, const std::string& bookmark, const std::string& steps, std::ostream& out)
  {
    bool bookmarkValid = book.isBookmarkExists(bookmark);
    bool first = steps == "first";
    bool last = steps == "last";
    bool plus = steps[0] == '+';
    bool minus = steps[0] == '-';
    bool zero = steps[0] == '0';
    if (bookmarkValid && ((std::isdigit(steps[0]) && !zero) || minus || plus || first || last))
    {
      book.moveBookmark(bookmark, steps);
    }
    else if (!bookmarkValid)
    {
      out << INVALID_BOOKMARK;
    }
    else
    {
      out << INVALID_STEP;
    }
  }

}

int samoilenko::executeUserInterface(Book& book, std::vector< std::string >& args, std::ostream& out)
{
  int count = args.size();
  if (args[0] == "add" && count == 3)
  {
    add(book, args[1], args[2], out);
    return 0;
  }
  else if (args[0] == "store" && count == 3)
  {
    store(book, args[1], args[2], out);
    return 0;
  }
  else if (args[0] == "insert" && count == 5)
  {
    if (args[1] == "before")
    {
      insertBefore(book, args[2], args[3], args[4], out);
      return 0;
    }
    else if (args[1] == "after")
    {
      insertAfter(book, args[2], args[3], args[4], out);
      return 0;
    }
    else
    {
      out << INVALID_COMMAND;
      return 2;
    }
  }
  else if (args[0] == "delete" && count == 2)
  {
    deleteNote(book, args[1], out);
    return 0;
  }
  else if (args[0] == "show" && count == 2)
  {
    show(book, args[1], out);
    return 0;
  }
  else if (args[0] == "move" && count == 3)
  {
    move(book, args[1], args[2], out);
    return 0;
  }
  else
  {
    out << INVALID_COMMAND;
    return 2;
  }
  return 2;
}
