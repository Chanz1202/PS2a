#include "Universe.hpp"

int main(int argc, char* argv[])
{
  std::string num_of_planets, radius;

  // Use cin to redirect the input
  std::cin >> num_of_planets;
  std::cin >> radius;

  int number_planets = atoi(num_of_planets.c_str());
  float universe_radius = atof(radius.c_str());

  std::cout << "Number of planets: " << number_planets << std::endl;
  std::cout << "Radius of universe: " << universe_radius << std::endl << std::endl;

  // create a vector of Universe objects
  std::vector<Universe> Universe_vector;

  // loop for creating Universe objects using the input file.
  for(int i = 0; i < number_planets; i++)
  {
    // to create a new object
    Universe* temp = new Universe();

    // read input to the object
    std::cin >> *temp;

    // to set the radius and planet positions
    temp->set_radius(universe_radius);
    temp->set_position();

    // save the object to the vector
    Universe_vector.push_back(*temp);

    std::cout << *temp;
  }

  // SFML Window
  sf::RenderWindow window(sf::VideoMode(500, 400), "The Solar System");
  
  window.setFramerateLimit(1);

  sf::Image background_image;

  if (!background_image.loadFromFile("universe.jpg"))
  {
      // quits if file doesn't exist  
    return -1;    
  }

  // load the image into a texture
  sf::Texture background_texture;
  background_texture.loadFromImage(background_image);

  // load the texture into a sprie
  sf::Sprite background_sprite;
  background_sprite.setTexture(background_texture);

  // sets the posiion of background image
  background_sprite.setPosition(sf::Vector2f(0, 0));

  // window loop
  while (window.isOpen())
  {
  
    sf::Event event;

    while(window.pollEvent(event))
    {
  
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window.close();
      }
    }

    window.clear();

    // display the given background
    window.draw(background_sprite);

    // display the vector of objects
    std::vector<Universe>::iterator i;

    for(i = Universe_vector.begin(); i != Universe_vector.end(); i++)
    {
      window.draw(*i);
    }
    window.display();
  }

  return 0;
}
