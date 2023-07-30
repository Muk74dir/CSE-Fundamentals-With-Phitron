import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="admin",
    database="mydatabase"
)

mycursor = mydb.cursor()

sql_command = """
                INSERT INTO student(roll, first_name, last_name)
                VALUE(01, "Muktadir", "Sarker");
            """
mycursor.execute(sql_command)
mydb.commit()
