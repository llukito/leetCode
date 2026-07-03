/* Write your T-SQL query statement below */

;WITH t as (
    SELECT *,
    MIN(exam_date) OVER(Partition by student_id, subject) as mindate,
    MAX(exam_date) OVER(Partition by student_id, subject) as maxdate
    FROM Scores
), m as (
    SELECT student_id, subject, score, exam_date
    FROM t
    WHERE exam_date = mindate OR exam_date = maxdate
)

SELECT DISTINCT m1.student_id, m1.subject, 
CASE
    WHEN m1.score < m2.score THEN m1.score
    ELSE m2.score
END as first_score,
CASE
    WHEN m1.score < m2.score THEN m2.score
    ELSE m1.score
END as latest_score
FROM m as m1
JOIN m as m2 ON m1.exam_date != m2.exam_date AND m1.student_id = m2.student_id AND m1.subject = m2.subject
WHERE (m1.exam_date < m2.exam_date AND m1.score < m2.score) OR (m2.exam_date < m1.exam_date AND m2.score < m1.score) 
ORDER BY m1.student_id, m1.subject
