// Room: /ruzhou/jiulou1.c
// YZC 1995/12/04 llm 99/07

inherit ROOM;

void create()
{
	set("short", "ӭ��¥");
	set("long", @LONG
��Բ�������ڣ�ӭ��¥��������ν�ǲ�С��������ŵ���ʿ�ſ�
ҲΪ��������ʫ�����²����������Ķ�����¥�²��ü��ף��˿Ͷ�
�ǴҴҵ����ˣ������ӣ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����ר�žٰ�
��������ϲ���á�
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaozheng",
		"up" : __DIR__"xifu-tang",
	]));

	set("objects", ([
      __DIR__"npc/xiaoer" : 1,
	]));

	setup();
	replace_program(ROOM);
}

