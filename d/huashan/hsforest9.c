//Cracked by Roath
// hsforest9
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

	set("exits", ([ 
		"southwest" : __DIR__"hsforest11",
		"southeast" : __DIR__"hsforest12",
		"south" : __DIR__"hsforest13",
		"west" : __DIR__"hsforest7",	
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

