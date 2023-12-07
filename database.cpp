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

    try
    {
        if(!transaction){
            throw (transaction);
        }
        else{
            tempMemory[key]=value;
        }
    }
    catch(...)
    {
        cerr << "Cannot update values outside of transaction." << endl;;
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
    try
    {
        if(!transaction){
            throw (transaction);
        }
        else{
            for(auto t : tempMemory){
                memory[t.first]=t.second;
            }

            transaction = false;
        }
    }
    catch(...)
    {
        cerr << "Must have active transaction to commit." << endl;;
    }
}

void database::rollback(){
    try
    {
        if(!transaction){
            throw (transaction);
        }
        else{
            tempMemory.clear();

            transaction = false;
        }
    }
    catch(...)
    {
        cerr << "Must have active transaction to rollback." << endl;;
    }
}
