//Cracked by Roath
// hsforest5
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
		"southwest" : __DIR__"hsforest1",
		"northeast" : __DIR__"hsforest16",
		"south" : __DIR__"hsforest2",
		"west" : __DIR__"hsforest4",		
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

