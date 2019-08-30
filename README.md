# QtMiner

**The best implementation of the famous game!** Игра Сапёр, написанная на Qt, с хранением результатов предыдущих игры в базе данных PostgreSQL.

# Использование

При запуске приложения открывается окно с игровым полем и меню. При первом нажатии на клетку поля генерируется карта с заданным количеством мин и запускается таймер. Установка / снятие флага на клетку осуществляется нажатием правой кнопки мыши. При нажатии на ячейку из пустой области происходит отображение всей пустой области. 

В процессе игры отображается информация о количестве оставшихся пустых клеток и мин, а таккже время текущей игры.

Пользователь может перезапустить игру, поставить её на паузу или изменить характеристики игрового поля.

**Compilation**:

From the main project folder run the following commands:

```sh
qmake
make
```

**Database connection**

For work with the database you need to install [PostgreSQL Core Distribution](https://www.postgresql.org/download/)
and create new user using commands:

```sh
sudo -u postgres createuser qtminer # create user

sudo -u postgres psql # change password
ALTER USER qtminer WITH encrypted PASSWORD '123456';

sudo -u postgres createdb -O qtminer qtminer # create db
```

For create the required table in the database you must run: 

```sh
src/db/createDB/createDB
```

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/EFevm0B7rLA/0.jpg)](http://www.youtube.com/watch?v=EFevm0B7rLA)

<p align="center">
  <a href="http://www.youtube.com/watch?feature=player_embedded&v=EFevm0B7rLA" target="_blank"><img src="http://img.youtube.com/vi/EFevm0B7rLA/0.jpg" 
  alt="IMAGE ALT TEXT HERE" width="240" height="180" border="2"/></a>
</p>

