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
-----
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
----------------
### City  
**Opis klasy:**  
> Klasa reprezentująca miasta. Posiada zestaw metod pozwalających uzystkać dostęp do atrybutów. Dodatkowo każdy obiekt (miasto) posiada inforormcję o wystąpieniu stacji autobusowej bądź stacji dla pociągów.  

**Atrybuty**:  
> * **std::string**  name;  - nazwa miasta  
> * **bool**  isTrain; - czy miasto zawiera stację dla pociągów   
>* **bool**  isBus; - czy miasto zawiera stację autobusową  

**Metody:**
>* City(std::string  n="", bool  isTrain=false, bool  isBus=false);  
>* **std::string**  get_name() const;  
>* **bool**  isBusStation() const;  
>* **bool**  isTrainStation() const;  
>* **void**  setTrainStation(bool  const&  b);  
>* **void**  setBusStation(bool  const&  b);  
>* **bool**  operator==(City  const&  other_city) const;  
>* **bool**  operator!=(City  const&  other_city) const;  
>* **friend std::ostream&**  operator<<(std::ostream&  os, City  const&  ct);  
------------
### Route  
**Opis klasy:**  
> Klasa abstrakcyjna. Utworzona została jako rodzic do klasy DirectConnection oraz klasy Connection. Obie te klasy korzystają z podobnego zestawu metod i atrybutów, tak więc w celu uniknięcia redundancji napisana została klasa Route. Nie można utworzyć obiektów typu Route.  

**Atrybuty**:  
>* **unsigned  int**  connection_id;  
>* **unsigned  int**  distance;  
>* **unsigned  int**  cost;  
>* **unsigned  int**  time;  
>* **City**  PlaceA;  
>* **City**  PlaceB;  

**Metody:**  
> * Route(unsigned  int  id, unsigned  int  d, unsigned  int  c, unsigned  int  t, City  const&  PA, City  const&  PB);  
>* **virtual  void** print_connection_details() =  0;  
>* **unsigned  int**  get_connection_id();  
>* **unsigned  int**  get_distance() const;  
>* **unsigned  int**  get_cost() const;  
>* **unsigned  int**  get_time() const;  
>* **City**  get_PlaceA() const;  
>* **City**  get_PlaceB() const;  
>* **City&**  get_modifable_PlaceA();  
>* **City&**  get_modifable_PlaceB();  
------------
### DirectConnection :  Route  
**Opis klasy:**  
> Lorem ipsum is a giasjdo. asodjasd asdadasd. AFsdf. ASDasdasd
> aasdad aSDASD asdADASdadsd....  

**Atrybuty**:  
>* **station_type**  type;   
>*station type to specjalnie utworzony typ enum, atrybut ten przechowuje czy dane połączenie jest połączeniem autobusowym, czy korzystając z pociągu*  

**Metody:**  
>* DirectConnection(unsigned  int  id, unsigned  int  d, unsigned  int  c,
unsigned  int  t, City  const&  PA, City  const&  PB, station_type  tp);  
>* **unsigned  int**  get_connection_id() const;  
>* **station_type**  get_type() const;  
>* **bool**  operator==(DirectConnection  dc);  
>* **bool**  operator!=(DirectConnection  dc);  
>* **friend std::ostream&**  operator<<(std::ostream&  os, DirectConnection  const&  dc);  
>* **virtual  void**  print_connection_details();  
-----------
### Connection :  Route  
**Opis klasy:**  
> Lorem ipsum is a giasjdo. asodjasd asdadasd. AFsdf. ASDasdasd
> aasdad aSDASD asdADASdadsd....  

**Atrybuty**:  
>* **std::vector\<DirectConnection\*>**  connection_elements;   
>* **std::vector\<City>**  changes_list;  

**Metody:**  
>* Connection(City  PA, City  PB);   
>* **std::vector\<DirectConnection\*>** get_connection_elements() const;  
>* **unsigned  int**  get_connection_id();  
>* **void**  add_direct_conection(DirectConnection*  dc);  
>* **void** set_id(unsigned  int  id);  
>* **friend std::ostream&**  operator<<(std::ostream&  os, Connection  const&  cnt);  
>* **void** print_connection_details();  
----------
### Matrix  
**Opis klasy:**  
> Lorem ipsum is a giasjdo. asodjasd asdadasd. AFsdf. ASDasdasd
> aasdad aSDASD asdADASdadsd....  

**Atrybuty**:  
>* **DirectConnection**  ***p;  
>* **unsigned  int**  size;  
>* **std::vector\<City>**  cites;   

**Metody prywatne:**  
>* **void**  extend_matrix();  

**Metody:**  
>* Matrix();  
>* Matrix(Matrix  const&  matrix_to_copy);  
>* **unsigned  int**  get_size() const;  
>* **std::vector\<City>** get_cities() const;   
>* **Matrix &**  operator=(Matrix  const&  matrix_to_assign);  
>* **DirectConnection\***  operator()(City  const&  CityA, City  const&  CityB);  
>* **DirectConnection\***  operator()(int  i, int  j);  
>* **void**  add_connection(DirectConnection  *cnt);  
>* **bool**  isCity(City  const&  city) const;  
>* **std::string**  description() const;  
>* **void**  print_matrix();  
>* **void**  clean();  
>* ~Matrix();  
--------
### DataBase
**Opis klasy:**  
> Lorem ipsum is a giasjdo. asodjasd asdadasd. AFsdf. ASDasdasd
> aasdad aSDASD asdADASdadsd....  

**Atrybuty:**   
>* **std::vector\<DirectConnection>**  connections;  
>* **std::vector\<City>**  cities;  
>* **Matrix**  current_matrix;  
>* **possible_type**  current_station_type;  
>* **possible_search_setting**  current_search_setting;  
>* **std::string**  path;  

**Metody prywatne:**  
>* **void**  add_city_using_connection(DirectConnection  const&  dc);   
>* **std::vector\<City>** city_using_info(std::string  const&  nameA, std::string  const&  nameB, station_type  type);  

**Metody:**  
>* DataBase();  
>* DataBase(std::string  const&  filepath);  
>* DataBase(std::string  const&  filepath, std::vector\<DirectConnection> c);  
>* **void**  add_direct_connection(DirectConnection  const&  dc);  
>* **void**  add_direct_connection(unsigned  int  dist, unsigned  int  cost, unsigned int  time, std::string const&  PlaceA, std::string  const&  PlaceB, station_type  type);  
>* **possible_search_setting**  get_current_setting() const;  
>* **possible_type**  get_current_stations_type() const;  
>* **Matrix**  get_current_matrix() const;  
>* **std::vector\<DirectConnection>** get_connections();  
>* **std::vector\<City>** get_cities() const;  
>* **void**  set_file_path(std::string  const&  p);  
>* **void**  create_cheapest_matrix(possible_type  const&  type);  
>* **void**  create_fastest_matrix(possible_type  const&  type);  
>* **void**  create_shortest_matrix(possible_type  const&  type);  
>* **void**  update_data_base() const;  
>* **void**  load_file();  
-----------
### FinderAlgorithm  
**Opis klasy:**  
> Lorem ipsum is a giasjdo. asodjasd asdadasd. AFsdf. ASDasdasd
> aasdad aSDASD asdADASdadsd....  

**Atrybuty**:  
>* **Matrix**  connections_matrix;  
>* **std::vector\<int>**  distance;  
>* **std::vector\<int>**  previous;  
>* **std::vector\<City>**  used;  
>* **std::vector\<City>**  cities;  

**Metody prywatne:**  
>* **bool**  is_used(City  const&  ct) const;  
>* **City**  min_city_node() const;  
>* **int**  find_city_index(City  const&  ct);  

**Metody:**  
>* FinderAlgorithm(Matrix  const&  cm);  
>* FinderAlgorithm();  
>* **Matrix**  get_connetions_matrix() const;  
>* **std::vector\<int>** get_distance() const;  
>* **std::vector\<int>** get_previous() const;  
>* **void**  set_connections_matrix(Matrix  const&  cm);  
>* **Connection**  generate_connection_time(City  const&  PlaceA, City  const&  PlaceB);  
>* **Connection**  generate_connection_cost(City  const&  PlaceA, City  const&  PlaceB);  
>* **Connection**  generate_connection_dist(City  const&  PlaceA, City  const&  PlaceB);  
>* **Connection**  generate_connection(City  const&  PlaceA, City  const&  PlaceB);  
>* **Connection**  generate_connection_setting(City  const&  PlaceA, City  const& PlaceB, possible_search_setting  s_set);  
>* **void**  dijkstra_dist(City  const&  PlaceA);  
>* **void**  dijkstra_time(City  const&  PlaceA);  
>* **void**  dijkstra_cost(City  const&  PlaceA);  
>* **void**  reset();  
---------
### RouteFinder  
**Opis klasy:**  
> Lorem ipsum is a giasjdo. asodjasd asdadasd. AFsdf. ASDasdasd
> aasdad aSDASD asdADASdadsd....  

**Atrybuty:**  
>* **DataBase**  db;  
>* **FinderAlgorithm**  FA;  
>* **City**  UserCityA;  
>* **City**  UserCityB;  

**Metody:**
>* RouteFinder(std::string  const&  filepath);  
>* **Connection**  find_user_connection(std::string  const&  nameA, std::string  const&  nameB, possible_search_setting  setting, possible_type  type);  
>* **City**  find_city(std::string  const&  name);  
>* **DataBase&**  get_db();  

-----
### Interface  
**Opis klasy**  
> Lorem ipsum i chuj z nimi  

**Metody:**  
>* Interface();  
>* **void**  run_interface();  
>* **int**  choose_function();  
>* **enum  possible_search_setting**  choose_setting();  
>* **enum  possible_type**  choose_type();  
--------
### Tests  
**Opis klasy**  
> Lorem ipsum i chuj z nimi  

**Metody prywatne:**  
>* **void**  test_City() const;  
>* **void**  test_Connection() const;  
>* **void**  test_DirectConnection() const;  
>* **void**  test_DataBase() const;  
>* **void**  test_FinderAlgorithms() const;  
>* **void**  test_Matrix() const;  
>* **void**  test_RouteFinder() const;  

**Metody:**  
>* **void**  run_test() const;  
-----
### Struktury wyjątków  
**Wyjątki:**  
>* MyException  
>* dcAlreadyAddedError  
>* StationTypeError  
>* CityNotFoundException  
>* DCNotFoundException  
>* ConnectionNotFoundException  
---
## Uruchomienie programu  
### System operacyjny:  
Linux (*program testowany był na distro Ubuntu*)  
### Kompilacja  
W celu skompilowania programu w terminalu należy wpisać polecenie ***make***.  
### Plik wykonywalny  
W celu wywołania aplikacji w terminu należy wpisać polecenie ***./RouteFinder.out***  
### Testy  
W celu uruchomienia testów jednostkowych należy wpisać w terminalu serię poleceń:  
* ***make run_tests***  
* ***./tests.out***  
