// Room: /u/star/cun8.c
// star 1998/12/04 ��������Ȩ���У����������޸Ĵ���


inherit ROOM;

void create()
{
	set("short", "�嶫��");
	set("long", @LONG
������С��Ķ�ͷ����Ϊ����չ�������һƬ��Ţ��·�ǳ������ߡ�˳
������·һֱ����һ����ʱ���Ϳɵ�����ɽ�ˡ�
LONG
	);
        set("outdoors", "wudujiao");
        set("no_npc",1);
	set("exits", ([
		"northwest" : __DIR__"cun7",
//		"northeast" : __DIR__"cun7",
//		"southwest" : __DIR__"cun6",
		"east" : "/d/wuyi/path5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

