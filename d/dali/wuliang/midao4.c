// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�������ܵ����ں����ģ�ʲôҲ�������У���ֻ����������ǰ�ߣ��ܷѾ�
�����һ�������ܵ�����
LONG
	); 
	set("exits", ([
	     "southdown" : __DIR__"midao5",
             "west" : __DIR__"midao3",
	]));

	setup();
	replace_program(ROOM);
}
