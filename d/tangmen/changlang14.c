//room: /d/tangmen/changlang14.c

inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵��������������չ÷��\n"
     );

  set("exits",([
      "north" : __DIR__"zhanmeige",
      "south" : __DIR__"changlang15",
    ]));

 setup();
 replace_program(ROOM);
}




