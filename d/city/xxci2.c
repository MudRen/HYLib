// Room: /d/npc/xianxianci.c

inherit ROOM;

void create()
{
	set("short", "����������ʦ��");
	set("long", @LONG
�����Ǽ���������ʦ�ĵط���ÿλ�����ﱻ�������ʦ��Ϊ��MUD
�������ܳ��ġ�����ĥ��Ĺ��ס�������Զ���ᰮ�����������ǡ�
̧ͷһ�ź��ң������߸���������Ľ��֣����׸�Ϊ����ţ
ע�����������Ⱥ󡣰���ĸ˳��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"xxci1",
	]));
	set("no_fight",1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/five" : 1,
		"/d/npc/fcxy" : 1,
		"/d/npc/jungu" : 1,
		"/d/npc/doll" : 1,
		"/d/npc/wind" : 1,
	]));

	setup();
	replace_program(ROOM);
}
