//room: /d/tangmen/changlang21.c
// by HEM
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵���������Ͼ�����������\n"
     );

  set("exits",([
      "south" : __DIR__"tianxingting",
      "north" : __DIR__"changlang22",
    ]));

 setup();
 replace_program(ROOM);
}




