# Route Finder - Dokumentacja
## Jak korzystać z programu?
>### Cel aplikacji:
>Celem aplikacji jest umożliwienie użytkownikowi znalezienia połączenia między dwoma wybranymi miastami, korzystając z podanych przez niego parametrów. Bazę danych stanowi plik "*connections.csv*", którego zawartość można edytować z poziomu programu.

>### Interface aplikacji:
>Drzewko interface'u prezentuje się następująco:
>>**Znajdź połączenie**  
>>Opcja ta umożliwia użytkowniki znaleźć połączenie między dwoma podanymi przez niego miastami. Dodatkowo użytkowni musi podać informacje odnośnie typu wyszukiwania:
>> * Połączenie najtańsze
>> * Połączenie najszybsze
>> * Połączenie najkrótsze
>>
>> Może także zdecydować, o typie połączeń jakie go interesują:
>> * Połączenia pociągiem
>> * Połączenia autobusem
>> * Obydwa powyższe rodzaje połączeń
>
>> **Zaplanuj podróż**  
>> Wybierając tą opcję użytkownik zostanie poproszony o podanie listy miejsc, które chciałby odwiedzić. Na jej podstawie oraz na podstawie podanych przez niego parametrów utworzona zostanie lista połączeń w taki sposób, aby odwiedzić wszystkie podane przez niego miejsca
>
>> **Dodaj połączenie**  
>> Użytkownik będzie mógł ręcznie dodać połączenie między dwoma miastami. Zostanie poproszony o podanie:
>> * Nazwy pierwszego miasta
>> * Nazwy drugiego miasta
>> * Ceny tego połączenia [zł]
>> * Długości tego połączenia [m]
>> * Czasu tego połączenia [min]
>> * Typu połączenia: Autobus/Pociąg
>>
>> Po dodaniu połączenia automatycznie zostanie nadany mu odpowiedni indeks, a miasta między którymi dane połączenie występuje, zaktualizują informacje o wystąpieniu stacji autobusowej lub stacji dla pociągów.
 ## Struktura programu
 ### Lista klas:
 >**Główne**
 > * City
 > * Route
 >     * DirectConnection
 >     * Connection
 > * Matrix
 > * DataBase
 > * FinderAlgorithm
 > * RouteFinder
 >
 >  **Dodatkowe**
 >   * Interface
 >   * Tests
 >   * struktury wyjątów

### City
**Opis klasy:**
> Klasa reprezentująca miasta. Posiada zestaw metod pozwalających uzystkać dostęp do atrybutów. Dodatkowo każdy obiekt (miasto) posiada inforormcję o wystąpieniu stacji autobusowej bądź stacji dla pociągów.

**Atrybuty**:
>  ***std::string***  name; - nazwa miasta
>***bool***  isTrain; - czy miasto zawiera stację dla pociągów
>***bool***  isBus; - czy miasto zawiera stację autobusową

**Metody:**
>City(*std::string*  n="", *bool*  isTrain=false, *bool*  isBus=false);
>***std::string***  get_name() const;
>***bool***  isBusStation() const;
>***bool***  isTrainStation() const;
>***void***  setTrainStation(*bool*  const&  b);
>***void***  setBusStation(*bool*  const&  b);
>***bool***  operator==(*City*  const&  other_city) const;
>***bool***  operator!=(*City*  const&  other_city) const;
>***friend std::ostream&***  operator<<(*std::ostream&*  os, *City*  const&  ct);
