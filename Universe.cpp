#include "Universe.hpp"

Universe::Universe()
{

  // does nothing
  return;
}

// constructor with parameters
Universe::Universe(double pos_x, double pos_y, double vel_x, double vel_y,
           double obj_mass, double radius, std::string file_name)
{
  // member variables
  _pos_x = pos_x;
  _pos_y = pos_y;
  _vel_x = vel_x;
  _vel_y = vel_y;
  _mass = obj_mass;
  _filename = file_name;

  // load the image into an image object
  if (!_image.loadFromFile(file_name))
  {
  
   // quits if the file doesn't exist
    return;    
  }

  // load the image into a texture
  _texture.loadFromImage(_image);

  // load the texture into a sprite
  _sprite.setTexture(_texture);

  // to set the position from the Vector2f for position
  _sprite.setPosition(sf::Vector2f(_pos_x, _pos_y));
}

// to set universe radius
void Universe::set_radius(float radius)
{
  _radius = radius;
  return;
}

// to set the planets position
void Universe::set_position()
{

  // adjusting position for planets to fit in SFML window
  _pos_x = ( (_pos_x / _radius) * (window_side / 2) ) + (window_side / 2);
  _pos_y = ( (_pos_y / _radius) * (window_height / 2) ) + (window_height / 2);

  // to set the position from the Vector2f for position
  _sprite.setPosition(sf::Vector2f(_pos_x, _pos_y));
}

// draw() method
void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(_sprite);
}

// overridden operator to take input from a file
std::istream& operator>> (std::istream &input, Universe &CelestialUniverse)
{
  // reads input into object
  input >> CelestialUniverse._pos_x >> CelestialUniverse._pos_y;
  input >> CelestialUniverse._vel_y >> CelestialUniverse._vel_y;
  input >> CelestialUniverse._mass  >> CelestialUniverse._filename;

  // load the image into an image object
  if (!CelestialUniverse._image.loadFromFile(CelestialUniverse._filename))
  {
  	// quits if the file doesn't exist
    return input;    
  }

  // load the image into a texture
  CelestialUniverse._texture.loadFromImage(CelestialUniverse._image);

  // load the texture into a sprite
  CelestialUniverse._sprite.setTexture(CelestialUniverse._texture);

  // to set initial position
  CelestialUniverse._sprite.setPosition(sf::Vector2f(CelestialUniverse._pos_x, CelestialUniverse._pos_y));

  return input;
}


// overriddden operator for debugging

std::ostream& operator<< (std::ostream &output, Universe &CelestialUniverse)
{
  // For debugging, output all the data stored in the object.
  output << "Filename: " << CelestialUniverse._filename << std::endl;
  output << "Pos (x): " << CelestialUniverse._pos_x << std::endl;
  output << "Pos (y): " << CelestialUniverse._pos_y << std::endl;
  output << "Vel (x): " << CelestialUniverse._vel_x << std::endl;
  output << "Vel (y): " << CelestialUniverse._vel_y << std::endl;
  output << "Mass: " << CelestialUniverse._mass << std::endl << std::endl;

  return output;
}
