# Bus Reservation System | نظام حجز تذاكر الباص

Bus Reservation System Written By c++ console program


## The main purpose of create this system is to improve the human transportation system, the system will automatically arrange all the ticket to it target trip, with each trip The system will arrange the bus size and amount . 


The system provides the opportunity to buy tickets in advance, with limitations, and buying in advance for one week only .

The system provides many payment methods:-
##### 1- cash or direct 
##### 2- buy by card 


This system cards has to top up then use, which mean the user can buy as much as he want cards , in each card he can top up the amount , the card has not valid date limitation, once the amount of card is not enough use have to top up.


The system provides many choices for users or customers:-
<br>
###### 1-buy Card 
###### 2-buy ticket 
###### 3-refund ticket




#### Buying card operation start from request user to input his name and id , then check if the user exist , after this step there are two possible operations :- 

###### 1- user exist then we ask him to input trip add and use payment method , finally confirm buy card . 

###### 2- user not exist, here first we have to add user to our system, by asking him his name and id and phone Number, after we added the  successfully to our new user , then get the confirmation to finish the buying operation. 


>> Notice | This system doesn’t provide chance to refund the card , once user confirm to buy the card no way to refund it . 



#### Next choice or service this system offers for user is buying tickets, this operation is more complicated than buying card. 


The user requests to buy new ticket , then system will show the user the available trips list , then depends on user input trip id , we move to next step and which is how many seat want to book , this system give limitations as we mentioned before , each request has three tickets, so the user each time buy ticket can buy three tickets under his name , then how to pay , there are two options :- 

###### a) if the user chose card, then we have to check  whether the card amount is enough or not.

###### b) if the user chose  cash or direct method , then directly get the money and confirm the buy operation. 



Also this system provide refund ticket service, with restrictions, the ticket can only refund before the deadline for the trip, trip deadline set by user in advance ,refund total amount of ticket .





## الهدف الرئيسي من كتابة هذا البرنامج هو من اجل تسهيل عملية بيع وترجيع التذاكر للباصات ، بحيث يحافظ على سرعة الإجراءات وتجنب الأخطاء البشرية .

هذا النظام يوفر امكانية شراء مسبقاً ، مع بعض القيود، وهذا المده لاسبوع واحد مقدماً .


يوفر هذا النظام عده طرق للدفع منها :-
##### ١- الدفع نقداً 
##### ٢- الدفع بالبطاقة


البطاقات التي يوفرها هذا النظام تعمل على مبدأ "اشحن ثم استخدم" ، بحيث لا يوجد مده صلاحية او انتهاء للبطاقة ، بحيث يقترن امكانية استعمال البطاقة بالرصيد المتوفر داخلها . 

##
#### شرح عمل النظام :-

#### شراء البطاقة 


تبدأ عملية شراء البطاقة بطلب المستخدم ادخال lسمه ورقم الهوية الشخصية ورقم الهاتف ، بعد هذا الخطوة هناك احتمالين :-


##### الأول المستخدم مسجل بالفعل بالنظام .
##### الثاني المستخدم غير مسجل بالنظام .


في الحالة الثانية يتم تسجيل المستخدم بالنظام ثم ننتقل إلى الخطوة التالية ، والتي هي سؤال المستخدم عن كمية الرصيد المراد شحن البطاقة به .


تنويه :- هذا النظام لا يدعم عملية ترجيع البطاقة.
#
#### شراء التذاكر 


تبدأ عملية شراء التذاكر بعرض لائحة الرحلات المتوفرة للمستخدم ، ثم طلب ادخال رقم الرحلة الهدف .

طرق الدفع بشراء التذاكر المتوفرة :-
##### ١- نقداً 
##### ٢- بالبطاقة 


اذا اختار المستخدم الشراء بالبطاقة نعرض لائحة بالبطاقات المتوفرة له ، و نطلب منه ادخال رقم البطاقة ، اذا كانت صالحة نتم العملية .
#
#### ترجيع التذكرة 

عملية الترجيع تبدأ بطلب من المستخدم ، ثم يُطلب منه ادخال رقم الرحلة ثم رقم التذكرة ، وهنا وحب التنوية أن عملية الترجيع لها وقت محدد ، بحث ان تكون قبل اكثر من ١٥ دقيقة من الانطلاق وإلا فلا يمكن اكمال العملية . 


