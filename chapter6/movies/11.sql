
Select distinct title from people join stars on people.id = stars.person_id join ratings on ratings.movie_id = stars.movie_id join movies on movies.id = stars.movie_id where name = "Chadwick Boseman" order by rating desc limit 5;
