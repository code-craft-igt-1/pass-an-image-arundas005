#pragma once
#include <cstdint>
#include <stdexcept>
#include <random>
#include <memory>

struct Image {
	int rows;
	int columns;
	std::unique_ptr<uint8_t[]> pixels;

	Image(int _rows, int _columns): rows(_rows), columns(_columns), 
		                            pixels(std::make_unique<uint8_t[]>(_rows * _columns))
	{
		std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> distribution(0, 255);

		for (int index = 0; index < rows * columns; ++index)
		{
			pixels[index] = distribution(generator);
		}

	}
};

class ImageBrightener {
private:
	Image& m_inputImage;
public:
	ImageBrightener(Image& inputImage);
	int BrightenWholeImage();
	Image& GetImage();
};
