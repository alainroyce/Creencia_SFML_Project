#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
class BaseRunner : private sf::NonCopyable
{
public:
	static const sf::Time	TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 1920;
	static const int WINDOW_HEIGHT = 1080;

	BaseRunner();
	void run();

private:
	sf::Texture logoTexture;
	sf::Sprite logo;
	sf::Vector2f velocity;
	sf::RenderWindow		window;
	sf::Sprite cdSprite;
	sf::Texture cdTexture;
	void render();
	void processEvents();
	void update(sf::Time elapsedTime);

	int displayValue = 0;
	int digits[4] = { 0 }; // Array to store individual digits of the displayValue

	// Other members of the class...

	// Function to update the display value and rotate the digits
	void updateDisplay(int number);

	// SFML Text object for displaying the digits
	sf::Text displayText;
};


