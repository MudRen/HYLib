// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�������ܵ����ں����ģ�ʲôҲ�������У���ֻ����������ǰ�ߣ��ܷѾ�
�����һ�������ܵ���
LONG
	);
        
	set("exits", ([
	     "east" : __DIR__"midao4",
             "north" : __DIR__"midao2",
	]));

	setup();
	replace_program(ROOM);
}
