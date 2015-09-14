


###Combine Two Tables

```sql
# Write your MySQL query statement below
select Person.FirstName, Person.LastName, Address.City, Address.State
from 
Person left join Address on Person.PersonId = Address.PersonId
```

###Second Highest Salary 

```sql
# Write your MySQL query statement below
select max(Salary) from Employee 
where 
Salary < (select max(Salary) from Employee)
```

###Nth Highest Salary

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary from Employee order by Salary desc limit M, 1
  );
END
```

###Rank Scores 

```sql
# Write your MySQL query statement below
Select Scores.Score, count(Ranking.Score)
from
Scores, (select distinct Score from Scores) as Ranking
where Scores.Score <= Ranking.Score
group by Scores.Id, Scores.Score
order by Scores.Score desc;
```