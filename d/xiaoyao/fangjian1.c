// fangjian1.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Կ���������ǰ������һ������ĵط����������һ��ʯ������ֻ��
��֮�⣬�յ�����һ�����У�ʯ���Ͽ����ݺ�ʮ�ŵ���·������ϲ��Ŷ���
������ӣ�ȴ�Ǻڰ׶��ţ���Ȼ��һ��û��������塣
LONG );
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
