// Advanced_Software_Dev_Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // Ekrana yazi yazmak icin
#include <fstream> // Dosyayi acmak ve okumak icin kullaniyoruz
#include <string> // Metin degisikliklerini kullanmak icin 
#include <vector> // Birden fazla ogrencinin bilgisini listede tutmak icin
using namespace std; // std = yazmadan cout, string vector gibi seyleri kullanmamizi sagliyorr.
struct STUDENT_DATA // std:: Ogrenci bilgilerini tutmak icin bir yapi olusturur
{
    string firstName; // Ogrenci adini tutuyor
    string lastName; // Ogrenci soyadini tutuyor
};

int main()
{
    vector<STUDENT_DATA> studentList; // Tum ogrecileri tutacak liste
    ifstream file("StudentData.txt"); // StudentData.txt dosyasini acar
    if (!file.is_open()) // Dosya acilmazsa bu kisim calisir
    {
        cout << "File couldn't open" << endl; // ekrana hata mesaji yazar;
            return 1;  // Programi btirir

    }

    string line; // Dosyadan okunan her satiri gecici olarak tutar

    while (getline(file, line))
    {
        // Dosyayi satir satir okur
        int comma = line.find(','); // Satirdaki virgulun yerini bulur
        if (comma != -1) // Eger virgul bulunduysa devam eder
        {
            STUDENT_DATA student; // Yeni bir ogrenci olusturur
            student.firstName = line.substr(0, comma); // virguldeki onceki kisimi alir ve ogrencinin adi yapar
            student.lastName = line.substr(comma + 1); // virgulden sonraki kismi alir ve ogrencin soy adi yapar

            studentList.push_back(student);
            //Ogrenciyi studentList isimli listeye ekler

        }




    }
#ifdef _DEBUG   // Program Debug modunda calisiyorsa bu kisim aktif olur

    cout << "Student List:" << endl; // Baslik yazdirir

    for (int i = 0; i < studentList.size(); i++) // Listedeki tum ogrencileri gezer
    {
        cout << studentList[i].firstName << " "  // Ogrencinin adini yazdirir
            << studentList[i].lastName << endl; // Ogrencinin soyadini yazdirir
    }

#endif   // Debug kodunun bittigi yer
    file.close(); // Dosyayi kapa
    return 1; // programi bitir

}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
