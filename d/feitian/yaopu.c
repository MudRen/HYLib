// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ�һ��Ư����ҽʦ��æµ�ĸ����˿����ڹ�̨ǰ������
һ�Ź��(guanggao)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����ּ������֣���Ҫ�﹤�Ŀ����򰢻ݴ���������\n",
	]));
	set("objects", ([
		__DIR__"npc/gaohehui" : 1,
		__DIR__"npc/baixing" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"jiedao1",
		]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}

