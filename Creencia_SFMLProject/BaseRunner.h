#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
class BaseRunner : private sf::NonCopyable
{
public:
	static const sf::Time	TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 720;

	BaseRunner();
	void run();

private:

	sf::RenderWindow		window;

	void render();
	void processEvents();
	void update(sf::Time elapsedTime);
};


