// /d/yixing/clxiaoting.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���ǰ������ܹ����ֻ��ܴ��µ����ڣ�������һ��̫ʦ�Σ����ϵ�
�Ű�ɵĺ��������ǽ�ϸ�ӹ���ŵع��ż���ɽˮ�ֻ���һ����֪����
����֮������ǰ����ջ�����ʮ�ַ�ï��
LONG );
	set("exits", ([
		"south" : __DIR__"clzoulang2",
		"north" : __DIR__"clwoshi",
	]));
	set("objects",([
		__DIR__"npc/cl_situ" : 1,
	]));
	setup();
}

