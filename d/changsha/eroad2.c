// /d/zhuojun/eroad2.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "´ɽ��");
	set("long", @LONG
´ɽ����������´ɽ�Ĺ������У��������Ͽ�������׺�
Ȫǰ��ص��㡢�������������������ơ������ֺ���Ϊ��
��������ʦ�׽�����"��κ�����ʤ�������һ����"֮��,����
ǧ�ֹ���ׯ�ϴ��顣��Ժ�ڱ��������������ɣ���Ϊ´ɽ����
����ʷ�Ļ��֤��
LONG );

	set("exits", ([
		"east"      : __DIR__"eroad3",
		"west"      : __DIR__"eroad1",
		
	]));
	       set("objects",([
        "/d/shaolin/npc/xiao-bei" : 2,
        ]));
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



