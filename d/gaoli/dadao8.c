// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������طǳ���æ����ʱ������������
�ҴҶ������ϱ�ͨ������ǡ���������һ��ͨ��Ͼ����Ĵ����
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southwest" : __DIR__"jiaojunchang",
                "northeast" : __DIR__"dadao1",
	]));
       setup();
	replace_program(ROOM);
}	
