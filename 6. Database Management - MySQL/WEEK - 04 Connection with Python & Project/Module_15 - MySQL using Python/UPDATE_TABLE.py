import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="admin",
    database="mydatabase"
)

mycursor = mydb.cursor()

sql_command = """
                UPDATE student
                SET roll = 2
                WHERE first_name = "Raju";
            """
mycursor.execute(sql_command)
mydb.commit()
