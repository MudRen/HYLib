// Room: /d/wizard/edit_room.c

inherit ROOM;

void create()
{
	set("short", "�޸ļ�¼��");
	set("long", @LONG
����Ĺ�����ϼ�¼����ʦ�ǽ���ļ�¼��
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"west" : __DIR__"wizard_room"
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	"/clone/board/wized_b"->foo();
	replace_program(ROOM);
}
