# Write your MySQL query statement below
select Person.firstName, Person.lastName, Address.city, Address.state from Address
right join Person on Address.personId = Person.personId