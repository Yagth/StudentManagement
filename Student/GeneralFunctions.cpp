void sortByName(){
    student* tempFirstName;

    if (SHead == NULL) {
        return;
    }else {
        for (student *current = SHead; current != NULL; current = current->next) {
            for (student *index = current->next; index != NULL; index = index->next) {
                if (current->firstName > index->firstName) {
                    tempFirstName = current;
                    current = index;
                    index= tempFirstName;
                }
            }
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
