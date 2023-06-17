#pragma once

union ALLEGRO_EVENT;

/// Klasa bazowa innych scen.
class Scene {
private:

public:
	/// Funkcja wirtualna do zaj�cia si� zdarzeniem.
	/// @param event referencja na zdarzenie ALLEGRO_EVENT do zarz�dzenia.
	virtual void processInput(ALLEGRO_EVENT& event) = 0;
	/// Funkcja wirtualna do wykonania od�wierzenia sceny.
	/// @param dt krok czasu.
	virtual void update(double dt) = 0;
	/// Funkcja wirtualna do wyrenderowania sceny.
	/// @param lag op�nienie. S�u�y do wyg�adzenia ruchu obiekt�w ruchomych.
	virtual void render(double lag) const = 0;
};