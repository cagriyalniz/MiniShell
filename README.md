# MiniShell 

Bu projede bash terminalini taklit eden bir terminal yazdık. 

Bunun için terminalden aldığımız komutları önce parse ettik, sonra syntax analizi yaptık, en sonunda ilgili komuta göre çalışmasını sağladık.

Parse kısmında göz önünde bulundurduğumuz karakterler şunlardı: eşittir(=), tek tırnak('), çift tırnak("), boşluk( )

Tabi bash terminalinin kendisine özgü bazı özelliklerinden dolayı direkt bu karakterlere göre parse işlemini gerçekleştirmedik, bazı kısımlarında özel hamleler yapmamız gerekti. Örneğin, çift tırnak içinde bulunan tek tırnak karakteri, çift tırnak içinde bulunmayan tek tırnak karakterinden farklı çalışıyor. 

-> echo 'merhaba'

-> echo "mer'ha'ba"

Bu iki komut farklı çıktılar verecektir. 

.......

......

....

..

.
