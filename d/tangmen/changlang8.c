//room: /d/tangmen/changlang8.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵�����������������´�����\n"
     );

  set("exits",([
      "north" : __DIR__"dating",
      "south" : __DIR__"changlang9",
    ]));

 setup();
 replace_program(ROOM);
}




