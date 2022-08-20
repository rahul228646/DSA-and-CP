# SQL Notes

- SQL stands for Structured Query Language 

- The FOREIGN KEY constraint is used to prevent actions that would destroy links between tables.

- A FOREIGN KEY is a field (or collection of fields) in one table, that refers to the PRIMARY KEY in another table.

- The table with the foreign key is called the child table, and the table with the primary key is called the referenced or parent table.

- The FOREIGN KEY constraint prevents invalid data from being inserted into the foreign key column, because it has to be one of the values contained in the parent table.

## CHAR

- Used to store character string value of fixed length.
- The maximum no. of characters the data type can hold is 255 characters.
- It's 50% faster than VARCHAR.
- Uses static memory allocation.

## VARCHAR

- Used to store variable length alphanumeric data.
- It's slower than CHAR.
- Uses dynamic memory allocation.

- **RDBMS** stands for Relational Database Management System
    The data in RDBMS is stored in database objects called tables. A table is a collection of related data entries and it consists of columns and rows.

## CREATE TABLE

    CREATE TABLE table_name (
        column1 datatype,
        column2 datatype,
        column3 datatype,
    );

    CREATE TABLE Persons (
        PersonID int,
        LastName varchar(255),
        FirstName varchar(255),
        Address varchar(255),
        City varchar(255) 
    );


## SELECT 

- used to select data

- **DISTINCT** is ued to select distinct values of a column

      **SELECT DISTINCT Country FROM Customers;**

- **Top / LIMIT** is used to specify the no. of records we want in no. or percentage

      SELECT TOP 3 * FROM table
      SELECT TOP 50 PERCENT * FROM table

## WHERE

- used to filter records

-  The WHERE clause is not only used in SELECT statements, it is alse used in UPDATE, DELETE, etc.
  
        SELECT * FROM Customers
        WHERE CustomerID=1;

- WHERE is can be used with **OR AND** and **NOT**

- WHERE clause cannot be used with aggregate functions

## ORDERED BY

- used to sort column by **ASC** or **DESC**
 
      SELECT column1, column2, ...
      FROM table_name
      ORDER BY column1, column2, ... ASC

## INSERT INTO

    INSERT INTO table_name (column1, column2, column3, ...)
    VALUES (value1, value2, value3, ...);

## NULL

- a field with no value

- It is not possible to test for NULL values with comparison operators, such as =, <, or <>.
We will have to use the **IS NULL** and **IS NOT NULL** operators instead.

## UPDATE and SET

    UPDATE Customers
    SET ContactName='Juan'
    WHERE Country='Mexico';

## DELETE 

- DELETE statement is used to delete existing records in a table.

## DROP TABLE

- The DROP TABLE command deletes a table in the database.

## TRUNCATE TABLE

- The TRUNCATE TABLE command deletes the data inside a table, but not the table itself.

## MIN() / MAX()

- The MIN()/MAX() function returns the smallest/largest value of the selected column.

       SELECT MIN(column_name) FROM table
              or 
       SELECT MAX(column_name) FROM table

## COUNT() , AVG() and SUM()

- to find the count, average and sum of the specified column

## LIKE

- used to search for a specified pattern in a coulmn

      WHERE name LIKE 'a%'    - name starts with a 
      
      WHERE name LIKE 'a__'   - name starts with a and has 2 characters after a 
      
      WHERE name LIKE '%a%'   - name contains a 
      
      WHERE name LIKE '_a'    - one character before a and zero after a
      
      WHERE name LIKE '_a%'   - 2nd character is a
      
      WHERE name LIKE 'a%o'   - name starts with a and ends with o

## Wildcard Characters

    - **%**   - Represents zero or more characters
    
    - **_**   - Represents a single character
    
    - **[]**  - Represents any single character within the brackets
                eg - h[oa]t finds hot and hat, but not hit
                
    - **^**   - Represents any character not in the brackets
                eg - h[^oa]t finds hit, but not hot and hat
                
    - **-**   - Represents any single character within the specified range
                eg - c[a-b]t finds cat and cbt

## IN and NOT IN

- The IN operator allows you to specify multiple values in a WHERE clause.
 
      SELECT * FROM Customers
      WHERE Country IN ('Germany', 'France', 'UK');

      SELECT * FROM Customers
      WHERE Country NOT IN ('Germany', 'France', 'UK');

## BETWEEN and NOT BETWEEN

- The BETWEEN operator selects values within a given range. The values can be numbers, text, or dates.

- The BETWEEN operator is **inclusive** i.e. begin and end values are included. 

      SELECT * FROM Products WHERE Price BETWEEN 10 AND 20;
      SELECT * FROM Products WHERE Price N OT BETWEEN 10 AND 20;
      SELECT * FROM Orders WHERE OrderDate BETWEEN '1996-07-01' AND '1996-07-31';


## Alias - AS

- used to rename a column , name is NOT chnaged in the database

      SELECT CustomerID AS ID, CustomerName AS Customer
      FROM Customers;

## CONCAT 

- used to concatinate strings

      SELECT CustomerName, CONCAT(Address,', ',PostalCode,', ',City,', ',Country) AS Address FROM Customers;




## JOIN

- A JOIN clause is used to combine rows from two or more tables, based on a **related column** between them.


      SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
      FROM Orders
      JOIN Customers ON Orders.CustomerID=Customers.CustomerID;
    
- Types of Join : 

      **INNER JOIN / JOIN**  :  Returns records that have matching values in both tables

      **LEFT JOIN**          :  Returns all records from the left table, and the matched records from the right table

      **RIGHT JOIN**         :  Returns records that have matching values in both tables

      **FULL JOIN**          :   Returns all records when there is a match in either left or right table


## UNION

- The UNION operator is used to combine the result-set of two or more SELECT statements.

- The UNION operator selects only distinct values by default. To allow duplicate values, use UNION ALL

## GROUP BY

- The GROUP BY statement groups rows that have the same values into summary rows, like "find the number of customers in each country".

- The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) to group the result-set by one or more columns.

## HAVING 

- The HAVING clause was added to SQL because the WHERE keyword cannot be used with aggregate functions eg - we use having with group by.

## EXISTS

- The EXISTS operator is used to test for the existence of any record in a subquery.

- The EXISTS operator returns TRUE if the subquery returns one or more records.

## CASE

- The CASE expression goes through conditions and returns a value when the first condition is met (like an if-then-else statement). 

- So, once a condition is true, it will stop reading and return the result. If no conditions are true, it returns the value in the ELSE clause.

          SELECT OrderID, Quantity,
          CASE
              WHEN Quantity > 30 THEN 'The quantity is greater than 30'
              WHEN Quantity = 30 THEN 'The quantity is 30'
              ELSE 'The quantity is under 30'
          END AS QuantityText
          FROM OrderDetails;

##  IFNULL(), ISNULL(), COALESCE(), and NVL()

- all the above clause helps us return an alternate value if null is encountered
 
      SELECT ProductName, UnitPrice * (UnitsInStock + 
      COALESCE(UnitsOnOrder, 0)) 
      FROM Products;

      SELECT ProductName, UnitPrice * (UnitsInStock + 
      IFNULL(UnitsOnOrder, 0)) 
      FROM Products;


## Other Operators

- https://www.w3schools.com/sql/sql_operators.asp

