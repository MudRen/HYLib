inherit ROOM;

void create()
{
	set("short", "ҩ���ʷ�");
	set("long", @LONG
�������ҩ���ʷ���ҩ�̵����ϰ�������̫ʦ���ϳ����
�ء�ҩ�̵��ʷ��������ʱ���һ��æ�����ʡ���������һ���
���ʱ�������Ҫ����������Ǯ���ҵĿɾͺ��ˡ�
LONG);
	set("objects", ([
  		__DIR__"npc/wupanbing" : 1,
	]));
        set("no_fight", 1);
	set("no_clean_up", 0);
	set("exits", ([
  		"south" : __DIR__"yaopu",
	]));

	set("coor/x", -220);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
