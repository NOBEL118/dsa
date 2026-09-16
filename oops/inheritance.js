// now inherring some functions for child from parents class 

class Parent {
    constructor(password) {
        this.password = password;
    } ;

    parentInfo() {
        console.log(`Child Name: ${this.name}`);
        console.log(`Parent Password: ${this.password}`);
    } ;
} ;

class child extends Parent {
    constructor(password, name) {
        super(password); // calling the parent class constructor
        this.name = name;
    } ;
} ;

const child1 = new child("12345", "John");
child1.parentInfo();