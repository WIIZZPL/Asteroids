#pragma once

union ALLEGRO_EVENT;

/// Klasa bazowa innych scen.
class Scene {
private:

public:
	/// Funkcja wirtualna do zajêcia siê zdarzeniem.
	/// @param event referencja na zdarzenie ALLEGRO_EVENT do zarz¹dzenia.
	virtual void processInput(ALLEGRO_EVENT& event) = 0;
	/// Funkcja wirtualna do wykonania odœwierzenia sceny.
	/// @param dt krok czasu.
	virtual void update(double dt) = 0;
	/// Funkcja wirtualna do wyrenderowania sceny.
	/// @param lag opóŸnienie. S³u¿y do wyg³adzenia ruchu obiektów ruchomych.
	virtual void render(double lag) const = 0;
};