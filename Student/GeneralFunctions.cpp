void sortStudentByName(){

    if (SHead == NULL) {
        return;
    }else {
        student* current = SHead, *prev = NULL, *next = NULL;
        while(current != NULL){
            if(current->firstName > current->next->firstName){
                if(current == SHead){
                    prev = current->
                }
            }
            prev = current;
            current = current->next;
            next = current->next;
        }
    }
}

void display() {
    student* current = SHead;

    if (SHead == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (current != NULL) {
        cout << "ID: " << current->id << endl;
        cout << "First name: " << current->firstName << endl;
        cout << "Last name: " << current->lastName << endl;
        cout << "Age: " << current->age << endl;
        cout << "Sex: " << current->sex << endl;

        current = current->next;
    }
}
