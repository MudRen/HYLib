//room: /d/tangmen/zhawujian.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","�����");
  set("long",
      "���������ŵ�����䡣����ɢ�ҵĶѷ�����಻֪����ʲô�Ķ�����\n"
     );

  set("exits",([
        "north" : __DIR__"huayuan11",
        "east" : __DIR__"changlang16",
    	"westup" : __DIR__"jiaolou5",
	]));
    set("objects", ([
                __DIR__"npc/puren" : 1,
                        ]));


 setup();
 replace_program(ROOM);
}




