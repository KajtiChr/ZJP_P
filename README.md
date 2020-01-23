# Wstęp - kilka słów o refaktoryzacji
## Czym jest refaktoryzacja
Refaktoryzacja, to zmiana organizacji struktury kodu programu, jednak z zachowaniem integralności jego działania.

Dostosowanie istniejących programów komputerowych do nowych lub zmieniających się wymagań jest trudne i czasochłonne. Jednym ze sposobów radzenia sobie z tym zadaniem jest refaktoryzacja - proces przekształcania kodu źródłowego niezmieniający działania programu. Ułatwia on budowę i pielęgnację oprogramowania, umożliwiając utrzymanie systemu komputerowego w stanie pozwalającym na łatwą rozbudowę. Refaktoryzacja jest jednak procesem czasochłonnym i podatnym na błędy, wobec czego pożądana jest jej automatyzacja. Stworzenie niezawodnych i wydajnych narzędzi wspierających programistów w tym zadaniu jest niezbędnym warunkiem do tego, by refaktoryzacja mogła stać się powszechnie przyjętą techniką tworzenia i pielęgnacji programów.

## Rodzaje refaktoryzacji
Refaktoryzacje proste mozna to podzielić na:
1. Organizacje odpowiedzialności klas
1. Skladanie lub wyodrębnianie metod
1. Dobra organizacja danych
1. Meta-refactoring

## Zapachy kodu
Zapachami kodu (ang. Code Smells) nazywamy takie cechy kodu, które świadczą o złym sposobie implementacji i wymagają refaktoryzacji.

1. Zbyt długa klasa lub metoda
1. Metoda z dużą liczbą parametrów
1. Klasa leniwa (ang.lazy class) - klasa o bardzo małej odpowiedzialności
1. Zazdrość o kod (ang.feature envy) - metoda za bardzo korzystająca z innej klasy
1. Mała intymność (ang.inappropriate intimacy)- klasy zbyt zależne od implementacji innych klas
1. Martwy kod
1. Zduplikowany kod.

## Metryki kodu

- **Złożoność cyklomatyczna** – metryka oprogramowania opracowana przez Thomasa J. McCabe'a w 1976, używana do pomiaru stopnia skomplikowania programu. Podstawą do wyliczeń jest liczba dróg w schemacie blokowym danego programu, co oznacza wprost liczbę punktów decyzyjnych w tym programie.
- **Złożoność kognitywna** - metryka oznaczająca łatwość zrozumienia kodu dla osoby czytającej. Często pomijana (ze względu na swoją „nie techniczność”), ale jest nie mniej ważna od złożoności samego kodu.


# Refaktoryzowany program - Labirynt

## O prokekcie
Program to prosta gra w labirynt zrealizowana w konsoli.

## Narzędzie użyty do automatyzacji rekatoryzacji
### Lizard
Proste narzędznie do analizy złożoności cyklomatyczniej kodu

## Fragmety kodu po refaktoryzacji
```cpp
char Maze_set_uper(int Switcher)
{
    char result;
    switch(Switcher)
    {
    case 0:
        result = '?';
        break;
    case 1:
        result = 'x';
        break;
    case 2:
        result = 'P';
        break;
    case 3:
        result = 'E';
        break;
    case 4:
        result = ' ';
        break;
    case 5:
        result = '?';
        break;
    }
    return result;
}
```
```cpp
void Maze_Generator_Empty_Fields(int limit, int Values[N][N])
{
    for(int i = 0; i < limit; i++)
    {
        for(int j = 0; j < limit; j++)
        {
            Values[i][j] = 0;
        }
    }
}

void Wall_Builder(int limit, int Values[N][N])
{
    for (int i = 0; i < limit; i++)
    {
        for(int j = 0; j < limit; j++)
        {
            if(i==0  || j ==0 || i == limit-1 || j == limit-1) Values[i][j] = 1;
        }
    }
}

```