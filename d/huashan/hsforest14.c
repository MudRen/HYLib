//Cracked by Roath
// hsforest14
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
		"north" : __DIR__"hsforest11",
		"west" : __DIR__"hsforest15",
		"east" : __DIR__"hsforest13",		
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
