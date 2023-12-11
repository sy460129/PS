-- 코드를 입력하세요
SELECT animal_type, case when name is NULL then "No name" else name end as NAME, sex_upon_intake from animal_ins order by animal_id
