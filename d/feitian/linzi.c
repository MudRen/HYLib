// Room: linzi.c
// Date: diabio

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ɭ���в�");
	set("long", @LONG
ɭ����������һ�����𣬼����ز�����Χ�����ܡ�һ����ɫ�����
���������ڻ�ߴ������
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"senlin",
	]));

	set("objects",([
		__DIR__"npc/luo": 1,
	]));
	setup();
}

void init()
{	
	mapping mine;
        object ob = this_player();

	mine = this_player()->query("family");

    if(!userp(ob)) return;
    if (ob->query("family/family_name") == "������" && (ob->query("passdu") || ob->query("pass_xin"))) 
return;
	message_vision("
�����м����ŵ�ɮ���ƺ���֪����ĵ�������Ȼ�������ž�
"CYN"���������.....
�������........
....����......��.......
"HIC"ͻȻɮ�����о����ʢ,��������������˫�ֺ�ʮ�������"NOR"
"CYN"ɮ������������
......�ȿ����...��..
��������.... ���������.....��
"HIR"ֻ��һ�����죬���ܵĵز��������һ��ȫ������ը����"NOR"
"RED"$Nֻ������һ��ǿ���Ĳ����������������⵽�޴���ͻ��һ�ھ������һ���"HIR"��Ѫ\n\n" NOR, this_player());
}

