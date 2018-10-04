#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Movie {
public:
  string name;
  float ranking;
  vector<Movie> related;

  /**
   * This operator overload is used to compare two movies and return
   * the greater one, based on their rankings. 
   * It's used by sort() function <line 75>
   * 
   * @param  Movie a
   * @param  Movie b
   * @return   True|False (Based on ranking)
   */
  bool operator () (const Movie& a, const Movie& b) {
    return a.ranking > b.ranking;
  }
};

/**
 * Reads all relations and create an structure like: 
 * Movie -> related [
 *   Movie -> related [ ... ],
 *   Movie -> related [ ... ],
 *   ...
 * ]
 *
 * @param  int n  number of related movies
 * @return   vector<Movie>  all movies related to an specific Movie
 */
vector<Movie> setRelated(int n) {
  vector<Movie> movies;
  int x;

  for (int i = 0; i < n; ++i) {
    Movie movie = Movie();
    cin >> movie.name >> movie.ranking >> x;

    movie.related = setRelated(x);

    movies.push_back(movie);
  }

  return movies;
}

vector<Movie> getTopRelatedMovies(Movie movie, int n) {
  vector<Movie> top_movies;

  stack<Movie> movies;
  movies.push(movie);

  while(!movies.empty()){
    movie = movies.top();
    movies.pop();

    cout << movie.name << endl;
    top_movies.push_back(movie);

    for (int i = 0; i < movie.related.size(); ++i){
      movies.push(movie.related[i]);
    }
  }

  // We need to sort all movies related from greater to smaller
  sort(top_movies.begin(), top_movies.end(), Movie());

  // We only need n movies, so we resize top_movies to keep the greatest
  top_movies.resize(n);

  return top_movies;
}

int main() {
  int n;
  Movie movie_seen = Movie(), movie = Movie();

  cin >> movie_seen.name >> movie_seen.ranking >> n;
  movie_seen.related = setRelated(n);

  cin >> n;
  vector<Movie> result = getTopRelatedMovies(movie_seen, n);
  for (int i = 0; i < result.size(); ++i) cout << result[i].name << ' ';

  return 0;
}