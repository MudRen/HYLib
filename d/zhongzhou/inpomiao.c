inherit ROOM;

void create()
{
	set("short", "ؤ�����ݷֶ�");
	set("long", @LONG
������ؤ���������ݸ��ķֶ档���������ɢ����һЩ��
�ݺ����ޱ������е��������ѱ��˰��ߣ����һ��л���ռ
�˵ط�����ֻ���߹�ɢ�������и�����ԭ����ʢ��ˮ�ġ�
LONG);
	set("no_clean_up", 0);
	set("outdoors", "zhongzhou");
	set("exits", ([
  		"out" : __DIR__"guandimiao",
	]));
	set("objects", ([
                __DIR__"npc/walker" : 1,
	]));
	set("coor/x", -260);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
