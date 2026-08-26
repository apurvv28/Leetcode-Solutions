with cte as (
    select distinct player_id,first_value(event_date) over (partition by player_id order by event_date) as first_login_date from Activity
)
select round(count(distinct a.player_id)/(select count(distinct player_id) from Activity),2)as fraction
from cte c
join Activity a 
on c.player_id = a.player_id 
and a.event_date = date_add(c.first_login_date, interval 1 day);
