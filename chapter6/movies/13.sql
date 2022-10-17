
Select distinct name from people join stars on people.id = stars.person_id where name != "Kevin Baocn" and movie_id in (Select movie_id from people join stars on people.id = stars.person_id where name = "Kevin Bacon" and birth = 1958);
