//room: /d/tangmen/changlang18.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "����һ�γ��ȣ������Ǻ�ľ�����������к�Ư�����ử���鷨��ÿһ�γ��ȵ�\n"
"�黭ǡ�ö������һ�����»���һ����Զ�Ĵ�˵���������������䳡��\n"
     );

  set("exits",([
        "north" : __DIR__"lianwuchang",
	"west" : __DIR__"changlang17",
	"east" : __DIR__"changlang19",    
	]));

 setup();
 replace_program(ROOM);
}




