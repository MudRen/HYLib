// /d/taiyuan/road4.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡��������
̫ԭ�Ķ��ţ�������ȥ�ÿ��Ĵ����
LONG );
	set("exits", ([
		"northeast" : __DIR__"road5",
		"west" : __DIR__"dongmen",
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



