//Cracked by Roath
// hsstreet3
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
//		"north" : __DIR__"hsstreet3",
//		"northwest" : __DIR__"hsstreet2",
		"southwest" : __DIR__"hsforest10",
		"southeast" : __DIR__"hsforest11",
		"west" : __DIR__"hsforest8",
		"east" : __DIR__"hsforest9",		
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

