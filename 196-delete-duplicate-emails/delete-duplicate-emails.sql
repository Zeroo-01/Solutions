# Write your MySQL query statement below
delete p from person p,person pp where p.email=pp.email and p.id>pp.id