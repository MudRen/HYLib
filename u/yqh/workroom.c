// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
	set("short", "��ʦ��Ϣ��");
	set("long", @LONG
������ǡ�������ʦ����Ϣ���ڣ��շ�ˢ��������ǽ���Ϲ�
ͺͺ��ʲô��û�У����ӵ����������һ���ľ�����������һ��
��ʦ���Բ�(board)��
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"north": "/d/death/outjail",
	]));
        set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( dir=="down" && !wizardp(me) );
                return notify_fail("����ֻ����ʦ�ŵǽ�ȥ��\n");
this_player()->move("/d/biwu/hole");
}
