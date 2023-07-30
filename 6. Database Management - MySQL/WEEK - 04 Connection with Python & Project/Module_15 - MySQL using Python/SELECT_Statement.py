import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="admin",
    database="hr"
)

mycursor = mydb.cursor()

sql_command = """
                SELECT * FROM employees
                WHERE salary > 100
                LIMIT 10;
            """
mycursor.execute(sql_command)
data = mycursor.fetchall()
for i in data:
    print(i)