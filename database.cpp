#include <database.h>

database::database(){

}

void database::begin_transaction(){
    if(transaction){
        cout<<"There is already an active transaction."<<endl;
    }
    else{
        transaction=true;
    }
}

void database::put(string key, int value){
    if(transaction){
        memory[key]=value;
    }
    else{
        cout<<"Begin a transaction to update values."<<endl;
    }
}

int database::get(string key){
    if(memory.find(key)!=memory.end()){
        return memory[key];
    }
    else{
        return -1;
    }
}

void database::commit(){

}

void database::rollback(){

}
