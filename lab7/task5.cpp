#include <iostream>
using namespace std;

class Media
{
private:
  string title, publicationDate, publisher;
  static int globalID;
  int id;

public:
  Media(string t, string pd, string ps) : title(t), publicationDate(pd), publisher(ps)
  {
    id = ++globalID;
  }

  virtual void DisplayInfo()
  {
    cout << "Name: " << title << endl;
    cout << "Publication Date: " << publicationDate << endl;
    cout << "Publisher Name: " << publisher << endl;
    cout << "ID of Media: " << id << endl;
  }

  void CheckOut() { cout << "The process of lending is happening." << endl; }
  void ReturnItem() { cout << "The request to return the item has been received." << endl; }

  string getTitle() { return title; }
  string getPublicationDate() { return publicationDate; }
  string getPublisher() { return publisher; }
};

int Media::globalID = 0;

class Book : public Media
{
private:
  string author, ISBN, numberOfPages;

public:
  Book(string t, string pd, string ps, string a, string isbn, string pages)
      : Media(t, pd, ps), author(a), ISBN(isbn), numberOfPages(pages) {}

  void DisplayInfo() override
  {
    Media::DisplayInfo();
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Number of Pages: " << numberOfPages << endl;
  }
};

class CD : public Media
{
private:
  string artist, numberOfTracks, genre;

public:
  CD(string t, string pd, string ps, string a, string tracks, string g)
      : Media(t, pd, ps), artist(a), numberOfTracks(tracks), genre(g) {}

  void DisplayInfo() override
  {
    Media::DisplayInfo();
    cout << "Artist: " << artist << endl;
    cout << "Number of Tracks: " << numberOfTracks << endl;
    cout << "Genre: " << genre << endl;
  }
};

class DVD : public Media
{
private:
  string director, duration, rating;

public:
  DVD(string t, string pd, string ps, string d, string dur, string r)
      : Media(t, pd, ps), director(d), duration(dur), rating(r) {}

  void DisplayInfo() override
  {
    Media::DisplayInfo();
    cout << "Director: " << director << endl;
    cout << "Duration: " << duration << endl;
    cout << "Rating: " << rating << endl;
  }
};

class Magazine : public Media
{
public:
  Magazine(string t, string pd, string ps) : Media(t, pd, ps) {}

  void DisplayInfo() override
  {
    Media::DisplayInfo();
    cout << "This is a magazine." << endl;
  }
};

void SearchMedia(Media *list[], int size, string title)
{
  cout << "Searching for title: " << title << endl;
  for (int i = 0; i < size; i++)
  {
    if (list[i]->getTitle() == title)
    {
      list[i]->DisplayInfo();
      return;
    }
  }
  cout << "Title not found." << endl;
}

void SearchMediaByDate(Media *list[], int size, string date)
{
  cout << "Searching for date: " << date << endl;
  for (int i = 0; i < size; i++)
  {
    if (list[i]->getPublicationDate() == date)
    {
      list[i]->DisplayInfo();
      return;
    }
  }
  cout << "Date not found." << endl;
}

void SearchMediaByPublisher(Media *list[], int size, string publisher)
{
  cout << "Searching for publisher: " << publisher << endl;
  for (int i = 0; i < size; i++)
  {
    if (list[i]->getPublisher() == publisher)
    {
      list[i]->DisplayInfo();
      return;
    }
  }
  cout << "Publisher not found." << endl;
}

int main()
{
  Media *list[3];
  list[0] = new Book("The code", "1991", "Harry", "Pinkaj", "988-00628815007", "128");
  list[1] = new CD("Thrive", "1781", "records", "Michael warne", "9", "lyric");
  list[2] = new DVD("Insects", "2019", "shen bond.", "Columbus", "158 minutes", "Ps-12");
  SearchMedia(list, 3, "The code");
  SearchMediaByDate(list, 3, "1982");
  SearchMediaByPublisher(list, 3, "Micheal warne.");
  for (int i = 0; i < 3; i++)
  {
    delete list[i];
  }
}
