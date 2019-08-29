# QtMiner

**The best implementation of the famous game!** 

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