//room: /d/tangmen/changlang4.c
//  by HEM
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵�����������Ǳ����⡣\n"
     );

  set("exits",([
      "north" : __DIR__"changlang3",
      "south" : __DIR__"bingqiku",
    ]));

 setup();
 replace_program(ROOM);
}




