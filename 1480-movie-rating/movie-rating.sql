SELECT name AS results
FROM (
    SELECT u.name, COUNT(mr.rating) AS rating_count
    FROM users u
    JOIN movierating mr ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
    ORDER BY rating_count DESC, u.name ASC
    LIMIT 1
) AS top_user

UNION ALL


SELECT title AS results
FROM (
    SELECT m.title, AVG(mr.rating) AS avg_rating
    FROM movies m
    JOIN movierating mr ON m.movie_id = mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id, m.title
    ORDER BY avg_rating DESC, m.title ASC
    LIMIT 1
) AS top_movie;
