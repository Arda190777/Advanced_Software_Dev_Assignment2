#include <iostream> // Ekrana yazi yazmak icin
#include <fstream> // Dosyayi acmak ve okumak icin
#include <string> // Metin kullanmak icin
#include <vector> // Birden fazla ogrenciyi listede tutmak icin

#define PRE_RELEASE // Pre-release modunu aktif eder

using namespace std; // std:: yazmadan cout, string ve vector kullanmamizi saglar

struct STUDENT_DATA // Ogrenci bilgilerini tutan yapi
{
    string firstName; // Ogrencinin adini tutar
    string lastName; // Ogrencinin soyadini tutar
    string email; // Ogrencinin email adresini tutar
};

int main()
{
    vector<STUDENT_DATA> studentList; // Tum ogrencileri tutacak liste

#ifdef PRE_RELEASE
    ifstream file("StudentData_Emails.txt"); // Pre-release dosyasini acar
    cout << "Running Pre-Release Version" << endl; // Pre-release mesajini yazdirir
#else
    ifstream file("StudentData.txt"); // Standard dosyayi acar
    cout << "Running Standard Version" << endl; // Standard mesajini yazdirir
#endif

    if (!file.is_open()) // Dosya acilmazsa kontrol eder
    {
        cout << "File couldn't open" << endl; // Hata mesaji yazdirir
        return 1; // Programi bitirir
    }

    string line; // Dosyadan okunan satiri tutar

    while (getline(file, line)) // Dosyayi satir satir okur
    {
        int firstComma = line.find(','); // Ilk virgulun yerini bulur

        if (firstComma != -1) // Ilk virgul bulunduysa devam eder
        {
            STUDENT_DATA student; // Yeni bir ogrenci olusturur

            student.firstName = line.substr(0, firstComma); // Adi alir

#ifdef PRE_RELEASE
            int secondComma = line.find(',', firstComma + 1); // Ikinci virgulun yerini bulur

            if (secondComma != -1) // Ikinci virgul bulunduysa devam eder
            {
                student.lastName = line.substr(firstComma + 1, secondComma - firstComma - 1); // Soyadi alir
                student.email = line.substr(secondComma + 1); // Email adresini alir
            }
#else
            student.lastName = line.substr(firstComma + 1); // Standard modda soyadi alir
#endif

            studentList.push_back(student); // Ogrenciyi listeye ekler
        }
    }

#ifdef _DEBUG // Sadece Debug modunda calisir

    cout << "Student List:" << endl; // Baslik yazdirir

    for (int i = 0; i < studentList.size(); i++) // Listedeki tum ogrencileri gezer
    {
        cout << studentList[i].firstName << " "
            << studentList[i].lastName; // Ad ve soyadi yazdirir

#ifdef PRE_RELEASE
        cout << " " << studentList[i].email; // Pre-release modunda emaili de yazdirir
#endif

        cout << endl; // Yeni satira gecer
    }

#endif

    file.close(); // Dosyayi kapatir

    return 1; // Programi bitirir
}