### Project 1 - Airline Database Management, AirED (Grade: 18.6 / 20)

A project done in one month with [Carolina Brandão](https://github.com/CarolBrandak) and [Gabriel Machado Jr.](https://github.com/gabrieltmjr). <br>
It is intended to implement an information management system that must store and manage information related to planes, flights, passengers and luggage.

Implemented features:
- [x] Simpler and non-recursive interface, based on the Stack data structure;

<br/>
<p align = "center" >
  <img 
       title = "Menu strategy"
       src = "../Images//Project1_Menu.png" 
       alt = "Credits: Gabriel Machado Jr." 
       />
</p>
<p align = "center" >Menu strategy. Image credits: Gabriel Machado Jr.</p>
<br>

- [x] Efficient search to the nearest transport, using Binary Search Tree data structure;
- [x] Efficient search to flights, planes, services, luggage using linear-search in lists and binary-search in sorted vectors;
- [x] Two types of luggage: hand-luggage and hold-luggage, depends on the user input and volume/weight proprieties;

<br/>
<p align = "center" >
  <img 
       title = "Luggage strategy"
       src = "../Images//Project1_Luggage.png" 
       alt = "Credits: Carolina Brandão" 
       />
</p>
<p align = "center" >Luggage strategy. Image credits: Carolina Brandão</p>
<br>

- [x] Automatic compound unique IDs, to better performance and avoid collisions in system population and manipulation;

<br/>
<p align = "center" >
  <img 
       title = "ID strategy"
       src = "../Images//Project1_IDs.png" 
       alt = "Credits: Gabriel Machado Jr." 
       />
</p>
<p align = "center" >IDs strategy. Image credits: Gabriel Machado Jr.</p>
<br>

- [x] Secure Data: files have the ability to self-heal if there is data corruption during the execution of program, using redundancy based on [RAID](https://pt.wikipedia.org/wiki/RAID);
- [x] [ON DELETE CASCADE](https://www.mysqltutorial.org/mysql-on-delete-cascade/) implicit behavior, activation whenever delete certain component, based on SQL databases management systems (DBMS);

<br>