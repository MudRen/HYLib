// /d/taiyuan/road5.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��ɽʯ��");
	set("long", @LONG
̫ԭ����26������Ͻ��������������ɽ���嶥�����ҹ��ִ��ģ���Ҳ��
������ĵ���ʯ�ߡ����߿�����Ԫ̫��������ʮһ��(��Ԫ1234��1239��)���ɵ�ʿ
�ε·�(����������)�����˽����ڷ嶥�ͱ��Ϲ�����8�����ߡ���ɽʯ���е���ʯ
����66�𡢸�������8����˫���微���ɺ׵���ม��ʯ������ʵ��������ׯ
�ء����μ���ؾ����������������ʯ�ߵ��������졣
LONG );
	set("exits", ([
                "south" : __DIR__"road7-1",
		"northeast" : __DIR__"road6",
		"southwest" : __DIR__"road4",
		
	]));
	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



