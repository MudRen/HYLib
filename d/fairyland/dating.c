// Room: /u/qingyun/jyzj/dating.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"����"NOR);
	set("long", @LONG
������ɽׯ���֮��������֮�����Ŵ˼�ׯ����ÿ����ڣ������������
�ڴ˵Ⱥϣ����������һЩ���ӡ��������Է�����������ӺͲ�����ǹ���
�����ġ�������ȻԶ����ԭ��������֮��ȴ�ǵ��治�١����б��Ϲ���һ��
�ͻ�֮ͼ�������м���ͯ�����ص��̺��š�
LONG	);
	set("exits", ([
		"south" : __DIR__"hongmeizhuang",
		"north" : __DIR__"nuange",
		"east" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"npc/zhu-changling" : 1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
