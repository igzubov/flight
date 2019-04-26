# Airctaft & missile modelling
Aircraft and missile are flying with the given velocity vectors and initial position.  
The missile can hit the aircraft if it will be in radius of missile affected area.

## How to use 
1. ``` git clone https://github.com/igzubov/flight/ && cd flight ```
2. ``` mkdir build && cd build ```
3. ``` cmake .. && make ```
4. ``` ./life_game x0 H v1_x v1_y v2_x v2_y R time_step end_time ```, 
where:  
- **x0** - x coordinate of the aircraft position    
- **H** - y coordinate of the aircraft position    
- **v1_x** - x coordinate of the aircraft velocity   
- **v1_y** - y coordinate of the aircraft velocity    
- **v2_x** - x coordinate of the missile velocity   
- **v2_y** - y coordinate of the missile velocity    
- **R** - radius of missile affected area
- **time_step** - dt for modelling
- **end_time** - end time of modelling
