#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace sf; 

int vm_x = 1000, vm_y = 100;

RenderWindow window(VideoMode(vm_x, vm_y), "Catinitsa", Style::Default);

void cat(char a, int aA,int poz) {

	ifstream letter;//файл в котором хранятся колличество и точки отрезков
	string b("alphabet/_.letter");//cсылка на файл
	b[9] = a;//вставляет в ссылку на файл нужный симвл
	int vekters , sm = 0, big = 10;//big отвечает за размер фигуры, sm за смещение по оси y
	float  x0, y0, x1, y1;//координаты вершин отрезка

	letter.open(b);
	letter >> vekters;

	if (aA == 2) {
		big = 5;
		sm = 9 * big;
	}
	
	for (int i = 0; i < vekters; i++)
	{
		letter >> x0;
		letter >> y0;
		letter >> x1;
		letter >> y1;
			Vertex line[] =
			{
				Vertex(Vector2f((x0 * big) + poz, y0 * big + sm )),
				Vertex(Vector2f((x1 * big) + poz, y1 * big + sm ))
			};
		line->color = Color(255, 255, 255);
		window.draw(line, 2, Lines);
	}
}
int main()
{
	int poz = 0;
	string word;
	getline(cin, word);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close(); 
		}
		window.clear(Color(0,0,0,0));
		
		for (int i = 0; i < word.size(); i++) {
			if (word[i] >= 'a' && word[i] <= 'z') {
				//проход по строке и отправка символов в функцию перевода, учитывая позицию символа в строке
				if (word[i] != ' ') 
					cat(word[i], 2, poz);
				poz = poz + 7 * 5;
			}
			else {
				if (word[i] != ' ') 
					cat(word[i], 1, poz);
				poz = poz + 7 * 10;
			}
		}
		poz = 0;//я сйка из за этой хурмы 30 мин потратил! если  в крадце если не сделать обнуление текст убегал вправо до бесконечности и его небыло видно 

		window.display();
	}
}