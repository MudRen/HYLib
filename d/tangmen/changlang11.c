//room: /d/tangmen/changlang11.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵�����������ǹҽ��á�\n"
     );

  set("exits",([
      "north" : __DIR__"changlang10",
      "south" : __DIR__"guajiantang",
    ]));

 setup();
 replace_program(ROOM);
}




