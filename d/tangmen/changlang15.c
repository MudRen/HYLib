//room: /d/tangmen/changlang15.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵���������Ͼ������߸�\n"
     );

  set("exits",([
      "north" : __DIR__"changlang14",
      "south" : __DIR__"wumiange",
    ]));

 setup();
 replace_program(ROOM);
}




