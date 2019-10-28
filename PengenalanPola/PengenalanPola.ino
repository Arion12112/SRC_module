String readString; //Inisialisasi variabel readString yang mempunyai tipe data String
char c; //Inisialisasi variabel c yang mempunyai tipe data char
int x; //Inisialisasi variable x yang mempunyai tipe data integer
int i; //Inisialisasi variable i yang mempunyai tipe data integer
int j; //Inisialisasi variable j yang mempunyai tipe data integer

void setup() 
{
  Serial.begin(9600); //Inisialisasi Serial Monitor dengan Baud Rate 9600
}

void loop() 
{
  while (Serial.available())  //Apabila ada input maka fungsi dijalankan 
  { 
    delay(2); //delay agar byte yang di input masuk ke buffer dengan aman
    c = Serial.read(); // membaca input dari serial monitor berupa char
    readString += c; //membuat char dari input menjadi string
  }

  if (readString.length() >0) //Jika variabel readString mempunyai isi
  {  
    Serial.print("Input yang dimasukkan adalah: "); //mencetak string "Input yang dimasukkan adalah: " ke serial monitor
    Serial.println(readString); //mencetak nilai dari readString ke serial monitor
    x = readString.toInt(); //Memasukan isi dari variabel readString yang tipe datanya diubah menjadi integer ke variabel x 
    for (i=1;i<=x;i++) //untuk nilai i = 1 lakukan perulangan sampai bernilai x dengan syarat setiap perulangan nilai i ditambah 1
    {
        for(j=1;j<=x;j++) //untuk nilai i = 1 lakukan perulangan sampai bernilai x dengan syarat setiap perulangan nilai i ditambah 1
        {
            if((i==j)||(i+j)%(x+1)==0) //jika nilai i sama dengan nilai j ATAU nilai i ditambah nilai j di modulo nilai x ditambah 1 sama dengan 0  
            {
            Serial.print("*"); //maka cetak *
            }
            else //selainnya
            {
            Serial.print(" "); //maka cetak spasi
            }
        }
          Serial.println(); //apabila nilai j sama dengan nilai input x maka cetak baris baru 
    }
    readString=""; //mengosongkan isi dari variabel readString 
    Serial.println(); //mencetak newline(baris baru) di serial monitor     
  }
}
