// Room: /lanzhou/xiaochidian.c
// xws 1998/10/14 

inherit ROOM;

void create()
{
	set("short", "С�Ե�");
	set("long", @LONG
	��һ�߽��������ŵ�һ��ŨŨ��С����ζ����վ���ſھ���һ����úó�
һ�ٵĸо������Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ
����������ƹʺ�ҥ�ԣ����ﵹ�Ǹ������ڡ�С��������֮�䴩����ȥ��æ�ø���
�������к��㡣
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"beidajie2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

