// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�������ܵ����ں����ģ���ֻ����������ǰ�ߣ��ܵ�����ľ����������
ʯ���ӡ���ֻ�ܷܺѾ������һ�������ܵ���
LONG
	);        

	set("exits", ([
	    "southdown" : __DIR__"midao2",
	]));

	setup();
	replace_program(ROOM);
}
