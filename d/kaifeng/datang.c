// /kaifeng/kaifeng.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "���⸮����");
	set("long", @LONG
���ŵ�����վ�����ߣ����Ա�����ͷ����ͷ����ͷ����ա��������
�ķ������˺�ëֱ����̨����߹ҡ��������������Ҷ���˴��ã���
��Ҳ�����������ȥ���ǽֵ���
LONG
	);
	set("objects", ([
		__DIR__"npc/baozheng" : 1,
__DIR__"npc/wangchao" : 1,
__DIR__"npc/sister" : 1,
	__DIR__"npc/wife" : 1,
__DIR__"npc/mahan" : 1,
	__DIR__"npc/zhanzhao.c" : 1,					
	]));
	set("exits", ([
		"east" : __DIR__"kaifeng",
	]));

	setup();
	replace_program(ROOM);
}
