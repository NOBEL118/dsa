// overrding -> same method name but different implementation in child class

class parent {
    info () {
        console.log("This is parent class method 💀" ) ;
    } ;
} ;

class child extends parent {
    info () {
        console.log("This is child class method ✳️") ;
    } ;
} ;

const child1 = new child() ;
child1.info() ; // Output: This is child class method ✳️