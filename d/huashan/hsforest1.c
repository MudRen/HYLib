//Cracked by Roath
// hsforest1
// qfy Oct 15, 97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ű�����������������������ľ�ߴ����ڵ���ɫ��������
����������֦Ҷ�ڷ���ҡ�ڣ������������������Ҷ���º��������ָ�ԭ
״���������κ��㼣��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"hsforest6",
		"northeast" : __DIR__"square",
//		"southeast" : __DIR__"hsstreet3",
//		"southwest" : __DIR__"hsstreet2",
		"north" : __DIR__"hsforest4",
		"west" : __DIR__"hsforest3",
		"east" : __DIR__"hsforest2",		
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

