#pragma once

#include "Object.h"

struct ALLEGRO_FONT;

/// <summary>
/// Klasa przycisku. Wykorzystywana jako czêœæ UI. Kolor obramowania i tekstu jest bia³y, t³a czarny.
/// </summary>
class Button : public Object{
private:
	const ALLEGRO_COLOR fillColour = al_map_rgb(0, 0, 0);
	const ALLEGRO_COLOR textColour = al_map_rgb(255, 255, 255);
	const ALLEGRO_FONT* font;
	const char* str;

public:
	/// <summary>
	/// Konstruktor klasy.
	/// </summary>
	/// <param name="P"> Pozycja przycisku, wedle jego œrodka.</param>
	/// <param name="D"> Rozmiar przycisku, szerokoœæ i wysokoœæ.</param>
	/// <param name="font"> WskaŸnik na font do wykorzystania.</param>
	/// <param name="str"> String z tekstem do wypisania.</param>
	Button(Vector2D P, Vector2D D, const ALLEGRO_FONT* font, const char str[]);
	~Button();
	/// <summary>
	/// Renderuje przycisk.
	/// </summary>
	void render() const;
};

