// making class lets say "animal" ;

class Animal {
    constructor(name, age) { // to get the name and age of the animal ofc
        this.name = name;
        this.age = age;
    } ;
    
    info() {
        console.log(`Name: ${this.name}, Age: ${this.age}`);
    } ;
} ;

const dog = new Animal("Dog", 5);
dog.info(); // Output: Name: Dog, Age: 5