#include <iostream>
#include <string>

using namespace std;

template <class datatype>
class Stack
{
    int size;
    int top;
    datatype data[10];
public:
    Stack()
    {
        size = 10;
        top = -1;
    }
    ~Stack()
    {

    }
    bool isfull()
    {
        return (top == size - 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void push(datatype value)
    {
        if (isfull())
        {
            return;
        }
        data[++top] = value;
    }
    datatype pop()
    {
        if (isEmpty())
        {
            exit(0);
        }
        return data[top--];
    }
    int getSize() const
    {
        return this->size;
    }
    void show() const {
        int temp = top;

        while (temp != -1) {
            cout << data[temp--] << endl;
        }
    }
};

class Patient {
private:
    string name;
    int patient_id;
    Stack<string> visit_date;
    Stack<int> charges;
    int turns;
    string diagnosis;
    string treatment;
    string observations;
    string physicians_name;
    int physicians_id;
    int total_bill;
public:
    Patient() {
        name = "Patient";
        patient_id = 0;
        turns = 0;
        diagnosis = "";
        treatment = "";
        observations = "";
        physicians_name = "";
        physicians_id = -1;
        total_bill = 0;
    }

    void insertRecord(string name, int id, string visit, int turn, int charges, string diag_, string treatment, string observation, string phys_name, int phys_id) {
        this->name = name;
        this->patient_id = id;
        this->visit_date.push(visit);
        this->turns = turn;
        this->charges.push(charges);
        total_bill = charges;
        this->diagnosis = diag_;
        this->treatment = treatment;
        this->observations = observation;
        this->physicians_name = phys_name;
        this->physicians_id = phys_id;
    }
    void addVisit(string visit_date, int charges) {
        this->visit_date.push(visit_date);
        this->turns++;
        this->charges.push(charges);
        total_bill += charges;
    }
    int getId() const {
        return this->patient_id;
    }
    void Invoice() {
        cout << "Patient Name: " << name << endl;
        cout << "Patient ID: " << patient_id << endl;
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Treatment: " << treatment << endl;
        cout << "Observation: " << observations << endl;
        cout << "Physician Name: " << physicians_name << endl;
        cout << "Physician id: " << physicians_id << endl;
        cout << "Visit Dates: ";
        visit_date.show();
        cout << "Sevice charges on each visit: ";
        charges.show();

        cout << "************************************************" << endl;
        cout << "\t\tTotal Bill: " << total_bill << endl;
        cout << "************************************************" << endl;
    }

    bool operator==(const Patient& ref) {
        return this->patient_id == ref.patient_id;
    }
    friend ostream& operator<<(ostream& out, const Patient& ref);
};

ostream& operator<<(ostream& out, const Patient& ref) {
    out << "Patient Name: " << ref.name << endl;
    out << "Patient ID: " << ref.patient_id << endl;
    out << "Diagnosis: " << ref.diagnosis << endl;
    out << "Treatment: " << ref.treatment << endl;
    out << "Observation: " << ref.observations << endl;
    out << "Physician Name: " << ref.physicians_name << endl;
    out << "Physician id: " << ref.physicians_id << endl;
    out << "Visit Dates: ";
    ref.visit_date.show();
    out << "Sevice charges on each visit: ";
    ref.charges.show();

    return out;
}

class Physician {
private:
    string name;
    int physician_id;
    int service_charges;
public:
    Physician() {
        name = "";
        physician_id = 0;
        service_charges = 0;
    }
    void insertRecord(string name, int id, int charges) {
        this->name = name;
        this->physician_id = id;
        this->service_charges = charges;
    }
    bool operator==(const Physician& ref) {
        return this->physician_id == ref.physician_id;
    }
    int getId() const {
        return this->physician_id;
    }
    void addVisit(string data, int charges) {
        // 
    }
    void Invoice() {

    }

    friend ostream& operator<<(ostream& out, const Physician& ref);
};

ostream& operator<<(ostream& out, const Physician& ref) {
    out << "Physician name: " << ref.name << endl;
    out << "Physician ID: " << ref.physician_id << endl;
    out << "Service Charges: " << ref.service_charges << endl;

    return out;
}

template<class T>
class queue {
    int front, rear;
    T data[10];
    int capacity;
public:
    queue() {
        rear = front = -1;
        capacity = 10;
    }

    bool isFull() {
        return (rear == capacity - 1);
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    bool insert(T x) {
        if (rear == -1) {   // first item is being inserted
            front = rear = 0;
            data[rear] = x;

            return true;
        }
        else {
            if (isFull())
                return false;
            else
            {
                int temp = front;
                while (temp <= rear) {
                    if (data[temp] == x) {
                        return false;
                    }
                    temp++;
                }

                data[++rear] = x;

                return true;
            }
        }
    }
    T dequeue() {
        if (!isEmpty()) {
            return (data[front++]);
        }
        else
        {
            cout << "Queue is empty ";
            exit(0);
        }
    }
    bool alreadyExist(T Pdata) {
        if (front == -1 || front > rear) return false;

        int temp = front;
        while (temp <= rear) {
            if (data[temp] == Pdata) {
                return true;
            }
            temp++;
        }
        return false;
    }
    void search(int id) {
        int t, b, mid;
        t = rear;
        b = front;

        int i = 0;
        while (b <= t) {
            mid = (b + t) / 2;
            if (id == data[mid].getId())
                b = t + 1;
            else if (id < data[mid].getId())
                t = mid - 1;
            else
                b = mid + 1;

            i++;
        }
        if (id == data[mid].getId())
            cout << data[mid];
        else
            cout << "Not found in " << i << " steps\n";
    }
    void edit(T Pdata, string date, int charges) {
        if (front == -1 || front > rear) return;

        int temp = front;
        while (temp <= rear) {
            if (data[temp] == Pdata) {
                data[temp].addVisit(date, charges);
                return;
            }
            temp++;
        }
    }
    void showData(int id) {
        int t, b, mid;
        t = rear;
        b = front;

        int i = 0;
        while (b <= t) {
            mid = (b + t) / 2;
            if (id == data[mid].getId())
                b = t + 1;
            else if (id < data[mid].getId())
                t = mid - 1;
            else
                b = mid + 1;

            i++;
        }
        if (id == data[mid].getId())
            data[mid].Invoice();
        else
            cout << "Not found in " << i << " steps\n";
    }
    void show() {
        int t;
        if (!isEmpty()) {
            t = front;
            while (t <= rear)
            {
                cout << data[t++];
                cout << endl << endl;
            }

            cout << endl;
        }
        else {
            cout << "No data in queue" << endl;
        }
    }
};

void insertPhysician(queue<Physician>& physQueue) {
    string name;
    int id, charges;

    cin.ignore();
    cout << "Please Enter the name of the Physician: " << endl;
    getline(cin, name);

    cout << "Please Enter ID: ";
    cin >> id;
    cout << "Service Charges: ";
    cin >> charges;

    Physician physician;
    physician.insertRecord(name, id, charges);

    if (physQueue.alreadyExist(physician) == false) {
        physQueue.insert(physician);
        cout << "\n-------------------------------\n";
        cout << "Pyshician Added successfully" << endl << endl;
        cout << "-------------------------------\n";
    }
    else {
        cout << "Physician with same id already exist." << endl;
    }
}

void insertPatient(queue<Patient>& patQueue) {
    int id;
    cout << "please enter the id of the patient: ";
    cin >> id;

    Patient temp;
    temp.insertRecord("", id, "", 0, 0, "", "", "", "", 0);

    if (patQueue.alreadyExist(temp) == false) {
        string name, visit, diagn, treatment, obsev_, phys_name;
        int turn = 1, charges, pys_id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Visit Date(DD/MM/YY): ";
        cin >> visit;

        cout << "Charges: ";
        cin >> charges;
        cout << "Diagnosis: ";
        cin >> diagn;
        cout << "Treatment: ";
        cin >> treatment;
        cout << "Observation: ";
        cin >> obsev_;
        cout << "Physician Name: ";
        cin.ignore();
        getline(cin, phys_name);
        cout << "Physician ID: ";
        cin >> pys_id;

        Patient newPat;
        newPat.insertRecord(name, id, visit, turn, charges, diagn, treatment, obsev_, phys_name, pys_id);

        patQueue.insert(newPat);
    }
    else {
        string date;
        int charges;


        cout << "Please Enter date of visit(DD/MM/YY) :";
        cin >> date;
        cout << "Enter charges: ";
        cin >> charges;

        patQueue.edit(temp, date, charges);
    }
}

void searchPatient(queue<Patient> patQueue) {
    int id;
    cout << "Please Enter Patient ID: ";
    cin >> id;

    patQueue.search(id);
}
void searchPhsysician(queue<Physician> phyQueue) {
    int id;
    cout << "Please Enter Patient ID: ";
    cin >> id;

    phyQueue.search(id);
}

void displayAllPatients(queue<Patient> patQueue) {
    patQueue.show();
}

void printInvoice(queue<Patient> patQueue) {
    int id;
    cout << "Please Enter Patient ID: ";
    cin >> id;

    patQueue.showData(id);
}

int main() {
    queue<Patient> patientqueue;
    queue<Physician> physicianQueue;

    int choice = -1;
    cout << "\n===============================================\n\n";
    cout << "  Emergency Room Patients Healthcare System\n";
    cout << "\n===============================================\n\n";

    do {
        cout << "1. Add new Patient." << endl;
        cout << "2. Add new Physician." << endl;
        cout << "3. Find Patient." << endl;
        cout << "4. Find Physician." << endl;
        cout << "5. Display All Patiens." << endl;
        cout << "6. Print Invoice of Patient." << endl;
        cout << "7. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            /* code */
            insertPatient(patientqueue);
            break;
        case 2:
            insertPhysician(physicianQueue);
            break;
        case 3:
            searchPatient(patientqueue);
            break;
        case 4:
            searchPhsysician(physicianQueue);
            break;
        case 5:
            displayAllPatients(patientqueue);
            break;
        case 6:
            printInvoice(patientqueue);
            break;

        }

    } while (choice != 7);

    return 0;
}