// Room: xiaoshan
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
������һ��Сɽ�����������˹��˸ߵĳ��ݣ�������һ���ҷظڣ���˵�����ֹ�����û
�˸�ȥ����Ӵ��������һ�����������ŵ��������ë����
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"houmen",
		"eastdown" :__DIR__"luan",
	]));

	set("objects", ([
		__DIR__"npc/diyun" : 1,
	]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}