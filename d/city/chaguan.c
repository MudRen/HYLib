// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�
�����Ǹ������ڡ�����(help tea)����ѯ��ĺ��������
LONG );
	set("resource/water", 1);
//	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"nandajie2",
		"west" : __DIR__"huadian2",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
//		"d/pingan/npc/wang" : 1,	
		"d/pingan/shenzhen/npc/shenyi" : 1,	
		"/quest/newbie/qiandao/yuexm" : 1,	
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/player_b"->foo();
}

