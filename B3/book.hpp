#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <list>
#include <map>

namespace samoilenko
{
  class Book
  {
  public:
    struct note_t
    {
      std::string number;
      std::string name;
    };
    using NoteContainer = std::list< note_t >;
    using MapIterator = std::map< std::string, samoilenko::Book::NoteContainer::iterator >::const_iterator;
    Book();
    void moveBookmark(const std::string& bookmark, const std::string& steps);
    void insertNoteBefore(const std::string& bookmark, const note_t& note);
    void insertNoteAfter(const std::string& bookmark, const note_t& note);
    void deleteNote(const std::string& bookmark);
    void push_back(const note_t& note);
    void storeNote(const std::string& bookmark, const std::string& newBookmark);
    bool isEmpty() const;
    bool isBookmarkExists(const std::string& bookmark) const;
    MapIterator getBookmark(const std::string& bookmark) const;
    MapIterator getEnd() const;
  private:
    std::map< std::string, NoteContainer::iterator > bookmarks_;
    NoteContainer notes_;
  };
}

#endif
