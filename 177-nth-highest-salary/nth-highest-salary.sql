CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
     
      SELECT DISTINCT SALARY  FROM Employee ORDER BY SALARY DESC LIMIT 1 OFFSET N 

  );
END;