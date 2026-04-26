# Sliding_Puzzle
Konsol Tabanli 3x3 Puzzle Oyunu
C programlama dili kullanılarak geliştirilmiş, terminal üzerinden oynanabilen klasik bir 3x3 sliding puzzle oyunudur.

Oyunun amacı, rastgele karıştırılmış olan tablodaki sayıları kaydırarak 1'den 8'e kadar sıralamak ve boş alanı (0) sağ alt köşeye getirmektir.

Özellikler:

Renkli Arayüz: Doğru pozisyona yerleştirilen sayılar oyuncuya yardımcı olmak için yeşil renkte gösterilir.

Zaman Ölçümü: Oyun başladığı andan bitiş anına kadar geçen süreyi saniye cinsinden hesaplar.

Liderlik Tablosu: Oyuncuların isimleri ve tamamlama süreleri kaydedilir. Oyun sonunda en iyi 5 süre ekranda listelenir.

Dinamik Karıştırma: Oyun her başladığında sayılar çözülebilir bir formatta, rastgele karıştırılır.

Gereksinimler
Bu proje, Windows platformuna özgü kütüphaneler (windows.h ve conio.h) kullanılarak yazılmıştır. Bu nedenle projenin Windows İşletim Sistemi üzerinde derlenmesi ve çalıştırılması gerekmektedir.

GCC (MinGW) veya herhangi bir C derleyicisi.

Kontroller
Oyunda boş alanı hareket ettirmek için klavyenizin yön tuşlarını veya WASD tuşlarını kullanabilirsiniz.

W veya Yukarı Ok: Boşluğu yukarı hareket ettirir.

S veya Aşağı Ok: Boşluğu aşağı hareket ettirir.

A veya Sol Ok: Boşluğu sola hareket ettirir.

D veya Sağ Ok: Boşluğu sağa hareket ettirir.

Q: Oyundan çıkış yapar.