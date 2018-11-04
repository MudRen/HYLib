// Room: /u/qingyun/jyzj/lingaogong.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���Ṭ");
	set("long", @LONG
ֻ�����ϱ����д�š����Ṭ������Ѫ����֡�һ������������һ����
������ʮ��ͷ�۽��Ͷ�Ĵ�Ȯ���ֳ����Ŷ��ڵ��ϣ�һ�����׹��õ�Ů����
��һ�Ż�Ƥ���ϣ�����ִƤ�ޣ�����ָ�Ӷ�Ȯҧ�ˡ��ϱ���һ����Ժ�ӡ�
LONG	);
	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"npc/goupu" : 1,
		__DIR__"npc/dog1" : 1,
		__DIR__"npc/dog2" : 1,
		__DIR__"npc/dog3" : 1,
		__DIR__"npc/dog4" : 1,
		__DIR__"npc/zhu-jiuzhen" : 1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
