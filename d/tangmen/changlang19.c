//room: /d/tangmen/changlang19.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵�����������������߸�\n"
     );

  set("exits",([
      "west" : __DIR__"changlang18",
      "east" : __DIR__"wumiange",
    ]));

 setup();
 replace_program(ROOM);
}




