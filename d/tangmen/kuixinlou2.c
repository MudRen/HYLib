// Room: /d/tangmen/kuixinlou2.c
// BY hem
inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
	�������¥�ĵڶ���,������������ڷ��Ų輸�����Σ�һ����Ⱦ������ÿ
�춼��������ɨ���������߾��ǵ������ˡ�
LONG
	);
	

	set("exits", ([
		
		"down" : __DIR__"kuixinlou",
		"up" : __DIR__"kuixinlou3",
	]));

	setup();
	replace_program(ROOM);
}
