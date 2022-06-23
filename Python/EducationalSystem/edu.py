class EducationalSystem:
    def __init__(self, limit):
        self.subjects = dict()
        self.limit = limit
        
    def add_subject(self, subject):
        self.subjects[subject] = []
        
    def get_all_subjects(self):
        return list(self.subjects.keys())
    
    def add_student(self, subject, student):
        if len(self.subjects[subject]) < self.limit:
            self.subjects[subject].append(student)
        else:
            raise TooManyStudentException
        
    def get_all_students(self):
        students = set()
        for sub in self.subjects:
            for stud in self.subjects[sub]:
                students.add(stud)
        return students
    
    def get_number_of_free_places_per_subject(self):
        output = dict()
        for sub in self.subjects:
            if self.limit > len(self.subjects[sub]):
                output[sub] = self.limit - len(self.subjects[sub])
        return output
    
    def get_students_taking_all_subjects(self):
        output = [] 
        studonsub =  sum(self.subjects.values(), [])
        numberofsub = {i:studonsub.count(i) for i in self.get_all_students()}
        for stud in numberofsub:
            if numberofsub[stud] == len(self.subjects):
                output.add(stud)
        return output
        
class TooManyStudentException(Exception):
    pass
    
es = EducationalSystem(3)
es.add_subject("tesi")

print(es.get_students_taking_all_subjects())
