# Tom y Jerry consigna en español
Implementar en c++ un objeto que represente a tom, que es un gato. Lo que nos interesa de tom es manejar su energía y su velocidad, que
dependen de sus actividades de comer ratones y de correr. La persona que registra las actividades de tom, registra los ratones que
come y la cantidad de tiempo que corre en segundos. Cuando tom come un ratón, su energía aumenta en (12 joules + el peso del ratón en gramos). La
velocidad de tom es 5 metros x segundo + (energia medida en joules / 10). Cuando tom corre, su energía disminuye en (0.5 x cantidad de metros que
corrió). Observar que la cuenta está en joules consumidos por metro, pero cuando me dicen cuánto corrió, me lo dicen en segundos. La velocidad que
se toma es la que corresponde a la energía de Tom antes de empezar a correr, y no varía durante una carrera.
Nota: además de tom, hay otros objetos en juego, ¿cuáles son, qué mensaje tienen que entender?
a. Lograr que tom entienda el mensaje:
tom.meConvieneComerRatonA(unRaton, unaDistancia)
Devuelve true si la energía que gana por comer al ratón es mayor a la que consume corriendo la distancia, que está medida en metros

# Tom and Jerry work

Implement in C++ an object that represents tom, which is a cat. What interests us about Tom is managing his energy and speed, which
They depend on their activities of eating mice and running. The person who records Tom's activities records the mice that
eat and the amount of time it runs in seconds. When Tom eats a mouse, his energy increases by (12 joules + the mouse's weight in grams). The
tom speed is 5 meters x second + (energy measured in joules / 10). When Tom runs, his energy decreases by (0.5 x number of meters he
ran). Note that the count is in joules consumed per meter, but when they tell me how much it ran, they tell me in seconds. The speed that
taken is the one that corresponds to Tom's energy before starting to run, and does not vary during a race.
Note: besides tom, there are other objects in play, what are they, what message do they have to understand?
to. Getting Tom to understand the message:
tom.meIsSuitableToEatMouseA(aMouse, aDistance)
Returns true if the energy gained by eating the mouse is greater than the energy consumed by running the distance, which is measured in meters

