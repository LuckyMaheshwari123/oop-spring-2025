#include <iostream>
#include <string>
using namespace std;

// Movie class that stores details of each movie
class Movie {
private:
    string title;
    string director;
    int duration; // Duration in minutes

public:
    // Constructor to initialize movie details
    Movie(const string& t, const string& d, int dur)
        : title(t), director(d), duration(dur) {}

    // Function to display movie details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

// CinemaHall class that contains a list of movies being screened (composition relationship)
class CinemaHall {
private:
    string hallName;
    Movie** movies;  // Pointer to an array of pointers for movies
    int movieCount;  // Number of movies currently being screened

public:
    // Constructor to initialize the cinema hall's name and allocate memory for movies
    CinemaHall(const string& name, int count)
        : hallName(name), movieCount(count) {
        // Dynamically allocate memory for the list of movies
        movies = new Movie*[movieCount];
    }

    // Destructor to release dynamically allocated memory
    ~CinemaHall() {
        for (int i = 0; i < movieCount; ++i) {
            delete movies[i];  // Delete each movie object (composition)
        }
        delete[] movies;  // Delete the array of movie pointers
    }

    // Function to add a movie to the cinema hall's list of movies (in composition)
    void addMovie(int index, const string& title, const string& director, int duration) {
        if (index >= 0 && index < movieCount) {
            // Dynamically allocate memory for a new Movie object
            movies[index] = new Movie(title, director, duration);
        }
    }

    // Function to display details of the cinema hall and the movies being screened
    void displayCinemaDetails() const {
        cout << "Cinema Hall: " << hallName << endl;
        cout << "Currently Screening Movies: " << endl;

        if (movieCount == 0) {
            cout << "No movies are being screened currently." << endl;
        } else {
            for (int i = 0; i < movieCount; ++i) {
                movies[i]->displayDetails();
                cout << "-----------------------------" << endl;
            }
        }
    }
};

int main() {
    // Create a CinemaHall instance with 3 movies
    CinemaHall cinema("Cineplex", 3);

    // Add movies to the cinema hall
    cinema.addMovie(0, "The Dark Knight", "Christopher Nolan", 152);
    cinema.addMovie(1, "Inception", "Christopher Nolan", 148);
    cinema.addMovie(2, "Interstellar", "Christopher Nolan", 169);

    // Display cinema hall details
    cinema.displayCinemaDetails();

    return 0;
}
