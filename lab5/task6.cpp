#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;         
    string director;     
    int duration;        

public:
   
    Movie(string t, string d, int dur) : title(t), director(d), duration(dur) {}

   
    void displayDetails()  {
        cout << "Movie Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

class CinemaHall {
private:
    Movie* movies;      
    int totalMovies;    
    int capacity;        

public:
   
    CinemaHall(int cap) : totalMovies(0), capacity(cap) {
        movies = new Movie[capacity];  
    }

   
    ~CinemaHall() {
        delete[] movies;  
    }

    
    void addMovie(const string& title, const string& director, int duration) {
        if (totalMovies < capacity) {
            movies[totalMovies] = Movie(title, director, duration); 
            totalMovies++;
        } else {
            cout << "Cinema Hall capacity reached. Cannot add more movies." << endl;
        }
    }

    
    void displayCinemaHallDetails() const {
        cout << "Cinema Hall Details:" << endl;
        cout << "Total Movies: " << totalMovies << endl;
        for (int i = 0; i < totalMovies; i++) {
            cout << "Movie " << (i + 1) << " details:" << endl;
            movies[i].displayDetails(); 
            cout << "-----------------------------" << endl;
        }
    }
};

int main() {
   
    CinemaHall hall(3);


    hall.addMovie("DDLJ", "Karan Johar", 148);
    hall.addMovie("3 idiot", "Raj Kumar Hirani", 136);
    hall.addMovie("Jawan", "Atlee", 169);


    hall.displayCinemaHallDetails();

    return 0;
}
