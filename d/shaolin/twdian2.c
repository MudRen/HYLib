// Room: /d/shaolin/twdian2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������������������Ŵ�Ħ��ʦ��������ʿ�Ļ�
���Լ�һЩ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ
��ȡ������˴��Ǳ��ɵ��Ӵ�������֮������λ��������ֳ�
���飬���������
LONG );
	set("exits", ([
		"east" : __DIR__"twdian",
	]));
	set("sleep_room", "1");
	set("no_fight", "1");
	set("no_npc", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

