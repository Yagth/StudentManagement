void registerStudent(){
        student * curr = SHead;
        cout << "registerStudent";

        //Check if List is not empty
        while(SHead != NULL && curr->next != NULL){
            curr = curr->next;
        }
        
        student *st = new student();
        cout << "Enter ID : ";
        cin.ignore();
        cin >> st->id;
        cout << "Enter First name : ";
        cin >> st->firstName;
        cout << "Enter Last name : ";
        cin >> st->lastName;
        cout << "Enter Age : ";
        cin >> st->age;
        cout << "Enter Sex : ";
        cin >> st->sex;
        
        if(curr != NULL){
            st->next = curr->next;
            st->prev = curr->prev;
        }
        curr = st;
}



