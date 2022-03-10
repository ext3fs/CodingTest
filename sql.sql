select name
from animal_ins
where intake_condition != "Sick"
order by name asc, animal_id desc;
limit 1

select max(datetime)
from animal_ins

select count(*)
from (select name from animal_ins group by name) as tmp

select count(distinct name)
from animal_ins
where name is not null

select name, count(*) as cnt
from animal_ins
group by name having cnt > 1

select hour(datetime), count(*)
from animal_outs
group by 1

set @hour := -1;
select (@hour := @hour + 1),
       (select count(*) from animal_outs where hour(datetime) = @hour)
from animal_outs
where @hour < 23

select ifnull(name,"No name")
from animal_outs

select name
from animal_outs
where name in ("Lucy","Mitty")























