#include "book.hpp"
#include "tools.hpp"

samoilenko::Book::Book():
  bookmarks_({{"current", notes_.begin()}})
{}

void samoilenko::Book::moveBookmark(const std::string& bookmark, const std::string& steps)
{
  if ((std::isdigit(steps[0]) && steps[0] != '0') || steps[0] == '-')
  {
    int temp = atoi(steps.c_str());
    std::advance(bookmarks_[bookmark], temp);
  }
  else if (steps[0] == '+')
  {
    int temp = atoi(steps.substr(1, steps.length() - 1).c_str());
    std::advance(bookmarks_[bookmark], temp);
  }
  else if (steps == "first")
  {
    bookmarks_[bookmark] = notes_.begin();
  }
  else if (steps == "last")
  {
    bookmarks_[bookmark] = --notes_.end();
  }
}

void samoilenko::Book::insertNoteBefore(const std::string& bookmark, const note_t& note)
{
  notes_.insert(bookmarks_[bookmark], note);
}

void samoilenko::Book::insertNoteAfter(const std::string& bookmark, const note_t& note)
{
  NoteContainer::iterator temp = bookmarks_[bookmark];
  notes_.insert(++temp, note);
}

void samoilenko::Book::deleteNote(const std::string& bookmark)
{
  auto it = bookmarks_[bookmark];
  if (it == --notes_.end())
  {
    for (auto&& i: bookmarks_)
    {
      if (i.second == it && i.first != bookmark)
      {
        bookmarks_[i.first] = notes_.begin();
      }
    }
    notes_.erase(bookmarks_[bookmark]);
    if (!isEmpty())
    {
      bookmarks_[bookmark] = notes_.begin();
    }
  }
  else
  {
    for (auto&& i: bookmarks_)
    {
      if (i.second == it && i.first != bookmark)
      {
        ++bookmarks_[i.first];
      }
    }
    bookmarks_[bookmark] = notes_.erase(bookmarks_[bookmark]);
  }
}

void samoilenko::Book::push_back(const note_t& note)
{
  NoteContainer::iterator temp = notes_.end();
  bool flag = isEmpty();
  notes_.push_back(note);
  if (flag)
  {
    bookmarks_["current"] = --temp;
  }
}

void samoilenko::Book::storeNote(const std::string& bookmark, const std::string& newBookmark)
{
  bookmarks_[newBookmark] = bookmarks_[bookmark];
}

bool samoilenko::Book::isEmpty() const
{
  return notes_.empty();
}

bool samoilenko::Book::isBookmarkExists(const std::string& bookmark) const
{
  auto it = bookmarks_.find(bookmark);
  return it != bookmarks_.end();
}

samoilenko::Book::MapIterator samoilenko::Book::getBookmark(const std::string& bookmark) const
{
  return bookmarks_.find(bookmark);
}

samoilenko::Book::MapIterator samoilenko::Book::getEnd() const
{
  return bookmarks_.end();
}
