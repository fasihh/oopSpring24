#include <iostream>

using namespace std;

class Movie {
private:
    string title, director;
    int duration;
public:
    Movie(const string& _title = "", const string& _director = "", int _duration = 0) 
        : title(_title), director(_director), duration(_duration) {}

    const string& getTitle() const { return title; }
    const string& getDirector() const { return director; }
    const int getDuration() const { return duration; }
};

class Playlist {
private:
    string name;
    Movie *movies;
    int numMovies;
public:
    Playlist(const string& _name = "") : name(_name), numMovies(0), movies(nullptr) {}

    void addMovie(Movie *movie) {
        Movie *new_movies = new Movie[numMovies+1];
        new_movies[numMovies] = *movie;

        for (int i = 0; i < numMovies; i++)
            new_movies[i] = movies[i];
        
        delete[] movies;
        movies = new_movies;
        numMovies++;
    }

    void removeMovie(Movie *movie) {
        Movie *new_movies = new Movie[numMovies-1];

        for (int i = 0, j = 0; i < numMovies; i++, j++) {
            if (movies[i].getTitle() == movie->getTitle()) {
                i++;
                continue;
            }
            new_movies[j] = movies[i];
        }

        delete[] movies;
        movies = new_movies;
        numMovies--;
    }

    void displayInfo() const {
        cout << "Playlist: " << name << "\nTracks: " << numMovies << "\n";
        for (int i = 0; i < numMovies; i++) {
            cout << "Movie #" << i+1 << "\n";
            cout << "Title: " << movies[i].getTitle() << "\n";
            cout << "Director: " << movies[i].getDirector() << "\n";
            cout << "Duration: " << movies[i].getDuration() << "\n\n";
        }
    }
};

class User {
private:
    string name;
    Playlist *playlists;
    int numPlaylists;
public:
    User(const string& _name) : name(_name), playlists(nullptr), numPlaylists(0) {}

    void createPlaylist(const string& playlistName) {
        Playlist *new_playlists = new Playlist[numPlaylists+1];
        new_playlists[numPlaylists] = Playlist(playlistName);

        for (int i = 0; i < numPlaylists; i++)
            new_playlists[i] = playlists[i];
        
        delete[] playlists;
        playlists = new_playlists;
        numPlaylists++;
    }

    void addMovieToPlaylist(Playlist *playlist, Movie *movie) {
        for (int i = 0; i < numPlaylists; i++)
            if (&playlists[i] == playlist) playlists[i].addMovie(movie);
    }

    void removeMovieFromPlaylist(Playlist *playlist, Movie *movie) {
        for (int i = 0; i < numPlaylists; i++)
            if (&playlists[i] == playlist) playlists[i].removeMovie(movie);
    }

    void displayUserPlaylists() const {
        for (int i = 0; i < numPlaylists; i++) {
            cout << "Playlist #" << i+1 << endl;
            playlists[i].displayInfo();
        }
    }
};

int main() {
    User user("Fasih");

    user.createPlaylist("Action Movies");
    user.createPlaylist("Comedy Movies");

    // goofy aaa question
    // uses string to create movies. can't even access it
    // WHAT

    return 0;
}