
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ��˸�
�����ž�װ���¼��������еĻ���������ŵ�������������ЩЩϰ
��Ľ����ˡ���·��������������������֡�
LONG );
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : "/d/cangzhou/nroad3",
		//"west" : "/d/huizhu/to_bj",
	]));
	set("objects",([
		"/d/taishan/npc/tangzi" : 2,
"quest/skills2/wunon/non/nontian" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



