// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ƽ���㳡");
	set("long", @LONG
�����ƽ���ǵ����Ĺ㳡����������ķ�չ������������ࡣһ��ƽ
���������ĵط�һ�������Ҳ��һƬ��ƽ�ľ���ƽ���ǵľ���������Χ��
����ȥ���Խ������ﲢ���رܡ��㳡������������ķ�չ��ķ��������ˣ�
�����кܶ෿�ݺͽֵ���
LONG );
        set("no_sleep_room",1);
        set("outdoors", "city");
//	set("no_clean_up", 0);
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("exits", ([
		"east" : __DIR__"dong1",
		"south" : __DIR__"nan1",
		"west" : __DIR__"west1",
		"north" : __DIR__"bei1",
			]));
//	set("objects", ([
//		"quest/shenshu/jinyong" : 1,
//	]));
setup();
	"/clone/board/pingan_b"->foo();
//        replace_program(ROOM);
}
