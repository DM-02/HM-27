//
//  main.cpp
//  HM-27
//
//  Created by Дмитрий Сергеевич on 20.10.2023.
//

#include <iostream>
#include <string>


struct Movie {
    std::string title;
    int year;
    std::string genre;
    unsigned int duration;
    unsigned int price;
};

void print_movie(Movie movie){
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Year: " << movie.year << std::endl;
    std::cout << "Genre: " << movie.genre << std::endl;
    std::cout << "Duration: " << movie.duration << " minutes" << std::endl;
    std::cout << "Price: $" << movie.price << std::endl;
}

Movie expensive(Movie movies[], int length){
    Movie maxPriceMovie = movies[0];
    for (int i = 1; i < length; i++) {
        if (movies[i].price > maxPriceMovie.price) {
            maxPriceMovie = movies[i];
        }
    }  return maxPriceMovie;
}

void update_info(Movie& movie) {
    std::cout << "Enter new title: ";
    getline(std::cin, movie.title);
    std::cout << "Enter new genre: ";
    getline(std::cin, movie.genre);
    std::cout << "Enter new year: ";
    std::cin >> movie.year;
    std::cout << "Enter new duration: ";
    std::cin >> movie.duration;
    std::cout << "Enter new price: ";
    std::cin >> movie.price;
}

int main(int argc, const char * argv[]) {
    
    Movie movie;
    movie.title = "Green Mile";
    movie.year = 1999;
    movie.genre = "drama, fantasy, crime";
    movie.duration = 189;
    movie.price = 10;
    
    print_movie(movie);
    
    Movie movies[3];
    for (int i = 0; i < 3; i++) {
        std::cout << "Enter movie title: ";
        getline(std::cin, movies[i].title);
        std::cout << "Enter movie genre: ";
        getline(std::cin, movies[i].genre);
        std::cout << "Enter movie year: ";
        std::cin >> movies[i].year;
        std::cout << "Enter movie duration: ";
        std::cin >> movies[i].duration;
        std::cout << "Enter movie price: ";
        std::cin >> movies[i].price;
        std::cin.ignore();
    }
    
    std::cout << "Movies Information:" << std::endl;
    for (int i = 0; i < 3; i++){
        print_movie(movies[i]);
        std::cout << std::endl;
    }
    
    Movie maxPriceMovie = expensive(movies, 3);
    std::cout << "Movie with highest price:" << std::endl;
    print_movie(maxPriceMovie);
    int movieIndex;
    std:: cout << "Enter the index of the movie to update: ";
    std::cin >> movieIndex;
    std::cin.ignore();
    
    std::cout << "Updated movie information:" << std::endl;
    print_movie(movies[movieIndex]);
        
    
        
        
        
    return 0;
}


