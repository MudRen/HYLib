// Room: /d/tangmen/kuixinlou3.c
// BY hem
inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
	���ǿ���¥����ߴ�����Ȼֻ����¥����Ŀ��ȥ��ʮ��ƽ���������̣���
���۵ס���������ͷ����������ա�վ�����������һ������������Ҫ����������
�����С�
LONG
	);
	

	set("exits", ([
		
		"down" : __DIR__"kuixinlou2"
	]));

	setup();
	replace_program(ROOM);
}
