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
	 	"down" : __DIR__"guest_room",
                "west" : __DIR__"proom",
                "east" : __DIR__"edit_room",
	 	"up":    __DIR__"robot_court",
	 	"north": "/d/death/outjail",
	 	"south": __DIR__"work"
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
