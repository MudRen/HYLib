//room: /d/tangmen/changlang1.c

inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵�������������������á�\n"
     );

  set("exits",([
      "north" : __DIR__"xinyitang",
      "south" : __DIR__"changlang2",
    ]));

 setup();
 replace_program(ROOM);
}




