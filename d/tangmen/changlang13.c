//room: /d/tangmen/changlang13.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵���������Ͼ���չ÷��\n"
     );

  set("exits",([
      "north" : __DIR__"changlang12",
      "south" : __DIR__"zhanmeige",
    ]));

 setup();
 replace_program(ROOM);
}




