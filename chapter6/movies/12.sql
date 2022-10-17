
Select title from people join stars on people.id = stars.person_id join movies on movies.id = stars.movie_id where name = "Johnny Depp" 
and movie_id in (Select movie_id from people join stars on people.id = stars.person_id where name = "Helena Bonham Carter"); 