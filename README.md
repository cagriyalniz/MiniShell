
# MiniShell

    > Bash script terminal projesidir.

## Yol haritası

- white space kontrolü yapmak

- readline implemantasyonu

- env yapısı

- history yapısı

- redirection yapısı

- pipeline yapısı

- sinyal işlemleri

- hata kodları işlemleri

- crud işlemleri

    - lexical analizer

        - tablolar (parser_list; keyword_list; operator_list; quote_list; redir_list; command_list; delimiter_list; identifier_list; token_type_list;)

    - parser

        - shell komutları bölümlendirme

        - tokenize etme işlemi

        - token type bulma

        - token keyword eşletirme işlemi

- sytax analizer

- komut oluşturma

    - komut yürütme

## Açıklama

Bu projede bash terminalini taklit eden bir terminal yazdık. 

Bunun için önce rutine işlemler için fonksiyonlar ve amaçlar hazırladık.

İlk olarak bir satırı readline kütüphanesi kullanarak aldık bu satırı white space'ler den arındırdık sonra kullancağımız komutlar operatorler ve diğerler için tablolar oluşturduk.
Bu adımlardan sonra lexical analiz için parse etme işlemine geçtik
parse etme işlemi arg ve add olarak iki temel mantıkta kurguladık.
Parse etme işleminin her bir karakter tek tek okunarak buffer mantığı ile çalışmasını sağladık.
Parse ederken şu karakterleri göz önünde bulundurduk.

	- parser_arg_iskeyword_q (keywordler);
	- parser_arg_quote_q (tırnak içindekiler);
	- parser_arg_isnot_q (tırnak içinde olmayanlar);
	- parser_arg_redir_q (redirler);
	- parser_arg_pipe_q (pipeline);
    - parser_arg_space_q (boşluklar);
	- parser_add_dollar_q (dolar);
	- parser_add_operator_q (operatorler);
	- parser_add_option_q (optionlar);
	- parser_add_char_q (tek karakterler);

Parse etme işlemi sonucunda keyworler operatorler ve diğerlerini elde ettik ve token type'lerini keyworlere, bağlı option ve operatorlarine göre bölümlendirdik.
Bu bölümlendirme sonrasında komutların bulunduğu konumlara göre syntax kontrolü yaptık.
Redir , pipeline önceliklerine bağlı token typelar'a göre komut yürütme işlemini gerçekleştirdik.
Derlenebilir (bizim tarafımızdan işlemleri gerçekleştirilen ) veya çalıştırılabilir (execve fonskiyonu ile sistemin çalıştırdığı) komutlara göre komut tablosunu doldurduk ve bu sırayla komutları yürüttük ve sonuçlarını ilgili yerlere yazdık.

Tabi bash terminalinin kendisine özgü bazı özelliklerinden dolayı direkt bu karakterlere göre parse işlemini gerçekleştirmedik, bazı kısımlarında özel hamleler yapmamız gerekti. Örneğin, çift tırnak içinde bulunan tek tırnak karakteri, çift tırnak içinde bulunmayan tek tırnak karakterinden farklı çalışıyor. 

-> echo 'merhaba'

-> echo "mer'ha'ba"

Bu iki komut farklı çıktılar verecektir.

