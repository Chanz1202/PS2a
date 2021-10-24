#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// window size constructing
const int window_height = 500;
const int window_side = 500;

class Universe: public sf::Drawable
{
public:

  // constructors
  Universe();
  Universe(double pos_x, double pos_y, double vel_x, double vel_y, double obj_mass, double radius, std::string file_name);

  void set_radius(float radius);
  //sets the position of planet
  void set_position();          

  // overiding operator to take input from a file
  friend std::istream& operator>> (std::istream &input, Universe &CelestialUniverse);

  // overriddden operator for debugging
  friend std::ostream& operator<< (std::ostream &output, Universe &CelestialUniverse);

private:

  // draw() method
  void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

  // member variables
  double _pos_x, _pos_y;
  double _vel_x, _vel_y;
  double _mass;
  double _radius;
  std::string _filename;

  // image related objects
  sf::Image _image;
  sf::Sprite _sprite;
  sf::Texture _texture;
};
