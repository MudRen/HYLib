//room: /d/tangmen/changlang22.c
// by HEM
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵��\n"
     );

  set("exits",([
      "south" : __DIR__"changlang21",
      "north" : __DIR__"huayuan8",
    ]));

 setup();
 replace_program(ROOM);
}




