//room: /d/tangmen/changlang2.c
//By HEM
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵���������������´�����\n"
     );

  set("exits",([
      "north" : __DIR__"changlang1",
      "south" : __DIR__"dating",
    ]));

 setup();
 replace_program(ROOM);
}




