//room: /d/tangmen/lianwuchang.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long",@LONG
	���������ŵ����䳡������Щ���ŵ��ܹ��ɽ����Ƴ��Ļ�������,��������
�������ڴ����������书��
LONG    );
	set("outdoors", "tangmen");
	set("exits",([
       
		"north" : __DIR__"xiouxishi",
		"south" : __DIR__"changlang18",
	
	]));
	 set("objects", ([
        	__DIR__"npc/zhuren" : 4,
    ]) );

 setup();
 replace_program(ROOM);
}




