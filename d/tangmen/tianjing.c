//room: /d/tangmen/tianjing.c
//  by HEM
inherit ROOM;

void create()
{
	set("outdoors", "tangmen");
	set("short","�쾮");
	set("long",
          "�������쾮��һ��Ƭ�����Ŀտ��أ��м��������õ����ˡ���������\n"
"�����ã������������á�\n"
       );

	set("exits",([
                   "north" : __DIR__"liujiantang",
                   "south" : __DIR__"xinyitang",
    ]));
	 set("objects", ([
        __DIR__"npc/zhuren" : 4,
    ]) );


 setup();
 replace_program(ROOM);
}




