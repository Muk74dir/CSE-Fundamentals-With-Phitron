import mysql.connector as dbtest

mydb = dbtest.connect(
    host="localhost",
    user="root", 
    passwd="admin"
)

mycursor = mydb.cursor()
db_name = "mydatabase"
sql_command = "CREATE DATABASE IF NOT EXISTS " + db_name
mycursor.execute(sql_command)
