//room: /d/tangmen/changlang10.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵�������������Ǽ�������\n"
     );

  set("exits",([
      "north" : __DIR__"jizuting",
      "south" : __DIR__"changlang11",
    ]));

 setup();
 replace_program(ROOM);
}




