//room: /d/tangmen/changlang20.c
// by HEM
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵����������������������\n"
     );

  set("exits",([
      "north" : __DIR__"tianxingting",
      "south" : __DIR__"xiaoxiao-lou",
    ]));

 setup();
 replace_program(ROOM);
}




