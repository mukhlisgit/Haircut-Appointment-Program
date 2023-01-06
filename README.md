# Haircut-Appointment-Program
program’s aim is to implement a queue system where customers of a barbershop will be queued respectively. Each customer will have their own unique information recorded and also saved into a file after presented/displayed.

The customer’s information that will be saved by the program: 
1.	The customer’s name
2.	The customer’s type of hairstyle
3.	The cost of the hairstyle
4.	A unique id number given to every customer (in case our customers have the same name)
5.	And then a date and time of appointment( calculated from the moment our customers are enqueued)
6.	And other features as well

FILE STRUCTURE

Firstly, I will explain the queue structure in c. The queue is a data structure that implements the FIFO (first in first out) logic. Meaning any customer that requests for a service first will be attended to first. This is normally what goes on in our daily lives when queuing in shops or precisely barbershops. Now let’s get into details.

The queue can be implemented in two ways: Statically or Dynamically. In most cases dynamic queues are more advised because of flexibility of storage. The queue in this program is dynamic and was created using linked list. We insert elements into the queue from behind and is inserted into several blocks called nodes and then the nodes shift to the front. Below is a representation of how data is entered into a queue.

 

As you can see, we enqueue(insert) boxes which are called nodes from behind and then they shift forward as we dequeue(remove) the elements in the front. And since we are using linked lists not arrays the size is not precise but varies according to the data entered. The queue is the backbone of my program that’s why I gave that much explanation.




FLOWCHART

<img width="492" alt="image" src="https://user-images.githubusercontent.com/65587515/211117484-de6f96db-4448-41f6-84cb-8521739ff798.png">

 

